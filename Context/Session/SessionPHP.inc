<?

namespace Context;

class SessionPHP {
  public $SessionId;
  public $Session;

  public function __construct() {
    session_start();
    global $_SESSION;
    $this->Session = $_SESSION;
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

  public function KeyExists($key) {
    global $_SESSION;
    return isset($_SESSION[$key]);
  }

  public function SetSleep($key, $value) {
    global $_SESSION;
    $value = base64_encode(serialize($value));
    $_SESSION[$key] = $value;
  }

  public function GetWakeUp($key) {
    global $_SESSION;
    $value = $_SESSION[$key];
    return unserialize(base64_decode($value));
  }

}