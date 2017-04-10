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
  public static function mdlTextFieldFloating() {
    print "<div class='mdl-textfield mdl-js-textfield mdl-textfield--floating-label'>";
  }
  public static function mdlTextField() {
    print "<div class='mdl-textfield mdl-js-textfield'>";
  }
  public static function input($type, $name = '', $value = '') {
    print "<input class='mdl-textfield__input' type='{$type}' name='{$name}' id='{$name}' value='{$value}' />";
  }
  public static function labelFor($for = '', $content = '', $class ='') {
    print "<label for='{$for}' class='mdl-textfield__label {$class}'>{$content}</label>";
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
    print "<input class='mdl-button mdl-js-button {$class}' name='{$name}' value='{$value}' type='submit'>";
  }
}