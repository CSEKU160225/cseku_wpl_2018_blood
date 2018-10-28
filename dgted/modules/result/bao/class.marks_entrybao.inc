<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_RESULT.'dao/class.marks_entrydao.inc';


/*
	MarksEntry Business Object 
*/
Class MarksEntryBAO{

	private $_DB;
	private $_MarksEntryDAO;

	public function __construct(){

		$this->_MarksEntryDAO = new MarksEntryDAO();

	}


	//update the marks entry in to the database for this course, session, year and term for all 
	//registered students
	public function updateCourseAllMarksEntry($MarksEntryList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->updateCourseAllMarksEntry($MarksEntryList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.updateCourseAllMarksEntry()");		

		return $Result;
	}

	//update the marks entry in to the database for this course, session, year and term for all 
	//registered students
	public function updateCourseAllTestsEntry($MarksEntryList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->updateCourseAllTestsEntry($MarksEntryList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.updateCourseAllTestsEntry()");		

		return $Result;
	}

	//publish the marks entry in to the database to create result for this course, session, year and term for all registered students
	public function publishCourseAllMarksEntry($MarksEntryList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->publishCourseAllMarksEntry($MarksEntryList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.publishCourseAllMarksEntry()");		

		return $Result;
	}

	//delete all marks entry for a course registered on a session, year and term
	public function deleteCourseAllMarksEntry($MarksEntryList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->deleteCourseAllMarksEntry($MarksEntryList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.deleteCourseAllMarksEntry()");		

		return $Result;
	}

	//get default marks setup of a course
	public function getCourseMarksSetup($CourseNo){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->getCourseMarksSetup($CourseNo);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.getCourseMarksSetup()");		

		return $Result;
	}

	//get published marks of a student for a course
	public function getAStudentCoursePublishedMarks($CourseID,$Session,$Year,$Term,$Student){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->getAStudentCoursePublishedMarks($CourseID,$Session,$Year,$Term,$Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.getAStudentCoursePublishedMarks()");		

		return $Result;

	}	

	//get class tests marks of a student for a course
	public function getAStudentCourseTestMarks($CourseID,$Session,$Year,$Term,$Student){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->getAStudentCourseTestMarks($CourseID,$Session,$Year,$Term,$Student);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.getAStudentCourseTestMarks()");		

		return $Result;

	}	

	//get course marks for the students
	public function getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$StudentList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$StudentList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.getStudentCourseMarks()");		

		return $Result;

	}


	//get course class tests for the students
	public function getCourseStudentTests($CourseNo,$Session,$Year,$Term,$StudentList){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->getCourseStudentTests($CourseNo,$Session,$Year,$Term,$StudentList);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.getCourseStudentTests()");		

		return $Result;

	}


	//read course teacher row from the table based on the given criteria
	public function readCourseTeacher($CourseNo,$TeacherID,$SessionID,$YearID,$TermID){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->readCourseTeacher($CourseNo,$TeacherID,$SessionID,$YearID,$TermID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in CourseTeacherDAO.readCourseTeacher()");		

		return $Result;
	}
	
	//create MarksEntry funtion with the MarksEntry object
	public function createMarksEntry($MarksEntry){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->createMarksEntry($MarksEntry);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.createMarksEntry()");		

		return $Result;

	
	}



	//read an MarksEntry object based on its id form MarksEntry object
	public function readMarksEntry($MarksEntry){


		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->readMarksEntry($MarksEntry);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.readMarksEntry()");		

		return $Result;


	}



	//update an MarksEntry object based on its current information
	public function updateMarksEntry($MarksEntry){

		$Result = new Result();	
		$Result = $this->_MarksEntryDAO->updateMarksEntry($MarksEntry);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksEntryDAO.updateMarksEntry()");		

		return $Result;
	}


}

//$_Log->log(LogUtil::$DEBUG," exit the class.MarksEntrybao.inc");

?>