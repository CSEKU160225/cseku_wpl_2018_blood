<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';

Class YearDAO{

	private $_DB;
	private $_Year;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Year = new Year();

	}

	// get all the Years from the database using the database query
	public function getAllYears(){

		$YearList = array();

		$this->_DB->doQuery("SELECT * FROM reg_year order by Name ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Year = new Year();

		    $this->_Year->setID ( $row['ID']);
		    $this->_Year->setName( $row['Name'] );


		    $YearList[]=$this->_Year;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($YearList);

		return $Result;
	}

	//create Year funtion with the Year object
	public function createYear($Year){

		$ID=$Year->getID();
		$Name=$Year->getName();


		$SQL = "INSERT INTO reg_year(ID,Name) VALUES('$ID','$Name')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Year object based on its id form Year object
	public function readYear($Year){
		
		
		$SQL = "SELECT * FROM reg_year WHERE ID='".$Year->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Year from the database
		$row = $this->_DB->getTopRow();

		$this->_Year = new Year();

		//preparing the Year object
	    $this->_Year->setID ( $row['ID']);
	    $this->_Year->setName( $row['Name'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Year);

		return $Result;
	}

	//update an Year object based on its 
	public function updateYear($Year){

		$SQL = "UPDATE reg_year SET Name='".$Year->getName()."' WHERE ID='".$Year->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Year based on its id of the database
	public function deleteYear($Year){


		$SQL = "DELETE from reg_year where ID ='".$Year->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Yeardao.inc");

?>