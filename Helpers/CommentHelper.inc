<?php

class CommentHelper {
  public static function MdlCommentsList($class = '') {
    print "<ul class='comments-list-three mdl-list {$class}'>";
  }

  public static function MdlCommentsClose() {
    print "</ul>";
  }

  public static function mdlComment($name ='', $text ='', $delete_path = "") {
    print
      "<li class='mdl-list__item mdl-list__item--three-line'>
        <span class='mdl-list__item-primary-content'>
          <i class='material-icons mdl-list__item-avatar'>person</i>
          <span>{$name}</span>
          <span class='mdl-list__item-text-body'>
            {$text}
          </span>
        </span>
        <span class='mdl-list__item-secondary-content'>
          <a class='mdl-list__item-secondary-action' href='{$delete_path}'><i class='material-icons'>close</i></a>
        </span>
      </li>";
  }
}