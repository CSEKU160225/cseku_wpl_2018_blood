<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'dao/class.discussiondao.inc';


/*
	Discussion Business Object 
*/
Class DiscussionBAO{

	private $_DB;
	private $_DiscussionDAO;

	public function __construct(){

		$this->_DiscussionDAO = new DiscussionDAO();

	}

	//get all Discussions value
	public function getAllDiscussions(){

		$Result = new Result();	
		$Result = $this->_DiscussionDAO->getAllDiscussions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.getAllDiscussions()");		

		return $Result;
	}
	public function getAllDiscussionCategorys(){

		$Result = new Result();	
		$Result = $this->_DiscussionDAO->getAllDiscussionCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.getAllDiscussionCategorys()");		

		return $Result;
	}

	public function readCreator($CreatorID){


		$Result = new Result();	
		$Result = $this->_DiscussionDAO->readCreator($CreatorID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.readCreator()");		

		return $Result;


	}

	//create Discussion funtion with the Discussion object
	public function createDiscussion($Discussion){

		$Result = new Result();	
		$Result = $this->_DiscussionDAO->createDiscussion($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.createDiscussion()");		

		return $Result;

	
	}
	
	public function getNameFromCatagoryID($Discussion){


		$Result = new Result();	
		$Result = $this->_DiscussionDAO->getNameFromCatagoryID($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.readDiscussionCategory()");		

		return $Result;


	}


	public function readDiscussionCategory($Discussion){


		$Result = new Result();	
		$Result = $this->_DiscussionDAO->readDiscussionCategory($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.readDiscussionCategory()");		

		return $Result;


	}

	//read an Discussion object based on its id form Discussion object
	public function readDiscussion($Discussion){


		$Result = new Result();	
		$Result = $this->_DiscussionDAO->readDiscussion($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.readDiscussion()");		

		return $Result;


	}

	public function readDiscussion1($Discussion){


		$Result = new Result();	
		$Result = $this->_DiscussionDAO->readDiscussion1($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.readDiscussion()");		

		return $Result;


	}

	//update an Discussion object based on its current information
	public function updateDiscussion($Discussion){

		$Result = new Result();	
		$Result = $this->_DiscussionDAO->updateDiscussion($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.updateDiscussion()");		

		return $Result;
	}

	//delete an existing Discussion
	public function deleteDiscussion($Discussion){

		$Result = new Result();	
		$Result = $this->_DiscussionDAO->deleteDiscussion($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in DiscussionDAO.deleteDiscussion()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionbao.inc");

?>