<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.discussionCategorybao.inc';


$_DiscussionCategoryBAO = new DiscussionCategoryBAO();
$_DB = DBUtil::getInstance();

/* saving a new Discussion Category account*/
if(isset($_POST['save']))
{
	 $DiscussionCategory = new DiscussionCategory();	
	 $DiscussionCategory->setID(Util::getGUID());
     $DiscussionCategory->setName($_DB->secureInput($_POST['txtCat']));
	 $_DiscussionCategoryBAO->createDiscussionCategory($DiscussionCategory);		 
}


/* deleting an existing Discussion Category */
if(isset($_GET['del']))
{

	$DiscussionCategory = new DiscussionCategory();	
	$DiscussionCategory->setID($_GET['del']);	
	$_DiscussionCategoryBAO->deleteDiscussionCategory($DiscussionCategory); //reading the Discussion Category object from the result object

	header("Location:".PageUtil::$DISCUSSION_CAT);
}


/* reading an existing Discussion Category information */
if(isset($_GET['edit']))
{
	$DiscussionCategory = new DiscussionCategory();	
	$DiscussionCategory->setID($_GET['edit']);	
	$getROW = $_DiscussionCategoryBAO->readDiscussionCategory($DiscussionCategory)->getResultObject(); //reading the Discussion object from the result object
}

/*updating an existing Discussion information*/
if(isset($_POST['update']))
{
	$DiscussionCategory = new DiscussionCategory();	

    $DiscussionCategory->setID ($_GET['edit']);
    $DiscussionCategory->setName( $_POST['txtCat'] );
	
	$_DiscussionCategoryBAO->updateDiscussionCategory($DiscussionCategory);

	header("Location:".PageUtil::$DISCUSSION_CAT);
}



//$_Log->log(LogUtil::$DEBUG," exit blade.discussionCategory.inc");

?>