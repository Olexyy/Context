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

  public function __get($property) {
    if(substr($property, -1) == 's') {
      $className = substr_replace($property, "", -1);
      $fullClassName = "\\Context\\{$className}";
      if(class_exists($fullClassName)) {
        $model = new $fullClassName ();
        $fieldName = $this->ClassShortName.'_Id';
        $expression = "{$fieldName}={$this->Id}";
        $objects = self::$DB->Where($model, $expression);
        if(is_array($objects)) {
          $models = array();
          foreach($objects as $object) {
            $model = new $fullClassName ();
            $models[]= self::ObjectToModel($object, $model);
          }
          return $models;
        }
      }
    }
    return array();
  }

  public final static function SetUp() {
    if(self::$DB = Database::Instance()) {
      self::$Models = array();
      foreach (get_declared_classes() as $class) {
        if (is_subclass_of($class, __CLASS__)) {
          self::$Models[$class] = new $class();
          if (!self::$DB->TableExists(self::$Models[$class]->ClassShortName)) {
            self::$Models[$class]->Initialize();
          }
        }
      }
    }
  }

  public function __construct(array $params = null) {
    $this->Fields = array();
    $this->SetName();
    $this->SchemaDefinition();
    if(isset($params) && is_array($params)) {
      foreach ($this->Fields as $field) {
        if(isset($params[$field->Name])) {
          $this->{$field->Name} = $params[$field->Name];
        }
      }
    }
  }

  public function Initialize() {
    self::$DB->CreateTable($this);
  }

  protected function SetName() {
    $reflection = new \ReflectionClass($this);
    $this->ClassShortName = $reflection->getShortName();
    $this->ClassFullName = $reflection->getName();
  }

  protected function SchemaDefinition() {
    $this->AddField('Id', self::INT, self::NOT_NULL.' AUTO_INCREMENT, PRIMARY KEY(Id)');
  }

  protected function AddField($name, $type, $settings) {
    $this->Fields[] = new Field($name, $type, $settings);
  }

  public static function Create(Model $model) {
    $id = self::$DB->Create($model);
    if($id) {
      $model->Id = $id;
      return true;
    }
    return false;
  }

  public static function Read($id) {
    if(is_numeric($id)) {
      $class_name = get_called_class();
      $model = new $class_name (array( 'Id' => $id ));
      $object = self::$DB->Read($model);
      if(isset($object) && is_object($object)) {
        return self::ObjectToModel($object, $model);
      }
    }
    return false;
  }

  public static function Where ($expression) {
    $class_name = get_called_class();
    $model = new $class_name ();
    $objects = self::$DB->Where($model, $expression);
    if(is_array($objects)) {
      $models = array();
      foreach($objects as $object) {
        $model = new $class_name ();
        $models[]= self::ObjectToModel($object, $model);
      }
      return $models;
    }
    return false;
  }

  public static function All ($limit = null, $offset = null) {
    $class_name = get_called_class();
    $model = new $class_name ();
    $objects = self::$DB->All($model, $limit, $offset);
    if(is_array($objects) && !empty($objects)) {
      $models = array();
      foreach($objects as $object) {
        $model = new $class_name ();
        $models[]= self::ObjectToModel($object, $model);
      }
      return $models;
    }
    return false;
  }
  
  public static function Update (Model $model) {
    return self::$DB->Update($model);
  }

  public static function Delete ($mixed) {
    if($mixed instanceof Model) {
      return self::$DB->Delete($mixed);
    }
    if(is_numeric($mixed)) {
      $class_name = get_called_class();
      $model = new $class_name (array( 'Id' => $mixed ));
      return self::$DB->Delete($model);
    }
    return false;
  }

  private static function ObjectToModel(\stdClass $object, Model $model) {
    foreach ($model->Fields as $field) {
      if(isset($object->{$field->Name})) {
        $model->{$field->Name} = $object->{$field->Name};
      }
    }
    return $model;
  }

}