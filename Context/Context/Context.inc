<?

namespace Context;

class Context {
    static $Instance;   // Singleton.
    public $Settings;   // Class that defines basic settings.
    public $Router;     // Class that defines controller, it's method and holds get/post vars.
    public $Controller; // Controller class: is defined by reflection.
    public $Model;      // Model is filled by controller.
    public $Session;    // Session variables class.
    public $Messages;   // Array that can be used in template for system messages.
    public $DB;         // todo: implement standard mysqli class.
    public $User;       // todo: implement User depends on session and DB.
    // Singleton handler.
    static public function Application(){
        if(!isset(self::$Instance)) {
            self::$Instance = new Context();
        }
        return self::$Instance;
    }
    // Constructor.
    private function __construct() {
        $this->Messages = array();
        $this->Model = array();
        $this->Settings = new Settings();
        $this->Router = new Router();
        $this->Session = new SessionPHP();
        //$this->DB = new \mysqli ($this->settings->db['host'], $this->settings->db['user'], $this->settings->db['password'], $this->settings->db['database']);
    }
    // Main workflow.
    public function Run(){
        if(!$this->GetController()) {
            $this->Page404();
        }
        else {
            $this->ExecuteController();
            $this->Render();
        }
    }
    // Try to get instance of controller class and check it's handler method.
    private function GetController() {
        if($this->Router->HandlerExists) {
            require_once $this->Router->ControllerPath;
            $class = '\Context\\'.$this->Router->Controller;
            $this->Controller = new $class($this);
            if(is_object($this->Controller) && method_exists($this->Controller, $this->Router->View)) {
                return true;
            }
        }
        return false;
    }
    // Execute defined method.
    private function ExecuteController() {
        $this->Controller->{$this->Router->View}();
    }
    // Render page template.
    public function Render() {
        require_once CONTEXT_ROOT.'/Views/Template.inc';
    }
    // Render specific view.
    public function RenderView(){
        require_once CONTEXT_ROOT.'/Views/'. $this->Router->Controller .'/'.$this->Router->View.'.inc';
    }
    // Render not found page.
    private function Page404() {
        header('HTTP/1.0 404 Not Found');
        header('Status: 404 Not Found');
    }
    // End procedures.
    public function __destruct() {
        //$this->Session->save_session();
        //$this->DB->close();
    }
}