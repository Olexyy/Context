<?

namespace Context;

class Context {
    static $Instance;   // Singleton.
    public $Settings;   // Class that defines basic settings.
    public $Router;     // Class that defines controller, it's method and holds get/post vars.
    public $Controller; // Controller class: is defined by reflection.
    public $Model;      // Model is filled by controller.
    public $DB;         // todo: implement For now standard mysqli class.
    public $Session;    // todo: implement Session variables class.
    public $User;       // todo: implement User depends on session.
    public $Messages;   // array that can be used in template for system messages
    // Singleton handler.
    static public function Application(){
        if(!isset(self::$Instance)) {
            self::$Instance = new Context();
        }
        return self::$Instance;
    }
    // Constructor.
    private function __construct() {
        Context::$Instance = $this;
        $this->Messages = array();
        $this->Settings = new Settings();
        $this->Router = new Router();
        //$this->DB = new \mysqli ($this->settings->db['host'], $this->settings->db['user'], $this->settings->db['password'], $this->settings->db['database']);
        //$this->Session = new Session($this->db);
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
    // Try to get instance of controller class.
    private function GetController() {
        if($this->Router->HandlerExists) {
            require_once $this->Router->ControllerPath;
            $class = '\Context\\'.$this->Router->Controller;
            $this->Controller = new $class($this);
            return true;
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