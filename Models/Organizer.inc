<?php

class Event{
  private $Id;
  public $Date;
  public $Description;
  public function __construct($id, $date, $description) {
    $this->Id = $id;
    $this->Date = $date;
    $this->Description = $description;
  }
}

class Organizer {
  const Key = 'organizer';
  public $Events;
  
  public function __construct() {
    $this->Events = array();
  }

  public function Count() {
    return count($this->Events);
  }

  private function GetId() {
    $max = 0;
    foreach($this->Events as $event) {
      if($event->Id > $max) {
        $max = $event->Id;
      }
    }
    return ++$max;
  }

  public function Add($date, $description) {
    $this->Events[] = new \Event($this->GetId(), $date, $description);
  }
}

