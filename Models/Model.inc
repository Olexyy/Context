<?php
namespace Context;

class Field {
  public $Name;
  public $Type;     // INT | TEXT | NVARCHAR | ...
  public $Settings; // NULL | NOT NULL | ...
  public function __construct($name, $type, $settings) {
    $this->Name = $name;
    $this->Type = $type;
    $this->Settings = $settings;
  }
}

abstract class Model {
  protected $Name;
  protected $Fields;
  protected $DB;

  public function __construct(Database $db) {
    $this->Fields = array();
    $this->Name =  __CLASS__;
    $this->DB = $db;
  }

  public function AddField($name, $type, $settings) {
    $this->Fields[] = new Field($name, $type, $settings);
  }

  
}