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
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function farm_delivery_views_api() {
  return array("version" => "3.0");
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
    "name_edit" : "0",
    "done" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
