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
  /*
  $form['control']['better_formats_per_node_type'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Control formats per node type'),
    '#description' => t('Control formats allowed and default formats per node type. Global settings will be used until a content type admin page is saved.'),
    '#default_value' => config_get('better_formats.settings', 'better_formats_per_node_type'),
  );
  */
  $form['actions']['#type']  = 'actions';
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save configuration')
    );

    return $form;
}


function better_formats_admin_settings_form_submit($form, &$form_state)
{
    foreach ($form_state['values'] as $key => $value) {
        if (is_array($value) && isset($form_state['values']['array_filter'])) {
            $value = array_keys(array_filter($value));
        }
        config_set('better_formats.settings', $key, $value);
    }

    backdrop_set_message(t('The configuration options have been saved.'));
}
