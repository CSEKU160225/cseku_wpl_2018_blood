<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'dao/class.moduledao.inc';


/*
	Position Business Object 
*/
Class ModuleBAO{

	private $_DB;
	private $_ModuleDAO;

	public function __construct(){

		$this->_ModuleDAO = new ModuleDAO();

	}

	//get all Positions value
	public function getAllModule($Club){

		$Result = new Result();	
		$Result = $this->_ModuleDAO->getAllModule($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ModuleDAO.getAllClub()");		

		return $Result;
	}

	//create Position funtion with the Position object
	public function createModule($Module){

		$Result = new Result();	
		$Result = $this->_ModuleDAO->createModule($Module);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.createClub()");		

		return $Result;

	
	}

	//read an Position object based on its id form Position object
	public function readModule($Module){


		$Result = new Result();	
		$Result = $this->_ModuleDAO->readModule($Module);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.readClub()");		

		return $Result;


	}

	//update an Position object based on its current information
	public function updateModule($Module){

		$Result = new Result();	
		$Result = $this->_ModuleDAO->updateModule($Module);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.updateClub()");		

		return $Result;
	}

	//delete an existing Position
	public function deleteModule($Module){

		$Result = new Result();	
		$Result = $this->_ModuleDAO->deleteModule($Module);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.deleteClub()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG,"exit the class.molulebao.inc");

?>