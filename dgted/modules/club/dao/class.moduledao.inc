<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';
include_once UTILITY.'class.util.inc';

Class ModuleDAO{

	private $_DB;
	private $_Module;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Module = new ClubModule();

	}

	//get all the Club from the database using the database query
	public function getAllModule($Club){

		$ModuleList = array();

		$Club_ID = $Club->getID();

		$this->_DB->doQuery("SELECT * FROM cbms_club_module WHERE ClubID ='$Club_ID' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Module = new ClubModule();

		    $this->_Module->setClubID ( $row['ClubID']);
		    $this->_Module->setModuleID( $row['ModuleID']);
		    $this->_Module->setModuleName( $row['ModuleName'] );
		    $this->_Module->setContent( $row['Content']);


		    $ModuleList[]=$this->_Module;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($ModuleList);

		return $Result;
	}

	//create module to a club object
	public function createModule($Module){

		$ID=$Module->getClubID();
		$ModuleID=$Module->getModuleID();
		$Name=$Module->getModuleName();
		$IsVisible=$Module->getIsVisible();
		$Content=$Module->getContent();
		//$NoOfModules=$Module->getNoOfModules();
		


		$SQL = "INSERT INTO cbms_club_module(ClubID,ModuleID,ModuleName,IsVisible,Content) VALUES('$ID','$ModuleID','$Name','$IsVisible','$Content')";

		//echo $SQL;
		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Position object based on its id form Position object
	public function readModule($Module){
		
		
		$SQL = "SELECT * FROM cbms_club_module WHERE ModuleID='".$Module->getModuleID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Position from the database
		$row = $this->_DB->getTopRow();

		$this->_Module = new ClubModule();

		//preparing the Position object
	    $this->_Module->setClubID ( $row['ClubID']);
	    $this->_Module->setModuleID ( $row['ModuleID']);
	    $this->_Module->setModuleName( $row['ModuleName'] );
	    $this->_Module->setIsVisible( $row['IsVisible'] );

 	    $this->_Module->setContent( $row['Content'] );
 	   // $this->_Module->setNoOfModules( $row['NoOfModules'] );






	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Module);

		return $Result;
	}

	//update an Position object based on its 
	public function updateModule($Module){


		$ID=$Module->getClubID();
		$ModuleID=$Module->getModuleID();
		$Name=$Module->getModuleName();
		$IsVisible=$Module->getIsVisible();
		$Content=$Module->getContent();		

		$SQL = "UPDATE cbms_club_module SET ModuleName='$Name',IsVisible='$IsVisible', 
				Content='$Content' WHERE ModuleID='$ModuleID'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Position based on its id of the databas
	public function deleteModule($Module){


		$SQL = "DELETE from cbms_club_module where ModuleID ='".$Module->getModuleID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}



}

//$_Log->log(LogUtil::$DEBUG," exit the class.moduledao.inc");

?>