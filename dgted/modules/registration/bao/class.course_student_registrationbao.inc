<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.course_student_registraiondao.inc';


/*
	CourseStudentRegistration Business Object 
*/
Class CourseStudentRegistrationBAO{

	private $_DB;
	private $_CourseStudentRegistrationDAO;

	public function __construct(){

		$this->_CourseStudentRegistrationDAO = new CourseStudentRegistrationDAO();

	}

	//get all CourseStudentRegistrations value
	public function getAllCourseStudentRegistrations(){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->getAllCourseStudentRegistrations();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.getAllCourseStudentRegistrations()");		

		return $Result;
	}

	//create CourseStudentRegistration funtion with the CourseStudentRegistration object
	public function addCourseToStudentCart($CourseStudentRegistration){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->addCourseToStudentCart($CourseStudentRegistration);
		
	
		return $Result;

	
	}

	//read an CourseStudentRegistration object based on its id form CourseStudentRegistration object
	public function readCourseStudentRegistration($CourseStudentRegistration){


		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->readCourseStudentRegistration($CourseStudentRegistration);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.readCourseStudentRegistration()");		

		return $Result;


	}

	//read an CourseStudentRegistration object based on its id form CourseStudentRegistration object
	public function searchRegistrationCart($CourseStudentRegistration){


		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->searchRegistrationCart($CourseStudentRegistration);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.searchRegistrationCart()");		

		return $Result;


	}


	//read all the students that have sent registration request
	public function searchRegistrationRequest($Coordinator,$Status){


		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO
						->searchRegistrationRequest($Coordinator,$Status);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.searchRegistrationRequest()");		

		return $Result;


	}

	//update student course registration cart to reflect registration submit
	public function submitStudentRegistration($CourseStudentRegistration){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->submitStudentRegistration($CourseStudentRegistration);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.submitStudentRegistration()");		

		return $Result;
	}

	//delete an added course from the cart
	public function deleteCourseStudentRegistration($CourseStudentRegistration){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->deleteCourseStudentRegistration($CourseStudentRegistration);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.deleteCourseStudentRegistration()");		

		return $Result;

	}

	//update a course registration status
	public function updateCourseStudentRegistration_Status($CourseStudentRegistration){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->updateCourseStudentRegistration_Status($CourseStudentRegistration);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.updateCourseStudentRegistration_Status()");		

		return $Result;

	}

	//update a course registration status who has a given status
	// example: make approved status to registered
	public function updateCourseStudentRegistration_Status2($CourseStudentRegistration,$Prev_Status){

		$Result = new Result();	
		$Result = $this->_CourseStudentRegistrationDAO->updateCourseStudentRegistration_Status2($CourseStudentRegistration, $Prev_Status);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseStudentRegistrationDAO.updateCourseStudentRegistration_Status()");		

		return $Result;

	}
	
}

//$_Log->log(LogUtil::$DEBUG," exit the class.CourseStudentRegistrationbao.inc");

?>