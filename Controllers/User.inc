<?php

namespace Context;

class UserController extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
    $this->Context->Model = User::All();
  }
  
}