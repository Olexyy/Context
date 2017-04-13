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
    if(!Settings::Instance()->UseDB) {
      return false;
    }
    $user_id = Context::Application()->Session->Get('User');
    return isset($user_id );
  }

  public static function GetUser($entity = true) {
    if(!Settings::Instance()->UseDB) {
      return false;
    }
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
    exit;
  }

  public static function ValidateReCaptcha ($response) {
    //$url = Settings::Instance()->ReCaptchaBaseUrl;
    $key = Settings::Instance()->ReCaptchaBaseKeyPrivate;
    /*$ip = $_SERVER['REMOTE_ADDR'];
    $url_data = $url.'?secret='.$key.'&response='.$response.'&remoteip='.$ip;
    $curl = curl_init();
    curl_setopt($curl,CURLOPT_URL,$url_data);
    curl_setopt($curl,CURLOPT_SSL_VERIFYPEER,false);
    curl_setopt($curl,CURLOPT_RETURNTRANSFER,1);
    $result = curl_exec($curl);
    //print_r ($result);
    curl_close($curl);
    $result = json_decode($result);
    if($result->success) {
      return true;
    }
    return false;*/
    $reCAPTCHA = new \Library\ReCaptcha();
    $reCAPTCHA->setSecretKey($key);
    return $reCAPTCHA->isValid($response);
  }
  public static function UploadFile($directory) {
    global $_FILES;
    $file_path = CONTEXT_ROOT. '/Static/' . $directory . '/';
    if (move_uploaded_file($_FILES['file']['tmp_name'], $file_path . $_FILES['file']['name'])) {
      foreach (new \DirectoryIterator($file_path) as $file_info) {
        if( $file_info->getFilename() == $_FILES['file']['name']) {
          $file = new File(array(
            'Name' => $file_info->getFilename(),
            'Extension' => $file_info->getExtension(),
            'Path' => $file_info->getPath(),
            'Size' => $file_info->getSize(),
            'Created' => $file_info->getMTime(),
            'Type' => $file_info->getType(),
          ));
          File::Create($file);
          return $file->Id;
        }
      }
    }
    return false;
  }
  public static function RegisteredAccess($entity = true){
    if($user = Utils::GetUser($entity)) {
      return $user;
    }
    else {
      Message::SetMessage('Please, log in or sign up.');
      Utils::Redirect('/Home/Index');
    }
  }
  public static function Autoload($directory) {
    foreach (new \DirectoryIterator($directory) as $file_info) {
      if (!$file_info->isDot() && $file_info->isFile()) {
        require_once $file_info->getPathname();
      }
    }
  }
}