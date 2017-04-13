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
require_once CONTEXT_ROOT . '/Models/Model.inc';
\Context\Utils::Autoload(CONTEXT_ROOT . '/Models');
\Context\Utils::Autoload(CONTEXT_ROOT . '/Helpers');
\Context\Utils::Autoload(CONTEXT_ROOT . '/Library');