<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';


$_RoleBAO = new RoleBAO();
$_DB = DBUtil::getInstance();

/* saving a new Role account*/
if(isset($_POST['save']))
{
	 $Role = new Role();	
	 $Role->setID(strtolower($_DB->secureInput($_POST['txtName'])));
     $Role->setName($_DB->secureInput($_POST['txtName']));
	 $_RoleBAO->createRole($Role);		 
}


/* deleting an existing Role */
if(isset($_GET['del']))
{

	$Role = new Role();	
	$Role->setID($_GET['del']);	
	$_RoleBAO->deleteRole($Role); //reading the Role object from the result object

	header("Location:".PageUtil::$ROLE);
}


/* reading an existing Role information */
if(isset($_GET['edit']))
{
	$Role = new Role();	
	$Role->setID($_GET['edit']);	
	$getROW = $_RoleBAO->readRole($Role)->getResultObject(); //reading the Role object from the result object
}

/*updating an existing Role information*/
if(isset($_POST['update']))
{
	$Role = new Role();	

    $Role->setID ($_GET['edit']);
    $Role->setName( $_POST['txtName'] );
	
	$_RoleBAO->updateRole($Role);

	header("Location:".PageUtil::$ROLE);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.Role.inc");

?>