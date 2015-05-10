(function($){
  $(document).ready(function(){
    $('body.admin-menu [action*="/admin"] .form-actions [type=submit], body.admin-menu [action*="/edit"] .form-actions [type=submit], body.admin-menu [action*="/node/add"] .form-actions [type=submit], body.admin-menu #branding .tabs > li > a, body.admin-menu #page .tabs > li > a, body.admin-menu .region-content > .tabs > ul > li > a').each(function(i,o){

      $(o).clone().appendTo('.whitefox-menu').click(function(e){
        $(o).click();
      });
      
      $(o).hide();
      
      $("#views-display-menu-tabs.tabs.secondary > li > a").show();
      
      $("#views-display-menu-tabs.tabs.secondary").css({
        "left":"auto",
        "position":"relative",
      });
    });    
  });
})(jQuery);