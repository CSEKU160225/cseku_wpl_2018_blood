<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.forum.inc';
include_once UTILITY.'class.util.inc';

Class DiscussionCategoryDAO{

	private $_DB;
	private $_Cat;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cat = new DiscussionCategory();

	}

	// get all the Discussion Categorys from the database using the database query
	public function getAllDiscussionCategorys(){

		$DiscussionCategoryList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion_category");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_DiscussionCategory = new DiscussionCategory();

		    $this->_DiscussionCategory->setID ( $row['ID']);
		    $this->_DiscussionCategory->setName( $row['Name'] );


		    $DiscussionCategoryList[]=$this->_DiscussionCategory;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($DiscussionCategoryList);

		return $Result;
	}

	//create Discussion Category funtion with the Discussion Category object
	public function createDiscussionCategory($DiscussionCategory){

		$ID=$DiscussionCategory->getID();
		$Name=$DiscussionCategory->getName();


		$SQL = "INSERT INTO dms_discussion_category(ID,Name) VALUES('$ID','$Name')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Discussion Category object based on its id form Discussion Category object
	public function readDiscussionCategory($DiscussionCategory){
		
		
		$SQL = "SELECT * from dms_discussion_category WHERE ID='".$DiscussionCategory->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Discussion Category from the database
		$row = $this->_DB->getTopRow();

		$this->_DiscussionCategory= new DiscussionCategory();

		//preparing the Discussion Category object
	    $this->_DiscussionCategory->setID ( $row['ID']);
	    $this->_DiscussionCategory->setName( $row['Name'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_DiscussionCategory);

		return $Result;
	}

	//update an Discussion Category object based on its 
	public function updateDiscussionCategory($DiscussionCategory){

		$SQL = "UPDATE dms_discussion_category SET Name='".$DiscussionCategory->getName()."' 
				WHERE ID='".$DiscussionCategory->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Discussion Category based on its id of the database
	public function deleteDiscussionCategory($DiscussionCategory){


		$SQL = "DELETE from dms_discussion_category where ID ='".$DiscussionCategory->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.discussionCategorydao.inc");

?>