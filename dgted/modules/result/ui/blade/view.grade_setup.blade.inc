<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_RESULT.'bao/class.grade_setupbao.inc';



$_GradeSetupBAO = new GradeSetupBAO();
$_DB = DBUtil::getInstance();
$getROW="";

if(isset($_POST['save']))
{
	 $GradeSetup = new GradeSetup();

	 $GradeSetup->setID(Util::getGUID());

	 
     $GradeSetup->setGrades($_DB->secureInput($_POST['txtGrades']));
     
     $GradeSetup->setRanges($_DB->secureInput($_POST['txtRanges']));

  
     if(!isset($_POST['IsDefault'])||$_POST['IsDefault'] == "")
     {
     	$GradeSetup->setIsDefault(0);
     }
     else 
     {
     	$GradeSetup->setIsDefault(1);
     }

     $_GradeSetupBAO->createGradeSetup($GradeSetup);	 
}


/* deleting an existing Grade setup */
if(isset($_GET['del']))
{
	$GradeSetup = new GradeSetup();
	$GradeSetup->setID($_GET['del']);	
	$_GradeSetupBAO->deleteGradeSetup($GradeSetup); 
	header("Location:".PageUtil::$GRADE_SETUP);
}


/* reading an existing Grade setup information */
if(isset($_GET['edit']))
{
	$GradeSetup = new GradeSetup();
	$GradeSetup->setID($_GET['edit']);	
	//reading the Grade setup object from the result object
	$getROW = $_GradeSetupBAO->readGradeSetup($GradeSetup)->getResultObject(); 

}

/*updating an existing Grade setup information*/
if(isset($_POST['update']))
{
	 $GradeSetup = new GradeSetup();

	 $GradeSetup->setID($_GET['edit']);

      $GradeSetup->setGrades($_DB->secureInput($_POST['txtGrades']));
     
     $GradeSetup->setRanges($_DB->secureInput($_POST['txtRanges']));
	 
  
     if(!isset($_POST['IsDefault'])||$_POST['IsDefault'] == "")
     {
     	$GradeSetup->setIsDefault(0);
     }
     else 
     {
     	$GradeSetup->setIsDefault(1);
     }

     $_GradeSetupBAO->updateGradeSetup($GradeSetup);	 

	header("Location:".PageUtil::$GRADE_SETUP);
}



////$_Log->log(LogUtil::$DEBUG," exit view.GradeSetup.blade.inc");

?>