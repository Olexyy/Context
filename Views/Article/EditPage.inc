<?php
$Model = $this->Model;
Html::form("/Article/Edit", "edit-form");
  Html::mdlGrid();
    Html::mdlCell(8);
      Html::h3("Edit article");
    Html::mdlClose();
    Html::mdlCell(4); Html::mdlClose();
    Html::mdlCell(8);
      Html::mdlTextFieldFloating();
        Html::input('text', 'title', $Model->Title);
        Html::labelFor('title', 'Title');
      Html::mdlClose();
    Html::mdlClose();
    Html::mdlCell(4); Html::mdlClose();
    Html::mdlCell(8);
      Html::mdlTextFieldFloating();
        Html::textarea('description', $Model->Description);
        Html::labelFor('description', 'Description');
      Html::mdlClose();
    Html::mdlClose();
    Html::mdlCell(4); Html::mdlClose();
    Html::mdlCell(8);
      Html::mdlTextField();
        Html::input('file', 'file');
      Html::mdlClose();
    Html::mdlClose();
    Html::mdlCell(4); Html::mdlClose();
    Html::mdlCell(8);
      Html::button('Edit', 'Edit', 'text-white');
    Html::mdlClose();
    Html::mdlCell(4); Html::mdlClose();
  Html::mdlClose();
  Html::input('hidden', 'id', $Model->Id);
Html::formClose();