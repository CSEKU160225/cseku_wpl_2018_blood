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
    
    $User = new User();
    $StudentID = $_DB->secureInput($_POST['txtStudentID']);
    $StudentID = strtolower($StudentID);

    $Session = $_DB->secureInput($_POST['session']);

    $Year = $_DB->secureInput($_POST['year']);

    $Term = $_DB->secureInput($_POST['term']);
  
    $Result_Search_Course = $_CourseBAO->searchCoursesOfStudent($StudentID,$Session,$Year,$Term);

 
    if($Result_Search_Course->getIsSuccess())
        $_SESSION['Result_Search_Studentwise']=$Result_Search_Course;
    else
        $_SESSION['Result_Search_Studentwise']=NULL;
 }



////$_Log->log(LogUtil::$DEBUG," exit view.studentwise_registration.blade.inc");

?>