<?php

namespace Context;

class Article extends Model {

  public $Title;
  public $Description;
  public $File_Id;
  public $User_Id;
  public $Data;

  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Title', self::INT, self::NOT_NULL);
    $this->AddField('Description', self::NVARCHAR, self::NULL);
    $this->AddField('File_Id', self::INT, self::NULL);
    $this->AddField('User_Id', self::INT, self::NOT_NULL);
    $this->AddField('Data', self::TEXT, self::NULL);
  }

}