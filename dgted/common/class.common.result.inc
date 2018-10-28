<?php

class MarksSetup{

    private $_ID;
    private $_CourseType;
    private $_HeaderID;
    private $_HeaderName;
    private $_HeaderMax;
    private $_IsDefault;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setCourseType( $CourseType ) {
        $this->_CourseType = $CourseType;
    }

    public function getCourseType() {
        return $this->_CourseType;
    }

    public function setHeaderID( $HeaderID ) {
        $this->_HeaderID = $HeaderID;
    }

    public function getHeaderID() {
        return $this->_HeaderID;
    }

    public function setHeaderName( $HeaderName ) {
        $this->_HeaderName = $HeaderName;
    }

    public function getHeaderName() {
        return $this->_HeaderName;
    }

    public function setHeaderMax( $HeaderMax ) {
        $this->_HeaderMax = $HeaderMax;
    }

    public function getHeaderMax() {
        return $this->_HeaderMax;
    }

    public function setIsDefault($Default){
    	$this->_IsDefault=$Default;
    }

    public function getIsDefault(){
    	return $this->_IsDefault;
    }

}

class GradeSetup{

    private $_ID;
    private $_Grades;
    private $_Ranges;
    private $_IsDefault;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setGrades( $Grades ) {
        $this->_Grades = $Grades;
    }

    public function getGrades() {
        return $this->_Grades;
    }

    public function setRanges( $Ranges ) {
        $this->_Ranges = $Ranges;
    }

    public function getRanges() {
        return $this->_Ranges;
    }

 
    public function setIsDefault($Default){
        $this->_IsDefault=$Default;
    }

    public function getIsDefault(){
        return $this->_IsDefault;
    }

}

class MarksEntry{
    private $_ID;
    private $_Course;
    private $_Teacher;
    private $_Session;
    private $_Year;
    private $_Term;
    private $_Student;

    private $_MarksID;   
    private $_MarksValue; 
    private $_MarksTotal;

    private $_Status;

    private $_HeaderID;
    private $_HeaderName;
    private $_HeaderMax;  

    private $_Grades;
    private $_GradeRanges;
    private $_FinalGrade;  

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setCourse( $Course ) {
        $this->_Course = $Course;
    }

    public function getCourse() {
        return $this->_Course;
    }

    public function setTeacher( $Teacher ) {
        $this->_Teacher = $Teacher;
    }

    public function getTeacher() {
        return $this->_Teacher;
    }


    public function setSession( $Session ) {
        $this->_Session = $Session;
    }

    public function getSession() {
        return $this->_Session;
    }

    public function setYear( $Year ) {
        $this->_Year = $Year;
    }

    public function getYear() {
        return $this->_Year;
    }

    public function setTerm( $Term ) {
        $this->_Term = $Term;
    }

    public function getTerm() {
        return $this->_Term;
    }

    public function setStudent( $Student ) {
        $this->_Student = $Student;
    }

    public function getStudent() {
        return $this->_Student;
    }    

    public function setMarksID ( $MarksID ) {
        $this->_MarksID = $MarksID;
    }

    public function getMarksID () {
        return $this->_MarksID;
    }

    public function setMarksValue ( $MarksValue ) {
        $this->_MarksValue = $MarksValue;
    }

    public function getMarksValue () {
        return $this->_MarksValue;
    }

    public function setMarksTotal ( $MarksTotal ) {
        $this->_MarksTotal = $MarksTotal;
    }

    public function getMarksTotal () {
        return $this->_MarksTotal;
    }

    public function setStatus($Status){
        $this->_Status=$Status;
    }

    public function getStatus(){
        return $this->_Status;
    }


    public function setHeaderID( $HeaderID ) {
        $this->_HeaderID = $HeaderID;
    }

    public function getHeaderID() {
        return $this->_HeaderID;
    }

    public function setHeaderName( $HeaderName ) {
        $this->_HeaderName = $HeaderName;
    }

    public function getHeaderName() {
        return $this->_HeaderName;
    }

    public function setHeaderMax( $HeaderMax ) {
        $this->_HeaderMax = $HeaderMax;
    }

    public function getHeaderMax() {
        return $this->_HeaderMax;
    }
///
    public function setGrades( $Grades ) {
        $this->_Grades = $Grades;
    }

    public function getGrades() {
        return $this->_Grades;
    }

    public function setGradeRanges( $GradeRanges) {
        $this->_GradeRanges = $GradeRanges;
    }

    public function getGradeRanges() {
        return $this->_GradeRanges;
    }

    public function setFinalGrade( $FinalGrade ) {
        $this->_FinalGrade = $FinalGrade;
    }

    public function getFinalGrade() {
        return $this->_FinalGrade;
    }



}


?>