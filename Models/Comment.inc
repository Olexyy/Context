<?php

namespace Context;

class Comment extends Model {

  public $Text;
  public $Created;
  public $User_Id;

  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Text', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Created', self::INT, self::NULL);
    $this->AddField('User_Id', self::INT, self::NULL);
  }

}