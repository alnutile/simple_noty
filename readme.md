##Simple Library/Module to setup noty and make it so you can use it in your javascript.

1. Sets a drupal setting as Drupal.settings.simple_noty.active

2. Your javascript can check in your javascript

```
Drupal.settings.simple_noty.active
``` 
to see if you can use it.

3. You can then call to 
```
var n = noty({text: 'noty - a jquery notification library!'});
```
as needed.

There is a method
```
Drupal.simple_noty.renderNotyCustom(message, type)
```
if you want to call to it in your javascript.



##Install
Just run 
```
drush nl 
```
and it will download and instsall the libraries to the libraries folder
