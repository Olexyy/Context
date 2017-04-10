<?php

require_once CONTEXT_ROOT . '/Context/Settings/Settings.inc';
require_once CONTEXT_ROOT . '/Context/Router/Router.inc';
require_once CONTEXT_ROOT . '/Context/Session/SessionPHP.inc';
require_once CONTEXT_ROOT . '/Context/Database/Database.inc';
require_once CONTEXT_ROOT . '/Context/Helpers/Utils.inc';
require_once CONTEXT_ROOT . '/Context/Helpers/Html.inc';
require_once CONTEXT_ROOT . '/Context/Message/Message.inc';
require_once CONTEXT_ROOT . '/Context/Context/Context.inc';
require_once CONTEXT_ROOT . '/Controllers/Controller.inc';
// Models loaded automatically.
require_once CONTEXT_ROOT . '/Models/Model.inc';
foreach (new DirectoryIterator(CONTEXT_ROOT . '/Models') as $file_info) {
  if (!$file_info->isDot() && $file_info->isFile()) {
    require_once $file_info->getPathname();
  }
}