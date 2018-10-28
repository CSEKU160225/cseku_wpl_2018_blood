<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'bao/class.file_assignbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //module user dependency
include_once MODULES_USER.'bao/class.userbao.inc'; //module user depenedency



$globalUser = $_SESSION['globalUser'];
$globalFileID = $_SESSION['globalFileID'];
$_UserBAO = new UserBAO();

$_DB = DBUtil::getInstance();

$_File_assignBAO = new File_assignBAO();



/* saving a new File account*/
if(isset($_POST['save']))
{
	 $File = new File();
	 $File->setID(Util::getGUID());
	 $File->setCreator($globalUser->getID());
     $File->setName($_DB->secureInput($_POST['users']));
     $File->setLink($_DB->secureInput($_POST['link']));
     $File->setDiscipline($_POST['discipline']);
     
     
     
	 $_FileBAO->createFile($File);
	 //echo <br>"save";
	 //print_r(school);		 
}


/* deleting an existing File */
if(isset($_GET['del']))
{

	$File = new File();	
	$File->setID($_GET['del']);	
	$_FileBAO->deleteFile($File); //reading the File object from the result object

	header("Location:".PageUtil::$FILE);
}


/* reading an existing File information */
if(isset($_GET['edit']))
{
	$File = new File();	
	$File->setID($_GET['edit']);	
	$getROW = $_FileBAO->readFile($File)->getResultObject(); //reading the File object from the result object
}

/*updating an existing File information*/
if(isset($_POST['update']))
{
	
	$File = new File();
	
	$File->setID ($_GET['edit']);
	$File->setCreator($globalUser->getID());
	$File->setName($_DB->secureInput($_POST['users']));
	$File->setLink($_DB->secureInput($_POST['link']));
	$File->setDiscipline($_POST['discipline']);

    
	$_FileBAO->updateFile($File);

	header("Location:".PageUtil::$FILE);
}



//echo '<br> log:: exit blade.file.inc';

?>