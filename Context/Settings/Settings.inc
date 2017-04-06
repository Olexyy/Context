<?php

namespace Context;

class Settings {
  public $DB = array(
    'host' => '127.0.0.1:3306',
    'user' => 'root',
    'password' => '',
    'database' => 'context',
    /*'host' => 'sql213.rf.gd',
    'user' => 'rfgd_19931571',
    'password' => 'vgXtFyzC',
    'database' => 'rfgd_19931571_context',*/
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