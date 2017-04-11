<?php

namespace Context;

class ArticleController extends Controller {
  // $this->Context->Model array should be set.
  public function Index() {
    $user = Utils::RegisteredAccess();
    $this->Context->Model = $user->Articles;
  }

  public function AddPage() {
    Utils::RegisteredAccess(false);
  }

  public function Add() {
    $user_id = Utils::RegisteredAccess(false);
    $params = $this->Context->Router->Post;
    if(isset($params['title']) && isset($params['description']) && $params['Add'] == 'Add') {
      $article = new Article(array('Title' => $params['title'], 'Description' => $params['description']));
      $article->User_Id = $user_id;
      if($file_id = Utils::UploadFile($this->Context->Router->Controller)) {
        $article->File_Id = $file_id;
      }
      if(Article::Create($article)) {
        Message::SetMessage('Article created.');
        Utils::Redirect('/Article/Index');
      }
    }
    Message::SetMessage('Incorrect input data.');
    Utils::Redirect('/Article/AddPage');
  }

  public function SignUp() {
    $params = $this->Context->Router->Post;
    if(Utils::ValidateReCaptcha($params['g-recaptcha-response'])) {
      if (isset($params['username']) && isset($params['password']) && $params['SignUp'] == 'SignUp') {
        $user = new User(array('Name' => $params['username'], 'Password' => Utils::EncryptPass($params['password'])));
        if($file_id = Utils::UploadFile($this->Context->Router->Controller)) {
          $user->File_Id = $file_id;
        }
        User::Create($user);
        Utils::SetUser($user->Id);
        Utils::Redirect('/Home/Index');
      }
      else {
        Message::SetMessage('Incorrect input data.');
        Utils::Redirect('/User/SignUpPage');
      }
    }
    else {
      Message::SetMessage('ReCaptcha not solved.');
      Utils::Redirect('/User/SignUpPage');
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