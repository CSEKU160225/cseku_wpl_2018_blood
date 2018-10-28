<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_sessional_typebao.inc';




$_CourseTypeBAO = new CourseTypeBAO();
$_SessionalTypeBAO = new SessionalTypeBAO();
$_DB = DBUtil::getInstance();


if(isset($_POST['save']))
{
	 $CourseType = new CourseType();
	 $CourseType->setID(Util::getGUID());
	 
     $CourseType->setName($_DB->secureInput($_POST['txtName']));
     $CourseType->setSessionalTypeID($_POST['sessionaltype']);
     //echo '<br>'.$_POST['sessionaltype'];
     //echo '<br>'.$CourseType->getSessionalTypeID();
	 $_CourseTypeBAO->createCourseType($CourseType);
	 //echo '<br>"save"';
	 //print_r(school);		 
}


/* deleting an existing CourseType */
if(isset($_GET['del']))
{

	$CourseType = new CourseType();	
	$CourseType->setID($_GET['del']);	
	$_CourseTypeBAO->deleteCourseType($CourseType); //reading the CourseType object from the result object

	header("Location:".PageUtil::$COURSE_TYPE);
}


/* reading an existing CourseType information */
if(isset($_GET['edit']))
{
	$CourseType = new CourseType();	
	$CourseType->setID($_GET['edit']);	
	$getROW = $_CourseTypeBAO->readCourseType($CourseType)->getResultObject(); //reading the CourseType object from the result object
}

/*updating an existing CourseType information*/
if(isset($_POST['update']))
{
	$CourseType = new CourseType();	

    $CourseType->setID($_GET['edit']);
    $CourseType->setName($_POST['txtName']);
	$CourseType->setSessionalTypeID($_POST['sessionaltype']);
	$_CourseTypeBAO->updateCourseType($CourseType);

	header("Location:".PageUtil::$COURSE_TYPE);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.CourseType.inc");

?>