<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.yeardao.inc';


/*
	Year Business Object 
*/
Class YearBAO{

	private $_DB;
	private $_YearDAO;

	public function __construct(){

		$this->_YearDAO = new YearDAO();

	}

	//get all Years value
	public function getAllYears(){

		$Result = new Result();	
		$Result = $this->_YearDAO->getAllYears();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in YearDAO.getAllYears()");		

		return $Result;
	}

	//create Year funtion with the Year object
	public function createYear($Year){

		$Result = new Result();	
		$Result = $this->_YearDAO->createYear($Year);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in YearDAO.createYear()");		

		return $Result;

	
	}

	//read an Year object based on its id form Year object
	public function readYear($Year){


		$Result = new Result();	
		$Result = $this->_YearDAO->readYear($Year);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in YearDAO.readYear()");		

		return $Result;


	}

	//update an Year object based on its current information
	public function updateYear($Year){

		$Result = new Result();	
		$Result = $this->_YearDAO->updateYear($Year);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in YearDAO.updateYear()");		

		return $Result;
	}

	//delete an existing Year
	public function deleteYear($Year){

		$Result = new Result();	
		$Result = $this->_YearDAO->deleteYear($Year);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in YearDAO.deleteYear()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Yearbao.inc");

?>