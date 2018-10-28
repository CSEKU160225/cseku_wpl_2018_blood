<?php

include_once '/../util/class.util.php';
include_once '/../dao/class.newsdao.php';


/*
	User Business Object 
*/
Class NewsBAO{

	private $_DB;
	private $_NewsDAO;

	function NewsBAO(){

		$this->_NewsDAO = new NewsDAO();

	}

	//get all users value
	public function getAllNews(){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getAllNews();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}
	public function getEditedNews($Title){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getAllNews($Title);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}

	public function getNews($ID){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getNews($ID);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getNews($ID)");		

		return $Result;
	}
	public function getPagedNews($page1){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getPagedNews($page1);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}

	public function getSportsNews(){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getSportsNews();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}
	public function getAllumniNews(){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getAllumniNews();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}
	public function getTeachersNews(){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getTeachersNews();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}
	public function getNoticeNews(){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getNoticeNews();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}


	public function getSearchedNews($Keyword){

		$Result = new Result();	
		$Result = $this->_NewsDAO->getSearchedNews($Keyword);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.getAllNews()");		

		return $Result;
	}


	//create user funtion with the user object
	public function createNews($News){

		$Result = new Result();	
		$Result = $this->_NewsDAO->createNews($News);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.createNews()");		

		return $Result;

	
	}
	public function updateNews($News){

		$Result = new Result();	
		$Result = $this->_NewsDAO->updateNews($News);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in NewsDAO.updateNews()");		

		return $Result;
	} 

	
}

	echo '<br> log:: exit the class.newsbao.php';
	?>
