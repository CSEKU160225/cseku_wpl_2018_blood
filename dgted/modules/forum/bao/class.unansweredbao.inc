<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'dao/class.unanswereddao.inc';


/*
	Discussion Business Object 
*/
Class UnansweredBAO{

	private $_DB;
	private $_UnansweredDAO;

	public function __construct(){

		$this->_UnansweredDAO = new UnansweredDAO();

	}

	//get all Discussions value
	public function getAllDiscussions(){

		$Result = new Result();	
		$Result = $this->_UnansweredDAO->getAllDiscussions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UnansweredDAO.getAllDiscussions()");		

		return $Result;
	}
	public function getAllDiscussionCategorys(){

		$Result = new Result();	
		$Result = $this->_UnansweredDAO->getAllDiscussionCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UnansweredDAO.getAllDiscussionCategorys()");		

		return $Result;
	}

	
	public function getNameFromCatagoryID($Discussion){


		$Result = new Result();	
		$Result = $this->_UnansweredDAO->getNameFromCatagoryID($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UnansweredDAO.readDiscussionCategory()");		

		return $Result;


	}


	public function readDiscussionCategory($Discussion){


		$Result = new Result();	
		$Result = $this->_UnansweredDAO->readDiscussionCategory($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in UnansweredDAO.readDiscussionCategory()");		

		return $Result;


	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionbao.inc");

?>