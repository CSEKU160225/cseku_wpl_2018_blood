<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';


$_CourseBAO = new CourseBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();

$_DB = DBUtil::getInstance();

$globalUser ='';
$Result_Search_Course='';

$globalUser = $_SESSION['globalUser'];

if(isset($_POST['search']))
{
    
    $Course = new Course();
    $CourseNo = $_DB->secureInput($_POST['txtCourseNo']);
    $CourseNo = strtolower($CourseNo);

    $Session = $_DB->secureInput($_POST['session']);

    $Year = $_DB->secureInput($_POST['year']);

    $Term = $_DB->secureInput($_POST['term']);
  
    $Result_Search_Course = $_CourseBAO->searchAllStudents($CourseNo,$Session,$Year,$Term);

 
    if($Result_Search_Course->getIsSuccess())
        $_SESSION['Result_Search_Coursewise']=$Result_Search_Course;
    else
        $_SESSION['Result_Search_Coursewise']=NULL;
 }



////$_Log->log(LogUtil::$DEBUG," exit view.coursewise_registration.blade.inc");

?>