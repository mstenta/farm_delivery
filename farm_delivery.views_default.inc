<?php
/**
 * @file
 * farm_delivery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farm_delivery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'farm_deliveries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'log';
  $view->human_name = 'Farm Deliveries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Farm Deliveries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any log entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'field_farm_date' => 'field_farm_date',
    'field_farm_pickup_location' => 'field_farm_pickup_location',
    'field_farm_address' => 'field_farm_address',
    'field_farm_orders' => 'field_farm_orders',
    'field_farm_delivery_status' => 'field_farm_delivery_status',
  );
  $handler->display->display_options['style_options']['default'] = 'field_farm_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_pickup_location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_orders' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_delivery_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No deliveries were found that match the criteria above.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_farm_orders_target_id']['id'] = 'field_farm_orders_target_id';
  $handler->display->display_options['relationships']['field_farm_orders_target_id']['table'] = 'field_data_field_farm_orders';
  $handler->display->display_options['relationships']['field_farm_orders_target_id']['field'] = 'field_farm_orders_target_id';
  $handler->display->display_options['relationships']['field_farm_orders_target_id']['label'] = 'Commerce Order';
  /* Field: Bulk operations: Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Update Date/Status',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'farm_delivery::field_farm_date' => 'farm_delivery::field_farm_date',
          'farm_delivery::field_farm_delivery_status' => 'farm_delivery::field_farm_delivery_status',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::panelizer_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Log: Log ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  $handler->display->display_options['fields']['id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['id']['alter']['path'] = 'log/[id]';
  /* Field: Log: Date */
  $handler->display->display_options['fields']['field_farm_date']['id'] = 'field_farm_date';
  $handler->display->display_options['fields']['field_farm_date']['table'] = 'field_data_field_farm_date';
  $handler->display->display_options['fields']['field_farm_date']['field'] = 'field_farm_date';
  $handler->display->display_options['fields']['field_farm_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Log: Pickup Location */
  $handler->display->display_options['fields']['field_farm_pickup_location']['id'] = 'field_farm_pickup_location';
  $handler->display->display_options['fields']['field_farm_pickup_location']['table'] = 'field_data_field_farm_pickup_location';
  $handler->display->display_options['fields']['field_farm_pickup_location']['field'] = 'field_farm_pickup_location';
  $handler->display->display_options['fields']['field_farm_pickup_location']['settings'] = array(
    'link' => 1,
  );
  /* Field: Log: Address */
  $handler->display->display_options['fields']['field_farm_address']['id'] = 'field_farm_address';
  $handler->display->display_options['fields']['field_farm_address']['table'] = 'field_data_field_farm_address';
  $handler->display->display_options['fields']['field_farm_address']['field'] = 'field_farm_address';
  $handler->display->display_options['fields']['field_farm_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_farm_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Log: Orders */
  $handler->display->display_options['fields']['field_farm_orders']['id'] = 'field_farm_orders';
  $handler->display->display_options['fields']['field_farm_orders']['table'] = 'field_data_field_farm_orders';
  $handler->display->display_options['fields']['field_farm_orders']['field'] = 'field_farm_orders';
  $handler->display->display_options['fields']['field_farm_orders']['label'] = 'Order';
  $handler->display->display_options['fields']['field_farm_orders']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_farm_orders']['delta_offset'] = '0';
  /* Field: Log: Status */
  $handler->display->display_options['fields']['field_farm_delivery_status']['id'] = 'field_farm_delivery_status';
  $handler->display->display_options['fields']['field_farm_delivery_status']['table'] = 'field_data_field_farm_delivery_status';
  $handler->display->display_options['fields']['field_farm_delivery_status']['field'] = 'field_farm_delivery_status';
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'farm_delivery' => 'farm_delivery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Log: Date (field_farm_date) */
  $handler->display->display_options['filters']['field_farm_date_value']['id'] = 'field_farm_date_value';
  $handler->display->display_options['filters']['field_farm_date_value']['table'] = 'field_data_field_farm_date';
  $handler->display->display_options['filters']['field_farm_date_value']['field'] = 'field_farm_date_value';
  $handler->display->display_options['filters']['field_farm_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_farm_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['operator_id'] = 'field_farm_date_value_op';
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['operator'] = 'field_farm_date_value_op';
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['identifier'] = 'field_farm_date_value';
  $handler->display->display_options['filters']['field_farm_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
    146437786 => 0,
  );
  $handler->display->display_options['filters']['field_farm_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Log: Pickup Location (field_farm_pickup_location) */
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['id'] = 'field_farm_pickup_location_target_id';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['table'] = 'field_data_field_farm_pickup_location';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['field'] = 'field_farm_pickup_location_target_id';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['operator_id'] = 'field_farm_pickup_location_target_id_op';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['label'] = 'Pickup Location';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['operator'] = 'field_farm_pickup_location_target_id_op';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['identifier'] = 'field_farm_pickup_location_target_id';
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_farm_pickup_location_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
  );
  /* Filter criterion: Log: Orders (field_farm_orders) */
  $handler->display->display_options['filters']['field_farm_orders_target_id']['id'] = 'field_farm_orders_target_id';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['table'] = 'field_data_field_farm_orders';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['field'] = 'field_farm_orders_target_id';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_farm_orders_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['operator_id'] = 'field_farm_orders_target_id_op';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['label'] = 'Order #';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['description'] = 'Enter a specific order number.';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['operator'] = 'field_farm_orders_target_id_op';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['identifier'] = 'field_farm_orders_target_id';
  $handler->display->display_options['filters']['field_farm_orders_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
  );
  /* Filter criterion: Log: Status (field_farm_delivery_status) */
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['id'] = 'field_farm_delivery_status_value';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['table'] = 'field_data_field_farm_delivery_status';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['field'] = 'field_farm_delivery_status_value';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['value'] = array(
    'pending' => 'pending',
  );
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['operator_id'] = 'field_farm_delivery_status_value_op';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['operator'] = 'field_farm_delivery_status_value_op';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['identifier'] = 'field_farm_delivery_status_value';
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_farm_delivery_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
    146437786 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'To generate a list of deliveries based on completed orders in the system, use the <a href="/admin/farm/deliveries/generate">Generate Deliveries</a> form.

<ul>
  <li>Delivery status and date can be changed by selecting the deliveries below and clicking "Change Date/Status".</li>
  <li>Deliveries can be deleted by selecting them below and clicking "Delete".</li>
</ul>

You may narrow down the list of deliveries using the fields below. Click "Apply" to apply the filter.';
  $handler->display->display_options['path'] = 'admin/farm/deliveries/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Deliveries';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['farm_deliveries'] = $view;

  return $export;
}
