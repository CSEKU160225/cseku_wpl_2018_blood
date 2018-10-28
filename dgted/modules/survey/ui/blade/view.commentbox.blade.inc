<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.commentboxbao.inc';


$_SurveyQuestionBAO = new SurveyQuestionBAO();
$_DB = DBUtil::getInstance();

/* saving a new SurveyQuestion account*/
if(isset($_POST['save']))
{
	 $SurveyQuestion = new SurveyQuestion();	
	 
	 $SurveyQuestion->setID(Util::getGUID());
     $SurveyQuestion->setQuestionValue($_DB->secureInput($_POST['txtsurveyquestion']));

	 $_SurveyQuestionBAO->createSurveyQuestion($SurveyQuestion);		 
}


/* deleting an existing SurveyQuestion */
if(isset($_GET['del']))
{

	$SurveyQuestion = new SurveyQuestion();	
	$SurveyQuestion->setID($_GET['del']);	

	$_SurveyQuestionBAO->deleteSurveyQuestion($SurveyQuestion); //reading the SurveyQuestion object from the result object

	header("Location: view.commentbox.php");
}


/* reading an existing SurveyQuestion information */
if(isset($_GET['edit']))
{
	$SurveyQuestion = new SurveyQuestion();	
	$SurveyQuestion->setID($_GET['edit']);	
	$getROW = $_SurveyQuestionBAO->readSurveyQuestion($SurveyQuestion)->getResultObject(); //reading the SurveyQuestion object from the result object

	//header("Location: view.commentbox.php");
}

/*updating an existing SurveyQuestion information*/
if(isset($_POST['update']))
{
	$SurveyQuestion = new SurveyQuestion();	

    $SurveyQuestion->setID ($_GET['edit']);
    $SurveyQuestion->setQuestionValue( $_POST['txtsurveyquestion'] );
	
	$_SurveyQuestionBAO->updateSurveyQuestion($SurveyQuestion);

	header("Location: view.commentbox.php");
}



////$_Log->log(LogUtil::$DEBUG," exit blade.commentbox.php");

?>