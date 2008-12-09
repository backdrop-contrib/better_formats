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