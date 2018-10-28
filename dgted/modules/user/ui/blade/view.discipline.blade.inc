<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc';
include_once MODULES_USER.'bao/class.schoolbao.inc';


$_SchoolBAO = new SchoolBAO();
$_DisciplineBAO = new DisciplineBAO();
$_DB = DBUtil::getInstance();

/* saving a new Discipline account*/
if(isset($_POST['save']))
{
	 $Discipline = new Discipline();

	 $School = new School();
	 $School->setID($_POST['selectedSchool']);	 
	 $Discipline->setSchool($School);

	 $Discipline->setID(Util::getGUID());
     $Discipline->setName($_DB->secureInput($_POST['txtName']));
     $Discipline->setShortCode($_DB->secureInput($_POST['txtShortCode']));
	 
	 $_DisciplineBAO->createDiscipline($Discipline);		 
}


/* deleting an existing Discipline */
if(isset($_GET['del']))
{

	$Discipline = new Discipline();	
	$Discipline->setID($_GET['del']);	
	$_DisciplineBAO->deleteDiscipline($Discipline); //reading the Discipline object from the result object

	header("Location:".PageUtil::$DISCIPLINE);
}


/* reading an existing Discipline information */
if(isset($_GET['edit']))
{
	$Discipline = new Discipline();	
	$Discipline->setID($_GET['edit']);

	$getROW = $_DisciplineBAO->readDiscipline($Discipline)->getResultObject(); //reading the Discipline object from the result object

}

/*updating an existing Discipline information*/
if(isset($_POST['update']))
{
	$Discipline = new Discipline();	

	$School = new School();
	$School->setID($_POST['selectedSchool']);	 
	$Discipline->setSchool($School);


    $Discipline->setID ($_GET['edit']);
    $Discipline->setName( $_POST['txtName'] );
    $Discipline->setShortCode( $_POST['txtShortCode'] );
	
	$_DisciplineBAO->updateDiscipline($Discipline);

	header("Location:".PageUtil::$DISCIPLINE);
}



////$_Log->log(LogUtil::$DEBUG," exit view.blade.discipline.inc");

?>