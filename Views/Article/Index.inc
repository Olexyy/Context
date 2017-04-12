<?php
// Model available in $this->model variable.
$Model = $this->Model;
Html::mdlGrid();
  Html::l('Add article', '/Article/AddPage', 'mdl-navigation__link text-white');
  Html::mdlCell(8);
    Html::h2('Articles');
  Html::mdlClose();
  if(empty($Model)) {
    Html::p('You have no articles.');
  }
  foreach ($Model as $article) {
    ArticleHelper::mdlArticle($article->Title, $article->Description, '/Article/EditPage?id='.$article->Id);
  }
Html::mdlClose();