<?php

class ArticleHelper {
  public static function mdlArticle($title = '', $description ='', $edit_path = "", $delete_path = "", $edit_text = "Edit") {
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
}