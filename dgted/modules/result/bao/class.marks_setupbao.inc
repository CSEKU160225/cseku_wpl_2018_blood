<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_RESULT.'dao/class.marks_setupdao.inc';


/*
	MarksSetup Business Object 
*/
Class MarksSetupBAO{

	private $_DB;
	private $_MarksSetupDAO;

	public function __construct(){

		$this->_MarksSetupDAO = new MarksSetupDAO();

	}

	//get all MarksSetups value
	public function getAllMarksSetups(){

		$Result = new Result();	
		$Result = $this->_MarksSetupDAO->getAllMarksSetups();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksSetupDAO.getAllMarksSetups()");		

		return $Result;
	}



	//create MarksSetup funtion with the MarksSetup object
	public function createMarksSetup($MarksSetup){

		$Result = new Result();	
		$Result = $this->_MarksSetupDAO->createMarksSetup($MarksSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksSetupDAO.createMarksSetup()");		

		return $Result;

	
	}



	//read an MarksSetup object based on its id form MarksSetup object
	public function readMarksSetup($MarksSetup){


		$Result = new Result();	
		$Result = $this->_MarksSetupDAO->readMarksSetup($MarksSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksSetupDAO.readMarksSetup()");		

		return $Result;


	}



	//update an MarksSetup object based on its current information
	public function updateMarksSetup($MarksSetup){

		$Result = new Result();	
		$Result = $this->_MarksSetupDAO->updateMarksSetup($MarksSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksSetupDAO.updateMarksSetup()");		

		return $Result;
	}

	//delete an existing MarksSetup
	public function deleteMarksSetup($MarksSetup){

		$Result = new Result();	
		$Result = $this->_MarksSetupDAO->deleteMarksSetup($MarksSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MarksSetupDAO.deleteMarksSetup()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.MarksSetupbao.inc");

?>