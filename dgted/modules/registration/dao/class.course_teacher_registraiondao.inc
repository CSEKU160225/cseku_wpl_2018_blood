<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.coursedao.inc';
include_once 'class.registration_sessiondao.inc';
include_once 'class.termdao.inc';
include_once MODULES_USER.'dao/class.userdao.inc'; //module dependecy

Class CourseTeacherRegistrationDAO{

	private $_DB;
	private $_CourseTeacherRegistration;
	private $_CourseDAO;
	private $_UserDAO;
	private $_RegistrationSessionDAO;
	private $_YearDAO;
	private $_TermDAO;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CourseTeacherRegistration = new CourseTeacherRegistration();
		$this->_CourseDAO = new CourseDAO();
		$this->_UserDAO = new UserDAO();
		$this->_RegistrationSessionDAO = new RegistrationSessionDAO();
		$this->_YearDAO = new YearDAO();
		$this->_TermDAO = new TermDAO();
	}

	// get all the Courses from the database using the database query
	public function getAllCourseTeacherRegistrations(){

		$CourseTeacherRegistrationList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course_teacher_registration");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			//echo '<br>'.$row['ID']." ".$row['CourseID'];
			$this->_CourseTeacherRegistration = new CourseTeacherRegistration();
			$this->_CourseTeacherRegistration->setID($row['ID']);
			
			
		    
			$User = new User();
			$User->setID($row['TeacherID']);
			$Result_teacher = $this->_UserDAO->readUser($User)->getResultObject();
			$this->_CourseTeacherRegistration->setTeacherID($Result_teacher->getFullName());


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
								readRegistrationSession($Session)->getResultObject();
		    $this->_CourseTeacherRegistration->setSessionID($Result_Session->getName());

		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseTeacherRegistration->setYearID($Result_year->getName());

		    
		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseTeacherRegistration->setTermID($Result_term->getName());
		    
		    
		    $CourseTeacherRegistrationList[]=$this->_CourseTeacherRegistration;
  
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseTeacherRegistrationList);

		return $Result;
	}

	//create Course funtion with the Course object
	public function createCourseTeacherRegistration($CourseTeacherRegistration){

		$ID=$CourseTeacherRegistration->getID();
		
		$TeacherID=$CourseTeacherRegistration->getTeacherID();
		$SessionID=$CourseTeacherRegistration->getSessionID();
		$YearID=$CourseTeacherRegistration->getYearID();
		$TermID=$CourseTeacherRegistration->getTermID();
		
		echo '<br>'.$ID.$TeacherID.$SessionID.$TermID;

		$SQL = "INSERT INTO reg_course_teacher_registration(ID, TeacherID, SessionID, YearID, TermID) VALUES ('$ID','$TeacherID','$SessionID','$YearID','$TermID')";
		


		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Course object based on its id form Course object
	public function readCourseTeacherRegistration($CourseTeacherRegistration){
		
		
		$SQL = "SELECT * FROM reg_course_teacher_registration WHERE ID='".$CourseTeacherRegistration->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Course from the database
		$row = $this->_DB->getTopRow();

		$this->_CourseTeacherRegistration = new CourseTeacherRegistration();

		//preparing the Course object
			$this->_CourseTeacherRegistration->setID($row['ID']);
		    
		    $this->_CourseTeacherRegistration->setTeacherID($row['TeacherID']);
		    $this->_CourseTeacherRegistration->setSessionID($row['SessionID']);
		    $this->_CourseTeacherRegistration->setYearID($row['YearID']);
		    $this->_CourseTeacherRegistration->setTermID($row['TermID']);
		    ///echo '<br>'. $row['CourseID'] . $row['TeacherID'] . $row['SessionID'] . $row['TermID'];


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseTeacherRegistration);

		return $Result;
	}

	//update an Course object based on its 
	public function updateCourseTeacherRegistration($CourseTeacherRegistration){

		$SQL = "UPDATE reg_course_teacher_registration ". 
		"SET TeacherID='".$CourseTeacherRegistration->getTeacherID().
		"',SessionID='".$CourseTeacherRegistration->getSessionID().
		"',YearID='".$CourseTeacherRegistration->getYearID().
		"',TermID='".$CourseTeacherRegistration->getTermID().
		"' WHERE ID='".$CourseTeacherRegistration->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;


	}

	//delete an Course based on its id of the database
	public function deleteCourseTeacherRegistration($CourseTeacherRegistration){


		$SQL = "DELETE from reg_course_teacher_registration where ID ='".$CourseTeacherRegistration->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Coursedao.inc");

?>