<?php
/**
 * Created by PhpStorm.
 * User: Админ
 * Date: 28.03.2017
 * Time: 22:52
 */

namespace Context;


abstract class Controller {
  protected $Context;

  public function __construct(Context $context) {
    $this->Context = $context;
  }
  
}