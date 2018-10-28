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

$Result_Search_Course=null;

$globalUser =null;
$Print_Student=null;
$Print_Session=null;
$Print_Year=null;
$Print_Term=null;

$globalUser = $_SESSION['globalUser'];


if(isset($_GET['print']))
{
    
    $StudentID =  $globalUser->getUniversityID(); //getting current logged students university id

    $Session = $_DB->secureInput($_GET['session']);

    $Year = $_DB->secureInput($_GET['year']);

    $Term = $_DB->secureInput($_GET['term']);
 
    $Result_Search_Course = $_CourseBAO->searchCoursesOfStudent($StudentID,$Session,$Year,$Term);

 
    if($Result_Search_Course->getIsSuccess()){
  
         
        $Print_Student=$globalUser;

        $Print_Session = new RegistrationSession();
        $Print_Session->setID($Session);
        $Print_Session = $_RegistrationSessionBAO->
                                            readRegistrationSession($Print_Session)->getResultObject();

        $Print_Year = new Year();
        $Print_Year->setID($Year);
        $Print_Year = $_YearBAO->readYear($Print_Year)->getResultObject();

        $Print_Term = new Term();
        $Print_Term->setID($Term);
        $Print_Term = $_TermBAO->readTerm($Print_Term)->getResultObject();

    }
}
   ////$_Log->log(LogUtil::$DEBUG," exit view.print_registration.blade.inc");

?>