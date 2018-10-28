<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';

Class RegistrationSessionDAO{

	private $_DB;
	private $_RegistrationSession;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_RegistrationSession = new RegistrationSession();

	}

	// get all the RegistrationSessions from the database using the database query
	public function getAllRegistrationSessions(){

		$RegistrationSessionList = array();

		$this->_DB->doQuery("SELECT * FROM reg_registration_session  order by Name DESC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_RegistrationSession = new RegistrationSession();

		    $this->_RegistrationSession->setID ( $row['ID']);
		    $this->_RegistrationSession->setName( $row['Name'] );


		    $RegistrationSessionList[]=$this->_RegistrationSession;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($RegistrationSessionList);

		return $Result;
	}

	//create RegistrationSession funtion with the RegistrationSession object
	public function createRegistrationSession($RegistrationSession){

		$ID=$RegistrationSession->getID();
		$Name=$RegistrationSession->getName();


		$SQL = "INSERT INTO reg_registration_session(ID,Name) VALUES('$ID','$Name')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an RegistrationSession object based on its id form RegistrationSession object
	public function readRegistrationSession($RegistrationSession){
		
		
		$SQL = "SELECT * FROM reg_registration_session WHERE ID='".$RegistrationSession->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this RegistrationSession from the database
		$row = $this->_DB->getTopRow();

		$this->_RegistrationSession = new RegistrationSession();

		//preparing the RegistrationSession object
	    $this->_RegistrationSession->setID ( $row['ID']);
	    $this->_RegistrationSession->setName( $row['Name'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_RegistrationSession);

		return $Result;
	}

	//update an RegistrationSession object based on its 
	public function updateRegistrationSession($RegistrationSession){

		$SQL = "UPDATE reg_registration_session SET Name='".$RegistrationSession->getName()."' WHERE ID='".$RegistrationSession->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an RegistrationSession based on its id of the database
	public function deleteRegistrationSession($RegistrationSession){


		$SQL = "DELETE from reg_registration_session where ID ='".$RegistrationSession->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.RegistrationSessiondao.inc");

?>