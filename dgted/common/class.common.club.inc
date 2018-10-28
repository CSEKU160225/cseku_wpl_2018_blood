<?php


class Club{

    private $_ID;
    private $_Name;
    private $_CoverPhoto;
    private $_Description;
    private $_CreationDate;
    private $_Mail;

    public function setID( $ID ) {
        $this->_ID = $ID;
    }

    public function getID() {
        return $this->_ID;
    }

    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }

    public function setCoverPhoto( $CoverPhoto ) {
        $this->_CoverPhoto = $CoverPhoto;
    }

    public function getCoverPhoto() {
        return $this->_CoverPhoto;
    }

    public function setDescription( $Description ) {
        $this->_Description = $Description;
    }

    public function getDescription() {
        return $this->_Description;
    }

    public function setMail( $Mail ) {
        $this->_Mail = $Mail;
    }

    public function getMail() {
        return $this->_Mail;
    }

    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }

} 


/**
* 
*/
class ClubModule
{
    private $_ClubID;
    private $_ModuleName;
    private $_IsVisible;
    private $_PositionX;
    private $_PositionY;
    private $_SizeX;
    private $_SizeY;
    private $_Content;
    private $_ModuleID;
    


    public function setClubID( $ClubID ) {
        $this->_ClubID = $ClubID;
    }

    public function getClubID() {
        return $this->_ClubID;
    }

    public function setModuleID( $ModuleID ) {
        $this->_ModuleID = $ModuleID;
    }

    public function getModuleID() {
        return $this->_ModuleID;
    }   

    public function setModuleName( $ModuleName ) {
        $this->_ModuleName = $ModuleName;
    }

    public function getModuleName() {
        return $this->_ModuleName;
    }

    public function setContent( $Content ) {
        $this->_Content = $Content;
    }

    public function getContent() {
        return $this->_Content;
    }

    public function setIsVisible( $IsVisible ) {
        $this->_IsVisible = $IsVisible;
    }

    public function getIsVisible() {
        return $this->_IsVisible;
    }

}

class Members
{
    private $_ClubID;
    private $_MemberID;
    private $_Name;
    private $_Designation;

    public function setClubID( $ClubID ) {
        $this->_ClubID = $ClubID;
    }

    public function getClubID() {
        return $this->_ClubID;
    }

    public function setMemberID( $MemberID) {
        $this->_MemberID = $MemberID;
    }

    public function getMemberID() {
        return $this->_MemberID;
    }


    public function setName( $Name ) {
        $this->_Name = $Name;
    }

    public function getName() {
        return $this->_Name;
    }

    public function setDesignation( $Designation ) {
        $this->_Designation = $Designation;
    }

    public function getDesignation() {
        return $this->_Designation;
    }

}


?>