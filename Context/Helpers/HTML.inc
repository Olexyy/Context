<?php

class Html {
  public static function mdlCell($width = 4, $content = '', $class = '') {
    print "<div class='mdl-cell mdl-cell--{$width}-col {$class} mdl-cell--middle'>{$content}";
  }
  public static function mdlGrid($class = '') {
    print "<div class='mdl-grid {$class}'>";
  }
  public static function mdlClose() {
    print "</div>";
  }
  public static function h3($content = '', $class ='') {
    print "<h3 class='{$class}'>{$content}</h3>";
  }
  public static function h2($content = '', $class ='') {
    print "<h2 class='{$class}'>{$content}</h2>";
  }
  public static function p($content = '', $class ='') {
    print "<p class='{$class}'>{$content}</p>";
  }
  public static function mdlTextFieldFloating($class ='') {
    print "<div class='font-color mdl-textfield mdl-js-textfield mdl-textfield--floating-label {$class}'>";
  }
  public static function mdlTextField($class ='') {
    print "<div class='font-color mdl-textfield mdl-js-textfield {$class}'>";
  }
  public static function input($type, $name = '', $value = '', $class = '') {
    print "<input class='font-color mdl-textfield__input {$class}' type='{$type}' name='{$name}' id='{$name}' value='{$value}' />";
  }
  public static function textarea($name='', $value ='', $class='', $rows = 3) {
    print "<textarea class='font-color mdl-textfield__input {$class}' name='{$name}' rows= '{$rows}' id='{$name}'>{$value}</textarea>";
  }
  public static function labelFor($for = '', $content = '', $class ='') {
    print "<label for='{$for}' class='font-color mdl-textfield__label {$class}'>{$content}</label>";
  }
  public static function reCaptcha() {
    $key = \Context\Settings::Instance()->ReCaptchaBaseKeyPublic;
    print "<div class='g-recaptcha' data-sitekey='{$key}'></div>";
    print "<script src='https://www.google.com/recaptcha/api.js'></script>";
  }
  public static function printMessages() {
    foreach (\Context\Message::GetMessages() as $name => $message_group) {
      foreach ($message_group as $message) {
        print "<div class='message message-line {$name}'>{$message}</div>";
      }
    }
  }
  public static function l($text, $path, $class = '') {
    print "<a class='{$class}' href='{$path}'>{$text}</a>";
  }
  public static function form($action, $class = '', $method = 'post') {
    print "<form class='{$class}' action='{$action}' method='{$method}' enctype='multipart/form-data'>";
  }
  public static function formClose() {
    print "</form>";
  }
  public static function button($name, $value, $class ='') {
    print "<input class='font-color mdl-button mdl-js-button {$class}' name='{$name}' value='{$value}' type='submit'>";
  }
  public static function mdlCard($title = '', $description ='', $edit_path = "", $delete_path = "", $edit_text = "Edit") {
    print
      "<div class='demo-card-wide mdl-card mdl-shadow--2dp'>
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