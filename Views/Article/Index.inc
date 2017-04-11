<?php
// Model available in $this->model variable.
$Model = $this->Model;
Html::mdlGrid();
  Html::l('Add article', '/Article/AddPage', 'mdl-navigation__link text-white');
  Html::mdlCell(8);
    Html::h2('Articles');
  Html::mdlClose();
  Html::mdlCell(4);Html::mdlClose();
  if(empty($Model)) {
    Html::p('You have no articles.');
  }
  foreach ($Model as $article) {
    Html::h3($article->Title);
    Html::p($article->Description);
  }
Html::mdlClose();