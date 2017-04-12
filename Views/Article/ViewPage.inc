<?php
$Model = $this->Model;
Html::mdlGrid();
  Html::mdlCell(12);
    Html::h2('Article');
  Html::mdlClose();
  if(empty($Model)) {
    Html::p('Select article to view.');
  }
  ArticleHelper::mdlArticle($Model->Title, $Model->Description, '/Article/EditPage?id='.$Model->Id);
  CommentHelper::mdlCommentsList();
    foreach ($Model->Comments as $comment) {
      CommentHelper::mdlComment($comment->User->Name, $comment->Text, $Model->CurrentUserId == $comment->User_Id, "/Comment/Delete?cid={$Model->Id}&aid={$comment->Id}");
    }
  CommentHelper::mdlCommentsClose();
  if($Model->NotAuthor) {
    CommentHelper::AddForm($Model->Id, "text-white");
  }
Html::mdlClose();