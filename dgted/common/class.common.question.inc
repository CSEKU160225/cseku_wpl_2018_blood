<?php

class Question {

    private $_ID;
    private $_Title;
    private $_Course;
    private $_Term;
    private $_Session;
    private $_Teacher;
    private $_Type;
    private $_Tag;
    private $_Link;
    private $_QuestionDate;
    private $_Creator;

    public function setCreator($creator){
        $this->_Creator = $creator;
    }
    public function getCreator(){
        return $this->_Creator;
    }
    public function setID($ID){
        $this->_ID = $ID;
    }
    public function getID(){
        return $this->_ID;
    }
    public function setTitle($Title){
        $this->_Title = $Title;
    }
    public function getTitle(){
        return $this->_Title;
    }
    public function setCourse($Course){
        $this->_Course = $Course;
    }
    public function getCourse(){
        return $this->_Course;
    }
    public function setTerm($Term){
        $this->_Term = $Term;
    }
    public function getTerm(){
        return $this->_Term;
    }
    public function setSession($Session){
        $this->_Session = $Session;
    }
    public function getSession(){
        return $this->_Session;
    }
    public function setTeacher($Teacher){
        $this->_Teacher = $Teacher;
    }
    public function getTeacher(){
        return $this->_Teacher;
    }
    public function setType($Type){
        $this->_Type = $Type;
    }
    public function getType(){
        return $this->_Type;
    }
    public function setTag($Tag){
        $this->_Tag = $Tag;
    }
    public function getTag(){
        return $this->_Tag;
    }   
    public function setLink($Link){
        $this->_Link = $Link;
    }
    public function getLink(){
        return $this->_Link;
    } 
    public function setQuestionDate($Date){
        $this->_QuestionDate = $Date;
    }
    public function getQuestionDate(){
        return $this->_QuestionDate;
    } 
}

?>
