<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'bao/class.membersbao.inc';
include_once MODULES_CLUB.'bao/class.clubbao.inc';

$_ClubBAO = new ClubBAO();
$_MembersBAO = new MembersBAO();
$_DB = DBUtil::getInstance();

/* saving a new Member account*/
if(isset($_POST['save']))
{
	 $Members = new Members();

	 $Members->setClubID($_DB->secureInput($_POST['club_id']));
	 $Members->setMemberID(Util::getGUID());
     $Members->setName($_DB->secureInput($_POST['txtName']));
     $Members->setDesignation($_DB->secureInput($_POST['txtDes']));
	 $_MembersBAO->createMembers($Members);		 
}

if(isset($_POST['back']))
{
	 header("Location: club.php");	 
}

/* deleting an existing Member */
if(isset($_GET['del']))
{

	$Members = new Members();	
	$Members->setMemberID($_GET['del']);	
	$_MembersBAO->deleteMembers($Members); //reading the Member object from the result object

	header("Location: club_member.php?club=".$_GET['club']);
}


/* reading an existing Member information */
if(isset($_GET['edit']))
{
	$Members = new Members();	
	$Members->setMemberID($_GET['edit']);	
	$getROW = $_MembersBAO->readMembers($Members)->getResultObject(); //reading the Member object from the result object
}

/*updating an existing Member information*/
if(isset($_POST['update']))
{
	$Members = new Members();	

    $Members->setMemberID ($_GET['edit']);
    $Members->setName( $_POST['txtName'] );
    $Members->setDesignation( $_POST['txtDes'] );
	
	$_MembersBAO->updateMembers($Members);

	header("Location: club_member.php?club=".$_POST['club_id']);
}



//$_Log->log(LogUtil::$DEBUG," exit blade.Members.inc");

?>