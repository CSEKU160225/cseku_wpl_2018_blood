<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'dao/class.mostRecentdao.inc';


/*
	Discussion Business Object 
*/
Class MostRecentBAO{

	private $_DB;
	private $_MostRecentDAO;

	public function __construct(){

		$this->_MostRecentDAO = new MostRecentDAO();

	}

	//get all Discussions value
	public function getAllDiscussions(){

		$Result = new Result();	
		$Result = $this->_MostRecentDAO->getAllDiscussions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MostRecentDAO.getAllDiscussions()");		

		return $Result;
	}
	public function getAllDiscussionCategorys(){

		$Result = new Result();	
		$Result = $this->_MostRecentDAO->getAllDiscussionCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MostRecentDAO.getAllDiscussionCategorys()");		

		return $Result;
	}

	
	public function getNameFromCatagoryID($Discussion){


		$Result = new Result();	
		$Result = $this->_MostRecentDAO->getNameFromCatagoryID($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MostRecentDAO.readDiscussionCategory()");		

		return $Result;


	}


	public function readDiscussionCategory($Discussion){


		$Result = new Result();	
		$Result = $this->_MostRecentDAO->readDiscussionCategory($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MostRecentDAO.readDiscussionCategory()");		

		return $Result;


	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionbao.inc");

?>