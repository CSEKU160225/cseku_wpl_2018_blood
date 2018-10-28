<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.discussionbao.inc';
include_once MODULES_FORUM.'bao/class.discussionCategorybao.inc';

$_DiscussionBAO = new DiscussionBAO();
$_DiscussionCategoryBAO = new DiscussionCategoryBAO();
$_DB = DBUtil::getInstance();

/* saving a new Discussion account*/
if(isset($_POST['save']))
{
	 $DiscussionCategory = new DiscussionCategory();
	 $Discussion = new Discussion();	
	 $Discussion->setID(Util::getGUID());
     $Discussion->setName($_DB->secureInput($_POST['txtQuestion']));
     //$Discussion->setCategory($_DB->secureInput($_POST['txtCat']));
     $Discussion->setTag($_DB->secureInput($_POST['txtTag']));
     $Discussion->setDescription($_DB->secureInput($_POST['txtDes']));

   if(isset($_POST['txtCat'])){ 

			//$DiscussionCategory = new DiscussionCategory();
			//$DiscussionCategory->setName($_POST['txtCat']);
	
		$Discussion->setCategory($_POST['txtCat']);
	}
	 $_DiscussionBAO->createDiscussion($Discussion);		 
}


/* deleting an existing Discussion */
if(isset($_GET['del']))
{

	$Discussion = new Discussion();	
	$Discussion->setID($_GET['del']);	
	$_DiscussionBAO->deleteDiscussion($Discussion); //reading the Discussion object from the result object

	header("Location:".PageUtil::$DISCUSSION);
}

if(isset($_GET['view']))
{
	$Discussion1 = new Discussion();	
	$Discussion1->setID($_GET['view']);	
	$getROW = $_DiscussionBAO->readDiscussion($Discussion1)->getResultObject(); //reading the Discussion object from the result object

}
/* reading an existing Discussion information */
if(isset($_GET['edit']))
{
	$Discussion = new Discussion();	
	$Discussion->setID($_GET['edit']);	
	$getROW = $_DiscussionBAO->readDiscussion($Discussion)->getResultObject(); //reading the Discussion object from the result object
}

if (isset($_GET['catagoryview'])) {
	$Discussion = new Discussion();
	$Discussion->setCategory($_GET['catagoryview']);	
	$getROW = $_DiscussionBAO->readDiscussion1($Discussion)->getResultObject();

}



/*updating an existing Discussion information*/
if(isset($_POST['update']))
{
	$Discussion = new Discussion();	

    $Discussion->setID ($_GET['edit']);
    $Discussion->setName( $_POST['txtQuestion'] );
    $Discussion->setCategory($_POST['txtCat']);
    $Discussion->setTag($_POST['txtTag']);
    $Discussion->setDescription($_POST['txtDes']);
	
	$_DiscussionBAO->updateDiscussion($Discussion);

	header("Location:".PageUtil::$DISCUSSION);
}



//$_Log->log(LogUtil::$DEBUG," exit blade.discussion.inc");

?>