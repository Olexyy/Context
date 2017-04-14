<?php

namespace Context;

class Article extends Model {

  public $Title;
  public $Description;
  public $User_Id;
  public $File_Id;
  public $Created;
  public $Data;

  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Title', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Description', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('User_Id', self::INT, self::NOT_NULL);
    $this->AddField('File_Id', self::INT, self::NULL);
    $this->AddField('Created', self::INT, self::NULL);
    $this->AddField('Data', self::TEXT, self::NULL);
  }

}