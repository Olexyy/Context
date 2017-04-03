<?php

namespace Context;

class User extends Model {
  public $Name;
  public $Password;
  public $Created;
  public $LastLogin;
  public $Data;
  
  protected function SchemaDefinition(){
    parent::SchemaDefinition();
    $this->AddField('Name', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Password', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Created', self::INT, self::NULL);
    $this->AddField('LastLogin', self::INT, self::NULL);
    $this->AddField('Data', self::TEXT, self::NULL);
  }

  static function EncryptPass($pass) {
    return md5($pass);
  }
}