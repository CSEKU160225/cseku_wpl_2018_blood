<?php

/*All the common Model classes are listed here*/
class News{

    private $_ID;
    private $_Image;
   // private $_Path;
    private $_Title;
    private $_Description;
    private $_CreationDate;
    private $_HappeningDate;
    private $_Tag;
    private $_IsVisible=0;


    public function setID($ID) {
        $this->_ID = $ID;
    }

    public function getID() {
        return $this->_ID;
    }


    public function setImage($Image) {
        $this->_Image = $Image;
    }

    public function getImage() {
        return $this->_Image;
    }

   /* public function setPath($Path) {
        $this->_Path = $Path;
    }

    public function getpPath() {
        return $this->_Path;
    }*/



    public function setTitle($Title) {
        $this->_Title = $Title;
    }

    public function getTitle() {
        return $this->_Title;
    }

    
    public function setDescription($Description) {
        $this->_Description = $Description;
    }

    public function getDescription() {
        return $this->_Description;
    }


    public function setCreationDate($CreationDate) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }


    public function setHappeningDate($HappeningDate) {
        $this->_HappeningDate = $HappeningDate;
    }

    public function getHappeningDate() {
        return $this->_HappeningDate;
    }


    public function setTag($Tag) {
        $this->_Tag = $Tag;
    }

    public function getTag() {
        return $this->_Tag;
    }

    public function setIsVisible($IsVisible) {
        $this->_IsVisible = $IsVisible;
    }

    public function getIsVisible() {
        return $this->_IsVisible;
    }

}


class Result{

    private $_IsSuccess=0;
    private $_ResultObject;

    public function setIsSuccess($IsSuccess){
        $this->_IsSuccess = $IsSuccess;
    }

    public function getIsSuccess(){

        return $this->_IsSuccess;
    }

    public function setResultObject($ResultObject){
        $this->_ResultObject = $ResultObject;
    }

    public function getResultObject(){

        return $this->_ResultObject;
    }

}

class User{

    private $_ID;
    private $_UniversityID;
    private $_Email;
    private $_Password;
    private $_FirstName;
    private $_LastName;
    private $_IsArchived=0;
    private $_IsDeleted=0;
    private $_Roles;
    private $_Positions;


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


    public function setLastName( $LastName ) {
        $this->_LastName = $LastName;
    }

    public function getLastName() {
        return $this->_LastName;
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

class Discipline{

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

class Club{

    private $_ID;
    private $_Name;
    private $_CoverPhoto;
    private $_Description;
    private $_CreationDate;

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

    public function setCreationDate( $CreationDate ) {
        $this->_CreationDate = $CreationDate;
    }

    public function getCreationDate() {
        return $this->_CreationDate;
    }

} 




class PermissionUtil{

    public static $COURSE_C='COURSE_C';
    public static $COURSE_R='COURSE_R';
    public static $COURSE_U='COURSE_U';
    public static $COURSE_D='COURSE_D';

    public static $CLUB_C='CLUB_C';
    public static $CLUB_R='CLUB_R';
    public static $CLUB_U='CLUB_U';
    public static $CLUB_D='CLUB_D';

    public static $DISCIPLINE_C='DISCIPLINE_C';
    public static $DISCIPLINE_R='DISCIPLINE_R';
    public static $DISCIPLINE_U='DISCIPLINE_U';
    public static $DISCIPLINE_D='DISCIPLINE_D';

    public static $FILE_C='FILE_C';
    public static $FILE_R='FILE_R';
    public static $FILE_U='FILE_U';
    public static $FILE_D='FILE_D';

    public static $POSITION_C='POSITION_C';
    public static $POSITION_R='POSITION_R';
    public static $POSITION_U='POSITION_U';
    public static $POSITION_D='POSITION_D';

  
    public static $PROJECT_C='PROJECT_C';
    public static $PROJECT_R='PROJECT_R';
    public static $PROJECT_U='PROJECT_U';
    public static $PROJECT_D='PROJECT_D';

    public static $ROLE_C='ROLE_C';
    public static $ROLE_R='ROLE_R';
    public static $ROLE_U='ROLE_U';
    public static $ROLE_D='ROLE_D';

    public static $SESSION_C='SESSION_C';
    public static $SESSION_R='SESSION_R';
    public static $SESSION_U='SESSION_U';
    public static $SESSION_D='SESSION_D'; 

    public static $SURVEY_C='SURVEY_C';
    public static $SURVEY_R='SURVEY_R';
    public static $SURVEY_U='SURVEY_U';
    public static $SURVEY_D='SURVEY_D';

    public static $SCHOOL_C='SCHOOL_C';
    public static $SCHOOL_R='SCHOOL_R';
    public static $SCHOOL_U='SCHOOL_U';
    public static $SCHOOL_D='SCHOOL_D';

    public static $TERM_C='TERM_C';
    public static $TERM_R='TERM_R';
    public static $TERM_U='TERM_U';
    public static $TERM_D='TERM_D';


    public static $USER_C='USER_C';
    public static $USER_R='USER_R';
    public static $USER_U='USER_U';
    public static $USER_D='USER_D';

    public static $YEAR_C='YEAR_C';
    public static $YEAR_R='YEAR_R';
    public static $YEAR_U='YEAR_U';
    public static $YEAR_D='YEAR_D';

}

class PageUtil{

    public static $CLUB='club.php';
    public static $COURSE='course.php';

    public static $DISCIPLINE='discipline.php';
    public static $DISCUSSION='discussion.php';

    public static $ERROR='error.php';

    public static $FILE='file.php';
    public static $HOME='home.php';

    public static $QUESTION='question.php';

    public static $LOGIN='login.php';

    public static $PROJECT='project.php';
    public static $POSITION='position.php';
    public static $PERMISSION='permission.php';

    public static $ROLE='role.php';
    public static $RESOURCE='resource.php';


    public static $SCHOOL='school.php';
    public static $SESSION='session.php'; 
    public static $SURVEY='survey.php';
    
    public static $TERM='term.php';

    public static $USER='user.php';

    public static $YEAR='year.php';
    
    public static $VIDEO='video.php';
   
}

class RouteUtil{

    private static $s_Routes; //The single instance
    private static $s_instance; //The single instance


    private function RouteUtil(){
        
         self::$s_Routes = array();

        //add new page and routing address here always
         self::$s_Routes[PageUtil::$DISCIPLINE]       =   "/modules/dash/view.discipline.inc";

         self::$s_Routes[PageUtil::$HOME]             =   "/modules/dash/view.home.inc";

         self::$s_Routes[PageUtil::$LOGIN]            =   "/modules/dash/view.login.inc";

         self::$s_Routes[PageUtil::$PERMISSION]       =   "/modules/dash/view.permission.inc";
         self::$s_Routes[PageUtil::$POSITION]         =   "/modules/dash/view.position.inc";

         self::$s_Routes[PageUtil::$ROLE]             =   "/modules/dash/view.role.inc";

         self::$s_Routes[PageUtil::$SCHOOL]           =   "/modules/dash/view.school.inc";

         self::$s_Routes[PageUtil::$TERM]             =   "/modules/regs/view.term.inc";

         self::$s_Routes[PageUtil::$USER]             =   "/modules/dash/view.user.inc";

        //the page not found will redirect to error page
         self::$s_Routes[PageUtil::$ERROR]            =   "/modules/dash/view.error.inc";

    }

    public static function getInstance() {
        if(!self::$s_instance) { // If no instance then make one
            self::$s_instance = new self();
        }
        return self::$s_instance;
    }

    public static function get($Page){

        $Page = strtolower(trim($Page)); 

        if(array_key_exists($Page, self::$s_Routes)){
        
            return self::$s_Routes[$Page];
        }
        else{
        
            return self::$s_Routes[PageUtil::$ERROR]; 
        }
    }

}

RouteUtil::getInstance();

?>