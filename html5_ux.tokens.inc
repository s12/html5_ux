<?php

function html5_ux_token_info(){  
  return array(
    "types" => array(
      "path" => array(
        "name"        => t("Path Tokens"),
        "description" => t("Provides tokens to file system paths."),
      ),
    ),
    
    "tokens" => array(
      "path" => array(
        "public" => array(
          "name"        => t("File Public Path"),
          "description" => t("eg: @path", array("@path" =>  variable_get('file_public_path', conf_path() . '/files'))),
        ),
        
        "base" => array(
          "name"        => t("The System Base Path"),
          "description" => t("eg: @path", array("@path" =>  $GLOBALS['base_url'])),
        ),
        
        "theme" => array(
          "name"        => t("Default Theme Path"),
          "description" => t("eg: @path", array("@path" =>  drupal_get_path("theme", variable_get('theme_default', conf_path() . '/themes/jollyness')))),
        ),
      ),
    ),
  );
}

function html5_ux_tokens($type, $tokens, array $data = array(), array $options = array()){
  $replacements = array();

  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }

  $sanitize = !empty($options['sanitize']);
  
  // path tokens.
  if ($type == 'path') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case '':
          $path = variable_get('file_public_path', conf_path() . '/files');
          $replacements[$original] = $sanitize ? check_plain($path) : $path;
          break;
          
        case '':
          $path = $GLOBALS['base_url'];
          $replacements[$original] = $sanitize ? check_plain($path) : $path;
          break;
          
        case '':
          $path = drupal_get_path("theme", variable_get('theme_default', conf_path() . '/themes/jollyness'));
          $replacements[$original] = $sanitize ? check_plain($path) : $path;
          break;
      }
    }
  }
  
  return $replacements;
}