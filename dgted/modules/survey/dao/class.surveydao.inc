<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';
include_once UTILITY.'class.util.inc';


Class SurveyDAO{

	private $_DB;
	private $_Survey;
	private $_User;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Survey = new Survey();
		$this->_User = new User();

	}

	// get all the Surveys from the database using the database query
	public function getAllSurveys(){

		$SurveyList = array();

		$this->_DB->doQuery("SELECT * FROM svms_survey");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Survey = new Survey();

		    $this->_Survey->setID ( $row['ID']);
		    $this->_Survey->setTitle ( $row['Title'] );   
		    $this->_Survey->setDescription ( $row['Description'] );
		    $this->_Survey->setLink ( $row['Link'] );
		    $this->_Survey->setTotalQuestions( $row['TotalQuestions'] );
		    $this->_Survey->setCreator( $row['CreatorID'] );
		    $this->_Survey->setCreationDate( $row['CreationDate'] );
		    $this->_Survey->setCompletionDate( $row['CompletionDate'] );

		    $SurveyList[]=$this->_Survey;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SurveyList);

		return $Result;
	}

	public function getAllUsers(){
		$UserList = array();

		$this->_DB->doQuery("SELECT * FROM ums_user");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_User = new User();

			$this->_User->setID ( $row['ID']);
			$this->_User->setFirstName( $row['FirstName']." ".$row['LastName'] );


			$UserList[]=$this->_User;

		}
		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($UserList);

		return $Result;
	}

	//create Survey funtion with the Survey object
	public function createSurvey($Survey){

		$ID=$Survey->getID();
		$Title=$Survey->getTitle();
		$Description=$Survey->getDescription();
		$Link=$Survey->getLink();
		//$Link=" survey.php";
		$TotalQuestions=$Survey->getTotalQuestions();
		$CreatorID=$Survey->getCreator();
		$CreationDate=$Survey->getCreationDate();
		$CompletionDate=$Survey->getCompletionDate();
		//<a href="survey.php<?php echo $Survey->getID()"
		$SQL = "INSERT INTO svms_survey(ID,Title,Description,Link,TotalQuestions,CreatorID,CreationDate,CompletionDate) 
		 	VALUES('$ID','$Title','$Description','$Link','$TotalQuestions','$CreatorID',CURRENT_TIMESTAMP,'$CompletionDate')";
		 	
		//echo $SQL;

		$SQL = $this->_DB->doQuery($SQL);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	public function getTeacherFromID($ID){
		$SQL = "SELECT * FROM ums_user WHERE ID = '$ID'";

		$this->_DB->doQuery($SQL);
		$rows = $this->_DB->getAllRows();
		$row = $rows[0];
		return $row['FirstName']." ".$row['LastName'];
	}
	//read an Survey object based on its id from Survey object
	public function readSurvey($Survey){
		

		$SQL = "SELECT * FROM svms_survey WHERE ID='".$Survey->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Survey from the database
		$row = $this->_DB->getTopRow();

		$this->_Survey = new Survey();

		//preparing the Survey object
	    	$this->_Survey->setID ( $row['ID']);
		    $this->_Survey->setTitle ( $row['Title'] );   
		    $this->_Survey->setDescription ( $row['Description'] );
		    $this->_Survey->setLink ( $row['Link'] );
		    $this->_Survey->setTotalQuestions( $row['TotalQuestions'] );
		    $this->_Survey->setCreator( $row['CreatorID'] );
		    $this->_Survey->setCreationDate( $row['CreationDate'] );
		    $this->_Survey->setCompletionDate( $row['CompletionDate'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Survey);

		return $Result;
	}


	//update an Survey object based on its id information
	public function updateSurvey($Survey){

		$SQL = "UPDATE svms_survey SET Title='".$Survey->getTitle()."', 
			Description='".$Survey->getDescription()."',
			Link='".$Survey->getLink()."',
			TotalQuestions='".$Survey->getTotalQuestions()."',
			CreatorID='".$Survey->getCreator()."',
			CompletionDate='".$Survey->getCompletionDate()."'
			WHERE ID='".$Survey->getID()."'";

		$SQL = $this->_DB->doQuery($SQL);
	
		//closing the transaction
		//$this->_DB->getConnection()->commit();



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		return $Result;

	}

	//delete an Survey based on its id of the database
	public function deleteSurvey($Survey){

		// check the deleted row to true in the Survey now
		$SQL = "DELETE from svms_survey where ID ='".$Survey->getID()."'";

		//print_r($SQL);
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}


//$_Log->log(LogUtil::$DEBUG," exit the class.surveydao.inc");

?>