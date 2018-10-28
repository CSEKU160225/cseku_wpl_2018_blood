<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacherbao.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //depenency with modules
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules


$_CourseBAO = new CourseBAO();
$_CourseTeacherBAO = new CourseTeacherBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_CourseTypeBAO = new CourseTypeBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_UserBAO = new UserBAO();
$_DisciplineBAO = new DisciplineBAO();
$_CourseTeacherBAO = new CourseTeacherBAO();
$_DB = DBUtil::getInstance();

$globalCourse = '';
if(isset($_POST['save']))
{

    $CourseTeacher = new CourseTeacher();
    $CourseTeacher->setID(Util::getGUID());
    
    $CourseTeacher->setCourse($_POST['courseid']);
    $CourseTeacher->setTeacher($_POST['teacherid']);
    $CourseTeacher->setSession($_POST['session']);
    $CourseTeacher->setYear($_POST['yearid']);
    $CourseTeacher->setTerm($_POST['termid']);
    
    $_CourseTeacherBAO->createCourseTeacher($CourseTeacher);
     
}


/* deleting an existing Course */
if(isset($_GET['del']))
{

    $CourseTeacher = new CourseTeacher(); 
    $CourseTeacher->setID($_GET['del']);   
    $_CourseTeacherBAO->deleteCourseTeacher($CourseTeacher); //reading the Course object from the result object

    header("Location:".PageUtil::$COURSE_TEACHER);
}


/* reading an existing Course information */
if(isset($_GET['edit']))
{
    $CourseTeacher = new CourseTeacher(); 
    $CourseTeacher->setID($_GET['edit']);  
    $getROW = $_CourseTeacherBAO->readCourseTeacher($CourseTeacher)->getResultObject(); //reading the Course object from the result object

}

/*updating an existing Course information*/
if(isset($_POST['update']))
{
    $CourseTeacher = new CourseTeacher(); 
    $CourseTeacher->setID ($_GET['edit']);
    $CourseTeacher->setCourse($_POST['courseid']);
    $CourseTeacher->setTeacher($_POST['teacherid']);
    $CourseTeacher->setSession($_POST['session']);
    $CourseTeacher->setYear($_POST['yearid']);
    $CourseTeacher->setTerm($_POST['termid']);
    
    $_CourseTeacherBAO->updateCourseTeacher($CourseTeacher);

    header("Location:".PageUtil::$COURSE_TEACHER);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.Course.inc");

?>