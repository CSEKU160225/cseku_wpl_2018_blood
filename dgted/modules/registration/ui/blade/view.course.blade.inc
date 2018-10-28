<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc';//here comes module dependency

$_CourseBAO = new CourseBAO();
$_CourseTypeBAO = new CourseTypeBAO();
$_DisciplineBAO = new DisciplineBAO();
$_DB = DBUtil::getInstance();


if(isset($_POST['save']))
{
	 $Course = new Course();
	 $Course->setID(Util::getGUID());
	 
     $Course->setCourseNo($_POST['txtName']);
     $Course->setTitle($_POST['txttitle']);
     $Course->setCredit($_POST['txtcrdit']);
     $Course->setCourseTypeID($_POST['coursetype']);
     $Course->setDisciplineID($_POST['discipline']);
     
     if(!isset($_POST['ISdeleted'])||$_POST['ISdeleted'] == "")
     {
     	$Course->setISdeleted(1);
     }
     else 
     {
     	$Course->setISdeleted(0);
     }

     $_CourseBAO->createCourse($Course);	 
}


/* deleting an existing Course */
if(isset($_GET['del']))
{

	$Course = new Course();	
	$Course->setID($_GET['del']);	
	$_CourseBAO->deleteCourse($Course); //reading the Course object from the result object

	header("Location:".PageUtil::$COURSE);
}


/* reading an existing Course information */
if(isset($_GET['edit']))
{
	$Course = new Course();	
	$Course->setID($_GET['edit']);	
	$getROW = $_CourseBAO->readCourse($Course)->getResultObject(); //reading the Course object from the result object
}

/*updating an existing Course information*/
if(isset($_POST['update']))
{
	$Course = new Course();	

    $Course->setID($_GET['edit']);
    
    $Course->setCourseNo($_POST['txtName']);
    $Course->setTitle($_POST['txttitle']);
    $Course->setCredit($_POST['txtcrdit']);
    $Course->setCourseTypeID($_POST['coursetype']);
    $Course->setDisciplineID($_POST['discipline']);
    echo '<br> checkbox'.$_POST['ISdeleted'];
    if($_POST['ISdeleted'] == "")
    {
    $Course->setISdeleted(0);
    }
    else 
    {
    $Course->setISdeleted(1);
    }
	$_CourseBAO->updateCourse($Course);

	header("Location:".PageUtil::$COURSE);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.Course.inc");

?>