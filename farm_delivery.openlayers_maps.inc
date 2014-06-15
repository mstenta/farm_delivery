<?php
/**
 * @file
 * farm_delivery.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function farm_delivery_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'farm_map_deliveries';
  $openlayers_maps->title = 'Farm Deliveries Map';
  $openlayers_maps->description = 'Map of farm deliveries';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'profiles/root/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'profiles/root/modules/contrib/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-95.99999999999764, 40.00000000000016',
        'zoom' => '4',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_geofield' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'sortBaseLayer' => '0',
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
        'div' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'farm_deliveries_openlayers_1' => 'farm_deliveries_openlayers_1',
        ),
        'panMapIfOutOfView' => 1,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'farm_deliveries_openlayers_1' => 'farm_deliveries_openlayers_1',
          'google_satellite' => 0,
          'google_hybrid' => 0,
          'google_normal' => 0,
          'google_physical' => 0,
        ),
        'point_zoom_level' => '16',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'google_hybrid',
    'layers' => array(
      'google_satellite' => 'google_satellite',
      'google_hybrid' => 'google_hybrid',
      'google_normal' => 'google_normal',
      'google_physical' => 'google_physical',
      'farm_deliveries_openlayers_1' => 'farm_deliveries_openlayers_1',
    ),
    'layer_weight' => array(
      'farm_deliveries_openlayers_1' => '0',
      'farm_areas_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'farm_areas_openlayers_1' => '0',
      'farm_deliveries_openlayers_1' => 'farm_blue',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'farm_areas_openlayers_1' => '0',
      'farm_deliveries_openlayers_1' => 'farm_orange',
    ),
    'layer_styles_temporary' => array(
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'farm_areas_openlayers_1' => '0',
      'farm_deliveries_openlayers_1' => 'farm_green',
    ),
    'layer_activated' => array(
      'farm_deliveries_openlayers_1' => 'farm_deliveries_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'farm_areas_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'farm_deliveries_openlayers_1' => 0,
      'farm_areas_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:3857',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'farm_blue',
      'select' => 'farm_orange',
      'temporary' => 'farm_green',
    ),
  );
  $export['farm_map_deliveries'] = $openlayers_maps;

  return $export;
}
