<?php
/**
 * @file
 * erpal_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function erpal_profile_default_profile2_type() {
  $items = array();
  $items['contract'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "contract",
    "label" : "User contract",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 }
  }');
  return $items;
}
