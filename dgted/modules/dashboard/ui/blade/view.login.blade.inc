<?php

include_once UTILITY.'class.xml.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';


$_UserBAO = new UserBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();
$_Menu = XMLtoMenuUtil::getInstance();
$globalUser='';
$globalPermission='';
$globalMenu ='';



/* loading the user account*/
if(isset($_POST['login']))
{
	$User = new User();	
    $User->setEmail($_DB->secureInput($_POST['txtEmail']));
 
    $User->setPassword($_DB->secureInput($_POST['txtPassword']));

    $Result = $_UserBAO->userPasswordMatch($User); // matching user password

	if($Result->getIsSuccess()){



		$Result2 = $_UserBAO->readUserRolesPermissions($User); //reading the user object from the result 	

		if($Result2->getIsSuccess()){

			//storing the user object with all the roles and related permissions available in the complete system
			$globalUser = $Result2->getResultObject();
			//required to access session variables;		
	        if (session_status() == PHP_SESSION_NONE) {
	            session_start();
	        }

			$_SESSION["globalUser"]=$globalUser;

			//finding the complete permission list
			$globalPermission = getAllPermissions($globalUser);
				
			//storing permission in the session
			$_SESSION["globalPermission"] = $globalPermission;

			//updating permission on the menu
			XMLtoMenuUtil::viewable_menu($globalPermission);
			
			$_SESSION["unorganizedMenu"] = XMLtoMenuUtil::get_Menus();
			//organzing menu based on their parent child relationship
			$globalMenu =  XMLtoMenuUtil::reorganize_menu();
		  	
		  	//storing in the session

		  	$_SESSION["globalMenu"] = $globalMenu;


			$_SESSION[PageUtil::$LOGIN]='true';

			header("Location:".PageUtil::$HOME);		

		}
		else{
			echo '<strong>'.$Result2->getResultObject().'</strong>';	
		}

	}
	else{
		echo '<strong>'.$Result->getResultObject().'</strong>';	
		
	}
	
}


//return only the unique permissions a user has on the system
function getAllPermissions($User){

	//get all roles from user
	$Roles = $User->getRoles();
	
	$AllPermissions=array();
	
	foreach ($Roles as $Role) {
		
		//get all the permissions available in a role
		$Permissions = $Role->getPermissions();

		//iterate over the permission list
		foreach ($Permissions as $Permission) {
			
			//if a permission not available in the global list then add it
			if(!in_array($Permission->getID(), $AllPermissions)){

				//adding the permission to the global permission list
				$AllPermissions[]=$Permission->getID();

			}
		}

	}

	return $AllPermissions;
}

//echo '<br> log:: exit blade.login.inc';
//$_Log->log(LogUtil::$DEBUG,"exit blade.login.inc");

?>