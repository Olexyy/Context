<?php

namespace Context;

class Event extends Model{
  public $Date;
  public $Description;

  
}

class Organizer extends Model{
  const Key = 'organizer';
  public $Events;

  public function Count() {
    return count($this->Events);
  }

  public function Add($date, $description) {
    $this->Events[] = new Event($this->GetId(), $date, $description);
  }
}

