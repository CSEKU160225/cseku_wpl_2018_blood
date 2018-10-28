<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_QUESTION.'dao/class.questiondao.inc';


/*
	Question Business Object 
*/
Class QuestionBAO{

	private $_DB;
	private $_QuestionDAO;

	public function __construct(){

		$this->_QuestionDAO = new QuestionDAO();

	}

	//get all Questions
	public function getAllQuestions(){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->getAllQuestions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.getAllQuestions()");		

		return $Result;
	}
	public function searchQuestions($query){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->searchQuestions($query);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.searchQuestions()");		

		return $Result;
	}

	public function getAllTerms(){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->getAllTerms();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.getAllTerms()");		

		return $Result;
	}
	public function getAllCourse(){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->getAllCourse();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.getAllCourse()");		

		return $Result;
	}
	public function getAllUser(){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->getAllUser();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.getAllUser()");		

		return $Result;
	}
	public function getAllSession(){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getAllSession();

		if (!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.getAllSession()");
		return $Result;
	}
	public function getTeacherFromID($ID){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getTeacherFromID($ID);
		return $Result;
	}
	public function getTermFromID($ID){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getTermFromID($ID);
		return $Result;
	}
	public function getSessionFromID($ID){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getSessionFromID($ID);
		return $Result;
	}
	public function getCourseFromID($ID){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getCourseFromID($ID);
		return $Result;
	}
	public function getTitleFromID($ID){
		$Result = new Result();
		$Result = $this->_QuestionDAO->getTitleFromID($ID);
		return $Result;
	}

	//create Question funtion with the Question object
	public function createQuestion($Question){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->createQuestion($Question);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.createQuestion()");		

		return $Result;

	
	}

	//read a Question object based on its id form Question object
	public function readQuestion($Question){


		$Result = new Result();	
		$Result = $this->_QuestionDAO->readQuestion($Question);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.readQuestion()");		

		return $Result;


	}

	//update a Question object based on its current information
	public function updateQuestion($Question){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->updateQuestion($Question);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.updateQuestion()");		

		return $Result;
	}

	//delete an existing Question
	public function deleteQuestion($Question){

		$Result = new Result();	
		$Result = $this->_QuestionDAO->deleteQuestion($Question);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in QuestionDAO.deleteQuestion()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.questionbao.inc");

?>