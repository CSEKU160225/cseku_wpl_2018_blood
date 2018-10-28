<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_VIDEO.'bao/class.videosearchbao.inc';


$_VideoBAO = new VideoBAO();
$_DB = DBUtil::getInstance();
//$Video = new Video();
/* saving a new Term account*/



/* reading an existing Term information */
if(isset($_POST['search']))
{
	$Video = new Video();	
	$Video->setTag($_DB->secureInput($_POST['txtsearch']));
	$tag = $Video->getTag();
	//$Video->setTag($_POST['txtsearch']);
	
	header("Location:".PageUtil::$VIDEO_SEARCH."?tag=".$tag); //reading the Term object from the result object
}

/*updating an existing Term information*/




////$_Log->log(LogUtil::$DEBUG," exit blade.video.inc");

?>