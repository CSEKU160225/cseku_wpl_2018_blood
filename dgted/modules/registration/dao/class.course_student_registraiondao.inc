<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.coursedao.inc';
include_once 'class.registration_sessiondao.inc';
include_once 'class.termdao.inc';
include_once MODULES_USER.'dao/class.userdao.inc'; //module dependecy

/*
Course registration flow and states

pending, submitted, approved, rejected, registered, passed, failed

pending -> submitted -> approved/rejected
approved -> registered
registered -> passed/failed

*/

Class CourseStudentRegistrationDAO{

	private $_DB;
	private $_CourseStudentRegistration;
	private $_CourseDAO;
	private $_UserDAO;
	private $_RegistrationSessionDAO;
	private $_YearDAO;
	private $_TermDAO;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CourseStudentRegistration = new CourseStudentRegistration();
		$this->_CourseDAO = new CourseDAO();
		$this->_UserDAO = new UserDAO();
		$this->_RegistrationSessionDAO = new RegistrationSessionDAO();
		$this->_YearDAO = new YearDAO();
		$this->_TermDAO = new TermDAO();
	}

	// get all the Courses from the database using the database query
	public function getAllCourseStudentRegistrations(){

		$CourseStudentRegistrationList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course_student_registration");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			//echo '<br>'.$row['ID']." ".$row['CourseID'];
			$this->_CourseStudentRegistration = new CourseStudentRegistration();
			$this->_CourseStudentRegistration->setID($row['ID']);
			
			
		    
			$User = new User();
			$User->setID($row['StudentID']);
			$Result_Student = $this->_UserDAO->readUser($User)->getResultObject();
			$this->_CourseStudentRegistration->setStudent($Result_Student);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
								readRegistrationSession($Session)->getResultObject();
		    $this->_CourseStudentRegistration->setSession($Result_Session);

		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseStudentRegistration->setYear($Result_year);

		    
		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseStudentRegistration->setTerm($Result_term);
		    
		    
		    $CourseStudentRegistrationList[]=$this->_CourseStudentRegistration;
  
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		return $Result;
	}

	//add course as a cart to a student. this means registration is not completed yet
	public function addCourseToStudentCart($CourseStudentRegistration){

		$ID=$CourseStudentRegistration->getID();
		
		$StudentID=$CourseStudentRegistration->getStudent()->getID();
		$CourseID=$CourseStudentRegistration->getCourse()->getID();		
		$Status=$CourseStudentRegistration->getStatus();
		
		$SQL = "Select * from reg_course_student_registration where StudentID='$StudentID' AND 
			CourseID='$CourseID' LIMIT 1";

		$SQL = $this->_DB->doQuery($SQL);		

		if($this->_DB->getNumRows()==0){
		
			$SQL = "INSERT INTO reg_course_student_registration(ID, StudentID, CourseID, Status) VALUES ('$ID','$StudentID','$CourseID','$Status')";
			
			$SQL = $this->_DB->doQuery($SQL);		
			
		 	$Result = new Result();
			$Result->setIsSuccess(1);
			$msg = '<label style="color:green"><strong>Course Added to the Cart!</strong></label>';

			$Result->setResultObject($msg);

		}
		else //duplication registration
		{
		 	$Result = new Result();
			$Result->setIsSuccess(0);

			$row = $this->_DB->getTopRow();
			$status=$row['Status'];
			$msg = '<label style="color:red"><strong>Course already added. Current status is: '.strtoupper($status).'</strong></label>';

			$Result->setResultObject($msg);			
		}

		return $Result;
	}

	//read an Course object based on its id form Course object
	public function readCourseStudentRegistration($CourseStudentRegistration){
		
		
		$SQL = "SELECT * FROM reg_course_student_registration WHERE ID='".$CourseStudentRegistration->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Course from the database
		$row = $this->_DB->getTopRow();

		$this->_CourseStudentRegistration = new CourseStudentRegistration();

		//preparing the Course object
			$this->_CourseStudentRegistration->setID($row['ID']);
		    
		    $this->_CourseStudentRegistration->setStudentID($row['StudentID']);
		    $this->_CourseStudentRegistration->setSessionID($row['SessionID']);
		    $this->_CourseStudentRegistration->setYearID($row['YearID']);
		    $this->_CourseStudentRegistration->setTermID($row['TermID']);
		    ///echo '<br>'. $row['CourseID'] . $row['StudentID'] . $row['SessionID'] . $row['TermID'];


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseStudentRegistration);

		return $Result;
	}

	//search all the courses in specific session, year, term that are offered for registration
	public function searchCourseToRegister($CourseStudentRegistration){
		
		
		$CourseStudentRegistrationList = array();

		$SQL = "SELECT * ".
			   " FROM reg_course_teacher ct ".
			   " Where ". 
			   " ct.SessionID='".$CourseStudentRegistration->getSession()->getID()."' AND ".
			   " ct.YearID='".$CourseStudentRegistration->getYear()->getID()."' AND ".
			   " ct.TermID='".$CourseStudentRegistration->getTerm()->getID()."'";


		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			//echo '<br>'.$row['ID']." ".$row['CourseID'];
			$this->_CourseStudentRegistration = new CourseStudentRegistration();
		    
			$Course = new Course();
			$Course->setID($row['CourseID']);
			$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
			$this->_CourseStudentRegistration->setCourse($Result_course);

			$Teacher = new User();
			$Teacher->setID($row['TeacherID']);
			$Result_Teacher = $this->_UserDAO->readUser($Teacher)->getResultObject();
			$this->_CourseStudentRegistration->setTeacher($Result_Teacher);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
								readRegistrationSession($Session)->getResultObject();
		    $this->_CourseStudentRegistration->setSession($Result_Session);

		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseStudentRegistration->setYear($Result_year);

		    
		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseStudentRegistration->setTerm($Result_term);
		    
		    
		    $CourseStudentRegistrationList[]=$this->_CourseStudentRegistration;
  
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		return $Result;
	}

	//search all the courses a student has sent registration request
	public function searchRegistrationCart($CourseStudentRegistration){
		
		
		$CourseStudentRegistrationList = array();
		$StudentID = $CourseStudentRegistration->getStudent()->getID();

		$Status = $CourseStudentRegistration->getStatus();
		
		//building the status list for the query
		$Status_list = explode(",",$Status);		
		$Status = '';
		for($i = 0; $i < sizeof($Status_list); $i++) {
			$Status = $Status .'\''. $Status_list[$i].'\',';
		}
		$Status = rtrim($Status,',');


		$SQL = "SELECT * ".
			   " FROM reg_course_student_registration csr ".
			   " Where ". 
			   " csr.StudentID='$StudentID' AND ".
			   " csr.Status in ($Status)";
 
		
	

		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];

			$this->_CourseStudentRegistration = new CourseStudentRegistration();

			$this->_CourseStudentRegistration->setID($row['ID']);

			$Teacher = new User();
			$Teacher->setID($row['Regs_TeacherID']);
			$Result_Teacher = $this->_UserDAO->readUser($Teacher)->getResultObject();
			$this->_CourseStudentRegistration->setTeacher($Result_Teacher);

		    
			$Course = new Course();
			$Course->setID($row['CourseID']);
			$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
			$this->_CourseStudentRegistration->setCourse($Result_course);

			$Student = new User();
			$Student->setID($row['StudentID']);
			$Result_Student = $this->_UserDAO->readUser($Student)->getResultObject();
			$this->_CourseStudentRegistration->setStudent($Result_Student);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
			 					readRegistrationSession($Session)->getResultObject();
		     $this->_CourseStudentRegistration->setSession($Result_Session);

		     $Year = new Year();
		     $Year->setID($row['YearID']);
			 $Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		     $this->_CourseStudentRegistration->setYear($Result_year);

		    
		     $Term = new Term();
		     $Term->setID($row['TermID']);
			 $Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		     $this->_CourseStudentRegistration->setTerm($Result_term);

		     $this->_CourseStudentRegistration->setStatus($row['Status']);
		    
		    
		    $CourseStudentRegistrationList[]=$this->_CourseStudentRegistration;
  
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		return $Result;
	}



	//search all the students submitted registration requests to a coordinator of a particaluar
	//status (e.g. pending, submitted, approved, rejected)
	public function searchRegistrationRequest($Coordinator,$Status){
		
		
		$CourseStudentRegistrationList = array();
		$CoordinatorID = $Coordinator->getID();

		$SQL = "SELECT DISTINCT u.UniversityID, u.ID as StudentID 
			    FROM reg_course_student_registration csr, ums_user u 
			    Where csr.StudentID=u.ID AND
			    csr.Regs_TeacherID='$CoordinatorID' AND 
			    csr.Status= '$Status' order by (u.UniversityID * 1) ASC";

			   
		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];

			$this->_CourseStudentRegistration = new CourseStudentRegistration();

			$Student = new User();
			$Student->setID($row['StudentID']);
			$Result_Student = $this->_UserDAO->readUser($Student)->getResultObject();
			$this->_CourseStudentRegistration->setStudent($Result_Student);
		    
		    
		    $CourseStudentRegistrationList[]=$this->_CourseStudentRegistration;
  
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		return $Result;
	}


	//update an Course object based on its 
	public function submitStudentRegistration($CourseStudentRegistration){

		$CoordinatorID = $CourseStudentRegistration->getTeacher()->getID();
		$SessionID=$CourseStudentRegistration->getSession()->getID();
		$YearID=$CourseStudentRegistration->getYear()->getID();
		$TermID=$CourseStudentRegistration->getTerm()->getID();
		$StudentID=$CourseStudentRegistration->getStudent()->getID();
		$Status=$CourseStudentRegistration->getStatus();


		$SQL = "UPDATE reg_course_student_registration ". 
		"SET Regs_TeacherID='$CoordinatorID',SessionID='$SessionID',YearID='$YearID',
		TermID='$TermID',Status='$Status' WHERE StudentID='$StudentID' AND Status='pending'";


		$row = $this->_DB->doQuery($SQL);

		if($this->_DB->checkUpdateSuccess()){
		 	$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject('<label style="color:green"><strong>Approval request submitted!</strong></label>');

			//email to teacher about approval request
			$this->send_email_to_teacher_for_registration_approval($CourseStudentRegistration);
		}
			
		return $Result;

	}

	private function send_email_to_teacher_for_registration_approval($CourseStudentRegistration){

		$teacher = $CourseStudentRegistration->getTeacher();
		$student = $CourseStudentRegistration->getStudent();
		$session = $CourseStudentRegistration->getSession();

		$subject = 'Registration approval request submitted';
		$msg = $student->getFullName().' ('. $student->getUniversityID() .') submitted registration approval request for session:'.$session->getName();
		$headers = 'From: kucse@dgted.com';

		mail($teacher->getEmail(),$subject,$msg,$headers);

	
	}

	//delete an added course from the database cart
	public function deleteCourseStudentRegistration($CourseStudentRegistration){


		$SQL = "DELETE from reg_course_student_registration where ID ='".$CourseStudentRegistration->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//update registration status of a course for a student
	public function updateCourseStudentRegistration_Status($CourseStudentRegistration){

		$ID=$CourseStudentRegistration->getID();
		$Status=$CourseStudentRegistration->getStatus();

		$SQL = "UPDATE reg_course_student_registration SET Status='$Status' where ID ='$ID'";
	
		$SQL = $this->_DB->doQuery($SQL);


		$this->_DB->doQuery("SELECT * FROM reg_course_student_registration where ID='$ID' LIMIT 1");

		$row = $this->_DB->getTopRow();

		$this->_CourseStudentRegistration = new CourseStudentRegistration();
		$this->_CourseStudentRegistration->setID($row['ID']);
		
			
		    
		$User = new User();
		$User->setID($row['StudentID']);
		$Result_Student = $this->_UserDAO->readUser($User)->getResultObject();
		$this->_CourseStudentRegistration->setStudent($Result_Student);


		$Course = new Course();
		$Course->setID($row['CourseID']);
		$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
		$this->_CourseStudentRegistration->setCourse($Result_course);



		$Session = new RegistrationSession();
		$Session->setID($row['SessionID']);
		$Result_Session = $this->_RegistrationSessionDAO->
							readRegistrationSession($Session)->getResultObject();
	    $this->_CourseStudentRegistration->setSession($Result_Session);

	    $Year = new Year();
	    $Year->setID($row['YearID']);
		$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
	    $this->_CourseStudentRegistration->setYear($Result_year);

		    
	    $Term = new Term();
	    $Term->setID($row['TermID']);
		$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
	    $this->_CourseStudentRegistration->setTerm($Result_term);

	    $this->_CourseStudentRegistration->setStatus($row['Status']);


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseStudentRegistration);


		$this->send_email_to_student_for_registration_status($this->_CourseStudentRegistration);

		return $Result;

	}

	private function send_email_to_student_for_registration_status($CourseStudentRegistration){

		$course =  $CourseStudentRegistration->getCourse();
		$student = $CourseStudentRegistration->getStudent();
		$session = $CourseStudentRegistration->getSession();
		$status = $CourseStudentRegistration->getStatus();

		$subject = 'Course registration status updated';
		$msg = 'Registration request of course: '.$course->getTitle().' ('. $course->getCourseNo() 
				.') for session: '. $session->getName().' status : '.strtoupper($status);

		$msg = $msg. '. If approved then confirm your registration';
				
		$headers = 'From: kucse@dgted.com';

		mail($student->getEmail(),$subject,$msg,$headers);

	
	}

	//update registration status of a course for a student who has a particular status already
	// example: make approved status to registered
	public function updateCourseStudentRegistration_Status2($CourseStudentRegistration,$Prev_Status){

		$CoordinatorID = $CourseStudentRegistration->getTeacher()->getID();
		$SessionID=$CourseStudentRegistration->getSession()->getID();
		$YearID=$CourseStudentRegistration->getYear()->getID();
		$TermID=$CourseStudentRegistration->getTerm()->getID();
		$StudentID=$CourseStudentRegistration->getStudent()->getID();
		$Status=$CourseStudentRegistration->getStatus();		

		$SQL = "UPDATE reg_course_student_registration SET Status='$Status' where 
				StudentID ='$StudentID' AND 
				SessionID='$SessionID' AND
				YearID='$YearID' AND
				TermID='$TermID' AND
				Regs_TeacherID='$CoordinatorID' AND
				Status='$Prev_Status'";

		//echo $SQL;		
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$msg = '<label style="color:green"><strong>Registration Completed!</strong></label>';
		$Result->setResultObject($msg);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Coursedao.inc");

?>