<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'dao/class.File_assigndao.inc';


/*
	File_assign Business Object 
*/
Class File_assignBAO{

	private $_DB;
	private $_File_assignDAO;

	public function __construct(){

		$this->_File_assignDAO = new File_assignDAO();

	}

	//get all File_assigns value
	public function getAllFile_assigns(){

		$Result = new Result();	
		$Result = $this->_File_assignDAO->getAllFile_assigns();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.getAllFile_assigns()");		

		return $Result;
	}


	//search File_assign function with the File_assign 
	public function searchFile_assign($CurrentUserID){

		$Result = new Result();	
		$Result = $this->_File_assignDAO->searchFile_assign($CurrentUserID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.searchFile_assign()");

		return $Result;
	}

	public function searchFileID($FileID){

		$Result = new Result();	
		$Result = $this->_File_assignDAO->searchFileID($FileID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.searchFileID()");

		return $Result;
	}

	//create File_assign funtion with the File_assign object
	public function createFile_assign($File_assign){

		$Result = new Result();	
		$Result = $this->_File_assignDAO->createFile_assign($File_assign);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.createFile_assign()");		

		return $Result;

	
	}

	//read an File_assign object based on its id form File_assign object
	public function readFile_assign($File_assign){


		$Result = new Result();	
		$Result = $this->_File_assignDAO->readFile_assign($File_assign);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.readFile_assign()");		

		return $Result;


	}

	//update an File_assign object based on its current information
	public function updateFile_assign($File_assign){

		$Result = new Result();	
		$Result = $this->_File_assignDAO->updateFile_assign($File_assign);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.updateFile_assign()");		

		return $Result;
	}

	//delete an existing File_assign
	public function deleteFile_assign($File_assign){

		$Result = new Result();
		$Result = $this->_File_assignDAO->deleteFile_assign($File_assign);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in File_assignDAO.deleteFile_assign()");

		return $Result;

	}

}

echo '<br> log:: exit the class.file_assignbao.inc';

?>