<?php

namespace Context;

class Database {
  private $Host;
  private $Database;
  private $Password;
  private $User;
  private $UseDB;
  public $Tables;
  protected static $Instance;

  public static function Instance() {
    if(!isset(self::$Instance)) {
      self::$Instance = new Database();
    }
    return (self::$Instance->UseDB)? self::$Instance : false;
  }

  protected function __construct() {
    global $Settings;
    $DBSettings = $Settings->DB;
    $this->UseDB = $Settings->UseDB;
    $this->User = $DBSettings['user'];
    $this->Password = $DBSettings['password'];
    $this->Database = $DBSettings['database'];
    $this->Host = $DBSettings['host'];
    if($this->UseDB = $Settings->UseDB) {
      $this->GetTables();
    }
  }

  public function Query($query) {
    $connection = new \mysqli ($this->Host, $this->User, $this->Password, $this->Database);
    if($connection->connect_error) {
      return false;
    }
    $result = $connection->query($query);
    if($result === true || $result === false ) {
      return $result;
    }
    $output = array();
    if ($result->num_rows > 0) {
      while($row = $result->fetch_object()) {
        $output[] = $row;
      }
    }
    $connection->close();
    return $output;
  }

  private function GetTables() {
    $query = "SELECT * FROM information_schema.TABLES WHERE TABLE_SCHEMA = '{$this->Database}'";
    $results = $this->Query($query); // [0]->TABLE_NAME;
    $tables = array();
    foreach ($results as $result) {
      $tables[] = $result->TABLE_NAME;
    }
    $this->Tables = $tables;
  }

  public function CreateTable(Model $model) {
    $query = "SELECT COUNT(*) as count FROM information_schema.TABLES WHERE TABLE_SCHEMA = '{$this->Database}' AND TABLE_NAME = '{$model->ClassShortName}'";
    $result = $this->Query($query);
    $count = $result[0]->count;
    if ($count == 0) {
      $query = "CREATE TABLE {$model->ClassShortName} (";
      foreach($model->Fields as $field) {
        $query .= " {$field->Name} {$field->Type} {$field->Settings},";
      }
      $query = substr_replace($query, ")", -1);
      $result = $this->Query($query);
      if($result) {
        $this->GetTables();
      }
      return $result;
    }
    return false;
  }

  public function Read(Model $model, array $params = null) {
    $query = "SELECT * FROM {$model->ClassShortName} WHERE Id={$model->Id}";
    if(is_array($params) && !empty($params)) {
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
    $query = "INSERT INTO {$model->ClassShortName} {$fields} VALUES {$values}";
    if($result = $this->Query($query)) {
      $query = "SELECT MAX(Id) as MaxId FROM {$model->ClassShortName} ";
      $result = $this->Query($query);
      return $result[0]->MaxId;
    }
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
    $query = "UPDATE {$model->ClassShortName} SET  {$set} WHERE Id={$model->Id}";
    $result = $this->Query($query);
    return $result;
  }

  public function Delete(Model $model) {
    $query = "DELETE FROM {$model->ClassShortName} WHERE Id={$model->Id}";
    $result = $this->Query($query);
    return $result;
  }

  public function All(Model $model, $limit = null, $offset = null) {
    $query = "SELECT * FROM {$model->ClassShortName}";
    if(isset($limit) && is_numeric($limit)) {
      $query .= " LIMIT $limit";
      if(isset($offset) && is_numeric($offset)) {
        $query .= " OFFSET $offset";
      }
    }
    $result = $this->Query($query);
    return $result;
  }

  public function TableExists($table) {
    return in_array($table, $this->Tables);
  }

}

/*SELECT *
FROM INFORMATION_SCHEMA.COLUMNS
WHERE table_name = 'Address'*/