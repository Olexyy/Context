<?php

namespace Context;

class Message {
  const Notice = 'notice';
  const Alert = 'alert';
  const Warning = 'warning';
  public static function MessageTypes() {
    return array( 'notice', 'alert', 'warning' );
  }
  const MessagesKey = 'messages';
  private  static function DefaultMessagesArray() {
    return array(
      self::Notice => array(),
      self::Alert => array(),
      self::Warning => array(),
    );
  }

  private static function Initialize() {
    if(!Context::Application()->Session->KeyExists(self::MessagesKey)) {
      $Messages = self::DefaultMessagesArray();
      Context::Application()->Session->Set(self::MessagesKey, $Messages);
    }
  }

  public function Count() {
    $count = 0;
    global $Messages;
    if(isset($Messages)) {
      foreach ($Messages as $message_group) {
        $count += count($message_group);
      }
    }
    return $count;
  }
//TODO test
  public static function SetMessage($message, $type = self::Notice) {
    self::Initialize();
    if(in_array($type, self::MessageTypes())) {
      $existing_messages = Context::Application()->Session->Get(self::MessagesKey);
      $existing_messages[$type][] = $message;
      Context::Application()->Session->Set(self::MessagesKey, $existing_messages);
    }
  }
  public static function GetMessages($erase = true) {
    $existing_messages = Context::Application()->Session->Get(self::MessagesKey);
    if($erase) {
      Context::Application()->Session->Set(self::MessagesKey, self::DefaultMessagesArray());
    }
    return ($existing_messages)? : array();
  }
}