<?php 
class Job{
    
    private $_ID;
    private $_Title;
    private $_Details;
    private $_LastDateOfApplication;
    private $_Salary;
    private $_Qualification;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setTitle( $Title ) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }

    public function setDetails ( $Details ) {
        $this->_Details = $Details;
    }

    public function getDetails () {
        return $this->_Details;
    }

    public function setLastDateOfApplication ( $LastDateOfApplication ) {
        $this->_LastDateOfApplication = $LastDateOfApplication;
    }

    public function getLastDateOfApplication () {
        return $this->_LastDateOfApplication;
    }

    public function setSalary ( $Salary ) {
        $this->_Salary = $Salary;
    }

    public function getSalary () {
        return $this->_Salary;
    }

    public function setQualification ( $Qualification ) {
        $this->_Qualification = $Qualification;
    }

    public function getQualification () {
        return $this->_Qualification;
    }

}
?>