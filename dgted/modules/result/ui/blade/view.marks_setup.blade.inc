<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_RESULT.'bao/class.marks_setupbao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc'; // module dependency


$_CourseTypeBAO = new CourseTypeBAO();
$_MarksSetupBAO = new MarksSetupBAO();
$_DB = DBUtil::getInstance();
$getROW="";

if(isset($_POST['save']))
{
	 $MarksSetup = new MarksSetup();

	 $MarksSetup->setID(Util::getGUID());

	 if(isset($_POST['coursetype']))	 
	 	$MarksSetup->setCourseType($_POST['coursetype']);
	 
     $MarksSetup->setHeaderID($_DB->secureInput($_POST['txtHeaderID']));
     
     $MarksSetup->setHeaderName($_DB->secureInput($_POST['txtHeaderName']));

     $MarksSetup->setHeaderMax($_DB->secureInput($_POST['txtHeaderMax']));

     if(!isset($_POST['IsDefault'])||$_POST['IsDefault'] == "")
     {
     	$MarksSetup->setIsDefault(0);
     }
     else 
     {
     	$MarksSetup->setIsDefault(1);
     }

     $_MarksSetupBAO->createMarksSetup($MarksSetup);	 
}


/* deleting an existing marks setup */
if(isset($_GET['del']))
{
	$MarksSetup = new MarksSetup();
	$MarksSetup->setID($_GET['del']);	
	$_MarksSetupBAO->deleteMarksSetup($MarksSetup); 
	header("Location:".PageUtil::$MARKS_SETUP);
}


/* reading an existing marks setup information */
if(isset($_GET['edit']))
{
	$MarksSetup = new MarksSetup();
	$MarksSetup->setID($_GET['edit']);	
	//reading the marks setup object from the result object
	$getROW = $_MarksSetupBAO->readMarksSetup($MarksSetup)->getResultObject(); 

}

/*updating an existing marks setup information*/
if(isset($_POST['update']))
{
	 $MarksSetup = new MarksSetup();

	 $MarksSetup->setID($_GET['edit']);

	 if(isset($_POST['coursetype']))	 
	 	$MarksSetup->setCourseType($_POST['coursetype']);
	 
     $MarksSetup->setHeaderID($_DB->secureInput($_POST['txtHeaderID']));
     
     $MarksSetup->setHeaderName($_DB->secureInput($_POST['txtHeaderName']));

     $MarksSetup->setHeaderMax($_DB->secureInput($_POST['txtHeaderMax']));

     if(!isset($_POST['IsDefault'])||$_POST['IsDefault'] == "")
     {
     	$MarksSetup->setIsDefault(0);
     }
     else 
     {
     	$MarksSetup->setIsDefault(1);
     }

     $_MarksSetupBAO->updateMarksSetup($MarksSetup);	 

	header("Location:".PageUtil::$MARKS_SETUP);
}



////$_Log->log(LogUtil::$DEBUG," exit view.MarksSetup.blade.inc");

?>