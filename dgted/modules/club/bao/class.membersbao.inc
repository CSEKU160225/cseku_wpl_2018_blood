<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'dao/class.membersdao.inc';


/*
	Member of a Club Business Object 
*/
Class MembersBAO{

	private $_DB;
	private $_MembersDAO;

	public function __construct(){

		$this->_MembersDAO = new MembersDAO();

	}

	//get all members for this club
	public function getAllMembers($Club){

		$Result = new Result();	
		$Result = $this->_MembersDAO->getAllMembers($Club);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MembersDAO.getAllMembers()");		

		return $Result;
	}

	//create Member funtion with the Member object
	public function createMembers($Members){

		$Result = new Result();	
		$Result = $this->_MembersDAO->createMembers($Members);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MemberDAO.createMember()");		

		return $Result;

	
	}

	//read an Member object based on its id form Member object
	public function readMembers($Members){


		$Result = new Result();	
		$Result = $this->_MembersDAO->readMembers($Members);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MembersDAO.readMembers()");		

		return $Result;


	}

	//update an Member object based on its current information
	public function updateMembers($Members){

		$Result = new Result();	
		$Result = $this->_MembersDAO->updateMembers($Members);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MemberDAO.updateMember()");		

		return $Result;
	}

	//delete an existing Member
	public function deleteMembers($Members){

		$Result = new Result();	
		$Result = $this->_MembersDAO->deleteMembers($Members);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in MembersDAO.deleteMembers()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG,"exit the class.Membersbao.inc");

?>