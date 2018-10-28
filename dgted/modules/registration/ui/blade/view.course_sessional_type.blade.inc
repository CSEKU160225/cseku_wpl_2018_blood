<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_sessional_typebao.inc';


$_SessionalTypeBAO = new SessionalTypeBAO();
$_DB = DBUtil::getInstance();

/* saving a new SessionalType account*/
if(isset($_POST['save']))
{
	 $SessionalType = new SessionalType();	
	 $SessionalType->setID(Util::getGUID());
     $SessionalType->setName($_DB->secureInput($_POST['txtName']));
	 $_SessionalTypeBAO->createSessionalType($SessionalType);		 
}


/* deleting an existing SessionalType */
if(isset($_GET['del']))
{

	$SessionalType = new SessionalType();	
	$SessionalType->setID($_GET['del']);	
	$_SessionalTypeBAO->deleteSessionalType($SessionalType); //reading the SessionalType object from the result object

	header("Location:".PageUtil::$COURSE_SESSIONAL_TYPE);
}


/* reading an existing SessionalType information */
if(isset($_GET['edit']))
{
	$SessionalType = new SessionalType();	
	$SessionalType->setID($_GET['edit']);	
	$getROW = $_SessionalTypeBAO->readSessionalType($SessionalType)->getResultObject(); //reading the SessionalType object from the result object
}

/*updating an existing SessionalType information*/
if(isset($_POST['update']))
{
	$SessionalType = new SessionalType();	

    $SessionalType->setID ($_GET['edit']);
    $SessionalType->setName( $_POST['txtName'] );
	
	$_SessionalTypeBAO->updateSessionalType($SessionalType);

	header("Location:".PageUtil::$COURSE_SESSIONAL_TYPE);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.SessionalType.inc");

?>