<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';

Class PositionDAO{

	private $_DB;
	private $_Position;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Position = new Position();

	}

	// get all the Positions from the database using the database query
	public function getAllPositions(){

		$PositionList = array();

		$this->_DB->doQuery("SELECT * FROM ums_position order by Name ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Position = new Position();

		    $this->_Position->setID ( $row['ID']);
		    $this->_Position->setName( $row['Name'] );


		    $PositionList[]=$this->_Position;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($PositionList);

		return $Result;
	}

	//create Position funtion with the Position object
	public function createPosition($Position){

		$ID=$Position->getID();
		$Name=$Position->getName();


		$SQL = "INSERT INTO ums_position(ID,Name) VALUES('$ID','$Name')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Position object based on its id form Position object
	public function readPosition($Position){
		
		
		$SQL = "SELECT * FROM ums_position WHERE ID='".$Position->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Position from the database
		$row = $this->_DB->getTopRow();

		$this->_Position = new Position();

		//preparing the Position object
	    $this->_Position->setID ( $row['ID']);
	    $this->_Position->setName( $row['Name'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Position);

		return $Result;
	}

	//update an Position object based on its 
	public function updatePosition($Position){

		$SQL = "UPDATE ums_position SET Name='".$Position->getName()."' WHERE ID='".$Position->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Position based on its id of the database
	public function deletePosition($Position){


		$SQL = "DELETE from ums_position where ID ='".$Position->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.positiondao.inc");

?>