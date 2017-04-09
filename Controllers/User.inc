<?php

namespace Context;

class UserController extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
    $this->Context->Model = User::All();
  }

  public function Login() {
    $params = $this->Context->Router->Post;
    if(isset($params['login']) && isset($params['password']) && $params['Login'] == 'Login') {
      $users = User::Where("Name='{$params['login']}'");
      if(!empty($users)) {
        $user = $users[0];
        if(md5($params['password']) == $user->Password) {
          Utils::SetUser($user->Id);
          Utils::Redirect('/Home/Index');
        }
      }
    }
  }

  public function SignUpPage() {

  }

  public function SignUp() {
    $params = $this->Context->Router->Post;
    if(Utils::ValidateReCaptcha($params['g-recaptcha-response'])) {
      if (isset($params['username']) && isset($params['password']) && $params['SignUp'] == 'SignUp') {
        $user = new User(array('Name' => $params['username'], 'Password' => Utils::EncryptPass($params['password'])));
        User::Create($user);
        Utils::SetUser($user->Id);
        Utils::Redirect('/Home/Index');
      }
    }
    
  }

  public function Logout() {
    $params = $this->Context->Router->Post;
    if(isset($params['user']) && $params['Logout'] == 'Logout') {
      Utils::UnsetUser($params['user']);
      Utils::Redirect('/Home/Index');
    }
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