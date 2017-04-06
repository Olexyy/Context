<?php

namespace Context;

class Settings {
  const Development = 'development';
  const Production = 'production';
  const DevelopmentServerName = 'context.loc';

  public $DB = array(
    Settings::Development => array(
      'host' => '127.0.0.1:3306',
      'user' => 'root',
      'password' => '',
      'database' => 'context',
    ),
    Settings::Production => array(
      'host' => 'sql213.rf.gd',
      'user' => 'rfgd_19931571',
      'password' => 'vgXtFyzC',
      'database' => 'rfgd_19931571_context',
    ),
  );
  public $UseDB = true;
  public $Environment;

  private function __construct() {
    global $_SERVER;
    if($_SERVER['SERVER_NAME'] == Settings::DevelopmentServerName) {
      $this->Environment = Settings::Development;
    }
    else {
      $this->Environment = Settings::Production;
    }
  }

  public static function Instance() {
    global $Settings;
    if(!isset($Settings)) {
      $Settings = new Settings();
    }
    return $Settings;
  }
}