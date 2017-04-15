<?php
$Model = $this->Model;
Html::mdlGrid();
Html::mdlCell(12);
  Html::h2('Articles');
Html::mdlClose();
if(!$Model) {
  Html::mdlCell(12);
    Html::p('There are no articles in list.');
  Html::mdlClose();
}
else {
  ArticleHelper::mdlArticlesList();
  foreach ($Model as $article) {
    ArticleHelper::mdlArticleTeaser($article->Title, \Context\Utils::Tease($article->Description), $article->Id);
  }
  ArticleHelper::mdlArticlesListClose();
}

Html::mdlClose();