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

  public function EditPage() {
    Utils::RegisteredAccess(false);
    $params = $this->Context->Router->Get;
    if(isset($params['id']) && ($model = Article::Read($params['id']))) {
      $this->Context->Model = $model;
    }
    else {
      Utils::Redirect('/Home/Index');
    }
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

  public function Edit() {
    Utils::RegisteredAccess(false);
    $params = $this->Context->Router->Post;
    if(isset($params['id']) && isset($params['title']) && isset($params['description']) && $params['Edit'] == 'Edit') {
      if($article = Article::Read($params['id'])) {
        if($file_id = Utils::UploadFile($this->Context->Router->Controller)) {
          $article->File_Id = $file_id;
        }
        $article->Title = $params['title'];
        $article->Description = $params['description'];
        if(Article::Update($article)) {
          Message::SetMessage('Article updated.');
          Utils::Redirect('/Article/Index');
        }
      }
    }
    Message::SetMessage('Incorrect input data.');
    Utils::Redirect('/Article/EditPage?id='.$params['id']);
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