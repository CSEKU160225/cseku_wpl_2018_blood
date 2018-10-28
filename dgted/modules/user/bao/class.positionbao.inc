<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'dao/class.positiondao.inc';


/*
	Position Business Object 
*/
Class PositionBAO{

	private $_DB;
	private $_PositionDAO;

	public function __construct(){

		$this->_PositionDAO = new PositionDAO();

	}

	//get all Positions value
	public function getAllPositions(){

		$Result = new Result();	
		$Result = $this->_PositionDAO->getAllPositions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PositionDAO.getAllPositions()");		

		return $Result;
	}

	//create Position funtion with the Position object
	public function createPosition($Position){

		$Result = new Result();	
		$Result = $this->_PositionDAO->createPosition($Position);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PositionDAO.createPosition()");		

		return $Result;

	
	}

	//read an Position object based on its id form Position object
	public function readPosition($Position){


		$Result = new Result();	
		$Result = $this->_PositionDAO->readPosition($Position);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PositionDAO.readPosition()");		

		return $Result;


	}

	//update an Position object based on its current information
	public function updatePosition($Position){

		$Result = new Result();	
		$Result = $this->_PositionDAO->updatePosition($Position);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PositionDAO.updatePosition()");		

		return $Result;
	}

	//delete an existing Position
	public function deletePosition($Position){

		$Result = new Result();	
		$Result = $this->_PositionDAO->deletePosition($Position);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in PositionDAO.deletePosition()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.positionbao.inc");

?>