<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'dao/class.videoCommentdao.inc';

Class VideoCommentBAO{

	private $_DB;
	private $_VideoCommentDAO;

	public function __construct(){

		$this->_VideoCommentDAO = new VideoCommentDAO();

	}

	//get all Terms value
	public function getAllVideoComments(){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->getAllVideoComments();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.getAllVideoComments()");		

		return $Result;
	}
	public function createVideoComment($VideoComment){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->createVideoComment($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.createVideoComment()");		

		return $Result;

	
	}

	public function readCreator($VideoComment){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->readCreator($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.readCreator()");		

		return $Result;

	
	}

	//create Term funtion with the Term object
	public function searchVideoComment($VideoComment){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->searchVideoComment($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.searchVideoComment()");		

		return $Result;

	
	}

	//read an Term object based on its id form Term object
	public function readVideoComment($VideoComment){


		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->readVideoComment($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.readVideoComment()");		

		return $Result;


	}

	public function readvideo($Video){


		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->readvideo($Video);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.readvideo()");		

		return $Result;


	}

	//update an Term object based on its current information
	public function updateVideoComment($VideoComment){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->updateVideoComment($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.updateVideoComment()");		

		return $Result;
	}

	//delete an existing Term
	public function deleteVideoComment($VideoComment){

		$Result = new Result();	
		$Result = $this->_VideoCommentDAO->deleteVideoComment($VideoComment);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in VideoCommentDAO.deleteVideoComment()");		

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videoCommentbao.inc");

?>