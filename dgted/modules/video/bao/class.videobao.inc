<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'dao/class.videodao.inc';


/*
	Term Business Object 
*/
Class VideoBAO{

	private $_DB;
	private $_VideoDAO;

	public function __construct(){

		$this->_VideoDAO = new VideoDAO();

	}

	//get all Terms value
	public function getAllVideos(){

		$Result = new Result();	
		$Result = $this->_VideoDAO->getAllVideos();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoDAO.getAllVideos()");		

		return $Result;
	}

	//create Term funtion with the Term object
	public function createVideo($Video){

		$Result = new Result();	
		$Result = $this->_VideoDAO->createVideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoDAO.createVideo()");		

		return $Result;

	
	}

	//read an Term object based on its id form Term object
	public function readVideo($Video){


		$Result = new Result();	
		$Result = $this->_VideoDAO->readVideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoDAO.readVideo()");		

		return $Result;


	}

	//update an Term object based on its current information
	public function updateVideo($Video){

		$Result = new Result();	
		$Result = $this->_VideoDAO->updateVideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoDAO.updateVideo()");		

		return $Result;
	}

	//delete an existing Term
	public function deleteVideo($Video){

		$Result = new Result();	
		$Result = $this->_VideoDAO->deleteVideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoDAO.deleteVideo()");		

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videobao.inc");

?>