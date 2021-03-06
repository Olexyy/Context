<?php
$Model = $this->Model;
Html::mdlGrid();
  Html::mdlCell(2);
    Html::l('All articles', '/Article/Index', 'mdl-navigation__link text-white');
    echo '<br />';
    if(\Context\Utils::IsLoggedIn()) {
      Html::l('My articles', '/Article/All', 'mdl-navigation__link text-white');
    }
  Html::mdlClose();
  Html::mdlCell(8);
    Html::h2('Article');
  Html::mdlClose();
  if(empty($Model)) {
    Html::p('Select article to view.');
  }
  if($Model->NotAuthor) {
    ArticleHelper::mdlArticle($Model->Title, $Model->Description);
  }
  else {
    ArticleHelper::mdlArticleEdit($Model->Title, $Model->Description, '/Article/EditPage?id='.$Model->Id, '/Article/Delete?id='.$Model->Id);
  }
  CommentHelper::mdlCommentsList();
  foreach ($Model->Comments as $comment) {
    CommentHelper::mdlComment($comment->User->Name, $comment->Text, $Model->CurrentUserId == $comment->User_Id, "/Comment/Delete?cid={$Model->Id}&aid={$comment->Id}");
  }
  CommentHelper::mdlCommentsClose();
  if ($Model->LoggedIn && $Model->NotAuthor) {
    CommentHelper::AddForm($Model->Id, "text-white");
  }
Html::mdlClose();