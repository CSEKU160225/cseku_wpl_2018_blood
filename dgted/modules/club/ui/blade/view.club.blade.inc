<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'bao/class.clubbao.inc';


$_ClubBAO = new ClubBAO();
$_DB = DBUtil::getInstance();
$Club = new Club();


// creating a new club
if(isset($_POST["save"]))
{
	$Club = new Club();	
	$Club->setID(Util::getGUID());
	$Club->setName($_DB->secureInput($_POST['txtName']));
	$Club->setDescription($_DB->secureInput($_POST['txtDes']));


	if($_FILES['cover_photo']['size'] > 0){
 
	$fileName = $_FILES['cover_photo']['name'];
	$tmpName  = $_FILES['cover_photo']['tmp_name'];
	$fileSize = $_FILES['cover_photo']['size'];
	$fileType = $_FILES['cover_photo']['type'];

	$fp      = fopen($tmpName, 'r');
	$content = fread($fp, filesize($tmpName));
	$content = addslashes($content);
	
	fclose($fp);
		
				
	$Club->setCoverPhoto($content);
	}
    
	$Club->setMail($_DB->secureInput($_POST['txtMail']));
	
	$_ClubBAO->createClub($Club);	 	 
}


// deleting an existing Club
if(isset($_GET['del']))
{

	$Club = new Club();	
	$Club->setID($_GET['del']);	
	$_ClubBAO->deleteClub($Club); //reading the Club object from the result object

	header("Location: club.php");
}
 


//reading an existing Position information 
if(isset($_GET['edit']))
{
	$Club = new Club();	
	$Club->setID($_GET['edit']);	
	$getROW = $_ClubBAO->readClub($Club)->getResultObject(); //reading the Position object from the result object
}


//updating an existing Position information
if(isset($_POST['update']))
{
	$Club = new Club();	

    $Club->setID ($_GET['edit']);
    $Club->setName( $_POST['txtName'] );
    $Club->setDescription( $_POST['txtDes'] );
    $Club->setMail( $_POST['txtMail'] );

	if($_FILES['cover_photo']['size'] > 0){
 
	$fileName = $_FILES['cover_photo']['name'];
	$tmpName  = $_FILES['cover_photo']['tmp_name'];
	$fileSize = $_FILES['cover_photo']['size'];
	$fileType = $_FILES['cover_photo']['type'];

	$fp      = fopen($tmpName, 'r');
	$content = fread($fp, filesize($tmpName));
	$content = addslashes($content);
	
	fclose($fp);
		
				
	$Club->setCoverPhoto($content);
	}

	$_ClubBAO->updateClub($Club);

	header("Location: club.php");
}

if(isset($_GET['new_module']))
{
	$Club = new Club();	
	$Club->setID($_GET['new_module']);	

	$getROW = $_ClubBAO->readClub($Club)->getResultObject();
	
	$_SESSION['current_club']=$getROW;

	header("Location: club_module.php");
}

if(isset($_GET['new_Member']))
{
	$Club = new Club();	
	$Club->setID($_GET['new_Member']);	
	$getROW = $_ClubBAO->readClub($Club)->getResultObject();
	
	header("Location: club_member.php");
}
if(isset($_GET['page']))
{
	$Club = new Club();	
	$Club->$_GET['page'];
	//$club=$_GET['page'];
	
	header("Location: clubpage.php"); //reading the Position object from the result object
}



//$_Log->log(LogUtil::$DEBUG," exit blade.club.inc");

?>