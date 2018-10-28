<?php
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.forum.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.discussiondao.inc';

Class CommentDAO{

	private $_DB;
	private $_Cat;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Cat = new Comment();

	}

	// get all the Comments from the database using the database query
	public function getAllComments(){

		$CommentList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion_comment");
		$rows = $this->_DB->getAllRows();


		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Comment = new Comment();

		    $this->_Comment->setCommentID ( $row['CommentID']);
		    $this->_Comment->setDiscussionID( $row['DiscussionID'] );
		    $this->_Comment->setComment( $row['Comment'] );
		    $this->_Comment->setCreator( $row['CreatorID'] );
		    $this->_Comment->setCommentIDTop($row['CommentIDTop']);


		    $CommentList[]=$this->_Comment;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CommentList);

		return $Result;
	}

	//create Comment funtion with the Comment object
	public function createComment($Comment){

		$CommentID=$Comment->getCommentID();
		$DiscussionID=$Comment->getDiscussionID();
		$Comment=$Comment->getComment();
		$Creator=$_SESSION["globalUser"]->getID ();


		$SQL = "INSERT INTO dms_discussion_comment(CommentID,DiscussionID,Comment,CreatorID,CommentTime) 
				VALUES('$CommentID','$DiscussionID','$Comment','$Creator',now())";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	public function readDiscussion($Discussion){
		
		//$Dis = $Discussion->getID();
		$SQL = "SELECT * FROM dms_discussion WHERE ID='".$Discussion."'";
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

	public function readCreator($CreatorID){

		$SQL = "SELECT * FROM ums_user
				WHERE ID ='".$CreatorID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_useradd = new User();

		$this->_useradd->setID ( $row['ID']);
		$this->_useradd->setUniversityID( $row['UniversityID'] );
		$this->_useradd->setEmail ( $row['Email']);
		$this->_useradd->setPassword( $row['Password'] );
		$this->_useradd->setFirstName ( $row['FirstName']);
		$this->_useradd->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_useradd);

		return $Result;
	}

	public function readDiscussionCreator($CreatorID){

		$SQL = "SELECT * FROM ums_user
				WHERE ID ='".$CreatorID."'";
		$SQL = $this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$this->_useradd = new User();

		$this->_useradd->setID ( $row['ID']);
		$this->_useradd->setUniversityID( $row['UniversityID'] );
		$this->_useradd->setEmail ( $row['Email']);
		$this->_useradd->setPassword( $row['Password'] );
		$this->_useradd->setFirstName ( $row['FirstName']);
		$this->_useradd->setLastName( $row['LastName'] );
		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_useradd);

		return $Result;
	}
	//read an Comment object based on its id form Comment object
	public function readComment($Discussion){
		
		
		$CommentList = array();

		$this->_DB->doQuery("SELECT * FROM dms_discussion_comment WHERE DiscussionID = '".$Discussion."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Comment = new Comment();

		    $this->_Comment->setCommentID ( $row['CommentID']);
		    $this->_Comment->setDiscussionID( $row['DiscussionID'] );
		    $this->_Comment->setComment( $row['Comment'] );
		    $this->_Comment->setCreator( $row['CreatorID'] );
		    $this->_Comment->setCommentTime( $row['CommentTime'] );
		    $this->_Comment->setCommentIDTop($row['CommentIDTop']);


		    $CommentList[]=$this->_Comment;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CommentList);

		return $Result;
	}

	//update an Comment object based on its 
	public function updateComment($Comment){

		$SQL = "UPDATE dms_discussion_comment SET Comment='".$Comment->getComment()."'
				WHERE CommentID='".$Comment->getCommentID()."'";

		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Comment based on its id of the database
	public function deleteComment($Comment){


		$SQL = "DELETE from dms_discussion_comment where CommentID ='".$Comment->getCommentID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.commentdao.inc");

?>