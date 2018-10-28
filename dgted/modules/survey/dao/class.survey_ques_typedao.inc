<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';
include_once UTILITY.'class.util.inc';

Class SurveyQuestionTypeDAO{

	private $_DB;
	private $_SurveyQuestionType;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_SurveyQuestionType = new SurveyQuestionType();

	}

	// get all the SurveyQuestionTypes from the database using the database query
	public function getAllSurveyQuestionTypes(){

		$SurveyQuestionTypeList = array();

		$this->_DB->doQuery("SELECT * FROM svms_survey_question_type");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_SurveyQuestionType = new SurveyQuestionType();

		    $this->_SurveyQuestionType->setID ( $row['ID']);
		    $this->_SurveyQuestionType->setType( $row['Type'] );


		    $SurveyQuestionTypeList[]=$this->_SurveyQuestionType;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SurveyQuestionTypeList);

		return $Result;
	}

	//create SurveyQuestionType funtion with the SurveyQuestionType object
	public function createSurveyQuestionType($SurveyQuestionType){

		$ID=$SurveyQuestionType->getID();
		$Type=$SurveyQuestionType->getType();


		$SQL = "INSERT INTO svms_survey_question_type(ID,Type) VALUES('$ID','$Type')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an SurveyQuestionType object based on its id form SurveyQuestionType object
	public function readSurveyQuestionType($SurveyQuestionType){
		
		
		$SQL = "SELECT * FROM svms_survey_question_type WHERE ID='".$SurveyQuestionType->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this SurveyQuestionType from the database
		$row = $this->_DB->getTopRow();

		$this->_SurveyQuestionType = new SurveyQuestionType();

		//preparing the SurveyQuestionType object
	    $this->_SurveyQuestionType->setID ( $row['ID']);
	    $this->_SurveyQuestionType->setType( $row['Type'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_SurveyQuestionType);

		return $Result;
	}

	//update an SurveyQuestionType object based on its 
	public function updateSurveyQuestionType($SurveyQuestionType){

		$SQL = "UPDATE svms_survey_question_type SET Type='".$SurveyQuestionType->getType()."' WHERE ID='".$SurveyQuestionType->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an SurveyQuestionType based on its id of the database
	public function deleteSurveyQuestionType($SurveyQuestionType){


		$SQL = "DELETE from svms_survey_question_type where ID ='".$SurveyQuestionType->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.questiontypedao.inc");

?>