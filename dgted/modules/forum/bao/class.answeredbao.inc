<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'dao/class.answereddao.inc';


/*
	Discussion Business Object 
*/
Class AnsweredBAO{

	private $_DB;
	private $_AnsweredDAO;

	public function __construct(){

		$this->_AnsweredDAO = new AnsweredDAO();

	}

	//get all Discussions value
	public function getAllDiscussions(){

		$Result = new Result();	
		$Result = $this->_AnsweredDAO->getAllDiscussions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AnsweredDAO.getAllDiscussions()");		

		return $Result;
	}
	public function getAllDiscussionCategorys(){

		$Result = new Result();	
		$Result = $this->_AnsweredDAO->getAllDiscussionCategorys();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AnsweredDAO.getAllDiscussionCategorys()");		

		return $Result;
	}

	
	public function getNameFromCatagoryID($Discussion){


		$Result = new Result();	
		$Result = $this->_AnsweredDAO->getNameFromCatagoryID($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AnsweredDAO.readDiscussionCategory()");		

		return $Result;


	}


	public function readDiscussionCategory($Discussion){


		$Result = new Result();	
		$Result = $this->_AnsweredDAO->readDiscussionCategory($Discussion);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in AnsweredDAO.readDiscussionCategory()");		

		return $Result;


	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionbao.inc");

?>