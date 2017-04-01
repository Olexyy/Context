<?php

namespace Context;

class User extends Model {
  public $Id;
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

  protected function SetName() {
    parent::SetName();
  }

  protected function __construct(Database $db) {
    parent::__construct($db);
  }
}