<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_JOB.'bao/class.jobbao.inc';


$_jobBAO = new jobBAO();
$_DB = DBUtil::getInstance();

/* saving a new job account*/
if(isset($_POST['save']))
{
	 $job = new Job();	
	 $job->setID(strtolower($_DB->secureInput($_POST['txtTitle'])));
     $job->setTitle($_DB->secureInput($_POST['txtTitle']));
	 $_jobBAO->createjob($job);		 
}


/* deleting an existing job */
if(isset($_GET['del']))
{

	$job = new Job();	
	$job->setID($_GET['del']);	
	$_jobBAO->deletejob($job); //reading the job object from the result object

	header("Location:".PageUtil::$Job);
}


/* reading an existing job information */
if(isset($_GET['edit']))
{
	$job = new Job();	
	$job->setID($_GET['edit']);	
	$getROW = $_jobBAO->readjob($job)->getResultObject(); //reading the job object from the result object
}

/*updating an existing job information*/
if(isset($_POST['update']))
{
	$job = new Job();	

    $job->setID ($_GET['edit']);
    $job->setTitle( $_POST['txtTitle'] );
	
	$_jobBAO->updatejob($job);

	header("Location:".PageUtil::$Job);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.job.inc");

?>