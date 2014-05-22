<?php
/**
 * @file
 * farm_delivery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_delivery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_log_type().
 */
function farm_delivery_default_log_type() {
  $items = array();
  $items['farm_delivery'] = entity_import('log_type', '{
    "type" : "farm_delivery",
    "label" : "Delivery",
    "weight" : 0,
    "name_pattern" : "Delivery [log:id]",
    "rdf_mapping" : []
  }');
  return $items;
}
