<?php

class CommentHelper {

  public static function mdlCommentsList($class = '') {
    print "<ul class='comments-list-three mdl-list {$class}'>";
  }

  public static function mdlCommentsClose() {
    print "</ul>";
  }

  public static function mdlComment($name ='', $text ='', $can_delete, $delete_path = "") {
    $delete_link = '';
    if($can_delete) {
      $delete_link = "<span class='mdl-list__item-secondary-content'>
          <a class='mdl-list__item-secondary-action' href='{$delete_path}'><i class='material-icons'>close</i></a>
        </span>";
    }
    print
      "<li class='mdl-list__item mdl-list__item--three-line'>
        <span class='mdl-list__item-primary-content'>
          <i class='material-icons mdl-list__item-avatar'>person</i>
          <span>{$name}</span>
          <span class='mdl-list__item-text-body'>
            {$text}
          </span>
        </span>
        {$delete_link}
      </li>";
  }

  public static function AddForm($id, $class ='') {
    Html::form("/Comment/Add", "add-form {$class}");
    Html::mdlGrid();
      Html::mdlCell(12);
        Html::mdlTextFieldFloating();
          Html::input('text', 'text');
          Html::labelFor('title', 'Leave comment ...', 'text-white');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(12);
        Html::button('Add', 'Add', 'text-white');
      Html::mdlClose();
        Html::input('hidden', 'id', $id);
      Html::mdlClose();
    Html::formClose();
  }

}