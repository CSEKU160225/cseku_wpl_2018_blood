<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';


$_YearBAO = new YearBAO();
$_DB = DBUtil::getInstance();

/* saving a new Year account*/
if(isset($_POST['save']))
{
	 $Year = new Year();	
	 $Year->setID(Util::getGUID());
     $Year->setName($_DB->secureInput($_POST['txtName']));
	 $_YearBAO->createYear($Year);		 
}


/* deleting an existing Year */
if(isset($_GET['del']))
{

	$Year = new Year();	
	$Year->setID($_GET['del']);	
	$_YearBAO->deleteYear($Year); //reading the Year object from the result object

	header("Location:".PageUtil::$YEAR);
}


/* reading an existing Year information */
if(isset($_GET['edit']))
{
	$Year = new Year();	
	$Year->setID($_GET['edit']);	
	$getROW = $_YearBAO->readYear($Year)->getResultObject(); //reading the Year object from the result object
}

/*updating an existing Year information*/
if(isset($_POST['update']))
{
	$Year = new Year();	

    $Year->setID ($_GET['edit']);
    $Year->setName( $_POST['txtName'] );
	
	$_YearBAO->updateYear($Year);

	header("Location:".PageUtil::$YEAR);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.year.inc");

?>