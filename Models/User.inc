<?php

namespace Context;

class User extends Model {
  public $Name;
  public $Password;
  public $Created;
  public $LastLogin;
  public $Data;
  public $File_Id;
  
  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Name', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Password', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Created', self::INT, self::NULL);
    $this->AddField('LastLogin', self::INT, self::NULL);
    $this->AddField('Data', self::TEXT, self::NULL);
    $this->AddField('File_Id', self::INT, self::NULL);
  }

  protected function Seed() {
    parent::Seed();
    $user = new User(array('Name' => 'admin', 'Password' => Utils::EncryptPass('admin'), 'Created' => time()));
    User::Create($user);
  }
}