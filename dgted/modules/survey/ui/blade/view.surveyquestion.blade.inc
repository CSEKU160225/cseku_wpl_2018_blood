<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.questiontypebao.inc';


$_SurveyQuestionTypeBAO = new SurveyQuestionTypeBAO();
$_DB = DBUtil::getInstance();
$_Log = LogUtil::getInstance();

/* saving a new QuestionType account*/
if(isset($_POST['save']))
{
	 $SurveyQuestionType = new SurveyQuestionType();

	if(isset($_POST['selectedQuestionType']))	
	 	$SurveyQuestionType->setID($_POST['selectedQuestionType']);
}



/* reading an existing QuestionType information */
if(isset($_GET['edit']))
{
	$SurveyQuestionType = new SurveyQuestionType();	
	$SurveyQuestionType->setID($_GET['edit']);	
	$globalSurveyQuestionType = $_SurveyQuestionTypeBAO->readSurveyQuestionType($SurveyQuestionType)->getResultObject(); //reading the QuestionType object from the result object
}

//if a permission(ID) is present in the list of list(permissions(ID))


////$_Log->log(LogUtil::$DEBUG," exit blade.surveyquestion.inc");

?>