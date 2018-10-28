<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'dao/class.clubdao.inc';


/*
	Position Business Object 
*/
Class ClubBAO{

	private $_DB;
	private $_ClubDAO;

	public function __construct(){

		$this->_ClubDAO = new ClubDAO();

	}

	//get all Positions value
	public function getAllClub(){

		$Result = new Result();	
		$Result = $this->_ClubDAO->getAllClub();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.getAllClub()");		

		return $Result;
	}

	//create Position funtion with the Position object
	public function createClub($Club){

		$Result = new Result();	
		$Result = $this->_ClubDAO->createClub($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.createClub()");		

		return $Result;

	
	}

	//read an Position object based on its id form Position object
	public function readClub($Club){


		$Result = new Result();	
		$Result = $this->_ClubDAO->readClub($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.readClub()");		

		return $Result;


	}

	//update an Position object based on its current information
	public function updateClub($Club){

		$Result = new Result();	
		$Result = $this->_ClubDAO->updateClub($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.updateClub()");		

		return $Result;
	}

	//delete an existing Position
	public function deleteClub($Club){

		$Result = new Result();	
		$Result = $this->_ClubDAO->deleteClub($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in ClubDAO.deleteClub()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG,"exit the class.clubbao.inc");

?>