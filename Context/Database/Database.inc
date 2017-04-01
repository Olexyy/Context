<?php

namespace Context;

class Database {
  private $Host;
  private $Database;
  private $Password;
  private $User;
  private $UseDB;
  protected static $Instance;

  public static function Instance() {
    if(!isset(self::$Instance)) {
      self::$Instance = new Database();
    }
    return (self::Instance()->UseDB)? self::$Instance : false;
  }

  protected function __construct() {
    global $Settings;
    $DBSettings = $Settings->DB;
    $this->UseDB = $Settings->UseDB;
    $this->User = $DBSettings['user'];
    $this->Password = $DBSettings['password'];
    $this->Database = $DBSettings['database'];
    $this->Host = $DBSettings['host'];
  }

  public function Query($query){
    $connection = new \mysqli ($this->Host, $this->User, $this->Password, $this->Database);
    if($connection->connect_error) {
      return false;
    }
    $result = $connection->query($query);
    $output = array();
    if ($result->num_rows > 0) {
      while($row = $result->fetch_object()) {
        $output[] = $row;
      }
    }
    $connection->close();
    return $output;
  }

  public function CreateTable($type, array $fields) {
    $query = "SELECT COUNT(*) as count FROM information_schema.TABLES WHERE TABLE_SCHEMA = '{$this->Database}' AND TABLE_NAME = '{$type}'";
    $result = $this->Query($query);
    $count = $result[0]->count;
    if ($count == 0) {
      $query = "CREATE TABLE {$type} (";
      foreach($fields as $field) {
        $query .= " {$field->Name} {$field->Type} {$field->Settings},";
      }
      $query = substr_replace($query, ")", -1);
      return $this->Query($query);
    }
    return false;
  }

  public function Read($name, $id, array $params = array()) {
    $query = "SELECT * FROM {$name} WHERE Id={$id}";
    if(!empty($params)) {
      foreach ($params as $operand => $param) {
        $query .= " $operand $param";
      }
    }
    $result = $this->Query($query);
    if(count($result) == 1) {
      return $result[0];
    }
    return $result;
  }

  public function Create(Model $model) {
    $fields = $values ='(';
    foreach ($model->Fields as $field) {
      if(!empty($model->{$field->Name})) {
        $fields .= " {$field->Name},";
        if(stristr(Model::NVARCHAR, $field->Type)) {
          $values .= " '{$model->{$field->Name}}',";
        }
        else {
          $values .= " {$model->{$field->Name}},";
        }
      }
    }
    $fields = substr_replace($fields, ")", -1);
    $values = substr_replace($values, ")", -1);
    $query = "INSERT INTO {$model->Name} {$fields} VALUES {$values}";
    $result = $this->Query($query);
    return $result;
  }

  public function Update(Model $model) {
    $set = '';
    foreach ($model->Fields as $field) {
      if(!empty($model->{$field->Name})) {
        if(stristr(Model::NVARCHAR, $field->Type)) {
          $set .= " {$field->Name} = '{$model->{$field->Name}}',";
        }
        else {
          $set .= " {$field->Name} = {$model->{$field->Name}},";
        }
      }
    }
    $set = substr_replace($set, "", -1);
    $query = "UPDATE {$model->Name} SET  {$set} WHERE Id={$model->Id}";
    $result = $this->Query($query);
    return $result;
  }

  public function Delete($id, $name = null) {
    $id = (isset($name))? $id : $id->Id;
    $name = (isset($name))? $name : $id->Name;
    $query = "DELETE FROM {$name} WHERE Id={$id}";
    $result = $this->Query($query);
    return $result;
  }

}
