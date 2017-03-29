<?php

class Event{
  public $Date;
  public $Description;
  public function __construct($date, $description) {
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
  public function Add($date, $description) {
    $this->Events[] = new \Event($date, $description);
  }
}

