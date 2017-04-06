<?php

namespace Context;

class HTML {
  public static function MdlCell($width = 4, $content = '') {
    print "<div class='mdl-cell mdl-cell--{$width}-col'>{$content}</div>";
  }


}