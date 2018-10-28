<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';

Class CourseTypeDAO{

	private $_DB;
	private $_CourseType;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CourseType = new CourseType();

	}

	// get all the CourseTypes from the database using the database query
	public function getAllCourseTypes(){

		$CourseTypeList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course_type");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_CourseType = new CourseType();

		    $this->_CourseType->setID ( $row['ID']);
		    $this->_CourseType->setName( $row['Name'] );
		    $sid = $row['SessionalTypeID'];
		    $this->_DB->doQuery("SELECT * FROM reg_course_sessional_type where ID='".$sid."'");

			$newrows = $this->_DB->getAllRows();

			for($j = 0; $j < sizeof($newrows); $j++) {
				$newrow = $newrows[$j];
			
		    	$value = $newrow['Name'] ;
		    
			}
		    $this->_CourseType->setSessionalTypeID($value);
			
		    $CourseTypeList[]=$this->_CourseType;
   
		}



		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseTypeList);

		return $Result;
	}
	public function getsessionalname($sessionalID)
	{
		

		$this->_DB->doQuery("SELECT * FROM reg_course_sessional_type where ID='".$sessionalID."'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			
		    $value = $row['Name'] ;
		    
		}
		return $value;
	}

	//create CourseType funtion with the CourseType object
	public function createCourseType($CourseType){

		$ID=$CourseType->getID();
		$Name=$CourseType->getName();
		$Sessional = $CourseType->getSessionalTypeID();
		echo '<br> DAO ->' . $Sessional;
		$SQL = "INSERT INTO reg_course_type(ID,Name,SessionalTypeID) VALUES('$ID','$Name','$Sessional')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an CourseType object based on its id form CourseType object
	public function readCourseType($CourseType){
		
		
		$SQL = "SELECT * FROM reg_course_type WHERE ID='".$CourseType->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this CourseType from the database
		$row = $this->_DB->getTopRow();

		$this->_CourseType = new CourseType();

		//preparing the CourseType object
	    $this->_CourseType->setID ( $row['ID']);
	    $this->_CourseType->setName( $row['Name'] );
	    $this->_CourseType->setSessionalTypeID( $row['SessionalTypeID']);


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseType);

		return $Result;
	}

	//update an CourseType object based on its 
	public function updateCourseType($CourseType){

		$SQL = "UPDATE reg_course_type SET Name='".$CourseType->getName()."', SessionalTypeID='".$CourseType->getSessionalTypeID()."' WHERE ID='".$CourseType->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an CourseType based on its id of the database
	public function deleteCourseType($CourseType){


		$SQL = "DELETE from reg_course_type where ID ='".$CourseType->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.CourseTypedao.inc");

?>