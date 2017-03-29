<?php

namespace Context;

class Home extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
      $this->Context->Model = '<h2>Welcome to Organizer!</h2>';
  }
  public function Add() {
    if($this->Context->Session->KeyExists(\Organizer::Key)) {
      $this->Context->Model[\Organizer::Key] = $this->Context->Session->GetWakeUp(\Organizer::Key);
    }
    else {
      $this->Context->Model[\Organizer::Key] = new \Organizer();
    }
    if(!empty($this->Context->Router->Post)) {
      $values = $this->Context->Router->Post;
      if(isset($values['name']) && isset($values['date']) && isset($values['description'])) {
        $this->Context->Model[\Organizer::Key]->Add($values['name'], $values['date'], $values['description']);
        $this->Context->Session->SetSleep(\Organizer::Key, $this->Context->Model[\Organizer::Key]);
      }
    }
  }
  public function View() {
    if($this->Context->Session->KeyExists(\Organizer::Key)) {
      $this->Context->Model[\Organizer::Key] = $this->Context->Session->GetWakeUp(\Organizer::Key);
    }
    else {
      $this->Context->Model[\Organizer::Key] = new \Organizer();
      $this->Context->Session->SetSleep(\Organizer::Key, $this->Context->Model[\Organizer::Key]);
    }
  }
}
