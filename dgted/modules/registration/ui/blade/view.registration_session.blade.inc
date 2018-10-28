<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';


$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_DB = DBUtil::getInstance();

/* saving a new RegistrationSession account*/
if(isset($_POST['save']))
{
	 $RegistrationSession = new RegistrationSession();	
	 $RegistrationSession->setID(Util::getGUID());
     $RegistrationSession->setName($_DB->secureInput($_POST['txtName']));
	 $_RegistrationSessionBAO->createRegistrationSession($RegistrationSession);		 
}


/* deleting an existing RegistrationSession */
if(isset($_GET['del']))
{

	$RegistrationSession = new RegistrationSession();	
	$RegistrationSession->setID($_GET['del']);	
	$_RegistrationSessionBAO->deleteRegistrationSession($RegistrationSession); //reading the RegistrationSession object from the result object

	header("Location:".PageUtil::$REGISTRATION_SESSION);
}


/* reading an existing RegistrationSession information */
if(isset($_GET['edit']))
{
	$RegistrationSession = new RegistrationSession();	
	$RegistrationSession->setID($_GET['edit']);	
	$getROW = $_RegistrationSessionBAO->readRegistrationSession($RegistrationSession)->getResultObject(); //reading the RegistrationSession object from the result object
}

/*updating an existing RegistrationSession information*/
if(isset($_POST['update']))
{
	$RegistrationSession = new RegistrationSession();	

    $RegistrationSession->setID ($_GET['edit']);
    $RegistrationSession->setName( $_POST['txtName'] );
	
	$_RegistrationSessionBAO->updateRegistrationSession($RegistrationSession);

	header("Location:".PageUtil::$REGISTRATION_SESSION);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.RegistrationSession.inc");

?>