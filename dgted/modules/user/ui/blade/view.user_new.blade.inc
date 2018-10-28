<?php


include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.userbao.inc';
include_once MODULES_USER.'bao/class.rolebao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc';//here comes module dependency


$_UserBAO = new UserBAO();
$_RoleBAO = new RoleBAO();
$_DisciplineBAO = new DisciplineBAO();
$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();


/* saving a new user account*/
if(isset($_POST['request']))
{
	 $User = new User();	

	 $User->setID(strtolower($_DB->secureInput($_POST['txtEmail']))); 
	 
	 $User->setUniversityID($_DB->secureInput($_POST['txtUniversityID']));

     $User->setFirstName($_DB->secureInput($_POST['txtFirstName']));
     $User->setMiddleName($_DB->secureInput($_POST['txtMiddleName']));
     $User->setLastName($_DB->secureInput($_POST['txtLastName']));
     $User->setBlood($_DB->secureInput($_POST['selectBlood']));
	 $User->setEmail(strtolower($_DB->secureInput($_POST['txtEmail']))); 

	 $HashPwd = Util::getPasswordHash($_DB->secureInput($_POST['txtPassword'])); //hashing the password

     $User->setPassword($HashPwd);

     $User->setStatus('pending');

    
    if(isset($_POST['selectRole'])){ 
		$Role = new Role();
		$Role->setID($_POST['selectRole']);
		$Roles[]=$Role;		
		$User->setRoles($Roles);
	}
	
    if(isset($_POST['selectDiscipline'])){ 
		$Discipline = new Discipline();
		$Discipline->setID($_POST['selectDiscipline']);	
		$User->setDiscipline($Discipline);
	}

	$Result = $_UserBAO->newUserRequest($User);		

	if($Result->getIsSuccess()){
	   Util::printToast($Result->getResultObject());	
	}
    

}



//$_Log->log(LogUtil::$DEBUG,"exit blade.user_new.inc");

?>