<?php
/**
 * @file
 * erpal_contract.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_contract_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_contract_node_info() {
  $items = array(
    'erpal_contract' => array(
      'name' => t('Contract'),
      'base' => 'node_content',
      'description' => t('A node to manage contracts'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
