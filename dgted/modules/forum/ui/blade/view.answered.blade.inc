<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.answeredbao.inc';

$_AnsweredBAO = new AnsweredBAO();
$_DB = DBUtil::getInstance();
$Discussion = new Discussion();


//$_Log->log(LogUtil::$DEBUG," exit blade.searchDiscussion.inc");

?>