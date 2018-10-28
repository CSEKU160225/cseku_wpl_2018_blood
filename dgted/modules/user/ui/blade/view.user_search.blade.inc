<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';
include_once MODULES_USER.'bao/class.positionbao.inc';


$_UserBAO = new UserBAO();
$_RoleBAO = new RoleBAO();
$_PositionBAO = new PositionBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalUser = '';

$globalUser = $_SESSION["globalUser"];



/* saving a new user account*/
if(isset($_POST['search']))
{

	if(isset($_POST['assignedRoles']))
	{	   
		$Role = $_POST['assignedRoles'];
	}

	if(isset($_POST['selectedField']))
	{	   
		$SearchField = $_POST['selectedField'];
	}

	if(isset($_POST['txtSearch']))
	{	   
		$SearchText = $_DB->secureInput($_POST['txtSearch']);

		$ResultSearch = $_UserBAO->searchUser( $Role, $SearchField, $SearchText);		
	}	
		
}


//$_Log->log(LogUtil::$DEBUG,"exit blade.user_search.inc");

?>