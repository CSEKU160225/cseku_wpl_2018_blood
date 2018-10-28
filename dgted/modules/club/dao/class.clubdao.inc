<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';
include_once UTILITY.'class.util.inc';

Class ClubDAO{

	private $_DB;
	private $_Club;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Club = new Club();

	}

	//get all the Club from the database using the database query
	public function getAllClub(){

		$ClubList = array();

		$this->_DB->doQuery("SELECT * FROM cbms_club");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Club = new Club();

		    $this->_Club->setID ( $row['ID']);
		    $this->_Club->setName( $row['Name'] );


		    $ClubList[]=$this->_Club;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ClubList);

		return $Result;
	}

	//create Position funtion with the Position object
	public function createClub($Club){

		$ID=$Club->getID();
		$Name=$Club->getName();
		$CoverPhoto=$Club->getCoverPhoto();
		$Description=$Club->getDescription();
		$CreationDate=$Club->getCreationDate();
		$Mail = $Club->getMail();


		$SQL = "INSERT INTO cbms_club(ID,Name,CoverPhoto,Description,Mail,CreationDate) VALUES('$ID','$Name','$CoverPhoto','$Description','$Mail',now())";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Position object based on its id form Position object
	public function readClub($Club){
		
		
		$SQL = "SELECT * FROM cbms_club WHERE ID='".$Club->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Position from the database
		$row = $this->_DB->getTopRow();

		$this->_Club = new Club();

		//preparing the Position object
	    $this->_Club->setID ( $row['ID']);
	    $this->_Club->setName( $row['Name'] );
	    $this->_Club->setDescription( $row['Description'] );
	    $this->_Club->setCoverPhoto($row['CoverPhoto']);
	    $this->_Club->setMail( $row['Mail'] );


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Club);

		return $Result;
	}

	//update an Position object based on its 
	public function updateClub($Club){

		$ID=$Club->getID();
		$Name=$Club->getName();
		$CoverPhoto=$Club->getCoverPhoto();
		$Description=$Club->getDescription();
		
		$Mail = $Club->getMail();

		$SQL = "UPDATE cbms_club SET Name='$Name', Description='$Description',
				Mail='$Mail', CoverPhoto='$CoverPhoto' WHERE ID='$ID'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Position based on its id of the database
	public function deleteClub($Club){


		$SQL = "DELETE from cbms_club where ID ='".$Club->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG,"exit the class.clubdao.inc");

?>