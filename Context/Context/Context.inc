<?

namespace Context;

class Context {
  public $Settings;   // Class that defines basic settings.
  public $Router;     // Class that defines controller, it's method and holds get/post vars.
  public $Controller; // Controller class: is defined by reflection.
  public $Model;      // Model is filled by controller.
  public $Session;    // Session variables class.
  public $Messages;   // Array that can be used in template for system messages.
  public $DB;         // Implementation of wrapper around standard mysqli class.
  public $User;       // Implementation of User that depends on session and DB.
  // Singleton handler.
  static public function Application() {
    global $Context; // Singleton.
    if(!isset($Context)) {
      $Context = new Context();
    }
    return $Context;
  }
  // Constructor.
  private function __construct() {
    $this->Session = new SessionPHP();
    $this->Router = new Router();
    $this->Settings = Settings::Instance();
    $this->DB = Database::Instance();
    Model::SetUp();
    $this->Model = '';
  }
  // Main workflow.
  public function Run(){
    if(!$this->GetController()) {
      $this->Page404();
    }
    else {
      $this->ExecuteController();
      if(!$this->GetView()) {
        $this->Page404();
      }
      else {
        $this->Render();
      }
    }
  }
  // Try to get instance of controller class and check its handler method.
  private function GetController() {
    if($this->Router->ControllerExists) {
      require_once $this->Router->ControllerPath;
      $class = '\Context\\' . $this->Router->Controller . 'Controller';
      $this->Controller = new $class($this);
      if(is_object($this->Controller) && method_exists($this->Controller, $this->Router->View)) {
        return true;
      }
    }
    return false;
  }
  private function GetView() {
    return $this->Router->ViewExists;
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
  public function RenderView() {
    require_once CONTEXT_ROOT.'/Views/'. $this->Router->Controller .'/'.$this->Router->View.'.inc';
  }
  // Render not found page.
  private function Page404() {
    header('HTTP/1.0 404 Not Found');
    header('Status: 404 Not Found');
    exit;
  }
}