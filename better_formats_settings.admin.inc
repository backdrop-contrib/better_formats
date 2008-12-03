<?php
  
function better_formats_settings_admin_form() {
  $form = array();
  
  $key = 'better_formats_settings_display';
  $form[$key] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
  );
  
  $form[$key]['better_formats_hide_format_selection'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('better_formats_hide_format_selection', 0),
    '#title' => t('Hide format selection'),
    '#description' => t('Hides the format selection fieldset leaving only the default format tips.'),
  );
  $form[$key]['better_formats_hide_format_tips'] = array(
    '#type'  => 'checkbox',
    '#default_value' => variable_get('better_formats_hide_format_tips', 0),
    '#title' => t('Hide format tips'),
    '#description' => t('Hides the format tips leaving only the format selection or nothing if the "Hide format selection" option is checked.'),
  );
  $form[$key]['better_formats_default_expanded'] = array(
    '#type'  => 'checkbox',
    '#default_value' => variable_get('better_formats_default_expanded', 0),
    '#title' => t('Expand fieldset by default'),
    '#description' => t('Expands the Input formats fieldset by default.'),
  );
  $form[$key]['better_formats_noncollapse'] = array(
    '#type'  => 'checkbox',
    '#default_value' => variable_get('better_formats_noncollapse', 0),
    '#title' => t('Disable fieldset collapse'),
    '#description' => t('Removes the ability for the user to collapse the fieldset.'),
  );
  $form[$key]['better_formats_fieldset_title'] = array(
    '#type'  => 'textfield',
    '#default_value' => variable_get('better_formats_fieldset_title', ''),
    '#title' => t('Selection title'),
    '#description' => t('Change the format selection fieldset title. Defaults to "Input format"'),
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