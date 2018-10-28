<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacher_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacherbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //depenency with modules
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules


$_CourseTeacherRegistrationBAO = new CourseTeacherRegistrationBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_CourseTypeBAO = new CourseTypeBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_UserBAO = new UserBAO();
$_CourseTeacherBAO = new CourseTeacherBAO();
$_DB = DBUtil::getInstance();


if(isset($_POST['save']))
{

    $CourseTeacherRegistration = new CourseTeacherRegistration();
    $CourseTeacherRegistration->setID(Util::getGUID());
    
    
    $CourseTeacherRegistration->setTeacherID($_POST['teacherid']);
    $CourseTeacherRegistration->setSessionID($_POST['session']);
    $CourseTeacherRegistration->setYearID($_POST['yearid']);
    $CourseTeacherRegistration->setTermID($_POST['termid']);
    
    $_CourseTeacherRegistrationBAO->createCourseTeacherRegistration($CourseTeacherRegistration);
     
}


/* deleting an existing Course */
if(isset($_GET['del']))
{

    $CourseTeacherRegistration = new CourseTeacherRegistration(); 
    $CourseTeacherRegistration->setID($_GET['del']);   
    $_CourseTeacherRegistrationBAO->deleteCourseTeacherRegistration($CourseTeacherRegistration); //reading the Course object from the result object

    header("Location:".PageUtil::$COURSE_TEACHER_REGISTRATION);
}


/* reading an existing Course information */
if(isset($_GET['edit']))
{
    $CourseTeacherRegistration = new CourseTeacherRegistration(); 
    $CourseTeacherRegistration->setID($_GET['edit']);  
    $getROW = $_CourseTeacherRegistrationBAO->readCourseTeacherRegistration($CourseTeacherRegistration)->getResultObject(); //reading the Course object from the result object

}

/*updating an existing Course information*/
if(isset($_POST['update']))
{
    $CourseTeacherRegistration = new CourseTeacherRegistration(); 
    $CourseTeacherRegistration->setID ($_GET['edit']);
    
    $CourseTeacherRegistration->setTeacherID($_POST['teacherid']);
    $CourseTeacherRegistration->setSessionID($_POST['session']);
    $CourseTeacherRegistration->setYearID($_POST['yearid']);
    $CourseTeacherRegistration->setTermID($_POST['termid']);
    
    $_CourseTeacherRegistrationBAO->updateCourseTeacherRegistration($CourseTeacherRegistration);

    header("Location:".PageUtil::$COURSE_TEACHER_REGISTRATION);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.Course.inc");

?>