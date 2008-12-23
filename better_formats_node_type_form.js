// $Id$

/**
 * @file
 * Enhances the default format selection on content type edit forms.
 *
 * Fixes bug that shows weight field when drag and drop is enabled 
 * because the field is hidden by default.
 * Also hides formats that are not available per the Allowed checkboxes.
 */
 
function better_formats_toggle_formats(el) {
  $('select.bf-default-formats option').each(function() {
    var option = $(this);
    if (option.val() == el.val()) {
      if (el.attr('checked')) {
        // hide all formats except site default when the first box is checked
        if (Drupal.settings.better_formats.num_checked === 0) {
          $('select.bf-default-formats option[value != "0"]').hide();
        }
        Drupal.settings.better_formats.num_checked += 1;
        option.show();
      } else {
        option.removeAttr('selected').hide();
        // keep num_checked from going below zero
        if (Drupal.settings.better_formats.num_checked > 0) {
          Drupal.settings.better_formats.num_checked -= 1;
        }
        // show all globally allowed formats if no boxes are checked
        if (Drupal.settings.better_formats.num_checked === 0) {
          // show global formats available to roles 
          // because no format allowed boxes are checked
          $('select.bf-default-formats option').show();
        }
      }
    }
  });
}

function better_formats_show_global_formats() {
  $('select.bf-default-formats option').show();
}

$(document).ready(function() {
  // set default settings check for use of global allowed formats
  Drupal.settings.better_formats = {"num_checked" : 0};
  // collapsing the input format setting after the weight columns have been hidden
  $('.input-format-settings > legend > a').click();
  // add hide/show events for allowed formats
  $('input.bf-allowed-formats').click(function() {
    better_formats_toggle_formats($(this));
  }).each(function() {
    better_formats_toggle_formats($(this));
  });
});