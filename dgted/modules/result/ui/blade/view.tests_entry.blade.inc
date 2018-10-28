<?php

include_once UTILITY.'class.util.inc';

include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules
include_once MODULES_RESULT.'bao/class.marks_entrybao.inc';//depenency with modules




$_MarksEntryBAO = new MarksEntryBAO();
$_CourseBAO = new CourseBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_CourseStudentRegistrationBAO = new CourseStudentRegistrationBAO();
$_UserBAO = new UserBAO();

$_DB = DBUtil::getInstance();

$globalUser =null;
$Result_Course_Students=null;
$Result_Course_Student_Tests=null;
$Result_Course_Teacher=null;

$globalUser = $_SESSION['globalUser'];



if(isset($_GET['update']))
{
  
    $CourseNo = $_DB->secureInput($_GET['course']);

    $TeacherID = $_DB->secureInput($_GET['teacher']);    
 
    $SessionID = $_DB->secureInput($_GET['session']);

    $YearID = $_DB->secureInput($_GET['year']);

    $TermID = $_DB->secureInput($_GET['term']);
  
    //read all registered students to this course
    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseNo,$SessionID,$YearID,$TermID);


    //read the class tests of the students for this course, session, year, term
    $Result_Course_Student_Tests = $_MarksEntryBAO->getCourseStudentTests($CourseNo,$SessionID,$YearID,
        $TermID,$Result_Course_Students->getResultObject());


    //read the course teacher row to get the no of tests
    $Result_Course_Teacher = $_MarksEntryBAO->readCourseTeacher($CourseNo,$TeacherID,$SessionID,$YearID,$TermID)->getResultObject();

   

    $Course = new Course();
    $Course->setCourseNo($CourseNo);
    $Course = $_CourseBAO->readCourseFromCourseNo($Course)->getResultObject();


    $Teacher = new User();
    $Teacher->setID($TeacherID);
    $Teacher = $_UserBAO->readUser($Teacher)->getResultObject();


    $Session = new RegistrationSession();
    $Session->setID($SessionID);
    $Session = $_RegistrationSessionBAO->readRegistrationSession($Session)->getResultObject();


    $Year = new Year();
    $Year->setID($YearID);
    $Year=$_YearBAO->readYear($Year)->getResultObject();


    $Term = new Term();
    $Term->setID($TermID);
    $Term=$_TermBAO->readTerm($Term)->getResultObject();

}


//tests marks update
if(isset($_POST['save_marks']))
{
    
    $StudentIDList=null;
    $CourseNo=null;
    $SessionID=null;
    $YearID=null;
    $TermID=null;
    $NoOfTests=null;
    $TeacherID = $globalUser->getID(); 


    if(isset($_POST['hidden_all_students']))
        $StudentIDList = explode(",", $_POST['hidden_all_students']);

    if(isset($_POST['hiddenCourseNo']))
        $CourseNo = $_POST['hiddenCourseNo'];

    if(isset($_POST['hiddenSession']))
        $SessionID = $_POST['hiddenSession'];

    if(isset($_POST['hiddenYear']))
        $YearID = $_POST['hiddenYear'];

    if(isset($_POST['hiddenTerm']))
        $TermID = $_POST['hiddenTerm'];

   if(isset($_POST['hidden_no_of_tests']))
        $NoOfTests = $_POST['hidden_no_of_tests'];

    

   $MarksEntryList = array();

   for ($i=0; $i < sizeof($StudentIDList) ; $i++) { 
       
       $StudentID= $StudentIDList[$i];
       
       $MarksList = array();

       $j=0;
       foreach ($_POST[$StudentID] as $input) {
            
            if($j>=1 && $j<=$NoOfTests) //avoiding first id
            {
               $MarksList[]=$input;
            }   
         $j++;   
       }
        

       if(isset($MarksList))
            $MarksValue = implode(",", $MarksList);

        $MarksEntry  = new MarksEntry();
        
        $MarksEntry->setCourse ( $CourseNo);        

        $MarksEntry->setSession ( $SessionID);

        $MarksEntry->setYear ( $YearID);         

        $MarksEntry->setTerm ( $TermID); 

        $MarksEntry->setTeacher($TeacherID);

        $MarksEntry->setStudent ( $StudentID);   

        $MarksEntry->setMarksValue( $MarksValue);

        $MarksEntryList[] = $MarksEntry;

        
   }

   //update the tests entry in to the database for this course, session, year and term

    $Result_Marks_Entry = $_MarksEntryBAO->updateCourseAllTestsEntry($MarksEntryList);

    //*****reload the UI********

 //read all registered students to this course
    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseNo,$SessionID,$YearID,$TermID);


    //read the class tests of the students for this course, session, year, term
    $Result_Course_Student_Tests = $_MarksEntryBAO->getCourseStudentTests($CourseNo,$SessionID,$YearID,
        $TermID,$Result_Course_Students->getResultObject());


    //read the course teacher row to get the no of tests
    $Result_Course_Teacher = $_MarksEntryBAO->readCourseTeacher($CourseNo,$TeacherID,$SessionID,$YearID,
        $TermID)->getResultObject();

   

    $Course = new Course();
    $Course->setCourseNo($CourseNo);
    $Course = $_CourseBAO->readCourseFromCourseNo($Course)->getResultObject();


    $Teacher = new User();
    $Teacher->setID($TeacherID);
    $Teacher = $_UserBAO->readUser($Teacher)->getResultObject();


    $Session = new RegistrationSession();
    $Session->setID($SessionID);
    $Session = $_RegistrationSessionBAO->readRegistrationSession($Session)->getResultObject();


    $Year = new Year();
    $Year->setID($YearID);
    $Year=$_YearBAO->readYear($Year)->getResultObject();


    $Term = new Term();
    $Term->setID($TermID);
    $Term=$_TermBAO->readTerm($Term)->getResultObject();


 }


//publish marks to the final result database
if(isset($_POST['publish_marks']))
{
    
    $HeaderIDList=null;
    $HeaderNameList=null;
    $HeaderMaxList=null;
    $MarksTotal=null;
    
    $GradeList=null;
    $GradeRangesList=null;
    $FinalGrade=null;

    $MarksID=null;
    $StudentIDList=null;

    $CourseNo=null;
    $Session=null;
    $Year=null;
    $Term=null;

    $MarksEntryList=null;

    if(isset($_POST['all_header_id']))
        $HeaderIDList = explode(",", $_POST['all_header_id']);
    if(isset($_POST['all_header_name']))
        $HeaderNameList = explode(",", $_POST['all_header_name']);
    if(isset($_POST['all_header_max']))
        $HeaderMaxList = explode(",", $_POST['all_header_max']);

    if(isset($_POST['all_grades']))
        $GradeList = explode(",", $_POST['all_grades']);
    if(isset($_POST['all_grade_ranges']))
        $GradeRangesList = explode(",", $_POST['all_grade_ranges']);


    if(isset($_POST['marks_id']))
        $MarksID = $_POST['marks_id'];

    if(isset($_POST['all_students']))
        $StudentIDList = explode(",", $_POST['all_students']);


    if(isset($_POST['txtCourseNo']))
        $CourseNo = $_POST['txtCourseNo'];

    if(isset($_POST['session']))
        $Session = $_POST['session'];

    if(isset($_POST['year']))
        $Year = $_POST['year'];

    if(isset($_POST['term']))
        $Term = $_POST['term'];

   $MarksEntryList = array();

   for ($i=0; $i < sizeof($StudentIDList) ; $i++) { 
       
       $StudentID= $StudentIDList[$i];
       
       $MarksList = array();

       $j=0;
       foreach ($_POST[$StudentID] as $input) {
            
            if($j==(sizeof($HeaderIDList)+1))
                $MarksTotal=$input;
            else if($j==(sizeof($HeaderIDList)+2))
                $FinalGrade=$input;
            else if($j>=1 && $j<=sizeof($HeaderIDList)) //avoiding first id and last total and grade
            {
               $MarksList[]=$input;
            }   
         $j++;   
       }
        

       if(isset($MarksList)){
            $MarksValue = implode(",", $MarksList);
            $MarksTotal = array_sum(array_map('intval',$MarksList));
       }

        $MarksEntry  = new MarksEntry();
       
  
        $MarksEntry->setCourse ( $CourseNo);        

        $MarksEntry->setSession ( $Session);

        $MarksEntry->setYear ( $Year);         

        $MarksEntry->setTerm ( $Term); 

        $MarksEntry->setStudent ( $StudentID);   

        $MarksEntry->setMarksValue( $MarksValue);

        $MarksEntry->setMarksTotal( $MarksTotal);

        $MarksEntry->setHeaderID( implode(",", $HeaderIDList) );

        $MarksEntry->setHeaderName( implode(",", $HeaderNameList) );

        $MarksEntry->setHeaderMax( implode(",", $HeaderMaxList) );

        $MarksEntry->setGrades( implode(",", $GradeList) );

        $MarksEntry->setGradeRanges( implode(",", $GradeRangesList));

        $MarksEntry->setFinalGrade( $FinalGrade );

        $MarksEntryList[] = $MarksEntry;

        
   }

   //update the marks entry in to the database for this course, session, year and term

    $Result_Marks_Entry = $_MarksEntryBAO->publishCourseAllMarksEntry($MarksEntryList);

    //*****reload the UI********

     //read all registered students to this course
    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseNo,$Session,$Year,$Term);

    //read the marks of the students for this course, session, year, term
    $Result_Course_Student_Marks = $_MarksEntryBAO->getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$Result_Course_Students->getResultObject());

    //read the marks setup for this course
    $Result_Marks_Setup = $_MarksEntryBAO->getCourseMarksSetup($CourseNo);   

   //read default grade
    $Result_Grade_Setup = $_GradeSetupBAO->readDefaultGradeSetup();

 }


//delete marks for a course registered on a session, year and term
if(isset($_POST['delete_marks']))
{
    
    $HeaderIDList=null;
    $MarksID=null;
    $StudentIDList=null;
    $CourseNo=null;
    $Session=null;
    $Year=null;
    $Term=null;


    if(isset($_POST['all_header_id']))
        $HeaderIDList = explode(",", $_POST['all_header_id']);

    if(isset($_POST['marks_id']))
        $MarksID = $_POST['marks_id'];

    if(isset($_POST['all_students']))
        $StudentIDList = explode(",", $_POST['all_students']);

    if(isset($_POST['txtCourseNo']))
        $CourseNo = $_POST['txtCourseNo'];

    if(isset($_POST['session']))
        $Session = $_POST['session'];

    if(isset($_POST['year']))
        $Year = $_POST['year'];

    if(isset($_POST['term']))
        $Term = $_POST['term'];

   $MarksEntryList = array();

   for ($i=0; $i < sizeof($StudentIDList) ; $i++) { 
       
       $StudentID= $StudentIDList[$i];
       
        $MarksEntry  = new MarksEntry();
       
  
        $MarksEntry->setCourse ( $CourseNo);        

        $MarksEntry->setSession ( $Session);

        $MarksEntry->setYear ( $Year);         

        $MarksEntry->setTerm ( $Term); 

        $MarksEntry->setStudent ( $StudentID);   

        $MarksEntry->setMarksID( $MarksID);

        $MarksEntryList[] = $MarksEntry;
        
   }

   //delete all the marks entry in to the database for this course, session, year and term

    $Result_Marks_Entry = $_MarksEntryBAO->deleteCourseAllMarksEntry($MarksEntryList);

    //*****reload the UI********

     //read all registered students to this course
    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseNo,$Session,$Year,$Term);

    //read the marks of the students for this course, session, year, term
    $Result_Course_Student_Marks = $_MarksEntryBAO->getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$Result_Course_Students->getResultObject());

    //read the marks setup for this course
    $Result_Marks_Setup = $_MarksEntryBAO->getCourseMarksSetup($CourseNo);   

   //read default grade
    $Result_Grade_Setup = $_GradeSetupBAO->readDefaultGradeSetup();

 }


////$_Log->log(LogUtil::$DEBUG," exit view.marks_entry.blade.inc");

?>