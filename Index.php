<?php
define('CONTEXT_ROOT', getcwd());
require_once CONTEXT_ROOT . '/Context/Boot.inc';
\Context\Context::Application()->Run();