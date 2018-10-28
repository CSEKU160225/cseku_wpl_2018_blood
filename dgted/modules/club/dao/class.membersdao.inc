<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';
include_once UTILITY.'class.util.inc';

Class MembersDAO{

	private $_DB;
	private $_Members;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Members= new Members();

	}

	// get all the Members from the database using the database query
	public function getAllMembers($Club){

		$MembersList = array();


		$Club_ID = $Club->getID();


		$this->_DB->doQuery("SELECT * FROM cbms_club_member WHERE ClubID ='$Club_ID'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Members = new Members();

		    $this->_Members->setClubID( $row['ClubID']);
		    $this->_Members->setMemberID( $row['MemberID']);
		    $this->_Members->setName( $row['Name'] );
			$this->_Members->setDesignation( $row['Designation']);

		    $MembersList[]=$this->_Members;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($MembersList);

		return $Result;
	}

	//create Member funtion with the Member object
	public function createMembers($Members){

		$ClubID=$Members->getClubID();
		$MemberID=$Members->getMemberID();
		$Name=$Members->getName();	
		$Designation=$Members->getDesignation();

		$SQL = "INSERT INTO cbms_club_member(ClubID,MemberID,Name,Designation) VALUES('$ClubID','$MemberID','$Name','$Designation')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Member object based on its id form Member object
	public function readMembers($Members){
		
		
		$SQL = "SELECT * FROM cbms_club_member WHERE MemberID='".$Members->getMemberID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Member from the database
		$row = $this->_DB->getTopRow();

		$this->_Members = new Members();

		//preparing the Member object
	    $this->_Members->setClubID ( $row['ClubID']);
	    $this->_Members->setMemberID ( $row['MemberID']);
		$this->_Members->setName( $row['Name'] );
	    $this->_Members->setDesignation ( $row['Designation']);




	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Members);

		return $Result;
	}

	//update an Member object based on its 
	public function updateMembers($Members){

		$SQL = "UPDATE cbms_club_member SET Name='".$Members->getName()."',Designation='".$Members->getDesignation()."' WHERE MemberID='".$Members->getMemberID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Member based on its id of the database
	public function deleteMembers($Members){


		$SQL = "DELETE from cbms_club_member where MemberID ='".$Members->getMemberID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Membersdao.inc");

?>