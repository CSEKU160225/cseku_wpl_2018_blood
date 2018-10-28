<?php

include_once UTILITY.'class.util.inc';
//depenency with modules
include_once MODULES_RESULT.'bao/class.marks_entrybao.inc';
include_once MODULES_RESULT.'bao/class.grade_setupbao.inc';

include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //depenency with modules
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules

$_GradeSetupBAO = new GradeSetupBAO();
$_MarksEntryBAO = new MarksEntryBAO();
$_CourseBAO = new CourseBAO();
$_UserBAO = new UserBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_CourseStudentRegistrationBAO = new CourseStudentRegistrationBAO();

$_DB = DBUtil::getInstance();

$globalUser =null;
$Result_Course_Students=null;
$Result_Marks_Setup=null;
$Result_Course_Student_Marks=null;
$Result_Grade_Setup=null;

$globalUser = $_SESSION['globalUser'];



if(isset($_POST['load_marks']))
{
  
    $Course = new Course();
    $CourseNo = $_DB->secureInput($_POST['txtCourseNo']);
    $CourseNo = strtolower($CourseNo);

    $Session = $_DB->secureInput($_POST['session']);

    $Year = $_DB->secureInput($_POST['year']);

    $Term = $_DB->secureInput($_POST['term']);
  
    //read all registered students to this course
    $Result_Course_Students = $_CourseBAO->searchAllStudents($CourseNo,$Session,$Year,$Term);

    //read the marks of the students for this course, session, year, term
    $Result_Course_Student_Marks = $_MarksEntryBAO->getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$Result_Course_Students->getResultObject());

    //read the marks setup for this course
    $Result_Marks_Setup = $_MarksEntryBAO->getCourseMarksSetup($CourseNo);

    //read default grade
    $Result_Grade_Setup = $_GradeSetupBAO->readDefaultGradeSetup();


  
}


//marks update
if(isset($_POST['save_marks']))
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
       
       $MarksList = array();

       $j=0;
       foreach ($_POST[$StudentID] as $input) {
            
            if($j>=1 && $j<=sizeof($HeaderIDList)) //avoiding first id and last total and grade
            {
               $MarksList[]=$input;
            }   
         $j++;   
       }
        

       if(isset($MarksList))
            $MarksValue = implode(",", $MarksList);

        $MarksEntry  = new MarksEntry();
       
  
        $MarksEntry->setCourse ( $CourseNo);        

        $MarksEntry->setSession ( $Session);

        $MarksEntry->setYear ( $Year);         

        $MarksEntry->setTerm ( $Term); 

        $MarksEntry->setTeacher($globalUser->getID());

        $MarksEntry->setStudent ( $StudentID);   

        $MarksEntry->setMarksID( $MarksID);

        $MarksEntry->setMarksValue( $MarksValue);

        $MarksEntry->setStatus(null);

        $MarksEntryList[] = $MarksEntry;

        
   }

   //update the marks entry in to the database for this course, session, year and term

    $Result_Marks_Entry = $_MarksEntryBAO->updateCourseAllMarksEntry($MarksEntryList);

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