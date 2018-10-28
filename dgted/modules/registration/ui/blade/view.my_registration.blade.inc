<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_RESULT.'bao/class.marks_entrybao.inc';


$_CourseBAO = new CourseBAO();
$_MarksEntryBAO = new MarksEntryBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();

$_DB = DBUtil::getInstance();

$globalUser ='';
$Result_Search_Course=null;
$Result_Student_Marks=null;
$Result_Student_Tests=null;

$Print_Student=null;
$Print_Session=null;
$Print_Year=null;
$Print_Term=null;

$globalUser = $_SESSION['globalUser'];


if(isset($_POST['my_registration']))
{
    
    $StudentID =  $globalUser->getUniversityID(); //getting current logged students university id
 
    $Session = $_DB->secureInput($_POST['session']);

    $Year = $_DB->secureInput($_POST['year']);

    $Term = $_DB->secureInput($_POST['term']);
  
    $Result_Search_Course = $_CourseBAO->
                            searchCoursesOfStudent_Status($StudentID,$Session,$Year,$Term,'registered');

 
    if($Result_Search_Course->getIsSuccess()){
        
        $_SESSION['Result_Search_Course']=$Result_Search_Course;
        
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
    else
        $_SESSION['Result_Search_Course']=NULL;

}

//get marks of the student for a course
if(isset($_GET['course']) && isset($_GET['marks']) && $_GET['marks']="true")
{
	$CourseID = $_GET['course'];
 
    $StudentID =  $globalUser->getUniversityID(); //getting current logged students university id
 
    $Session = $_DB->secureInput($_GET['session']);

    $Year = $_DB->secureInput($_GET['year']);

    $Term = $_DB->secureInput($_GET['term']);
 
	$Result_Student_Marks = $_MarksEntryBAO->
						getAStudentCoursePublishedMarks($CourseID,$Session,$Year,$Term,$StudentID);

    $Course = new Course();
    $Course->setID($CourseID);
    $Course = $_CourseBAO->readCourse($Course)->getResultObject();


    if($Result_Student_Marks->getIsSuccess())
        $_SESSION['Result_Student_Marks']=$Result_Student_Marks;
    else
        $_SESSION['Result_Student_Marks']=NULL;

}


//get tests marks of the student for a course
if(isset($_GET['course']) && isset($_GET['tests']) && $_GET['tests']="true")
{
    $CourseID = $_GET['course'];
 
    $StudentID =  $globalUser->getUniversityID(); //getting current logged students university id
 
    $Session = $_DB->secureInput($_GET['session']);

    $Year = $_DB->secureInput($_GET['year']);

    $Term = $_DB->secureInput($_GET['term']);
 
    $Result_Student_Tests = $_MarksEntryBAO->
                        getAStudentCourseTestMarks($CourseID,$Session,$Year,$Term,$StudentID);


    $Course = new Course();
    $Course->setID($CourseID);
    $Course = $_CourseBAO->readCourse($Course)->getResultObject();


    if($Result_Student_Tests->getIsSuccess())
        $_SESSION['Result_Student_Tests']=$Result_Student_Tests;
    else
        $_SESSION['Result_Student_Tests']=NULL;

}
////$_Log->log(LogUtil::$DEBUG," exit view.marks_entry.blade.inc");

?>