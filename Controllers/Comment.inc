<?php

namespace Context;

class CommentController extends Controller {

  public function Add() {
    $user_id = Utils::RegisteredAccess(false);
    $params = $this->Context->Router->Post;
    if(isset($params['id']) && isset($params['text']) && $params['Add'] == 'Add') {
      $comment = new Comment(array('Text' => $params['text']));
      $comment->User_Id = $user_id;
      $comment->Article_Id = $params['id'];
      $comment->Created = time();
      if(Comment::Create($comment)) {
        Message::SetMessage('Comment added.');
        Utils::Redirect('/Article/ViewPage?id='.$params['id']);
      }
    }
    Message::SetMessage('Incorrect input data.');
    Utils::Redirect('/Home/Index');
  }

  public function Delete() {
    $user_id = Utils::RegisteredAccess(false);
    $params = $this->Context->Router->Get;
    if(isset($params['aid']) && isset($params['cid']) && ($comment = Comment::Read($params['aid']))) {
      if($comment->User_Id == $user_id) {
        if(Comment::Delete($comment)) {
          Message::SetMessage('Comment deleted.');
          Utils::Redirect('/Article/ViewPage?id='.$params['cid']);
        }
      }
    }
    Message::SetMessage('Wrong action.');
    Utils::Redirect('/Home/Index');
  }
}