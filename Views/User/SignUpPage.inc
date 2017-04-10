<?php
// Model available in $this->model variable.
$Model = $this->Model;
?>
<?php
  Html::form('/User/SignUp');
    Html::mdlGrid();
      Html::mdlCell(8); Html::h3('Sign up', 'title'); Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();

      Html::mdlCell(8);
        Html::mdlTextFieldFloating();
          Html::input('text', 'username'); Html::labelFor('username', 'Username');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();

      Html::mdlCell(8);
        Html::mdlTextFieldFloating();
          Html::input('password', 'password'); Html::labelFor('password', 'Password');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();

      Html::mdlCell(8);
        Html::mdlTextField();
          Html::input('file', 'file'); Html::labelFor('file', ' ');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();

      Html::mdlCell(2); Html::mdlClose();
      Html::mdlCell(4); Html::reCaptcha(); Html::mdlClose();
      Html::mdlCell(6); Html::mdlClose();

      Html::mdlCell(8);
        Html::button('SignUp', 'SignUp', 'text-white');
      Html::mdlClose();
    Html::mdlClose();
  Html::formClose();
?>