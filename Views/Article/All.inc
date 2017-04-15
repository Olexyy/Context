<?php
$Model = $this->Model;
Html::mdlGrid();
  Html::mdlCell(2);
    Html::l('Add article', '/Article/AddPage', 'mdl-navigation__link text-white');
  Html::mdlClose();
  Html::mdlCell(8);
    Html::h2('Articles');
  Html::mdlClose();
  if(empty($Model)) {
    Html::mdlCell(12);
      Html::p('You have no articles.');
    Html::mdlClose();
  }
  Html::mdlCell(12);
  foreach ($Model as $article) {

    ArticleHelper::mdlArticleEdit($article->Title, $article->Description, '/Article/Delete?id='.$article->Id);
    ArticleHelper::DetailsLink($article->Id);
  }
  Html::mdlClose();
Html::mdlClose();