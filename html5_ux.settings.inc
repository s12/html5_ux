<?php
function html5_ux_admin_settings_form(){
  $pre = "html5_ux_";

  $var = array(
    $pre."modernizr.js" => TRUE,
    $pre."migrate.js" => TRUE,
    $pre."fix.js" => TRUE,
    $pre."fix.css" => TRUE,
  );

  foreach($var as $name => $value){
    $file = str_replace($pre, "", $name);

    $form[$name] = array(
      "#type" => "checkbox",
      "#title" => t("Load: @file", array("@file" => $file)),
      "#default_value" => variable_get($name, $value),
    );
  }

  return system_settings_form($form);
}
