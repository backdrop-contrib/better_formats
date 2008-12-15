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
        option.show();
      } else {
        option.removeAttr('selected').hide();
      }
    }
  });
}

$(document).ready(function() {
  // collapsing the input format setting after the weight columns have been hidden
  $('.input-format-settings > legend > a').click();
  // 
  $('input.bf-allowed-formats').click(function() {
    better_formats_toggle_formats($(this));
  }).each(function() {
    better_formats_toggle_formats($(this));
  });
});