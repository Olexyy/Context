<?php

namespace Context;

class Database {
    public $Settings;
    public $Connection;

    public function __construct(){
        $database_settings = array();
        require_once CONTEXT_ROOT.'/Context/Settings/Database.inc';
        $this->Settings = $database_settings;
    }
    public function Connect(&$MessageBoard){
        $Connection = $this->Connection = mysqli_connect ($this->Settings['host'], $this->Settings['user'], $this->Settings['password'], $this->Settings['database']);
        if(mysqli_connect_errno()){
            $MessageBoard['error'][] = 'Database:' . mysqli_connect_error();
        }
        $result = mysqli_query($Connection, "SELECT* FROM table");
        return $Connection;
    }
    public function Query($Query){
       mysqli_query($this->Connection, $Query);
    }
}