<?php

namespace Context;

class Database {
  private $Host;
  private $Database;
  private $Password;
  private $User;

  public function __construct($Settings) {
    $this->User = $Settings['user'];
    $this->Password = $Settings['password'];
    $this->Database = $Settings['database'];
    $this->Host = $Settings['host'];
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

  public function Read($type, $id) {
    $query = "SELECT * FROM {$type} WHERE id={$id}";
    return $this->Query($query);
  }

  public function CreateTable($type, array $fields) {
    $query = "SELECT COUNT(*) as count FROM information_schema.TABLES WHERE TABLE_SCHEMA = '{$this->Database}' AND TABLE_NAME = '{$type}'";
    $result = $this->Query($query);
    $count = $result[0]->count;
    if ($count == 0) {
      $query = "CREATE TABLE {$type} (id INT NOT NULL, PRIMARY KEY(id),";
      foreach($fields as $field) {
        $query .= "{$field->Name} {$field->Type} {$field->Setting},";
      }
      $query .= ")";
      return $this->Query($query);
    }
    return false;
  }

}

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