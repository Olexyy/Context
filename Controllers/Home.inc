<?php

namespace Context;

class Home extends Controller {
    // $this->Context->Model should be set.
    public function Index() {
        $this->Context->Model = '<h2>Welcome to Organizer!</h2>';
    }
    public function Add() {
      if(!empty($this->Context->Router->Post)) {
        $values = $this->Context->Router->Post;
        if(isset($values['serialized'])) {
          $this->Context->Model = unserialize(base64_decode($values['serialized']));
        }
        if(isset($values['date']) && isset($values['description'])) {
          $this->Context->Model->Events[]= new \Event($values['date'], $values['description']);
        }
      }
      else {
        $this->Context->Model = new \Organizer();
      }
      $this->Context->Model = base64_encode(serialize($this->Context->Model));
    }
}
