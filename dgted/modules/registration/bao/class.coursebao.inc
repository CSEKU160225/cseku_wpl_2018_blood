<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.coursedao.inc';


/*
	Course Business Object 
*/
Class CourseBAO{

	private $_DB;
	private $_CourseDAO;

	public function __construct(){

		$this->_CourseDAO = new CourseDAO();

	}

	//get all Courses value
	public function getAllCourses(){

		$Result = new Result();	
		$Result = $this->_CourseDAO->getAllCourses();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.getAllCourses()");		

		return $Result;
	}

	//get all Courses that match the course no
	public function searchAllCourses($CourseNo){

		$Result = new Result();	
		$Result = $this->_CourseDAO->searchAllCourses($CourseNo);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.searchAllCourses()");		

		return $Result;
	}

	//get all Courses that matches student id and other related paremeters the course no
	public function searchCoursesOfStudent($StudentID,$Session,$Year,$Term){

		$Result = new Result();	
		$Result = $this->_CourseDAO->searchCoursesOfStudent($StudentID,$Session,$Year,$Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.searchCoursesOfStudent(StudentID,Session,Year,Term)");		

		return $Result;
	}

	//get all Courses that matches student id and other related paremeters and a given status
	public function searchCoursesOfStudent_Status($StudentID,$Session,$Year,$Term,$Status){

		$Result = new Result();	
		$Result = $this
					->_CourseDAO
					->searchCoursesOfStudent_Status($StudentID,$Session,$Year,$Term,$Status);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.searchCoursesOfStudent_Status(StudentID,Session,Year,Term,Status)");		

		return $Result;
	}

	//get all Students that have registered a certain course on specificied session, year, term
	public function searchAllStudents($CourseNo,$Session,$Year,$Term){

		$Result = new Result();	
		$Result = $this->_CourseDAO->searchAllStudents($CourseNo,$Session,$Year,$Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.searchAllStudents($CourseNo,$Session,$Year,$Term)");		

		return $Result;
	}

	//create Course funtion with the Course object
	public function createCourse($Course){

		$Result = new Result();	
		$Result = $this->_CourseDAO->createCourse($Course);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.createCourse()");		

		return $Result;

	
	}

	//read an Course object based on its id form Course object
	public function readCourse($Course){


		$Result = new Result();	
		$Result = $this->_CourseDAO->readCourse($Course);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.readCourse()");		

		return $Result;


	}

	
	//read an Course object based on the course no
	public function readCourseFromCourseNo($Course){


		$Result = new Result();	
		$Result = $this->_CourseDAO->readCourseFromCourseNo($Course);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.readCourseFromCourseNo()");		

		return $Result;


	}


	//update an Course object based on its current information
	public function updateCourse($Course){

		$Result = new Result();	
		$Result = $this->_CourseDAO->updateCourse($Course);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.updateCourse()");		

		return $Result;
	}

	//delete an existing Course
	public function deleteCourse($Course){

		$Result = new Result();	
		$Result = $this->_CourseDAO->deleteCourse($Course);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseDAO.deleteCourse()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Coursebao.inc");

?>