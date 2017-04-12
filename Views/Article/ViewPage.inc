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
Html::mdlClose();