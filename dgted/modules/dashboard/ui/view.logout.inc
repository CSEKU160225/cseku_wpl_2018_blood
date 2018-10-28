<?php

include_once COMMON.'class.common.inc';

session_unset(); 
session_destroy();
header("Location:".PageUtil::$LOGIN);		


?>