Better Formats
==============

Better Formats is a port of a Drupal module to add more flexibility to the core input format system.  It comes with different content permissions to assign to roles of users, and an admin page for configuring fields.

Installation
------------

Install this module using the official Backdrop CMS instructions at <https://backdropcms.org/guide/modules>.

1. Display options: When BF is enabled you will have permissions at
   `admin/people/permissions` to control per role display of:
   1. format tips
   2. format tips link
   3. format selection for [entity]

   #3 is actually several permissions. There is one for each entity in your site.
2. Simple field level default format.
   This allows you set a field level default format using the standard "Default Value"
   setting of a field. This is only possibly normally if you enter something in the
   text field for the field api to save the format too. BF gives you the ability
   to set the format WITHOUT having to set a value in the field.

   1. At `admin/config/content/formats/settings` enable "Use field default" option.
   2. Create a text type of field on one of your content types.
   3. Ensure you set the "Text processing" option to "Filtered text".
   4. Save the field.
   5. Now go back and edit the field you just saved. This is required because of
      how the field default value option works.
   6. You will now see a "Text format" dropdown below your field in the
      "Default Value" area. Set the default format in the dropdown.
   7. Save the field. Default will now be used on all new content forms for that field.
3. FAPI integration.
   You are able to trigger Better Formats programatically on custom forms built
   with the form API:

```php
      function my_example_form($form, &$form_state) {
         $form = array();
         $form['example_text_field'] = array(
           '#title' => 'Contribution message ',
           '#type' => 'text_format',
           '#format' => 'teaser_text',
         );
         $form['example_text_field']['better_formats'] = array(
           '#show_selection' => FALSE,
           '#show_tips' => FALSE,
           '#show_tips_link' => FALSE,
         );
         return $form;
      }
```

Permissions
-----------

This module installs permissions for your roles to use.

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.

Maintainers
-----------

- [herbdool](https://github.com/herbdool)

Credits
-------

Ported to Backdrop by [biolithic](https://github.com/biolithic).

This module is based on the Better Formats module for Drupal, originally written and maintained by a large number of contributors, including:

- [dragonwize](https://www.drupal.org/u/dragonwize)
