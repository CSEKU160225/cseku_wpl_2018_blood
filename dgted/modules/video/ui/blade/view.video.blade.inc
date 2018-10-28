<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'bao/class.videobao.inc';


$_VideoBAO = new VideoBAO();
$_DB = DBUtil::getInstance();

/* saving a new Term account*/
if(isset($_POST['save']))
{
	 $Video = new Video();	
	 $Video->setID(Util::getGUID());
     $Video->setTitle($_DB->secureInput($_POST['txtName']));
     $Video->setDescription($_DB->secureInput($_POST['txtdes']));
     $Video->setLink($_DB->secureInput($_POST['txtlink']));
     $Video->setIsEmbed($_DB->secureInput($_POST['txtembed']));
     $Video->setTag($_DB->secureInput($_POST['txttag']));
	 $_VideoBAO->createVideo($Video);		 
}


/* deleting an existing Term */
if(isset($_GET['del']))
{

	$Video = new Video();	
	$Video->setID($_GET['del']);	
	$_VideoBAO->deleteVideo($Video); //reading the Term object from the result object

	header("Location:".PageUtil::$VIDEO);
}


/* reading an existing Term information */
if(isset($_GET['edit']))
{
	$Video = new Video();	
	$Video->setID($_GET['edit']);	
	$getROW = $_VideoBAO->readVideo($Video)->getResultObject(); //reading the Term object from the result object
}

/*updating an existing Term information*/
if(isset($_POST['update']))
{
	$Video = new Video();	

    $Video->setID ($_GET['edit']);
    $Video->setTitle( $_POST['txtName'] );
    $Video->setDescription( $_POST['txtdes'] );
	$Video->setLink( $_POST['txtlink'] );
	//$Video->setIsEmbed( $_POST['txtembed'] );
	$Video->setTag( $_POST['txttag'] );
	$_VideoBAO->updateVideo($Video);

	header("Location:".PageUtil::$VIDEO);
}



////$_Log->log(LogUtil::$DEBUG," exit blade.video.inc");

?>