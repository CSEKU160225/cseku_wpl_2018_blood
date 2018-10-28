<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.searchDiscussionbao.inc';

$_searchDiscussionBAO = new searchDiscussionBAO();
$_DB = DBUtil::getInstance();
$Discussion = new Discussion();

if(isset($_POST['search']))
{
	 
     $Discussion->setTag($_DB->secureInput($_POST['txtSearch']));

     //$_searchDiscussionBAO->readTagwiseDiscussion($Discussion);
     $tag = $Discussion->getTag();

     header("Location:".PageUtil::$DISCUSSION_SEARCH."?tag=".$tag);

}


//$_Log->log(LogUtil::$DEBUG," exit blade.searchDiscussion.inc");

?>