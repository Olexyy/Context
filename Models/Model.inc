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

  public $Name;
  public $Fields;
  protected $DB;

  protected function __construct(Database $db) {
    $this->Fields = array();
    $this->DB = $db;
    $this->SetName();
    $this->SchemaDefinition();
    $this->DB->CreateTable($this->Name, $this->Fields);
  }

  protected function SetName() {
    $reflection = new \ReflectionClass($this);
    $this->Name = $reflection->getShortName();
  }

  protected function SchemaDefinition() {
    $this->AddField('Id', self::INT, self::NOT_NULL . ', PRIMARY KEY(Id)');
  }

  public function AddField($name, $type, $settings) {
    $this->Fields[] = new Field($name, $type, $settings);
  }

  public function Find($id, array $params = array()) {
    return $this->DB->Find($this->name, $id, $params);
  }
  
}