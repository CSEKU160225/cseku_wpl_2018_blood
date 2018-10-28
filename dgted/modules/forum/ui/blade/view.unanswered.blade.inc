<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.unansweredbao.inc';

$_UnansweredBAO = new UnansweredBAO();
$_DB = DBUtil::getInstance();
$Discussion = new Discussion();


//$_Log->log(LogUtil::$DEBUG," exit blade.searchDiscussion.inc");

?>