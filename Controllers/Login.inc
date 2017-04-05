<?php

namespace Context;

class LoginController extends Controller{
  public function Login() {
    $params = $this->Context->Router->Post;
    if(isset($params['login']) && isset($params['password']) && $params['Login'] == 'Login') {
      $users = User::Find(array(' ' => "Name='{$params['login']}'"));
      if(!empty($users)) {
        $user = $users[0];
        if(md5($params['password']) == $user->Password) {
          Utils::SetUser($user->Id);
          header('location:/Index/Home');
        }
      }
    }
  }
  public function Logout() {
    
  }
}