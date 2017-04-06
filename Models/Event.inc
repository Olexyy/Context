<?php

namespace Context;

class Event extends Model{
  public $Date;
  public $Description;
  public $User_Id;

  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Date', self::INT, self::NOT_NULL);
    $this->AddField('Description', self::NVARCHAR, self::NULL);
    $this->AddField('User_Id', self::INT, self::NULL);
  }

}