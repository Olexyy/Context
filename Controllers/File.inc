<?php

namespace Context;

class FileController extends Controller {
  public function Upload() {
    if(Utils::UploadFile($this->Context->Controller)) {
      Message::SetMessage('File uploaded');
    }
    else {
      Message::SetMessage('File was not uploaded');
    }
    Utils::Redirect('Home/Index');
  }
}
