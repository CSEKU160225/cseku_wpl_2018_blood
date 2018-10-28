<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_RESULT.'dao/class.grade_setupdao.inc';


/*
	GradeSetup Business Object 
*/
Class GradeSetupBAO{

	private $_DB;
	private $_GradeSetupDAO;

	public function __construct(){

		$this->_GradeSetupDAO = new GradeSetupDAO();

	}

	//get all GradeSetups value
	public function getAllGradeSetups(){

		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->getAllGradeSetups();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.getAllGradeSetups()");		

		return $Result;
	}



	//create GradeSetup funtion with the GradeSetup object
	public function createGradeSetup($GradeSetup){

		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->createGradeSetup($GradeSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.createGradeSetup()");		

		return $Result;

	
	}



	//read an GradeSetup object based on its id form GradeSetup object
	public function readGradeSetup($GradeSetup){


		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->readGradeSetup($GradeSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.readGradeSetup()");		

		return $Result;


	}

	//read default GradeSetup
	public function readDefaultGradeSetup(){


		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->readDefaultGradeSetup();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.readDefaultGradeSetup()");		

		return $Result;


	}


	//update an GradeSetup object based on its current information
	public function updateGradeSetup($GradeSetup){

		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->updateGradeSetup($GradeSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.updateGradeSetup()");		

		return $Result;
	}

	//delete an existing GradeSetup
	public function deleteGradeSetup($GradeSetup){

		$Result = new Result();	
		$Result = $this->_GradeSetupDAO->deleteGradeSetup($GradeSetup);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in GradeSetupDAO.deleteGradeSetup()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.GradeSetupbao.inc");

?>