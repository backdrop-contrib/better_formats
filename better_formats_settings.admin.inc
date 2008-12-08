<?php
  
function better_formats_settings_admin_form() {
  $form = array();
  
  $key = 'better_formats_settings_display';
  $form[$key] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
  );
  $form[$key]['better_formats_fieldset_title'] = array(
    '#type'  => 'textfield',
    '#default_value' => variable_get('better_formats_fieldset_title', ''),
    '#title' => t('Selection title'),
    '#description' => t('Change the format selection title. Defaults to "Input format"'),
  );
  
  
  $key = 'better_formats_settings_control';
  $form[$key] = array(
    '#type' => 'fieldset',
    '#title' => t('Control'),
  );
  $form[$key]['better_formats_per_node_type'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Control formats per node type.'),
    '#description' => t('Control formats allowed and default formats per node type. Global settings will be used until a content type admin page is saved with different values.'),
    '#default_value' => variable_get('better_formats_per_node_type', 0),
  );
  
  return system_settings_form($form);
}