<?php
/**
 * @file
 * Farm delivery admin pages
 */

/**
 * Form builder function for the delivery generator.
 */
function farm_delivery_generate_form($form, &$form_state) {

  // Set the page title.
  drupal_set_title('Generate Deliveries');

  // Overview.
  $form['overview'] = array(
    '#type' => 'markup',
    '#markup' => t('<p>Use the form below to generate a list of deliveries. These deliveries will appear in the <a href="@deliveries">Farm Deliveries</a> list.</p><p>Deliveries will be generated based on completed orders in the system, using the options below.</p>', array('@deliveries' => '/admin/farm/deliveries')),
  );

  // Delivery date.
  $today = date('Y-m-d');
  $form['date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Delivery date'),
    '#description' => t('Enter the date that the deliveries will be made.'),
    '#default_value' => $today,
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'm/d/Y',
    '#date_increment' => 1,
    '#date_year_range' => '0:+1',
    '#required' => TRUE,
  );

  // Orders since date.
  $lastweek = date('Y-m-d', strtotime('1 week ago'));
  $form['since'] = array(
    '#type' => 'date_popup',
    '#title' => t('Include orders since'),
    '#description' => t('Deliveries will be generated for all orders that were created after this date.'),
    '#default_value' => $lastweek,
    '#date_type' => DATE_DATETIME,
    '#date_timezone' => date_default_timezone(),
    '#date_format' => 'm/d/Y',
    '#date_increment' => 1,
    '#date_year_range' => '-1:+1',
    '#required' => TRUE,
  );

  // Submit button.
  $form['actions']['#weight'] = 100;
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate Deliveries'),
  );

  // Return the form array.
  return $form;
}

/**
 * Validation function for the generate deliveries form.
 */
function farm_delivery_generate_form_validate($form, &$form_state) {

  // Convert dates to a unix timestamps.
  $delivery_date = strtotime($form_state['values']['date']);
  $since_date = strtotime($form_state['values']['since']);

  // Deliveries must be made in the future.
  $today = strtotime(date('Y-m-d'));
  if ($delivery_date < $today) {
    form_set_error('date', t('Deliveries cannot be made in the past.'));
  }

  // Do not allow deliveries for orders over 60 days old (as a performance precaution).
  $cutoff = REQUEST_TIME - 60 * 60 * 24 * 60;
  if ($since_date < $cutoff) {
    form_set_error('since', t('Only orders created in the past 60 days can be used to generate deliveries.'));
  }
}

/**
 * Submit function for the generate deliveries form.
 */
function farm_delivery_generate_form_submit($form, &$form_state) {

  // Convert the delivery date to a unix timestamp.
  $delivery_date = strtotime($form_state['values']['date']);

  // Start an empty array of deliveries.
  $deliveries = array();

  // Ask modules for order items.
  foreach (module_implements('farm_delivery_orders') as $module) {
    $delivery_orders = module_invoke($module, 'farm_delivery_orders', $form_state);

    // Iterate through the delivery orders.
    foreach ($delivery_orders as $order_id) {

      // Load the order.
      $order = commerce_order_load($order_id);

      // Create a new delivery log item.
      $delivery = entity_create('log', array('type' => 'farm_delivery'));

      // Set the delivery date.
      $delivery->field_farm_date[LANGUAGE_NONE][] = array('value' => $delivery_date);

      // Set the status to 'pending'.
      $delivery->field_farm_delivery_status[LANGUAGE_NONE][] = array('value' => 'pending');

      // Add the order id.
      $delivery->field_farm_orders[LANGUAGE_NONE][] = array('target_id' => $order_id);

      // Add the order's shipping address if available.
      if (!empty($order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id'])) {

        // Load the customer profile.
        $shipping_profile = commerce_customer_profile_load($order->commerce_customer_shipping[LANGUAGE_NONE][0]['profile_id']);

        // Copy the customer's shipping address to the delivery.
        $delivery->field_farm_address = $shipping_profile->commerce_customer_address;
      }

      // If the commerce_pickup module is enabled, see if the order has a pickup location.
      if (module_exists('commerce_pickup')) {

        // Load the order's pickup line item, if available.
        $pickup = _commerce_pickup_order_line_item($order);
        if (!empty($pickup) && !empty($pickup->data['shipping_service']['name'])) {

          // Parse the shipping service name.
          $pickup_parse = _commerce_pickup_parse_location($pickup->data['shipping_service']['name']);

          // If there is a node id...
          if (!empty($pickup_parse['id'])) {

            // Load the node.
            $pickup_node = node_load($pickup_parse['id']);

            // Add a reference to the pickup location node from the delivery.
            $delivery->field_farm_pickup_location[LANGUAGE_NONE][] = array('target_id' => $pickup_parse['id']);

            // Copy the pickup location's address to the delivery.
            $delivery->field_farm_address = $pickup_node->field_pickup_address;
          }
        }
      }

      // Add to the array of deliveries.
      $deliveries[] = $delivery;
    }
  }

  // Create deliveries.
  $created = 0;
  foreach ($deliveries as $delivery) {
    log_save($delivery);
    $created++;
  }

  // Announce how many were created.
  if ($created == 0) {
    drupal_set_message(t('No deliveries were generated.'));
  }
  elseif ($created == 1) {
    drupal_set_message(t('1 delivery was generated.'));
  }
  else {
    drupal_set_message($created . t(' deliveries were generated.'));
  }

  // Redirect to the deliveries list.
  $form_state['redirect'] = 'admin/farm/deliveries';
}