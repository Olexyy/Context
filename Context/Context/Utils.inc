<?php

namespace Context;

class Utils {

  public static function ValidateId($id) {
    if(is_numeric($id)) {
      return true;
    }
    return false;
  }

  public static function IsLoggedIn() {
    $user_id = Context::Application()->Session->Get('User');
    return isset($user_id );
  }

  public static function GetUser($entity = true) {
    $user_id = Context::Application()->Session->Get('User');
    if(!isset($user_id)) {
      return false;
    }
    return ($entity)? User::Read($user_id) : $user_id;
  }

  public static function SetUser($id) {
    if(self::ValidateId($id)) {
      Context::Application()->Session->Set('User', $id);
      return true;
    }
    return false;
  }

  public static function UnsetUser($id) {
    if(self::ValidateId($id)) {
      $existing = Context::Application()->Session->Get('User');
      if(isset($existing) && $existing == $id) {
        Context::Application()->Session->Set('User', null);
        return true;
      }
    }
    return false;
  }

  static function EncryptPass($pass) {
    return md5($pass);
  }

  public static function Redirect($path) {
    header('location:'.$path);
  }
}