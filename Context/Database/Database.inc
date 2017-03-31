<?php

namespace Context;

class Database {
  public $Settings;

  public function __construct($Settings) {
    $this->Settings = $Settings;
  }

  public function Query($query){
    $connection = new \mysqli ($this->Settings['host'], $this->Settings['user'], $this->Settings['password'], $this->Settings['database']);
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

}