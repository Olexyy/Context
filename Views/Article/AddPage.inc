<?php
// Model available in $this->model variable.
$Model = $this->Model;
  Html::form("/Article/Add", "add-form");
    Html::mdlGrid();
      Html::mdlCell(8);
        Html::h3("Add article");
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();
      Html::mdlCell(8);
        Html::mdlTextFieldFloating();
          Html::input('text', 'title');
          Html::labelFor('title', 'Title');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();
      Html::mdlCell(8);
        Html::mdlTextFieldFloating();
          Html::textarea('description');
          Html::labelFor('description', 'Description');
        Html::mdlClose();
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();
      Html::mdlCell(8);
        Html::button('Add', 'Add', 'text-white');
      Html::mdlClose();
      Html::mdlCell(4); Html::mdlClose();
    Html::mdlClose();
  Html::formClose();