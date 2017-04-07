<?php

namespace Context;

class EventController extends Controller {
  // $this->Context->Model array should be set.
  public function All() {
    if($user_id = Utils::GetUser($entity = false)) {
      $this->Context->Model = Event::Where("User_Id={$user_id}");
    }
    else {
      $this->Context->Model = false;
    }
  }
  public function AddPage() {
    if($user_id = Utils::GetUser($entity = false)) {
      $this->Context->Model = Event::Where("User_Id={$user_id}");
    }
    else {
      $this->Context->Model = false;
    }
  }
  public function Add() {
    if($user_id = Utils::GetUser($entity = false)) {
      $params = $this->Context->Router->Post;
      if(isset($params['date']) && isset($params['description']) && $params['add_button'] == 'Add event') {
        $event = new Event(array('Date' => strtotime($params['date']), 'Description' => $params['description'], 'User_Id' => $user_id,));
        Event::Create($event);
        Utils::Redirect('/Event/All');
      }
    }
  }
  public function Delete() {
    if($user_id = Utils::GetUser($entity = false)) {
      $params = $this->Context->Router->Get;
      if(isset($params['id'])) {
        Event::Delete($params['id']);
        Utils::Redirect('/Event/All');
      }
    }
  }
}
