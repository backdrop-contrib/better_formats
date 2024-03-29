
/**
 * @file
 * Enhances the default format selection on content type edit forms.
 *
 * Fixes bug that shows weight field when drag and drop is enabled
 * because the field is hidden by default.
 * Also hides formats that are not available per the Allowed checkboxes.
 *
 * @todo remove this file. This file is only referenced in commented out code.
 */

/**
 * Initialize Better Formats settings and defaults.
 */
function betterFormatsInit() {
  // Set default settings check for use of global allowed formats.
  Backdrop.settings.betterFormats = {"numChecked" : $('input.bf-allowed-formats:checked').length};

  // Collapsing the input format setting after the weight columns have been hidden.
  $('.input-format-settings > legend > a').click();

  // Add hide/show events for allowed formats.
  var formatBoxes = $('input.bf-allowed-formats');
  formatBoxes.click(function() {
    betterFormatsToggleFormats($(this));
  });
  if (Backdrop.settings.betterFormats.numChecked > 0) {
    formatBoxes.each(function() {
      betterFormatsToggleFormats($(this), true);
    });
  }
}

/**
 * Toggle format display in dropdowns in sync with allowed checkboxes.
 *
 * @param el
 *  DOM element of event.
 * @param init
 *  Boolean value to determine first toggle.
 */
function betterFormatsToggleFormats(el, init) {
  // Hide all formats except site default when the first box is checked.
  if (Backdrop.settings.betterFormats.numChecked === 0) {
    $('select.bf-default-formats option[value != "0"][value != "' + el.val() + '"]').removeAttr('selected').hide();
  }

  $('select.bf-default-formats option[value = "' + el.val() + '"]').each(function() {
    var option = $(this);
      if (el.attr('checked')) {
        option.show();
      }
      else {
        option.removeAttr('selected').hide();
      }
  });

  // Do not modify count on intial run.
  if (!init) {
    if (el.attr('checked')) {
      Backdrop.settings.betterFormats.numChecked += 1;
    }
    else if (Backdrop.settings.betterFormats.numChecked > 0) {
      // Keep num_checked from going below zero.
      Backdrop.settings.betterFormats.numChecked -= 1;
    }
  }

  // Show all globally allowed formats if no boxes are checked.
  if (Backdrop.settings.betterFormats.numChecked === 0) {
    // Show global formats available to roles because no format allowed boxes are checked.
    $('select.bf-default-formats option').show();
  }
}


$(document).ready(betterFormatsInit);
