<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'dao/class.searchDiscussiondao.inc';


/*
	Discussion Business Object 
*/
Class searchDiscussionBAO{

	private $_DB;
	private $_searchDiscussionDAO;

	public function __construct(){

		$this->_searchDiscussionDAO = new searchDiscussionDAO();

	}

	//get all Discussions value
	public function getAllDiscussions(){

		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->getAllDiscussions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.getAllDiscussions()");		

		return $Result;
	}
	public function getAllDiscussionCategorys(){

		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->getAllDiscussionCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.getAllDiscussionCategorys()");		

		return $Result;
	}

	public function readCategorywiseDiscussion($CreatorID){


		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->readCategorywiseDiscussion($CreatorID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.readCategorywiseDiscussion()");		

		return $Result;


	}
	public function readTagwiseDiscussion($tag){


		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->readTagwiseDiscussion($tag);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.readTagwiseDiscussion()");		

		return $Result;


	}

	
	public function getNameFromCatagoryID($Discussion){


		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->getNameFromCatagoryID($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.readDiscussionCategory()");		

		return $Result;


	}


	public function readDiscussionCategory($Discussion){


		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->readDiscussionCategory($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.readDiscussionCategory()");		

		return $Result;


	}

	//read an Discussion object based on its id form Discussion object
	public function readDiscussion($Discussion){


		$Result = new Result();	
		$Result = $this->_searchDiscussionDAO->readDiscussion($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in searchDiscussionDAO.readDiscussion()");		

		return $Result;


	}
	

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionbao.inc");

?>