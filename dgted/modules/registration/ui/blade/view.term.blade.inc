<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';


$_TermBAO = new TermBAO();
$_DB = DBUtil::getInstance();

/* saving a new Term account*/
if(isset($_POST['save']))
{
	 $Term = new Term();	
	 $Term->setID(Util::getGUID());
     $Term->setName($_DB->secureInput($_POST['txtName']));
	 $_TermBAO->createTerm($Term);		 
}


/* deleting an existing Term */
if(isset($_GET['del']))
{

	$Term = new Term();	
	$Term->setID($_GET['del']);	
	$_TermBAO->deleteTerm($Term); //reading the Term object from the result object

	header("Location:".PageUtil::$TERM);
}


/* reading an existing Term information */
if(isset($_GET['edit']))
{
	$Term = new Term();	
	$Term->setID($_GET['edit']);	
	$getROW = $_TermBAO->readTerm($Term)->getResultObject(); //reading the Term object from the result object
}

/*updating an existing Term information*/
if(isset($_POST['update']))
{
	$Term = new Term();	

    $Term->setID ($_GET['edit']);
    $Term->setName( $_POST['txtName'] );
	
	$_TermBAO->updateTerm($Term);

	header("Location:".PageUtil::$TERM);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.term.inc");

?>