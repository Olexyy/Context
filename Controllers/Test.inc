<?php

namespace Context;

class Test extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
    echo "Beginning base crud for model 'User'...";
    $user = new User(array('Name' => 'Test', 'Password' => '12345', 'Created' => time()));
    $result = User::Create($user);
    if($result == true) {
      echo "Created entity of 'User'...";
    }
    $user = User::Read(1);
    $user->Name = 'popkin';
    $result = User::Update($user);
    if($result == true) {
      echo "Updated entity of 'User'...";
    }
    $result = User::Delete(1);
    if($result == true) {
      echo "Deleted entity of 'User'...";
    }
  }
}
