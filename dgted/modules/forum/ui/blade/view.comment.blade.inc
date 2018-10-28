<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_FORUM.'bao/class.commentbao.inc';
include_once MODULES_FORUM.'bao/class.discussionbao.inc';


$_CommentBAO = new CommentBAO();
$_DiscussionBAO = new DiscussionBAO();
$_DB = DBUtil::getInstance();

/* saving a new Comment account*/
if(isset($_POST['save']))
{
	 $Comment = new Comment();
	 //$Discussion = new Discussion();	
	 $Comment->setCommentID(Util::getGUID());
     $Comment->setComment($_DB->secureInput($_POST['txtAns']));
     $Comment->setDiscussionID($_DB->secureInput($_POST['txtComment']));
     
	 $_CommentBAO->createComment($Comment);		 
}


/* deleting an existing Comment */
if(isset($_GET['del']))
{

	$Comment = new Comment();	
	$Comment->setCommentID($_GET['del']);	
	$_CommentBAO->deleteComment($Comment); //reading the Comment object from the result object

	header("Location:".PageUtil::$DISCUSSION_COMMENT);
}

/* reading an existing Comment information */
if(isset($_GET['edit']))
{
	$Comment = new Comment();	
	$Comment->setCommentID($_GET['edit']);	
	$getROW = $_CommentBAO->readComment($Comment)->getResultObject(); //reading the Comment object from the result object
}

/*updating an existing Comment information*/
if(isset($_POST['update']))
{
	$Comment = new Comment();	

    $Comment->setCommentID ($_GET['edit']);
    $Comment->setComment( $_POST['txtAns'] );
	
	$_CommentBAO->updateComment($Comment);

	header("Location:".PageUtil::$DISCUSSION_COMMENT);
}



//$_Log->log(LogUtil::$DEBUG," exit blade.comment.inc");

?>