<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FILE.'bao/class.filebao.inc';
include_once MODULES_FILE.'bao/class.file_assignbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc';
include_once MODULES_USER.'bao/class.userbao.inc';


//$fileVarible = $_SESSION['fileVarible'];
$globalUser = $_SESSION['globalUser'];
$File = $_SESSION['globalFileIDSend'];


$_FileBAO = new FileBAO();
$_DB = DBUtil::getInstance();
$_File_assignBAO = new File_assignBAO();

$_DisciplineBAO = new DisciplineBAO();
$_UserBAO = new UserBAO();

//$array = array("userId1", "userId2", "userId3");
//$discipline = array("CSE","ECE","MATH");

/* saving a new File Assign account*/
if(isset($_POST['save']))
{
	 


	$FileAssign = new File_assign();
//
	$FileAssign->setID(Util::getGUID());
	$FileAssign->setFile($File->getFile());
	$FileAssign->setFileComment($_DB->secureInput($_POST['Comment']));
	
	$FileAssign->setIsPending(1);
	$FileAssign->setHasSeen(0);
	$FileAssign->setIsRejected(0);
	$FileAssign->setIsApproved(0);
	$FileAssign->setPreviousUser($File->getCurrentUser());
	$FileAssign->setCurrentUser(($_DB->secureInput($_POST['users'])));
	$FileAssign->setAssignDate(date("Y-m-d H:i:s"));


    $_File_assignBAO->createFile_assign($FileAssign);
//

    header("Location:".PageUtil::$FILE_STATUS);
	 //echo <br>"save";
	 //print_r(school);		 
}


//echo '<br> log:: exit blade.share.inc';

?>