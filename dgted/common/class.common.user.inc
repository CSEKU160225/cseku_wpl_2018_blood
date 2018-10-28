<?php
        
class User{

    private $_ID;
    private $_UniversityID;
    private $_Email;
    private $_Password;
    private $_FirstName=null;
    private $_MiddleName=null;
    private $_LastName=null;
    private $_Discipline=null;
    private $_Status=null;
    private $_IsLogged=null;
    private $_IsArchived=null;
    private $_IsDeleted=null;
    private $_Roles;
    private $_Positions;
    private $_Blood;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setUniversityID ( $UniversityID ) {
        $this->_UniversityID = $UniversityID;
    }

    public function getUniversityID () {
        return $this->_UniversityID;
    }


    public function setEmail ( $Email ) {
        $this->_Email = $Email;
    }

    public function getEmail () {
        return $this->_Email;
    }

    
    public function setPassword ( $Password ) {
        $this->_Password = $Password;
    }

    public function getPassword () {
        return $this->_Password;
    }


    public function setFirstName( $FirstName ) {
        $this->_FirstName = $FirstName;
    }

    public function getFirstName() {
        return $this->_FirstName;
    }



    public function setMiddleName( $MiddleName ) {
        $this->_MiddleName = $MiddleName;
    }

    public function getMiddleName() {
        return $this->_MiddleName;
    }


    public function setLastName( $LastName ) {
        $this->_LastName = $LastName;
    }

    public function getLastName() {
        return $this->_LastName;
    }

    public function getFullName(){
        return $this->_FirstName. ' ' . $this->_MiddleName. ' ' .$this->_LastName;
    }

    public function setDiscipline( $Discipline ) {
        $this->_Discipline = $Discipline;
    }

    public function getDiscipline() {
        return $this->_Discipline;
    }
    
    public function setStatus( $Status ) {
        $this->_Status = $Status;
    }

    public function getStatus() {
        return $this->_Status;
    }
    
    public function setBlood( $Blood ) {
        $this->_Blood = $Blood;
    }

    public function getBlood() {
        return $this->_Blood;
    }
    public function setIsLogged( $IsLogged ) {
        $this->IsLogged = $IsLogged;
    }

    public function getIsLogged() {
        return $this->_IsLogged;
    }


    public function setIsArchived( $IsArchived ) {
        $this->_IsArchived = $IsArchived;
    }

    public function getIsArchived() {
        return $this->_IsArchived;
    }

    public function setIsDeleted( $IsDeleted ) {
        $this->_IsDeleted = $IsDeleted;
    }

    public function getIsDeleted() {
        return $this->_IsDeleted;
    }


    public function setRoles( $Roles ) {
        $this->_Roles = $Roles;
    }

    public function getRoles() {
        return $this->_Roles;
    }

    public function setPositions( $Positions ) {
        $this->_Positions = $Positions;
    }

    public function getPositions() {
        return $this->_Positions;
    }

}

class UserDetails{

    private $_ID;
    private $_FatherName;
    private $_MotherName;
    private $_PermanentAddress;
    private $_HomePhone;
    private $_CurrentAddress;
    private $_MobilePhone;
    private $_Blood;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }

    public function setFatherName ( $FatherName ) {
        $this->_FatherName = $FatherName;
    }

    public function getFatherName () {
        return $this->_FatherName;
    }

    public function setMotherName ( $MotherName ) {
        $this->_MotherName = $MotherName;
    }

    public function getMotherName () {
        return $this->_MotherName;
    }
    
 
    public function setPermanentAddress ( $PermanentAddress ) {
        $this->_PermanentAddress = $PermanentAddress;
    }

    public function getPermanentAddress () {
        return $this->_PermanentAddress;
    }

    public function setHomePhone( $HomePhone ) {
        $this->_HomePhone = $HomePhone;
    }

    public function getHomePhone() {
        return $this->_HomePhone;
    }

   public function setCurrentAddress ( $CurrentAddress ) {
        $this->_CurrentAddress = $CurrentAddress;
    }

    public function getCurrentAddress () {
        return $this->_CurrentAddress;
    }


    public function setMobilePhone( $MobilePhone ) {
        $this->_MobilePhone = $MobilePhone;
    }

    public function getMobilePhone() {
        return $this->_MobilePhone;
    }

    public function setBlood( $Blood ) {
        $this->_Blood = $Blood;
    }

    public function getBlood() {
        return $this->_Blood;
    }

}

class Role{

    private $_ID;
    private $_Name;
    private $_Permissions;


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

    public function setPermissions( $Permissions ) {
        $this->_Permissions = $Permissions;
    }

    public function getPermissions() {
        return $this->_Permissions;
    }

}


/*class UserRole{

    private $_User;
    private $_RoleList = array();

    public function setUser ( $User ) {
        $this->_User = $User;
    }

    public function getUser () {
        return $this->_User;
    }


    public function setRoleList( $RoleList ) {
        if(is_array($RoleList)){
            $this->_RoleList = $RoleList;
        }
        else{
            throw new Exception("Error!! not an array!!!");
        }
            
    }

    public function getRoleList() {
        return $this->_RoleList;
    }

    public function addNewRole($Role){

        $this->_RoleList[]=$Role;

    }


}*/

class Position{
    
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


class UserPosition{

    private $_User;
    private $_PositionList = array();

    public function setUser ( $User ) {
        $this->_User = $User;
    }

    public function getUser () {
        return $this->_User;
    }


    public function setPositionList( $PositionList ) {
        if(is_array($PositionList)){
            $this->_PositionList = $PositionList;
        }
        else{
            throw new Exception("Error!! not an array!!!");
        }
            
    }

    public function getPositionList() {
        return $this->_PositionList;
    }

    public function addNewPosition($Position){

        $this->_PositionList[]=$Position;

    }

}



class Permission{

    private $_ID;
    private $_Name;
    private $_Category;
    private $_IsChecked;


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

    public function setCategory( $Category ) {
        $this->_Category = $Category;
    }

    public function getCategory() {
        return $this->_Category;
    }

    public function setIsChecked( $IsChecked ) {
        $this->_IsChecked = $IsChecked;
    }

    public function getIsChecked() {
        return $this->_IsChecked;
    }


}



class RolePermission{

    private $_Role;
    private $_PermissionList = array();

    public function setRole ( $Role ) {
        $this->_Role = $Role;
    }

    public function getRole () {
        return $this->_Role;
    }


    public function setPermissionList( $PermissionList ) {
        if(is_array($PermissionList)){
            $this->_PermissionList = $PermissionList;
        }
        else{
            throw new Exception("Error!! not an array!!!");
        }
            
    }

    public function getPermissionList() {
        return $this->_PermissionList;
    }

    public function addNewPermission($Permission){

        $this->_PermissionList[]=$Permission;

    }

}

?>