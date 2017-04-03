<?php
// Model available in $this->model variable.
$Model = $this->Model;

(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';

print $Model;