<?php
// write dao object for each class

include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.roledao.inc';
include_once 'class.disciplinedao.inc';


Class UserDAO{

	private $_DB;
	private $_User;
	private $_RoleDAO;
	private $_DisciplineDAO;



	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_User = new User();
		$this->_RoleDAO = new RoleDAO();
		$this->_DisciplineDAO = new DisciplineDAO();

	}

	// get all the users from the database using the database query
	public function getAllUsers(){

		$UserList = array();

		$this->_DB->doQuery("SELECT * FROM ums_user where IsDeleted is null 
			order by (UniversityID * 1) ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_User = new User();

		    $this->_User->setID ( $row['ID']);
		    $this->_User->setUniversityID ( $row['UniversityID'] );   
		    $this->_User->setEmail ( $row['Email'] );
		    $this->_User->setPassword ( $row['Password'] );
		    $this->_User->setFirstName( $row['FirstName'] );
		    $this->_User->setMiddleName( $row['MiddleName'] );
		    $this->_User->setLastName( $row['LastName'] );

		    $Discipline = new Discipline();
		    $Discipline->setID($row['DisciplineID']);
		    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
		    $this->_User->setDiscipline( $Discipline );

		    $this->_User->setStatus( $row['Status'] );
		    $this->_User->setIsArchived( $row['IsArchived'] );
		    $this->_User->setIsDeleted( $row['IsDeleted'] );

		    $UserList[]=$this->_User;
   
		}


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($UserList);

		return $Result;
	}

	// get all the users from the database of a given role
	public function getAllUsersOfRole($Role){

		$UserList = array();

		$SQL = "SELECT u.* FROM ums_user u, ums_user_role ur where u.IsDeleted is null AND 
				u.ID=ur.UserID AND ur.RoleID='$Role'";

		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_User = new User();

		    $this->_User->setID ( $row['ID']);
		    $this->_User->setUniversityID ( $row['UniversityID'] );   
		    $this->_User->setEmail ( $row['Email'] );
		    $this->_User->setPassword ( $row['Password'] );
		    $this->_User->setFirstName( $row['FirstName'] );
		    $this->_User->setMiddleName( $row['MiddleName'] );
		    $this->_User->setLastName( $row['LastName'] );

		    $Discipline = new Discipline();
		    $Discipline->setID($row['DisciplineID']);
		    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
		    $this->_User->setDiscipline( $Discipline );

		    $this->_User->setStatus( $row['Status'] );
		    $this->_User->setIsArchived( $row['IsArchived'] );
		    $this->_User->setIsDeleted( $row['IsDeleted'] );

		    $UserList[]=$this->_User;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($UserList);

		return $Result;
	}



	//create user funtion with the user object
	public function createUser($User){

		$ID=$User->getID();
		$UniversityID=$User->getUniversityID();
		$Email=$User->getEmail();
		$Password=$User->getPassword();
		$FirstName=$User->getFirstName();
		$MiddleName=$User->getMiddleName();
		$LastName=$User->getLastName();
		$DisciplineID=$User->getDiscipline()->getID();
		$Status=$User->getStatus();
		$IsArchived=$User->getIsArchived();
		$IsDeleted=$User->getIsDeleted();
		$Roles = $User->getRoles();	
		$Positions=$User->getPositions();
	    $blood=$User->getBlood();

		$SQL = "INSERT INTO ums_user(ID,UniversityID,Email,Password,FirstName,MiddleName,LastName,DisciplineID,Status) 
		 	VALUES('$ID','$UniversityID','$Email','$Password','$FirstName','$MiddleName','$LastName',
		 	'$DisciplineID','$Status')";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the user
		$SQL = $this->_DB->doQuery($SQL);

		$SQL = "INSERT INTO ums_user_details(ID,blood_group) VALUES('$ID','$blood')";
		//creating user details
		$SQL = $this->_DB->doQuery($SQL);
		
		//assigning list of roles
		for ($i=0; $i < sizeof($Roles); $i++) { 
				$Role = $Roles[$i];

			
			$SQL_Role = "INSERT INTO ums_user_role(UserID,RoleID) 
										VALUES('".$User->getID()."','".$Role->getID()."')";	
		
			$SQL_Role = $this->_DB->doQuery($SQL_Role);
		}	

		//assigning list of positions
		for ($i=0; $i < sizeof($Positions); $i++) { 
				$Position = $Positions[$i];
		
			$SQL_Position = "INSERT INTO ums_user_position(UserID,PositionID) 
										VALUES('".$User->getID()."','".$Position->getID()."')";	
			
			$SQL_Position = $this->_DB->doQuery($SQL_Position);
		}	
				
		//closing the transaction
		$this->_DB->getConnection()->commit();



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}


	//create new user request with the user object
	public function newUserRequest($User){

		$ID=$User->getID();
		$UniversityID=$User->getUniversityID();
		$Email=$User->getEmail();
		$Password=$User->getPassword();
		$FirstName=$User->getFirstName();
		$MiddleName = $User->getMiddleName();
		$LastName=$User->getLastName();
		$DisciplineID=$User->getDiscipline()->getID();
		$Status=$User->getStatus();
		$Roles = $User->getRoles();	
		$blood = $User->getBlood();	
        

		$SQL = "INSERT INTO ums_user(ID,UniversityID,Email,Password,FirstName,MiddleName,LastName,DisciplineID,Status) 
		 	VALUES('$ID','$UniversityID','$Email','$Password','$FirstName','$MiddleName','$LastName',
		 			'$DisciplineID','$Status')";

		//echo $SQL; 	

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the user
		$SQL = $this->_DB->doQuery($SQL);

		$SQL = "INSERT INTO ums_user_details(ID,blood_group) VALUES('$ID','$blood')";
		//creating user details
		$SQL = $this->_DB->doQuery($SQL);
		
		//assigning list of roles
		for ($i=0; $i < sizeof($Roles); $i++) { 
				$Role = $Roles[$i];

			
			$SQL_Role = "INSERT INTO ums_user_role(UserID,RoleID) 
										VALUES('".$User->getID()."','".$Role->getID()."')";	
		
			$SQL_Role = $this->_DB->doQuery($SQL_Role);
		}	

	
		//closing the transaction
		$this->_DB->getConnection()->commit();



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject("New User Request Submitted Successfully.");

		$this->send_User_Request_Email($User);
		$this->send_User_Request_Admin_Email($User);

		return $Result;
	}

	private function send_User_Request_Email($User){

		$subject = 'New user request recieved';
		$msg = $User->getFullName(). ' Your request is pending for approval. You will be notified in your email: '.$User->getEmail().' about it';
		$headers = 'From: kucse@dgted.com';

		mail($User->getEmail(),$subject,$msg,$headers);

	}	

	private function send_User_Request_Admin_Email($User){

		$subject = 'New user request recieved';
		$msg = $User->getFullName(). ' user request is pending for approval.';
		$headers = 'From: kucse@dgted.com';

		mail('mkazi078@uottawa.ca',$subject,$msg,$headers);

	}

	//user requesting password
	public function requestPassword($User){
		

		$SQL = "SELECT * FROM ums_user WHERE ID like '".$User->getID()."' LIMIT 1";

	
		$this->_DB->doQuery($SQL);

		if($this->_DB->getNumRows()>=1)
		{
		 	$row = $this->_DB->getTopRow();

		    $this->_User->setID ( $row['ID']);
		    $this->_User->setUniversityID ( $row['UniversityID'] );   
		    $this->_User->setEmail ( $row['Email'] );
		    
		    $this->_User->setFirstName( $row['FirstName'] );
		    $this->_User->setMiddleName( $row['MiddleName'] );
		    $this->_User->setLastName( $row['LastName'] );

		 	$Result = new Result();
			$Result->setIsSuccess(1);
			$Result->setResultObject('User found, your password is forwarded to your email.');

			$RandomPwd = Util::random_password(8);

			$HashPwd = Util::getPasswordHash($RandomPwd);

			$SQL = "UPDATE ums_user SET Password='$HashPwd' WHERE ID like '".$User->getID()."'";

			$SQL = $this->_DB->doQuery($SQL);

			$this->_User->setPassword ( $RandomPwd );

			$this->send_Password_Email($this->_User);
		}
		else{
			$Result = new Result();
			$Result->setResultObject('User doest no exists!');
		}

		return $Result;
	}

	private function send_Password_Email($User){

		$subject = "Password sent from dgtED";
		$msg = $User->getFullName()." your password for user account: ".$User->getEmail()." is: ".$User->getPassword();
		$headers = "From: kucse@dgted.com";

		mail($User->getEmail(),$subject,$msg,$headers);

	}



	//read an user object based on its id from user object
	public function readUser($User){
		

		$SQL = "SELECT * FROM ums_user WHERE ID='".$User->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_User = new User();

		//preparing the user object
	    $this->_User->setID ( $row['ID']);
	    $this->_User->setUniversityID ( $row['UniversityID'] );   
	    $this->_User->setEmail ( $row['Email'] );
	    $this->_User->setPassword ( $row['Password'] );
	    $this->_User->setFirstName( $row['FirstName'] );
	    $this->_User->setMiddleName( $row['MiddleName'] );
	    $this->_User->setLastName( $row['LastName'] );

	    $Discipline = new Discipline();
	    $Discipline->setID($row['DisciplineID']);
	    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
	    $this->_User->setDiscipline( $Discipline );

	    $this->_User->setIsArchived( $row['IsArchived'] );
	    $this->_User->setIsDeleted( $row['IsDeleted'] );


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}

	//read an user object based on its id from user object
	public function readUser_By_UniversityID($User){
		

		$SQL = "SELECT * FROM ums_user WHERE UniversityID='".$User->getUniversityID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_User = new User();

		//preparing the user object
	    $this->_User->setID ( $row['ID']);
	    $this->_User->setUniversityID ( $row['UniversityID'] );   
	    $this->_User->setEmail ( $row['Email'] );
	    $this->_User->setPassword ( $row['Password'] );
	    $this->_User->setFirstName( $row['FirstName'] );
	    $this->_User->setMiddleName( $row['MiddleName'] );
	    $this->_User->setLastName( $row['LastName'] );

	    $Discipline = new Discipline();
	    $Discipline->setID($row['DisciplineID']);
	    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
	    $this->_User->setDiscipline( $Discipline );

	    $this->_User->setIsArchived( $row['IsArchived'] );
	    $this->_User->setIsDeleted( $row['IsDeleted'] );


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}


	//search an user object based on some criteria
	public function searchUser($Role,$SearchField,$SearchText){
		

		$SQL = "SELECT u.* FROM ums_user u, ums_user_role ur WHERE u.ID=ur.UserID AND 
				ur.RoleID='$Role' AND u.".$SearchField." Like '$SearchText'";


		$this->_DB->doQuery($SQL);
		
		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_User = new User();

		    $this->_User->setID ( $row['ID']);
		    $this->_User->setUniversityID ( $row['UniversityID'] );   
		    $this->_User->setEmail ( $row['Email'] );
		    $this->_User->setPassword ( $row['Password'] );
		    $this->_User->setFirstName( $row['FirstName'] );
		    $this->_User->setMiddleName( $row['MiddleName'] );
		    $this->_User->setLastName( $row['LastName'] );


		    $Discipline = new Discipline();
		    $Discipline->setID($row['DisciplineID']);
		    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
		    $this->_User->setDiscipline( $Discipline );


		    $this->_User->setStatus( $row['Status'] );
		    $this->_User->setIsArchived( $row['IsArchived'] );
		    $this->_User->setIsDeleted( $row['IsDeleted'] );

		    $UserList[]=$this->_User;
   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($UserList);

		return $Result;
	}



	//read an user object based on its id from user object
	public function readUserDetails($UserDetails){
		

		$SQL = "SELECT * FROM ums_user_details WHERE ID='".$UserDetails->getID()."'";

		$this->_DB->doQuery($SQL);

		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		$this->_User = new UserDetails();

		//preparing the user object
	    $this->_User->setID ( $row['ID']);
	    $this->_User->setFatherName ( $row['FatherName'] );   
	    $this->_User->setMotherName ( $row['MotherName'] );
	    $this->_User->setPermanentAddress ( $row['PermanentAddress'] );
	    $this->_User->setHomePhone ( $row['HomePhone'] ); 
	    $this->_User->setCurrentAddress ( $row['CurrentAddress'] );
	    $this->_User->setMobilePhone ( $row['MobilePhone'] );   
	    $this->_User->setBlood($row['blood_group']);


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}


	//read an user object based on its id form user object along with the roles
	//todo: add permissions to the roles
	public function readUserRoles($User){
		
		//getting the user information
		$Result = $this->readUser($User);

		if($Result->getIsSuccess()){


			$this->_User = $Result->getResultObject();

					
			$SQL = "SELECT r.ID, r.Name  FROM ums_user u,ums_user_role ur, ums_role r  
					WHERE u.ID=ur.UserID and ur.RoleID=r.ID and  u.IsDeleted is null and u.ID='".$this->_User->getID()."'";
			
			$this->_DB->doQuery($SQL);

			//reading all the rows 
			$rows = $this->_DB->getAllRows();

			//setting roles list object
			$Roles = array();

			for($i = 0; $i < sizeof($rows); $i++) {

				$row = $rows[$i];
		
				$Role = new Role();

			    //filling up role information
			    $Role->setID ( $row['ID']);
			    $Role->setName ( $row['Name']);

			    //adding new roles with every iteration belong to this user	
			    $Roles[]=$Role;
	   
			}
	
			//assigning role list to the user object
			$this->_User->setRoles($Roles);

		}

		//todo: LOG util with level of log

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}


	//read an user object based on its id form user object along with the Positions
	public function readUserRolesPositions($User){
		
		//getting the user information
		$Result = $this->readUserRoles($User);

		if($Result->getIsSuccess()){


			$this->_User = $Result->getResultObject();

					
			$SQL = "SELECT p.ID, p.Name  FROM ums_user u,ums_user_position up, ums_position p 
					WHERE u.ID=up.UserID and up.PositionID=p.ID and  u.IsDeleted is null and  u.ID='".$this->_User->getID()."'";
			
			$this->_DB->doQuery($SQL);

			//reading all the rows 
			$rows = $this->_DB->getAllRows();

			//setting Positions list object
			$Positions = array();

			for($i = 0; $i < sizeof($rows); $i++) {

				$row = $rows[$i];
		
				$Position = new Position();

			    //filling up Position information
			    $Position->setID ( $row['ID']);
			    $Position->setName ( $row['Name']);

			    //adding new Positions with every iteration belong to this user	
			    $Positions[]=$Position;
	   
			}
	
			//assigning Position list to the user object
			$this->_User->setPositions($Positions);

		}

		//todo: LOG util with level of log

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_User);

		return $Result;
	}

	//check user password is matched
	public function userPasswordMatch($User){

		$Result = new Result();

		$Email = $User->getEmail();
		$Password = $User->getPassword();

		//start::user reading information
		$SQL = "SELECT * FROM ums_user WHERE IsDeleted is NULL and Email='$Email'";
	
		$this->_DB->doQuery($SQL);
		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		//user found
		if($this->_DB->getNumRows()>0 && isset($row)){

			$Hash = $row['Password'];
			if (password_verify($Password, $Hash)){
				$Result->setIsSuccess(1);
				$Result->setResultObject("User is valid!");
			}
			else{
				$Result->setIsSuccess(0);
				$Result->setResultObject("User not valid!");

			}

		}

		return $Result;
	}

	//read an user object based on its email form user object with all the roles and related permissions
	public function readUserRolesPermissions($User){
	
		$Result = new Result();

		$Email = $User->getEmail();
		$Password = $User->getPassword();
		
		//start::user reading information
		$SQL = "SELECT * FROM ums_user WHERE IsDeleted is NULL and Email='$Email'";
	
		$this->_DB->doQuery($SQL);
		//reading the top row for this user from the database
		$row = $this->_DB->getTopRow();

		if(isset($row)){

			$this->_User = new User();

			//preparing the user object
		    $this->_User->setID ( $row['ID']);
		    $this->_User->setUniversityID ( $row['UniversityID'] );   
		    $this->_User->setEmail ( $row['Email'] );
		    $this->_User->setPassword ( $row['Password'] );

		    $this->_User->setFirstName( $row['FirstName'] );
		    $this->_User->setMiddleName( $row['MiddleName'] );
		    $this->_User->setLastName( $row['LastName'] );

		    $Discipline = new Discipline();
		    $Discipline->setID($row['DisciplineID']);
		    $Discipline = $this->_DisciplineDAO->readDiscipline($Discipline)->getResultObject();
		    $this->_User->setDiscipline( $Discipline );

		    $this->_User->setStatus( $row['Status'] );
		    $this->_User->setIsLogged( $row['IsLogged'] );	
		    $this->_User->setIsArchived( $row['IsArchived'] );
		    $this->_User->setIsDeleted( $row['IsDeleted'] );
			//end::user reading information

		
			if(strcasecmp( $row['Status'], 'approved')==0 )
			{

			//start::getting all the roles of the user
			$SQL = "SELECT r.ID, r.Name  FROM ums_user u,ums_user_role ur, ums_role r  
						WHERE u.ID=ur.UserID and ur.RoleID=r.ID and u.ID='".$this->_User->getID()."'";
				
			$this->_DB->doQuery($SQL);

			//reading all the rows 
			$rows = $this->_DB->getAllRows();

			//setting roles list object
			$Roles = array();

			for($i = 0; $i < sizeof($rows); $i++) {

				$row = $rows[$i];
		
				$Role = new Role();

			    //filling up role information
			    $Role->setID ( $row['ID']);
			    $Role->setName ( $row['Name']);


			    //reading related permissions of the role
			   	$ResultRole = $this->_RoleDAO->readRolePermissions($Role);

			   	//if role permission reading is succesful
			   	if($ResultRole->getIsSuccess()){
			   		//assigning the role information to current role object
			   		$Role = $ResultRole->getResultObject();	

			   	}

			    //adding new roles with every iteration belong to this user	
			    $Roles[]=$Role;
	   
			}

				//assigning role list to the user object
			$this->_User->setRoles($Roles);

			//end::getting all the roles of the user
		

			$Result->setIsSuccess(1);
			$Result->setResultObject($this->_User);

			}
			else{
				$Result->setResultObject('You are not an approved user');
			}

		}
		else{

			$Result->setResultObject('Wrong user name or password');
		}

		return $Result;
	}



	//update an user object based on its id information
	public function updateUser($User){

		$ID=$User->getID();
		$UniversityID=$User->getUniversityID();
		$Email=$User->getEmail();
		$Password=$User->getPassword();
		$FirstName=$User->getFirstName();
		$MiddleName = $User->getMiddleName();
		$LastName=$User->getLastName();
		$DisciplineID=$User->getDiscipline()->getID();


		if(strcasecmp($Password, "*__KEEP__*")==0){ //if you are keeping your old password

		$SQL = "UPDATE ums_user SET UniversityID='$UniversityID', 
			Email='$Email',FirstName='$FirstName',MiddleName='$MiddleName',LastName='$LastName',
			DisciplineID='$DisciplineID' WHERE ID='$ID'";

		}else{ //otherwise you have entered a new password

		$SQL = "UPDATE ums_user SET UniversityID='$UniversityID',Password='$Password', 
		Email='$Email',FirstName='$FirstName',MiddleName='$MiddleName',LastName='$LastName',
		DisciplineID='$DisciplineID' WHERE ID='$ID'";
	
			
		}

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);

		//removing previous roles 

		$SQL_delete = "DELETE from ums_user_role where UserID ='".$User->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);

		//print_r($User);
		$Roles = $User->getRoles();

		//assigning new roles to the user
		for ($i=0; $i < sizeof($Roles); $i++) { 
			$Role = $Roles[$i];
			
			$SQL_Role = "INSERT INTO ums_user_role(UserID,RoleID) 
										VALUES('".$User->getID()."','".$Role->getID()."')";
			$SQL_Role = $this->_DB->doQuery($SQL_Role);
		}	


		//removing previous Positions 

		$SQL_delete = "DELETE from ums_user_position where UserID ='".$User->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);

		//print_r($User);
		$Positions = $User->getPositions();

		//assigning new Positions to the user
		for ($i=0; $i < sizeof($Positions); $i++) { 
			$Position = $Positions[$i];
			
			$SQL_Position = "INSERT INTO ums_user_position(UserID,PositionID) 
										VALUES('".$User->getID()."','".$Position->getID()."')";

			$SQL_Position = $this->_DB->doQuery($SQL_Position);
		}	


				
		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		return $Result;

	}


	//update an user details object based on its id information
	public function updateUserDetails($UserDetails){

		$SQL = "UPDATE ums_user_details SET FatherName='".$UserDetails->getFatherName()."', 
			MotherName='".$UserDetails->getMotherName()."',
			PermanentAddress='".$UserDetails->getPermanentAddress()."',
			HomePhone='".$UserDetails->getHomePhone()."',
			CurrentAddress='".$UserDetails->getCurrentAddress()."',
			MobilePhone='".$UserDetails->getMobilePhone()." '
			WHERE ID='".$UserDetails->getID()."'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);
				
		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		return $Result;

	}

	//delete an user based on its id of the database
	public function deleteUser($User){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
		//removing previous Positions 

		$SQL_delete = "DELETE from ums_user_position where UserID ='".$User->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);

		//removing previous roles 

		$SQL_delete = "DELETE from ums_user_role where UserID ='".$User->getID()."'";
		$SQL_delete = $this->_DB->doQuery($SQL_delete);

		// check the deleted row to true in the user now
		$SQL = "UPDATE ums_user SET IsDeleted=true where ID ='".$User->getID()."'";

		$SQL = $this->_DB->doQuery($SQL);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	//approve or reject an user
	public function approve_Reject_User($User,$Status){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
	
	
		// check the deleted row to true in the user now
		$SQL = "UPDATE ums_user SET Status='$Status' where ID ='".$User->getID()."'";

		$SQL = $this->_DB->doQuery($SQL);


		//closing the transaction
		$this->_DB->getConnection()->commit();


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		$this->send_Approve_Reject_Email($User, $Status);

		return $Result;

	}

	private function send_Approve_Reject_Email($User, $Status){

		$subject = 'New user request: '.$Status;
		$msg = $User->getFullName(). ' Your user request is '. $Status;
		$headers = 'From: kucse@dgted.com';

		mail($User->getEmail(),$subject,$msg,$headers);

	}	


}

//$_Log->log(LogUtil::$DEBUG," exit the class.userdao.inc");

?>