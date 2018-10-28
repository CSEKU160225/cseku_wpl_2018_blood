<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.coursedao.inc';
include_once 'class.registration_sessiondao.inc';
include_once 'class.yeardao.inc';
include_once 'class.termdao.inc';
include_once MODULES_USER.'dao/class.userdao.inc'; //module dependency


Class CourseTeacherDAO{

	private $_DB;
	private $_CourseTeacher;
	private $_CourseDAO;
	private $_UserDAO;
	private $_YearDAO;
	private $_RegistrationSessionDAO;
	private $_TermDAO;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CourseTeacher = new CourseTeacher();
		$this->_CourseDAO = new CourseDAO();
		$this->_UserDAO = new UserDAO();
		$this->_RegistrationSessionDAO = new RegistrationSessionDAO();
		$this->_YearDAO = new YearDAO();
		$this->_TermDAO = new TermDAO();
	}

	// get all the Courses from the database using the database query
	public function getAllCourseTeachers(){

		$CourseTeacherList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course_teacher");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			//echo '<br>'.$row['ID']." ".$row['CourseID'];
			$this->_CourseTeacher = new CourseTeacher();
			$this->_CourseTeacher->setID($row['ID']);
			
			$Course = new Course();
	 		$Course->setID($row['CourseID']);
			$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
			$this->_CourseTeacher->setCourse($Result_course);
		    
			$User = new User();
			$User->setID($row['TeacherID']);

			$Result_teacher = $this->_UserDAO->readUser($User)->getResultObject();
			$this->_CourseTeacher->setTeacher($Result_teacher);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
										readRegistrationSession($Session)->getResultObject();
		    $this->_CourseTeacher->setSession($Result_Session);
		    
		    $Year = new Year();
		    $Year->setID($row['YearID']);
	
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseTeacher->setYear($Result_year);
	

		    $Term = new Term();
		    $Term->setID($row['TermID']);
	
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseTeacher->setTerm($Result_term);
		    
		    
		    $CourseTeacherList[]=$this->_CourseTeacher;

		    

   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseTeacherList);

		return $Result;
	}


	// get all the Courses assigned to a specific teacher
	public function getAllMyCourses($CourseTeacher){

		$TeacherID=$CourseTeacher->getTeacher();
		$SessionID=$CourseTeacher->getSession();
		//$YearID=$CourseTeacher->getYear();
		//$TermID=$CourseTeacher->getTerm();

		$CourseTeacherList = array();

		$SQL = "SELECT * FROM reg_course_teacher where TeacherID='$TeacherID' AND 
				SessionID='$SessionID'";
				// AND 
				//YearID='$YearID' AND 
				//TermID='$TermID'";

		$SQL = $this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			//echo '<br>'.$row['ID']." ".$row['CourseID'];
			$this->_CourseTeacher = new CourseTeacher();
			$this->_CourseTeacher->setID($row['ID']);
			
			$Course = new Course();
	 		$Course->setID($row['CourseID']);
			$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
			$this->_CourseTeacher->setCourse($Result_course);
		    
			$User = new User();
			$User->setID($row['TeacherID']);

			$Result_teacher = $this->_UserDAO->readUser($User)->getResultObject();
			$this->_CourseTeacher->setTeacher($Result_teacher);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
										readRegistrationSession($Session)->getResultObject();
		    $this->_CourseTeacher->setSession($Result_Session);
		    
		    $Year = new Year();
		    $Year->setID($row['YearID']);
	
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseTeacher->setYear($Result_year);
	

		    $Term = new Term();
		    $Term->setID($row['TermID']);
	
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseTeacher->setTerm($Result_term);


			$this->_CourseTeacher->setNoOfTests($row['NoOfTests']);		    
		    
		    $CourseTeacherList[]=$this->_CourseTeacher;

		   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseTeacherList);

		return $Result;
	}



	//update course test number
	public function updateCourseNoOfTests($ID, $NoOfTests){

		$Result = new Result();

		$SQL = "UPDATE reg_course_teacher SET NoOfTests=$NoOfTests where ID='$ID'";

		$SQL = $this->_DB->doQuery($SQL);

		$Result->setIsSuccess(1);
		$Result->setResultObject("Update successful!");

		return $Result;
	}


	//create Course funtion with the Course object
	public function createCourseTeacher($CourseTeacher){

		$ID=$CourseTeacher->getID();
		$CourseNo=$CourseTeacher->getCourse();
		$TeacherID=$CourseTeacher->getTeacher();
		$SessionID=$CourseTeacher->getSession();
		$YearID=$CourseTeacher->getYear();
		$TermID=$CourseTeacher->getTerm();
		
		

		$SQL = "INSERT INTO reg_course_teacher(ID, CourseID, TeacherID, SessionID, YearID, TermID) VALUES ('$ID','$CourseNo','$TeacherID','$SessionID','$YearID','$TermID')";
		

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Course object based on its id form Course object
	public function readCourseTeacher($CourseTeacher){
		
		
		$SQL = "SELECT * FROM reg_course_teacher WHERE ID='".$CourseTeacher->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Course from the database
		$row = $this->_DB->getTopRow();

		$this->_CourseTeacher = new CourseTeacher();

		//preparing the Course object
		$this->_CourseTeacher->setID($row['ID']);
		
		$Course = new Course();
 		$Course->setID($row['CourseID']);
		$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
		$this->_CourseTeacher->setCourse($Result_course);
	    
		$User = new User();
		$User->setID($row['TeacherID']);

		$Result_teacher = $this->_UserDAO->readUser($User)->getResultObject();
		$this->_CourseTeacher->setTeacher($Result_teacher);


		$Session = new RegistrationSession();
		$Session->setID($row['SessionID']);
		$Result_Session = $this->_RegistrationSessionDAO->
									readRegistrationSession($Session)->getResultObject();
	    $this->_CourseTeacher->setSession($Result_Session);
	    
	    $Year = new Year();
	    $Year->setID($row['YearID']);

		$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
	    $this->_CourseTeacher->setYear($Result_year);


	    $Term = new Term();
	    $Term->setID($row['TermID']);

		$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
	    $this->_CourseTeacher->setTerm($Result_term);


	    $this->_CourseTeacher->setNoOfTests($row['NoOfTests']);


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseTeacher);

		return $Result;
	}

	//update an Course object based on its 
	public function updateCourseTeacher($CourseTeacher){

		$SQL = "UPDATE reg_course_teacher SET CourseID='".$CourseTeacher->getCourse().
		"',TeacherID='".$CourseTeacher->getTeacher().
		"',SessionID='".$CourseTeacher->getSession().
		"',YearID='".$CourseTeacher->getYear().
		"',TermID='".$CourseTeacher->getTerm().
		"',NoOfTests='".$CourseTeacher->getNoOfTests().
		"' WHERE ID='".$CourseTeacher->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Course based on its id of the database
	public function deleteCourseTeacher($CourseTeacher){


		$SQL = "DELETE from reg_course_teacher where ID ='".$CourseTeacher->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Coursedao.inc");

?>