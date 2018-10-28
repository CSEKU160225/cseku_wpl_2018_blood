<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';


$_RoleBAO = new RoleBAO();
$_DB = DBUtil::getInstance();
$_Log = LogUtil::getInstance();

/* saving a new Role account*/
if(isset($_POST['save']))
{
	 $Role = new Role();

	if(isset($_POST['selectedRole']))	
	 	$Role->setID($_POST['selectedRole']);

	
	$Permissions = array();
    
    if(isset($_POST['selectedPermissions'])){ 
	    foreach ($_POST['selectedPermissions'] as $select)
		{
			$Permission = new Permission();
			$Permission->setID($select);
			$Permissions[]=$Permission;
		}

	}     
$_RoleBAO->assignPermissionsToRole($Role,$Permissions);	 
}



/* reading an existing Role information */
if(isset($_GET['edit']))
{
	$Role = new Role();	
	$Role->setID($_GET['edit']);	
	$globalRole = $_RoleBAO->readRolePermissions($Role)->getResultObject(); //reading the role object from the result object
}

//if a permission(ID) is present in the list of list(permissions(ID))
function isPermissionAvailable($Permission, $Permissions)
{
	
	for ($i=0; $i < sizeof($Permissions); $i++) { 
		# code...
		if(!strcmp($Permission->getID(),$Permissions[$i]->getID())){
			return true;
		}
	}

	return false;
}

////$_Log->log(LogUtil::$DEBUG," exit blade.permission.inc");

?>