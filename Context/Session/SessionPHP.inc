<?

namespace Context;

class SessionPHP {
  public $SessionId;

  public function __construct() {
    session_start();
    $this->SessionId = session_id();
  }

  public  function __destruct() {
    session_write_close();
  }

  public function Set($key, $value) {
    global $_SESSION;
    $_SESSION[$key] = $value;
  }

  public function Get($key) {
    global $_SESSION;
    return $_SESSION[$key];
  }


}