Better formats is a module to add more flexibility to Drupal's core input format system.
Features

    * Set the default format per role.
    * Set the default format per content type.
    * Control allowed formats per content type.
    * Hide format tips.
    * Hide format selection, forcing the default to be used.
    * Expand the selection fieldset by default.
    * Disable the expand/collapse of the selection fieldset.
    * Set selection fieldset title.
    * Set default formats for nodes and comments separately.
    * Works with CCK textareas.
    * and more.
    
-------------------------------------------------------------------

Installation:
1. Copy the module folder to your server.
2. Enable the module via the modules page.

Use:
1. Go to user permissions (/admin/user/permissions) and set your permissions.
2. Navigate to Site Configuration > Input formats (/admin/settings/filters)
3. There you will find 2 tabs where you can change your settings. 
    Defaults (/admin/settings/filters/defauts) 
    Settings (/admin/settings/filters/settings)
4. If you enable the "Control formats per node type" option. Go to your content
   type admin page to set those settings (example /admin/content/node-type/page).
   The settings are under the Input format settings fieldset.
   

The module is designed to always fall back to default settings when needed. 
This means that when you enable the module before you change any settings, 
it will use your current Drupal settings. Also when you enable conrol per node 
type it will use your global settings until you save the content type with new 
settings.