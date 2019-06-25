<?php

/**
 * @file
 * Contains FAPI and theme functions for the format settings form.
 */

/**
 * FAPI form builder for admin/settings/filters/settings page.
 *
 * @see better_formats_menu()
 */
function better_formats_admin_settings_form($form, &$form_state) {
  $form = array();

  $form['#config'] = 'better_formats.settings';
  $form['control'] = array(
    '#type' => 'fieldset',
    '#title' => t('Control'),
  );
  $form['control']['better_formats_per_field_core'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Use field default'),
    '#description' => t('Use the core field module default value to set the default format. This will force the default format even when the default field value is empty. To set a default format you must re-edit a text field after saving it with the "Filtered text" option turned on.'),
    '#default_value' => config_get('better_formats.settings', 'better_formats_per_field_core'),
  );

  return system_settings_form($form);
}
