<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup farm_delivery_hooks Farm Delivery hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend
 * farm_delivery.
 */

/**
 * Add to the list of orders that deliveries will be generated for.
 *
 * When deliveries are being automatically generated, this hook is called
 * to allow modules to add orders that should be delivered.
 *
 * The Farm Delivery module implements this hook to add orders that match
 * the date range selected in the Delivery Generation form, which contain
 * normal Commerce products (product type == "product").
 *
 * If another kind of product needs to be delivered, or if orders outside
 * the given date range need to be included, a new hook should be implemented
 * (probably by the module providing the type), which adds those orders.
 *
 * Two examples:
 *   farm_delivery_farm_delivery_orders() (in farm_delivery.module)
 *   farm_csa_farm_delivery_orders() (in farm_csa.module)
 *
 * @return
 *   An array of order ids, with the order id as the array item keys (so that
 *   they can be merged in without duplicating).
 */
function hook_farm_delivery_orders() {
  
  // Return orders 1, 2, 5, and 20.
  return array(
    '1' => '1',
    '2' => '2',
    '5' => '5',
    '20' => '20',
  );
}
