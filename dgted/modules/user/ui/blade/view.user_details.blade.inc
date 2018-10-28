<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';
include_once MODULES_USER.'bao/class.positionbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc';


$_UserBAO = new UserBAO();
$_RoleBAO = new RoleBAO();
$_PositionBAO = new PositionBAO();
$_DisciplineBAO = new DisciplineBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


$globalUser = '';
$globalUser = $_SESSION["globalUser"];


//calling from outside to know about specific user
if(isset($_GET['id']))
{
  $globalUser = new User();
  $globalUser->setID($_GET['id']);
}

$userPositions = $_UserBAO->readUserRolesPositions($globalUser)->getResultObject(); //reading the user 
$userDetails = $_UserBAO->readUserDetails($globalUser)->getResultObject(); 

//reading the detailed part of an user 


/* saving a new user account*/
if(isset($_POST['update']))
{
	 $User = new User();	
	 $User->setID($globalUser->getID());
	 $User->setEmail($_DB->secureInput($_POST['txtEmail']));
     $User->setUniversityID($_DB->secureInput($_POST['txtUniversityID']));

     if(!empty($_POST['txtPassword'])) // password update is initiated
     {
     	$HashPwd = Util::getPasswordHash($_DB->secureInput($_POST['txtPassword'])); //hashing the password
     	$User->setPassword($HashPwd);
     }
     else{
     	$User->setPassword("*__KEEP__*");//keep old password
     }

     $User->setFirstName($_DB->secureInput($_POST['txtFirstName']));
     $User->setMiddleName($_DB->secureInput($_POST['txtMiddleName']));
     $User->setLastName($_DB->secureInput($_POST['txtLastName']));


    if(isset($_POST['selectDiscipline'])){ 
		$Discipline = new Discipline();
		$Discipline->setID($_POST['selectDiscipline']);	
		$User->setDiscipline($Discipline);
	}

   if(isset($_POST['assignedRoles'])){ 
	    foreach ($_POST['assignedRoles'] as $select)
		{
			$Role = new Role();
			$Role->setID($select);
			$Roles[]=$Role;
		}
		$User->setRoles($Roles);
	}
	
	if(isset($_POST['assignedPositions'])){
		foreach ($_POST['assignedPositions'] as $select)
		{
			$Position = new Position();
			$Position->setID($select);
			$Positions[]=$Position;
		}
		$User->setPositions($Positions);
	}

	 $Result = $_UserBAO->updateUser($User);	

	 if($Result->getIsSuccess())
	 {

		$UserDetails = new UserDetails();
		$UserDetails->setID($globalUser->getID());    	
	    $UserDetails->setFatherName ( $_DB->secureInput($_POST['txtFatherName']) );   
	    $UserDetails->setMotherName ( $_DB->secureInput($_POST['txtMotherName']) );
	    $UserDetails->setPermanentAddress ( $_DB->secureInput($_POST['txtPermanentAddress']) );
	    $UserDetails->setHomePhone ( $_DB->secureInput($_POST['txtHomePhone']) ); 
	    $UserDetails->setCurrentAddress ( $_DB->secureInput($_POST['txtCurrentAddress']) );
	    $UserDetails->setMobilePhone ( $_DB->secureInput($_POST['txtMobilePhone']) );   

	 	$Result = $_UserBAO->updateUserDetails($UserDetails);	
	 }

	header("Location:".PageUtil::$USER_DETAILS);
}


//if a role(ID) is present in the list of list(roles(ID))
function isRoleAvailable($Role, $Roles)
{
	

	for ($i=0; $i < sizeof($Roles); $i++) { 
		# code...
		if(!strcasecmp($Role->getID(),$Roles[$i]->getID())){
			return true;
		}
	}

	return false;
}

//if a Position(ID) is present in the list of list(Positions(ID))
function isPositionAvailable($Position, $Positions)
{
	
	for ($i=0; $i < sizeof($Positions); $i++) { 
		# code...
		if(!strcasecmp($Position->getID(),$Positions[$i]->getID())){
			return true;
		}
	}

	return false;
}


//$_Log->log(LogUtil::$DEBUG,"exit blade.user_details.inc");

?>