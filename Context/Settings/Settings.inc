<?php

namespace Context;

class Settings {
  const Development = 'development';
  const Production = 'production';
  const DevelopmentServerName = 'context.loc';

  public $ReCaptchaBaseUrl = 'https://www.google.com/recaptcha/api/siteverify';
  public $ReCaptchaBaseKeyPrivate = '6Ld0zRwUAAAAAMRCdz8rOZqbKuj_pxyqRh54cO1a';
  public $ReCaptchaBaseKeyPublic = '6Ld0zRwUAAAAANbA2PDxxO0QVaF39xjxf02yVq-5';
  public $DB = array(
    Settings::Development => array(
      'host' => '127.0.0.1:3306',
      'user' => 'root',
      'password' => '',
      'database' => 'context',
    ),
    Settings::Production => array(
      'host' => 'fdb17.freehostingeu.com',
      'user' => '2339325_context',
      'password' => '1qaz2wsx!QAZ@WSX',
      'database' => '2339325_context',
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