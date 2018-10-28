<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.forum.inc';
include_once UTILITY.'class.util.inc';

Class searchDiscussionDAO{

	private $_DB;
	private $_Cat;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cat = new DiscussionCategory();

	}

	// get all the Discussions from the database using the database query
	public function getAllDiscussions(){

		$DiscussionList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Discussion = new Discussion();

		    $this->_Discussion->setID ( $row['ID']);
		    $this->_Discussion->setName( $row['Title'] );
		    $this->_Discussion->setCategory( $row['CategoryID'] );
		    $this->_Discussion->setDescription( $row['Description'] );
		    $this->_Discussion->setTag( $row['Tag'] );
		    $this->_Discussion->setCreationDate( $row['CreationDate'] );
		    $this->_Discussion->setCreator( $row['CreatorID'] );


		    $DiscussionList[]=$this->_Discussion;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($DiscussionList);

		return $Result;
	}
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

	public function readCategorywiseDiscussion($searchDiscussion){

		$DiscussionList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion WHERE CategoryID = '".$searchDiscussion."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Discussion= new Discussion();

		//preparing the Discussion object
		    $this->_Discussion->setID ( $row['ID'] );
		    $this->_Discussion->setName( $row['Title'] );
		    $this->_Discussion->setCategory( $row['CategoryID'] );
			$this->_Discussion->setDescription( $row['Description'] );
			$this->_Discussion->setTag( $row['Tag'] );
			$this->_Discussion->setCreationDate( $row['CreationDate'] );
			$this->_Discussion->setCreator( $row['CreatorID'] );


		    $DiscussionList[]=$this->_Discussion;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($DiscussionList);

		return $Result;
	}
	public function readTagwiseDiscussion($tag){

		$DiscussionList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion WHERE Tag like '%$tag%'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Discussion= new Discussion();

		//preparing the Discussion object
		    $this->_Discussion->setID ( $row['ID'] );
		    $this->_Discussion->setName( $row['Title'] );
		    $this->_Discussion->setCategory( $row['CategoryID'] );
			$this->_Discussion->setDescription( $row['Description'] );
			$this->_Discussion->setTag( $row['Tag'] );
			$this->_Discussion->setCreationDate( $row['CreationDate'] );
			$this->_Discussion->setCreator( $row['CreatorID'] );


		    $DiscussionList[]=$this->_Discussion;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($DiscussionList);

		return $Result;
	}


	public function getNameFromCatagoryID($CatagoryID){

		$SQL = "SELECT * FROM dms_discussion_category
				WHERE ID='".$CatagoryID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_DiscussionCategory = new DiscussionCategory();

		$this->_DiscussionCategory->setID ( $row['ID']);
		$this->_DiscussionCategory->setName( $row['Name'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_DiscussionCategory);

		return $Result;
	}


	//read an Discussion object based on its id form Discussion object
	public function readDiscussion($Discussion){
		
		
		$SQL = "SELECT * FROM dms_discussion WHERE ID='".$Discussion->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Discussion from the database
		$row = $this->_DB->getTopRow();

		$this->_Discussion= new Discussion();

		//preparing the Discussion object
	    $this->_Discussion->setID ( $row['ID'] );
	    $this->_Discussion->setName( $row['Title'] );
	    $this->_Discussion->setCategory( $row['CategoryID'] );
		$this->_Discussion->setDescription( $row['Description'] );
		$this->_Discussion->setTag( $row['Tag'] );
		$this->_Discussion->setCreationDate( $row['CreationDate'] );
		$this->_Discussion->setCreator( $row['CreatorID'] );




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Discussion);

		return $Result;
	}


}