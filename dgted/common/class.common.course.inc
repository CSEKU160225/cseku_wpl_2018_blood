<?php

class CourseTeacher
{
    private $_ID;
    private $_Course;
    private $_Teacher;
    private $_Session;
    private $_Year;
    private $_Term;
    private $_NoOfTests;

    public function setID($ID)
    {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setCourse($Course)
    {
        $this->_Course = $Course;
    }

    public function getCourse () {
        return $this->_Course;
    }

    public function setTeacher( $Teacher)
    {
        $this->_Teacher = $Teacher;
    }

    public function getTeacher () {
        return $this->_Teacher;
    }

    public function setSession( $Session)
    {
        $this->_Session = $Session;
    }

    public function getSession () {
        return $this->_Session;
    }

    public function setYear( $Year)
    {
        $this->_Year = $Year;
    }

    public function getYear () {
        return $this->_Year;
    }


    public function setTerm( $Term)
    {
        $this->_Term = $Term;
    }

    public function getTerm () {
        return $this->_Term;
    }

    public function setNoOfTests( $NoOfTests)
    {
        $this->_NoOfTests = $NoOfTests;
    }

    public function getNoOfTests () {
        return $this->_NoOfTests;
    }

}

class CourseTeacherRegistration
{
    private $_ID;
    
    private $_TeacherID;
    private $_SessionalID;
    private $_YearID;
    private $_TermID;

    public function setID($ID)
    {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }
    
    public function setTeacherID( $TeacherID)
    {
       $this->_TeacherID = $TeacherID;
    }

    public function getTeacherID () {
        return $this->_TeacherID;
    }

    public function setSessionID( $SessionalID)
    {
        $this->_SessionalID = $SessionalID;
    }

    public function getSessionID () {
        return $this->_SessionalID;
    }

    public function setYearID( $YearID)
    {
        $this->_YearID = $YearID;
    }

    public function getYearID () {
        return $this->_YearID;
    }
    public function setTermID( $TermID)
    {
        $this->_TermID = $TermID;
    }

    public function getTermID () {
        return $this->_TermID;
    }

}

class CourseStudentRegistration
{
    private $_ID;
    
    private $_Student;
    private $_Course;
    private $_Teacher;
    private $_Session;
    private $_Year;
    private $_Term;
    private $_Status;
    private $_IsRetake;


    public function setID($ID)
    {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setStudent($Student)
    {
        $this->_Student = $Student;
    }

    public function getStudent () {
        return $this->_Student;
    }

    public function setCourse($Course)
    {
        $this->_Course = $Course;
    }

    public function getCourse () {
        return $this->_Course;
    }
    
    public function setTeacher( $Teacher)
    {
        $this->_Teacher = $Teacher;
    }

    public function getTeacher () {
        return $this->_Teacher;
    }

    public function setSession( $Session)
    {
        $this->_Session = $Session;
    }

    public function getSession () {
        return $this->_Session;
    }

    public function setYear( $Year)
    {
        $this->_Year = $Year;
    }

    public function getYear () {
        return $this->_Year;
    }

    public function setTerm( $Term)
    {
        $this->_Term = $Term;
    }

    public function getTerm () {
        return $this->_Term;
    }

    public function setStatus( $Status)
    {
        $this->_Status = $Status;
    }

    public function getStatus() {
        return $this->_Status;
    }

    public function setIsRetake( $IsRetake)
    {
        $this->_IsRetake = $IsRetake;
    }

    public function getIsRetake () {
        return $this->_IsRetake;
    }

}


class CourseType
{
    private $_ID;
    private $_Name;
    private $_SessionalTypeID;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }

    public function setSessionalTypeID ( $SessionalTypeID ) {
        $this->_SessionalTypeID = $SessionalTypeID;
    }

    public function getSessionalTypeID() {
        return $this->_SessionalTypeID;
    }

}
class Course
{
    private $_ID;
    private $_CourseNo;
    private $_Title;
    private $_Credit;
    private $_CourseTypeID;
    private $_DisciplineID;
    private $_ISdeleted;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setCourseNo ($CourseNo) {
        $this->_CourseNo = $CourseNo;
    }

    public function getCourseNo () {
        return $this->_CourseNo;
    }

    public function setTitle ( $Title ) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }

    public function setCredit ( $Credit ) {
        $this->_Credit = $Credit;
    }

    public function getCredit () {
        return $this->_Credit;
    }

    public function setCourseTypeID ($CourseTypeID) {
        $this->_CourseTypeID = $CourseTypeID;
    }

    public function getCourseTypeID () {
        return $this->_CourseTypeID;
    }

    public function setDisciplineID ( $DisciplineID ) {
        $this->_DisciplineID = $DisciplineID;
    }

    public function getDisciplineID() {
        return $this->_DisciplineID;
    }

    public function setISdeleted ( $ISdeleted ) {
        $this->_ISdeleted = $ISdeleted;
    }

    public function getISdeleted() {
        return $this->_ISdeleted;
    }
    

}
class RegistrationSession
{
    private $_ID;
    private $_Name;
    
    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }
}

class SessionalType
{
    private $_ID;
    private $_Name;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }
    
}


class Discipline{

    private $_ID;
    private $_Name;
    private $_ShortCode;
    private $_School;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }

    public function setShortCode( $ShortCode ) {
        $this->_ShortCode = $ShortCode;
    }

    public function getShortCode() {
        return $this->_ShortCode;
    }

    public function setSchool( $School ) {
        $this->_School = $School;
    }

    public function getSchool() {
        return $this->_School;
    }


}

class School{

    private $_ID;
    private $_Name;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }


}

class Session{

    private $_ID;
    private $_Name;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }


}

class Term{

    private $_ID;
    private $_Name;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }

}

class Year{

    private $_ID;
    private $_Name;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }


}

?>