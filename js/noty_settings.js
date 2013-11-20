(function($) {
    Drupal.simple_noty = {};
    Drupal.simple_noty.renderNotyCustom = function(message, type, context) {
        var n = noty({text: message, type: type});
    };

})(jQuery);