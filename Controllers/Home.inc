<?php

namespace Context;

class Home extends Controller {
    // $this->Context->Model should be set.
    public function Index() {
        $this->Context->Model = '<a href="/Home/Other">Link to other page.</a>';
    }
    public function Other() {
      $this->Context->Model = '<a href="/Home/Index">Home.</a>';
    }
}
