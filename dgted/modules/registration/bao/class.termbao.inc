<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.termdao.inc';


/*
	Term Business Object 
*/
Class TermBAO{

	private $_DB;
	private $_TermDAO;

	public function __construct(){

		$this->_TermDAO = new TermDAO();

	}

	//get all Terms value
	public function getAllTerms(){

		$Result = new Result();	
		$Result = $this->_TermDAO->getAllTerms();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in TermDAO.getAllTerms()");		

		return $Result;
	}

	//create Term funtion with the Term object
	public function createTerm($Term){

		$Result = new Result();	
		$Result = $this->_TermDAO->createTerm($Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in TermDAO.createTerm()");		

		return $Result;

	
	}

	//read an Term object based on its id form Term object
	public function readTerm($Term){


		$Result = new Result();	
		$Result = $this->_TermDAO->readTerm($Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in TermDAO.readTerm()");		

		return $Result;


	}

	//update an Term object based on its current information
	public function updateTerm($Term){

		$Result = new Result();	
		$Result = $this->_TermDAO->updateTerm($Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in TermDAO.updateTerm()");		

		return $Result;
	}

	//delete an existing Term
	public function deleteTerm($Term){

		$Result = new Result();	
		$Result = $this->_TermDAO->deleteTerm($Term);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in TermDAO.deleteTerm()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.termbao.inc");

?>