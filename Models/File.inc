<?php

namespace Context;

class File extends Model {
  public $Name;
  public $Extension;
  public $Path;
  public $Type;
  public $Created;
  public $Size;
  
  protected function SchemaDefinition() {
    parent::SchemaDefinition();
    $this->AddField('Name', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Extension', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Path', self::NVARCHAR, self::NOT_NULL);
    $this->AddField('Type', self::NVARCHAR, self::NULL);
    $this->AddField('Created', self::INT, self::NULL);
    $this->AddField('Size', self::INT, self::NULL);
  }
}