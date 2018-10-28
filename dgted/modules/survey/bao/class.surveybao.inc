<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'dao/class.surveydao.inc';
/*
	Survey Business Object 
*/
Class SurveyBAO{
	private $_DB;
	private $_SurveyDAO;

	public function __construct(){

		$this->_SurveyDAO = new SurveyDAO();

	}

	//get all Surveys value
	public function getAllSurveys(){

		$Result = new Result();	
		$Result = $this->_SurveyDAO->getAllSurveys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.getAllSurveys()");		

		return $Result;
	}

	public function getAllUsers(){

		$Result = new Result();
		$Result = $this->_SurveyDAO->getAllUsers();

		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.getAllUsers()");

		return $Result;
	}

	public function getTeacherFromID($ID){
		$Result = new Result();
		$Result = $this->_SurveyDAO->getTeacherFromID($ID);
		return $Result;
	}

	//create Survey funtion with the Survey object
	public function createSurvey($Survey){

		$Result = $this->_SurveyDAO->createSurvey($Survey);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.createSurvey()");		

		return $Result;

	
	}

	//read an Survey object based on its id form Survey object
	public function readSurvey($Survey){


		$Result = new Result();	
		$Result = $this->_SurveyDAO->readSurvey($Survey);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.readSurvey()");		

		return $Result;


	}

	//update an Survey object based on its current information
	public function updateSurvey($Survey){

		$Result = new Result();	
		$Result = $this->_SurveyDAO->updateSurvey($Survey);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.updateSurvey()");		

		return $Result;
	}

	//delete an existing Survey
	public function deleteSurvey($Survey){

		$Result = new Result();	
		$Result = $this->_SurveyDAO->deleteSurvey($Survey);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in SurveyDAO.deleteSurvey()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.surveybao.inc");

?>