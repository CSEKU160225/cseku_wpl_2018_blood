<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.result.inc';
include_once UTILITY.'class.util.inc';


Class GradeSetupDAO{

	private $_DB;
	private $_GradeSetup;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_GradeSetup = new GradeSetup();
	}

	// get all the GradeSetups from the database using the database query
	public function getAllGradeSetups(){

		$GradeSetupList = array();

		$this->_DB->doQuery("SELECT * FROM rms_grade_setup");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_GradeSetup = new GradeSetup();

		    $this->_GradeSetup->setID ( $row['ID']);

		    $this->_GradeSetup->setGrades( $row['Grades'] );

		    $this->_GradeSetup->setRanges( $row['Ranges'] );

		    $this->_GradeSetup->setIsDefault( $row['IsDefault'] );

		    $GradeSetupList[]=$this->_GradeSetup; 
		}

		//todo: LOG util with level of log

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($GradeSetupList);

		return $Result;
	}




	//create GradeSetup funtion with the GradeSetup object
	public function createGradeSetup($GradeSetup){

		$ID=$GradeSetup->getID();
		$Grades=$GradeSetup->getGrades();
		$Ranges=$GradeSetup->getRanges();
		$IsDefault=$GradeSetup->getIsDefault();

		$SQL = "INSERT INTO rms_grade_setup(ID,Grades,Ranges,IsDefault) 
							VALUES('$ID','$Grades','$Ranges','$IsDefault')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	
	//read an GradeSetup object based on its id form GradeSetup object
	public function readGradeSetup($GradeSetup){
		
		
		$SQL = "SELECT * FROM rms_grade_setup WHERE ID='".$GradeSetup->getID()."'";
		
		$this->_DB->doQuery($SQL);

		//reading the top row for this GradeSetup from the database
		$row = $this->_DB->getTopRow();

		$this->_GradeSetup = new GradeSetup();
    
    	$this->_GradeSetup->setID ( $row['ID']);

	    $this->_GradeSetup->setGrades( $row['Grades'] );

	    $this->_GradeSetup->setRanges( $row['Ranges'] );

	    $this->_GradeSetup->setIsDefault( $row['IsDefault'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_GradeSetup);

		return $Result;
	}

	//read the default GradeSetup 
	public function readDefaultGradeSetup(){
		
		
		$SQL = "SELECT * FROM rms_grade_setup WHERE IsDefault='1' LIMIT 1";
		
		$this->_DB->doQuery($SQL);

		//reading the top row for this GradeSetup from the database
		$row = $this->_DB->getTopRow();

		$this->_GradeSetup = new GradeSetup();
    
    	$this->_GradeSetup->setID ( $row['ID']);

	    $this->_GradeSetup->setGrades( $row['Grades'] );

	    $this->_GradeSetup->setRanges( $row['Ranges'] );

	    $this->_GradeSetup->setIsDefault( $row['IsDefault'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_GradeSetup);

		return $Result;
	}

	
	//update an GradeSetup object based on its 
	public function updateGradeSetup($GradeSetup){

		$ID=$GradeSetup->getID();
		$Grades=$GradeSetup->getGrades();
		$Ranges=$GradeSetup->getRanges();
		$IsDefault=$GradeSetup->getIsDefault();

		$SQL = "UPDATE rms_grade_setup SET Grades='$Grades', Ranges='$Ranges', 
		  IsDefault='$IsDefault' WHERE 
		  ID='$ID'"; 


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an GradeSetup based on its id of the database
	public function deleteGradeSetup($GradeSetup){


		$SQL = "DELETE from rms_grade_setup where ID ='".$GradeSetup->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.GradeSetupdao.inc");

?>