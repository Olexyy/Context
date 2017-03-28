<?

namespace context;

class session {
  const CONTEXT = 'context';
  public $session_id;
  private $db;
  public function data($key, $value = null){
    if(isset($value)){
      $this->set_data($key, $value);
      return true;
    }
    else{
      return $this->get_data($key);
    }
  }
  public function set_data($key, $value){
      $_SESSION[session::CONTEXT][$key] = $value;
  }
  public function get_data($key){
     return $_SESSION[session::CONTEXT][$key];
  }
  public function __construct(\mysqli $db){
    $this->items = array();
    $this->db = $db;
    $this->create_table();
  }
  public  function __destruct(){
  }
  private function create_table(){
        $query_exist = $this->db->query("SELECT COUNT(*) FROM information_schema.TABLES WHERE (TABLE_SCHEMA = 'context') AND (TABLE_NAME = 'sessions')");
        $result = $query_exist->fetch_all();
        $count = $result[0][0];
        if ($count === '0') {
            $query = $this->db->query("CREATE TABLE sessions (id INT NOT NULL, created INT NOT NULL, changed INT NOT NULL, data TEXT NULL, PRIMARY KEY(id))");
        }
    }
    public function load_session(){
        if (isset($_COOKIE[session::CONTEXT])){
            $this->session_id = $_COOKIE[session::CONTEXT];
            $query_get_session = $this->db->query("SELECT data FROM sessions WHERE id = $this->session_id");
            $results = $query_get_session->fetch_all();
            $_SESSION[session::CONTEXT] = unserialize($results[0][0]);
        }
        else{
            $this->session_id = 0;
            do {
                $session_id = mt_rand(0, 2147483647); // should be PHP_INT_MAX (2147483647);
                $query_exists = $this->db->query("SELECT COUNT(*) FROM sessions WHERE id = $this->session_id");
                $results = $query_exists->fetch_all();
                $count = $results[0][0];
            }while($count !== '0');
            $timestamp = time();
            setcookie(session::CONTEXT, $session_id, time()+60*60*24);
            $_SESSION[session::CONTEXT] = array();
            $data = serialize($this->data);
            $query_set_session = $this->db->query("INSERT INTO sessions VALUES ($session_id, $timestamp, $timestamp, '$data')");
        }
    }
    public function save_session(){
        $data = serialize($_SESSION[session::CONTEXT]);
        $query_set_session = $this->db->query("UPDATE sessions SET data = '$data' WHERE id = $this->session_id");
    }
}