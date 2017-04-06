<?php

namespace Context;

class UserController extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
    $this->Context->Model = User::All();
  }

  public function Delete() {
    $params = $this->Context->Router->Get;
    if(isset($params['user']) && Utils::ValidateId($params['user'])) {
      if(User::Delete($params['user'])) {
        Utils::Redirect('/User/Index');
      }
    }
  }
}