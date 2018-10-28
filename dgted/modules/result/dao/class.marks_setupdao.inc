<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.result.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.course_typedao.inc'; //module dependency


Class MarksSetupDAO{

	private $_DB;
	private $_MarksSetup;
	private $_CourseTypeDAO;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_MarksSetup = new MarksSetup();
		$this->_CourseTypeDAO = new CourseTypeDAO();

	}

	// get all the MarksSetups from the database using the database query
	public function getAllMarksSetups(){

		$MarksSetupList = array();

		$this->_DB->doQuery("SELECT * FROM rms_marks_setup");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_MarksSetup = new MarksSetup();

		    $this->_MarksSetup->setID ( $row['ID']);

		    $CourseType = new CourseType();
		    $CourseType->setID($row['CourseTypeID']);

		    $this->_MarksSetup->setCourseType( $this->_CourseTypeDAO->readCourseType($CourseType)->getResultObject());

		    $this->_MarksSetup->setHeaderID( $row['HeaderID'] );

		    $this->_MarksSetup->setHeaderName( $row['HeaderName'] );

		    $this->_MarksSetup->setHeaderMax( $row['HeaderMax'] );

		    $this->_MarksSetup->setIsDefault( $row['IsDefault'] );

		    $MarksSetupList[]=$this->_MarksSetup; 
		}

		//todo: LOG util with level of log

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($MarksSetupList);

		return $Result;
	}




	//create MarksSetup funtion with the MarksSetup object
	public function createMarksSetup($MarksSetup){

		$ID=$MarksSetup->getID();
		$CourseTypeID=$MarksSetup->getCourseType();
		$HeaderID=$MarksSetup->getHeaderID();
		$HeaderName=$MarksSetup->getHeaderName();
		$HeaderMax=$MarksSetup->getHeaderMax();
		$IsDefault=$MarksSetup->getIsDefault();

		$SQL = "INSERT INTO rms_marks_setup(ID,CourseTypeID,HeaderID,HeaderName,HeaderMax,IsDefault) 
							VALUES('$ID','$CourseTypeID','$HeaderID','$HeaderName','$HeaderMax',
							'$IsDefault')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	
	//read an MarksSetup object based on its id form MarksSetup object
	public function readMarksSetup($MarksSetup){
		
		
		$SQL = "SELECT * FROM rms_marks_setup WHERE ID='".$MarksSetup->getID()."'";
		
		$this->_DB->doQuery($SQL);

		//reading the top row for this MarksSetup from the database
		$row = $this->_DB->getTopRow();

		$this->_MarksSetup = new MarksSetup();
    
    	$this->_MarksSetup->setID ( $row['ID']);

		//preparing the MarksSetup object
	    $CourseType = new CourseType();
	    $CourseType->setID($row['CourseTypeID']);

	    $this->_MarksSetup->setCourseType( $this->_CourseTypeDAO->readCourseType($CourseType)->getResultObject());

	    $this->_MarksSetup->setHeaderID( $row['HeaderID'] );

	    $this->_MarksSetup->setHeaderName( $row['HeaderName'] );

	    $this->_MarksSetup->setHeaderMax( $row['HeaderMax'] );

	    $this->_MarksSetup->setIsDefault( $row['IsDefault'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_MarksSetup);

		return $Result;
	}

	
	//update an MarksSetup object based on its 
	public function updateMarksSetup($MarksSetup){

		$ID=$MarksSetup->getID();
		$CourseTypeID=$MarksSetup->getCourseType();
		$HeaderID=$MarksSetup->getHeaderID();
		$HeaderName=$MarksSetup->getHeaderName();
		$HeaderMax=$MarksSetup->getHeaderMax();
		$IsDefault=$MarksSetup->getIsDefault();

		$SQL = "UPDATE rms_marks_setup SET CourseTypeID='$CourseTypeID', HeaderID='$HeaderID', 
		  HeaderName='$HeaderName', HeaderMax='$HeaderMax', IsDefault='$IsDefault' WHERE 
		  ID='$ID'"; 


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an MarksSetup based on its id of the database
	public function deleteMarksSetup($MarksSetup){


		$SQL = "DELETE from rms_marks_setup where ID ='".$MarksSetup->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.MarksSetupdao.inc");

?>