<?php

namespace Context;

class Test extends Controller {
  // $this->Context->Model can be set.
  public function Index() {
    echo "Beginning base crud for model 'User'...";
    $user = new User(array('Name' => 'Testovich', 'Password' => User::EncryptPass('12345'), 'Created' => time()));
    $result = User::Create($user);
    if($result == true) {
      echo "Created entity of 'User'...";
    }
    $user = User::Read($user->Id);
    if($user) {
      echo "Read entity of 'User'...";
    }
    $user->Name = 'Changed';
    $result = User::Update($user);
    if($result == true) {
      echo "Updated entity of 'User'...";
    }
    $result = User::Delete($user);
    if($result == true) {
      echo "Deleted entity of 'User'...";
    }
  }
}
