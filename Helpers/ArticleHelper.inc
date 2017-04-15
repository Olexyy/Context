<?php

class ArticleHelper {

  public static function mdlArticlesList($class = '') {
    print "<ul class='comments-list-three mdl-list {$class}'>";
  }

  public static function mdlArticlesListClose() {
    print "</ul>";
  }

  public static function mdlArticleTeaser($title = '', $description ='', $id = '') {
    print
      "<li class='mdl-list__item mdl-list__item--three-line'>
        <span class='mdl-list__item-primary-content'>
          <span>{$title}</span>
          <span class='mdl-list__item-text-body'>
            {$description}
          </span>
        </span>
        <a class='mdl-list__item-secondary-action' href='/Article/ViewPage?id={$id}'><i class='material-icons'>forward</i></a>
      </li>";
  }

  public static function mdlArticle($title = '', $description ='') {
    print
      "<div class='article-card-wide mdl-card mdl-shadow--2dp'>
        <div class='mdl-card__title'>
          <h2 class='mdl-card__title-text'>{$title}</h2>
        </div>
        <div class='mdl-card__supporting-text'> {$description} </div>
      </div>";
  }

  public static function mdlArticleEdit($title = '', $description ='', $edit_path = "", $delete_path = "", $edit_text = "Edit") {
    print
      "<div class='article-card-wide mdl-card mdl-shadow--2dp'>
        <div class='mdl-card__title'>
          <h2 class='mdl-card__title-text'>{$title}</h2>
        </div>
        <div class='mdl-card__supporting-text'> {$description} </div>
        <div class='mdl-card__actions mdl-card--border'>
          <a href='{$edit_path}' class='mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect'> {$edit_text}</a>
        </div>
        <div class='mdl-card__menu'>
          <a href='{$delete_path}'>
            <button class='mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect'>
              <i class='material-icons'>close</i>
            </button>
          </a>
        </div>
      </div>";
  }

  public static function DetailsLink($id, $class ='') {
    print "<a class='mdl-navigation__link text-white {$class}' href='/Article/ViewPage?id={$id}'> Details </a>";
  }
}