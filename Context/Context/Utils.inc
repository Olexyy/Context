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

  public static function GetUser() {
    $user_id = Context::Application()->Session->Get('User');
    return isset($user_id)? User::Read($user_id) : false;
  }

  public static function SetUser($id) {
    if(self::ValidateId($id)) {
      Context::Application()->Session->Set('User', $id);
      return true;
    }
    return false;
  }
}