<?php

namespace Context;

class Settings {
  public $DB = array(
    'host' => '127.0.0.1',
    'user' => 'root',
    'password' => '',
    'database' => 'context',
  );
  public $UseDB = true;

  private function __construct() { }
  
  public static function Instance() {
    global $Settings;
    if(!isset($Settings)) {
      $Settings = new Settings();
    }
    return $Settings;
  }
}