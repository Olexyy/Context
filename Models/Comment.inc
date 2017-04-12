<?php

namespace Context;

class Comment extends Model {

  public $Text;
  public $Article_Id;
  public $User_Id;
  public $Created;
  public $Data;

  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Text', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Article_Id', self::INT, self::NOT_NULL);
    $this->AddField('User_Id', self::INT, self::NOT_NULL);
    $this->AddField('Created', self::TEXT, self::NULL);
    $this->AddField('Data', self::TEXT, self::NULL);
  }

}