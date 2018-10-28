<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.survey_ques_typebao.inc';


$_SurveyQuestionTypeBAO = new SurveyQuestionTypeBAO();
$_DB = DBUtil::getInstance();

/* saving a new SurveyQuestionType account*/
if(isset($_POST['save']))
{
	 $SurveyQuestionType = new SurveyQuestionType();	
	 $SurveyQuestionType->setID(Util::getGUID());
     $SurveyQuestionType->setType($_DB->secureInput($_POST['txtType']));
	 $_SurveyQuestionTypeBAO->createSurveyQuestionType($SurveyQuestionType);		 
}


/* deleting an existing SurveyQuestionType */
if(isset($_GET['del']))
{

	$SurveyQuestionType = new SurveyQuestionType();	
	$SurveyQuestionType->setID($_GET['del']);	
	$_SurveyQuestionTypeBAO->deleteSurveyQuestionType($SurveyQuestionType); //reading the SurveyQuestionType object from the result object

	header("Location:".PageUtil::$SURVEY_QUES_TYPE);
}


/* reading an existing SurveyQuestionType information */
if(isset($_GET['edit']))
{
	$SurveyQuestionType = new SurveyQuestionType();	
	$SurveyQuestionType->setID($_GET['edit']);	
	$getROW = $_SurveyQuestionTypeBAO->readSurveyQuestionType($SurveyQuestionType)->getResultObject(); //reading the SurveyQuestionType object from the result object
}

/*updating an existing SurveyQuestionType information*/
if(isset($_POST['update']))
{
	$SurveyQuestionType = new SurveyQuestionType();	

    $SurveyQuestionType->setID ($_GET['edit']);
    $SurveyQuestionType->setType( $_POST['txtType'] );
	
	$_SurveyQuestionTypeBAO->updateSurveyQuestionType($SurveyQuestionType);

	header("Location:".PageUtil::$SURVEY_QUES_TYPE);
}



//$_Log->log(LogUtil::$DEBUG," exit view.blade.questiontype.inc");

?>