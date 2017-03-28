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
  public $Events;
}

