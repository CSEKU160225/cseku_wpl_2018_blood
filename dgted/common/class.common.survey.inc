<?php

/*All the common Model classes are listed here*/



class Survey{

    private $_ID;
    private $_Title;
    private $_Description;
    private $_Link;
    private $_TotalQuestions;
    private $_Creator;
    private $_CreationDate;
    private $_CompletionDate;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setTitle( $Title ) {
        $this->_Title= $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }

    public function setDescription ( $Description ) {
        $this->_Description = $Description;
    }

    public function getDescription () {
        return $this->_Description;
    }

    public function setLink ( $Link ) {
        $this->_Link = $Link;
    }

    public function getLink () {
        return $this->_Link;
    }

    public function setTotalQuestions ( $TotalQuestions ) {
        $this->_TotalQuestions = $TotalQuestions;
    }

    public function getTotalQuestions () {
        return $this->_TotalQuestions;
    }

    public function setCreator ( $Creator ) {
        $this->_Creator= $Creator;
    }

    public function getCreator () {
        return $this->_Creator;
    }

    public function setCreationDate ( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate () {
        return $this->_CreationDate;
    }

    public function setCompletionDate ( $CompletionDate ) {
        $this->_CompletionDate = $CompletionDate;
    }

    public function getCompletionDate () {
        return $this->_CompletionDate;
    }
}

class SurveyQuestion{

    private $_ID;
    private $_SurveyID;
    private $_QuestionNo;
    private $_QuestionType;
    private $_QuestionValue;
    private $_NumberOfOptions;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setSurveyID( $SurveyID ) {
        $this->_SurveyID= $SurveyID;
    }

    public function getSurveyID() {
        return $this->_SurveyID;
    }

    public function setQuestionNo ( $QuestionNo ) {
        $this->_QuestionNo = $QuestionNo;
    }

    public function getQuestionNo () {
        return $this->_QuestionNo;
    }

    public function setQuestionType ( $QuestionType ) {
        $this->_QuestionType = $QuestionType;
    }

    public function getQuestionType () {
        return $this->_QuestionType;
    }

    public function setQuestionValue ( $QuestionValue ) {
        $this->_QuestionValue = $QuestionValue;
    }

    public function getQuestionValue () {
        return $this->_QuestionValue;
    }

    public function setNumberOfOptions($NumOfOptions){
        $this->_NumberOfOptions=$NumOfOptions;
    }

    public function getNumberOfOptions(){
        return $this->_NumberOfOptions;
    }

}

class SurveyQuestionOption{
    private $_ID;
    private $_SurveyID;
    private $_QuestionID;
    private $_OptionFieldValue;

    public function setID($id){
        $this->_ID = $id;
    }

    public function getID(){
        return $this->_ID;
    }

    public function setSurveyID($surveyID){
        $this->_SurveyID = $surveyID;
    }

    public function getSurveyID(){
        return $this->_SurveyID;
    }

    public function setQuestionID($qID){
        $this->_QuestionID = $qID;
    }

    public function getQuestionID(){
        return $this->_QuestionID;
    }

    public function setQuestionFieldValue($fieldValue){
        $this->_OptionFieldValue = $fieldValue;
    }

    public function getQuestionFieldValue(){
        return $this->_OptionFieldValue;
    }
}


class SurveyQuestionFilled{

    private $_ID;
    private $_SurveyID;
    private $_QuestionID;
    private $_FilledValue;
    private $_FilledUserID;
    private $_FilledTime;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setSurveyID( $SurveyID ) {
        $this->_SurveyID= $SurveyID;
    }

    public function getSurveyID() {
        return $this->_SurveyID;
    }

    public function setQuestionID ( $QuestionID ) {
        $this->_QuestionID = $QuestionID;
    }

    public function getQuestionID () {
        return $this->_QuestionID;
    }

    public function setFilledValue ( $FilledValue ) {
        $this->_FilledValue = $FilledValue;
    }

    public function getFilledValue () {
        return $this->_FilledValue;
    }

    public function setFilledUserID ( $FilledUserID ) {
        $this->_FilledUserID= $FilledUserID;
    }

    public function getFilledUserID () {
        return $this->_FilledUserID;
    }

    public function setFilledTime ( $FilledTime ) {
        $this->_FilledTime = $FilledTime;
    }

    public function getFilledTime () {
        return $this->_FilledTime;
    }
}



class SurveyQuestionType{
    private $_ID;
    private $_Type;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setType( $Type) {
        $this->_Type= $Type;
    }

    public function getType() {
        return $this->_Type;
    }
}


?>