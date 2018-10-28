<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacherbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //depenency with modules
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules

$_CourseBAO = new CourseBAO();
$_CourseTeacherBAO = new CourseTeacherBAO();
$_UserBAO = new UserBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_CourseStudentRegistrationBAO = new CourseStudentRegistrationBAO();

$_DB = DBUtil::getInstance();

$globalUser =null;
$Result_Search_Course=null;
$Result_Course_Cart=null;
$Result_Confirm_Reg=null;

$globalUser = $_SESSION['globalUser'];

if(isset($_POST['search']))
{
    
    $CourseNo = $_DB->secureInput($_POST['txtCourseNo']);
  
    $Result_Search_Course = $_CourseBAO->searchAllCourses($CourseNo);

 
    if($Result_Search_Course->getIsSuccess())
        $_SESSION['Result_Search_Course']=$Result_Search_Course;
    else
        $_SESSION['Result_Search_Course']=null;
 }

if(isset($_GET['add'])) //adding to the cart
{

    $CourseStudentRegistration = new CourseStudentRegistration();
    
    $CourseStudentRegistration->setID(Util::getGUID());

      
    $Course = new Course();
    $Course->setID($_GET['add']);
    $CourseStudentRegistration->setCourse($Course);

    $Student = new User();
    $Student->setID($globalUser->getID());
    $CourseStudentRegistration->setStudent($Student);
    
 
    $CourseStudentRegistration->setStatus('pending');
    
    //adding the cart in the database
    $Result_Course_Cart = $_CourseStudentRegistrationBAO->
                        addCourseToStudentCart($CourseStudentRegistration);

                        
}

/* removing registration from the cart */
if(isset($_GET['remove'])&&strcasecmp($_GET['remove'], 'true')==0)
{

    $CourseStudentRegistration = new CourseStudentRegistration(); 
    $CourseStudentRegistration->setID($_GET['id']);   
    $_CourseStudentRegistrationBAO->deleteCourseStudentRegistration($CourseStudentRegistration); 

    //header("Location:".$_SESSION['previousPage']);
}

/* approving a course registration */
if(isset($_GET['approve'])&&strcasecmp($_GET['approve'], 'true')==0)
{

    $CourseStudentRegistration = new CourseStudentRegistration(); 
    $CourseStudentRegistration->setID($_GET['id']); 
    $CourseStudentRegistration->setStatus('approved'); 

    $_CourseStudentRegistrationBAO
    ->updateCourseStudentRegistration_Status($CourseStudentRegistration); 

    header("Location:".$_SESSION['previousPage']);

}

/* rejecting a course registration */
if(isset($_GET['reject'])&&strcasecmp($_GET['reject'], 'true')==0)
{

    $CourseStudentRegistration = new CourseStudentRegistration(); 
    $CourseStudentRegistration->setID($_GET['id']); 
    $CourseStudentRegistration->setStatus('rejected'); 

    $_CourseStudentRegistrationBAO
    ->updateCourseStudentRegistration_Status($CourseStudentRegistration); 

    header("Location:".$_SESSION['previousPage']);

}

//approval request is submitted
if(isset($_POST['approval_request']))
{

    $CourseStudentRegistration = new CourseStudentRegistration();
    
    $CourseStudentRegistration->setID(Util::getGUID());

    $Teacher = new User();
    $Teacher->setID($_POST['coordinator']);
    $Teacher = $_UserBAO->readUser($Teacher)->getResultObject();
    $CourseStudentRegistration->setTeacher($Teacher);
 
    $Student = $globalUser;
    $CourseStudentRegistration->setStudent($Student);
    
    $Session = new Session();
    $Session->setID($_POST['session']);
    $Session=$_RegistrationSessionBAO->readRegistrationSession($Session)->getResultObject();
    $CourseStudentRegistration->setSession($Session);

    $Year = new Year();
    $Year->setID($_POST['year']);
    $Year = $_YearBAO->readYear($Year)->getResultObject();
    $CourseStudentRegistration->setYear($Year);

    $Term = new Term();
    $Term->setID($_POST['term']);
    $Term = $_TermBAO->readTerm($Term)->getResultObject();
    $CourseStudentRegistration->setTerm($Term);

    $CourseStudentRegistration->setStatus('submitted');
    
    //adding the cart in the database
    $_CourseStudentRegistrationBAO->submitStudentRegistration($CourseStudentRegistration);

    header("Location:".PageUtil::$COURSE_STUDENT_REGISTRATION);

}

//confirm registration is submitted
if(isset($_POST['confirm_registration']))
{

    $CourseStudentRegistration = new CourseStudentRegistration();


    $Teacher = new User();
    $Teacher->setID($_POST['coordinator']);
    $CourseStudentRegistration->setTeacher($Teacher);
 
    $Student = new User();
    $Student->setID($globalUser->getID());
    $CourseStudentRegistration->setStudent($Student);
    
    $Session = new Session();
    $Session->setID($_POST['session']);
    $CourseStudentRegistration->setSession($Session);

    $Year = new Year();
    $Year->setID($_POST['year']);
    $CourseStudentRegistration->setYear($Year);

    $Term = new Term();
    $Term->setID($_POST['term']);
    $CourseStudentRegistration->setTerm($Term);

    $CourseStudentRegistration->setStatus('registered');
    
    //updating final registartion status

    $Result_Confirm_Reg = $_CourseStudentRegistrationBAO
    ->updateCourseStudentRegistration_Status2($CourseStudentRegistration,'approved'); 

    header("Location:".PageUtil::$COURSE_STUDENT_REGISTRATION);

}


////$_Log->log(LogUtil::$DEBUG," exit view.course_student_registration.blade.inc");

?>