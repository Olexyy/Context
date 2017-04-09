<?php

class HTML {
  public static function mdlCell($width = 4, $content = '', $class = '') {
    print "<div class='mdl-cell mdl-cell--{$width}-col {$class}'>{$content}";
  }
  public static function mdlGrid($class = '') {
    print "<div class='mdl-grid {$class}'>";
  }
  public static function mdlClose() {
    print "</div>";
  }
  public static function labelFor($for = '', $content = '', $class ='') {
    print "<label for='{$for}' class='{$class}'>{$content}</label>";
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
  public static function input($type, $name = '', $value = '') {
    print "<input type='{$type}' name='{$name}' id='{$name}' value='{$value}' />";
  }
  public static function reCaptcha() {
    $key = \Context\Settings::Instance()->ReCaptchaBaseKeyPublic;
    print "<div class='g-recaptcha' data-sitekey='{$key}'></div>";
    print "<script src='https://www.google.com/recaptcha/api.js'></script>";
  }
}