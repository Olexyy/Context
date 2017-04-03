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

  const INT = 'INT';
  const TEXT = 'TEXT';
  const NVARCHAR = 'NVARCHAR(255)';
  const NULL = 'NULL';
  const NOT_NULL = 'NOT NULL';

  protected static $Models;
  protected static $DB;

  public $Id;
  public $ClassFullName;
  public $ClassShortName;
  public $Fields;

  public final static function SetUp() {
    self::$DB = Database::Instance();
    self::$Models = array();
    foreach(get_declared_classes() as $class){
      if(is_subclass_of($class, __CLASS__)) {
        self::$Models[$class] = new $class();
        if(!in_array($class, self::$DB->Instance()->Tables)) {
          self::$Models[$class]->Initialize();
        }
      }
    }
  }

  public function __construct() {
    $this->Fields = array();
    $this->SetName();
    $this->SchemaDefinition();
  }

  public function Initialize() {
    self::$DB->CreateTable($this->ClassShortName, $this->Fields);
  }

  public function Instance() {
    return new $this->ClassFullName();
  }

  protected function SetName() {
    $reflection = new \ReflectionClass($this);
    $this->ClassShortName = $reflection->getShortName();
    $this->ClassFullName = $reflection->getName();
  }

  protected function SchemaDefinition() {
    $this->AddField('Id', self::INT, self::NOT_NULL . ', PRIMARY KEY(Id)');
  }

  protected function AddField($name, $type, $settings) {
    $this->Fields[] = new Field($name, $type, $settings);
  }

  public function Find($id, array $params = array()) {
    return self::$DB->Read($this->ClassShortName, $id, $params);
  }

}