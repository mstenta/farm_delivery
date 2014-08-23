FARM DELIVERY
=============

Provides features for managing farm deliveries.

This module adds a "Delivery" [Log](http://drupal.org/project/log) type,
and a form for automatically generating delivery lists based on recent orders.

Each delivery has a status (Pending, Loaded, In Transit, Delivered, Canceled),
and a default [View](http://drupal.org/project/views) is provided for managing
them.

A hook is provided for other modules to add delivery
information: hook_farm_delivery_orders() (see farm_delivery.api.php).
This is used by [Farm CSA](http://drupal.org/project/farm_csa) to add CSA
deliveries.

Optionally integrates with
[Commerce Pickup](http://drupal.org/project/commerce_pickup) for setting the
delivery location to a pickup location.

This module is part of the [Drupal Farm](http://drupal.org/project/farm)
distribution.

DEPENDENCIES
------------

This module depends on the following modules:

 * Addressfield (http://drupal.org/project/addressfield)
 * Ctools (http://drupal.org/project/ctools)
 * Commerce (http://drupal.org/project/commerce)
 * Date (http://drupal.org/project/date)
 * Entity API (http://drupal.org/project/entity)
 * Entity Reference (http://drupal.org/project/entityreference)
 * Features (http://drupal.org/project/features)
 * Geocoder (http://drupal.org/project/geocoder)
 * Geofield (http://drupal.org/project/geofield)
 * Log (http://drupal.org/project/log)
 * OpenLayers (http://drupal.org/project/openlayers)
 * Strongarm (http://drupal.org/project/strongarm)
 * Text List Formatter (http://drupal.org/project/textformatter)
 * Views (http://drupal.org/project/views)
 * Views Bulk Operations (http://drupal.org/project/views_bulk_operations)
 * Farm Admin (http://drupal.org/project/farm_admin)
 * Farm Map (http://drupal.org/project/farm_map)

INSTALLATION
------------

Install as you would normally install a contributed drupal module. See:
http://drupal.org/documentation/install/modules-themes/modules-7 for further
information.

MAINTAINERS
-----------

Current maintainers:
 * Michael Stenta (m.stenta) - https://drupal.org/user/581414

This project has been sponsored by:
 * [Farmier](http://farmier.com)
   Built on top of Drupal Farm, Farmier is a hosted platform that provides
   website and farm management tools to farmers in the cloud.
