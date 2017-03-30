<?

namespace Context;

class Router {
    public $Controller;
    public $View;
    public $Get;
    public $Post;
    public $Request;
    public $ControllerPath;
    public $ViewPath;
    public $HandlerExists;
    
    public function __construct(){
        $parsed_url = explode('/', $_SERVER['REDIRECT_URL']);
        $this->Controller = (isset($parsed_url[1])&&!empty($parsed_url[1]))? $parsed_url[1] : 'Home';
        $this->View = (isset($parsed_url[2])&&!empty($parsed_url[2]))? $parsed_url[2] : 'Index';
        if(file_exists(CONTEXT_ROOT.'/Controllers/'.$this->Controller.'.inc')) {
            $this->ControllerPath = CONTEXT_ROOT.'/Controllers/'.$this->Controller.'.inc';
        }
        if(file_exists(CONTEXT_ROOT.'/Views/'. $this->Controller .'/'.$this->View.'.inc')) {
            $this->ViewPath = CONTEXT_ROOT.'/Views/'. $this->Controller .'/'.$this->View.'.inc';
        }
        $this->HandlerExists = (isset($this->ControllerPath) && isset($this->ViewPath))?  true : false;
        $this->Get = $GLOBALS['_GET'];
        $this->Post = $GLOBALS['_POST'];
        $this->Request = $GLOBALS['_REQUEST'];
    }
}