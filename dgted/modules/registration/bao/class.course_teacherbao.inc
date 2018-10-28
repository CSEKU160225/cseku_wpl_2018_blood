<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.course_teacherdao.inc';


/*
	CourseTeacher Business Object 
*/
Class CourseTeacherBAO{

	private $_DB;
	private $_CourseTeacherDAO;

	public function __construct(){

		$this->_CourseTeacherDAO = new CourseTeacherDAO();

	}

	//get all CourseTeachers value
	public function getAllCourseTeachers(){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->getAllCourseTeachers();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.getAllCourseTeachers()");		

		return $Result;
	}

	//get all Courses assigned to a teacher
	public function getAllMyCourses($CourseTeaher){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->getAllMyCourses($CourseTeaher);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.getAllMyCourses($CourseTeaher)");		

		return $Result;
	}



	//get no of tests for the assigned course
	public function updateCourseNoOfTests($ID,$NoOfTests){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->updateCourseNoOfTests($ID,$NoOfTests);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.updateCourseNoOfTests()");		

		return $Result;
	}


	//create CourseTeacher funtion with the CourseTeacher object
	public function createCourseTeacher($CourseTeacher){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->createCourseTeacher($CourseTeacher);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.createCourseTeacher()");		

		return $Result;

	
	}

	//read an CourseTeacher object based on its id form CourseTeacher object
	public function readCourseTeacher($CourseTeacher){


		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->readCourseTeacher($CourseTeacher);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.readCourseTeacher()");		

		return $Result;


	}

	//update an CourseTeacher object based on its current information
	public function updateCourseTeacher($CourseTeacher){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->updateCourseTeacher($CourseTeacher);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.updateCourseTeacher()");		

		return $Result;
	}

	//delete an existing CourseTeacher
	public function deleteCourseTeacher($CourseTeacher){

		$Result = new Result();	
		$Result = $this->_CourseTeacherDAO->deleteCourseTeacher($CourseTeacher);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.deleteCourseTeacher()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.CourseTeacherbao.inc");

?>