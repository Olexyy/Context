<?php

namespace Context;

class ArticleController extends Controller {

  public function Index() {
    $this->Context->Model = Article::All();
  }

  public function All() {
    $user = Utils::RegisteredAccess();
    $this->Context->Model = $user->Articles;
  }

  public function ViewPage() {
    $user_id = Utils::GetUser(false);
    $params = $this->Context->Router->Get;
    if(isset($params['id']) && ($model = Article::Read($params['id']))) {
      $this->Context->Model = $model;
      if(!$user_id) {
        $this->Context->Model->LoggedIn = false;
      }
      else {
        $this->Context->Model->LoggedIn = true;
      }
      if($user_id != $model->User_Id) {
        $this->Context->Model->NotAuthor = true;
        $this->Context->Model->CurrentUserId = $user_id;
      }
    }
    else {
      Utils::Redirect('/Home/Index');
    }
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
      $article->Created = time();
      if(Article::Create($article)) {
        Message::SetMessage('Article created.');
        Utils::Redirect('/Article/All');
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
    if(isset($params['id']) && Utils::ValidateId($params['user'])) {
      if($article = Article::Read($params['id'])) {
        if(Article::Delete($params['id'])) {
          foreach($article->Comments as $comment) {
            Comment::Delete($comment);
          }
          Utils::Redirect('/Article/All');
        }
      }
    }
  }

}