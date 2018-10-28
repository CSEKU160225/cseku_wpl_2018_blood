<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'bao/class.modulebao.inc';
include_once MODULES_CLUB.'bao/class.clubbao.inc';

$_ClubBAO = new ClubBAO();
$_ModuleBAO = new ModuleBAO();
$_DB = DBUtil::getInstance();
$Club = new Club();


/* saving a new module to the club*/
if(isset($_POST['save']))
{
	 $Club = new Club();

	 $Module = new ClubModule();		 
	 $Module->setClubID($_DB->secureInput($_POST['club_id']));	 
	 $Module->setModuleID(Util::getGUID());
     $Module->setModuleName($_DB->secureInput($_POST['txtModuleName']));
     
     if(isset($_POST['visible']))
     	$Module->setIsVisible(1);
     else
     	$Module->setIsVisible(0);


     $Module->setContent($_DB->secureInput($_POST['txtContent']));

	 
	 $_ModuleBAO->createModule($Module);
	 	 
}



//reading an existing module and editing information 
if(isset($_GET['edit']))
{
	$Module = new ClubModule();	
	$Module->setModuleID($_GET['edit']);	
	$getROW = $_ModuleBAO->readModule($Module)->getResultObject(); //reading the Position object from the result object
}


// deleting an existing module from the selected club
if(isset($_GET['del']))
{

	$Module = new ClubModule();	
	$Module->setModuleID($_GET['del']);	
	$_ModuleBAO->deleteModule($Module); //reading the Club object from the result object

	header('Location: club_module.php?club='.$_GET['club']);
}

//updating an existing Position information
if(isset($_POST['update']))
{
	$Module = new ClubModule();	

    $Module->setModuleID ($_GET['edit']);
    $Module->setModuleName( $_POST['txtModuleName'] );
    if(isset($_POST['visible'])){

			$Module->setIsVisible(1);
	}
	else {
			$Module->setIsVisible(0);
	}

	$Module->setContent( $_POST['txtContent'] );

	
	$_ModuleBAO->updateModule($Module);


	header('Location: club_module.php?club='.$_POST['club_id']);
	
}


//$_Log->log(LogUtil::$DEBUG," exit blade.module.inc");

?>