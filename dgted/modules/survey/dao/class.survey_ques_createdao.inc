<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';
include_once UTILITY.'class.util.inc';

class QuestionDAO2{
    private $_DB;
    private $_surveyQuestion;
    private $_surQueFill;

    public function __construct(){
        $this->_DB = DBUtil::getInstance();
        $this->_surveyQuestion = new SurveyQuestion();
        $this->_surQueFill = new SurveyQuestionFilled();
    }

    public function getNumOfQue($sID){
        $sql = "select TotalQuestions from svms_survey where ID = '{$sID}'";

        $this->_DB->doQuery($sql);

        $rows = $this->_DB->getAllRows();

        $row = $rows[0];

        return $row['TotalQuestions'];
    }

    public function createQuestion($QuestionOb){
        $qID = $QuestionOb->getID();
        $surID = $QuestionOb->getSurveyID();
        $qNO = $QuestionOb->getQuestionNo();
        $qType = $QuestionOb->getQuestionType();
        $qVal = $QuestionOb->getQuestionValue();
        $noOp = $QuestionOb->getNumberOfOptions();

        $sql = "insert into  svms_survey_question(ID, SurveyID, QuestionNo, QuestionType, QuestionValue, NumberOfOption) VALUES ('$qID','$surID','$qNO','$qType','$qVal','$noOp')";
        

        $this->_DB->doQuery($sql);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($sql);

        return $Result;

    }

    public function createQuestionOption($queOpt){
        $id = $queOpt->getID();
        $surID = $queOpt->getSurveyID();
        $queID = $queOpt->getQuestionID();
        $optVal = $queOpt->getQuestionFieldValue();

        $sql = "insert into svms_survey_question_option(ID, SurveyID, QuestionID, OptionFieldValue) VALUES ('$id','$surID','$queID','$optVal')";

        $this->_DB->doQuery($sql);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($sql);

        return $Result;
    }

    public function getSurveyTitle($sID){
        $this->_DB->doQuery("select Title from svms_survey where ID='$sID'");

        $rows = $this->_DB->getAllRows();
        $row = $rows[0];

        echo $row['Title'];

    }

    public function getAllQuestions($sID){


        $questionList = array();
        $this->_DB->doQuery("select * from svms_survey_question where SurveyID='$sID'");

        $rows = $this->_DB->getAllRows();

        for($i=0;$i<sizeof($rows);$i++){
            $row = $rows[$i];
            $this->_surveyQuestion = new SurveyQuestion();

            $this->_surveyQuestion->setID($row['ID']);
            $this->_surveyQuestion->setSurveyID($row['SurveyID']);
            $this->_surveyQuestion->setQuestionNo($row['QuestionNo']);
            $this->_surveyQuestion->setQuestionType($row['QuestionType']);
            $this->_surveyQuestion->setQuestionValue($row['QuestionValue']);
            $this->_surveyQuestion->setNumberOfOptions($row['NumberOfOption']);

            $questionList[] = $this->_surveyQuestion;
        }

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($questionList);

        return $Result;

    }

    public function getAllOption($sID,$qID){

        $optionList = array();
        $this->_DB->doQuery("select * from svms_survey_question_option where SurveyID='$sID' and QuestionID='$qID'");

        $rows = $this->_DB->getAllRows();

        for($i=0;$i<sizeof($rows);$i++){
            $row = $rows[$i];
            $surQueOptOb = new SurveyQuestionOption();

            $surQueOptOb->setID($row['ID']);
            $surQueOptOb->setSurveyID($row['SurveyID']);
            $surQueOptOb->setQuestionID($row['QuestionID']);
            $surQueOptOb->setQuestionFieldValue($row['OptionFieldValue']);

            $optionList[] = $surQueOptOb;
        }

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($optionList);

        return $Result;

    }

    public function createSurveyQuestionFilled($filledData){

        $qID = $filledData->getQuestionID();
        $sID = $filledData->getSurveyID();
        $val = $filledData->getFilledValue();
        $uID = $filledData->getFilledUserID();
        $time = $filledData->getFilledTime();

        $sql = "insert into svms_survey_question_filled(SurveyID, QuestionID, FilledValue, FilledUserID, FilledTime) value('$sID','$qID','$val','$uID','$time')";

        $this->_DB->doQuery($sql);

        echo "Success";


    }


}