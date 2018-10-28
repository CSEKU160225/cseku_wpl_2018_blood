<?php


include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';

$_UserBAO = new UserBAO();
$_Log= LogUtil::getInstance();
$_DB = DBUtil::getInstance();


/* saving a new user account*/
if(isset($_POST['request']))
{
	$User = new User();	

	$User->setID(strtolower($_DB->secureInput($_POST['txtEmail']))); 
		 
	$User->setEmail(strtolower($_DB->secureInput($_POST['txtEmail']))); 

   	
	$Result = $_UserBAO->requestPassword($User);		

	echo '<strong>'.$Result->getResultObject().'</strong>';	

}


//$_Log->log(LogUtil::$DEBUG,"exit blade.user_new.inc");

?>