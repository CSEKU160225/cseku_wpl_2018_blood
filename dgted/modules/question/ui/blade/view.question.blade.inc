<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_QUESTION.'bao/class.questionbao.inc';


$_QuestionBAO = new QuestionBAO();
$_DB = DBUtil::getInstance();

/*Log out Operation*/
if (isset($_POST['log_out']))
{
	session_start();
	session_destroy();
	header("Location:login.php");
}
if (isset($_POST['search']))
{
	header("Location:question_search.php");
}
if (isset($_POST['upload']))
{
	header("Location:question.php");
}
/* saving a new Role account*/
if(isset($_POST['save']))
{
	echo "<br>Save called";
	 $Question = new Question();	
	 $Question->setID(Util::getGUID());
     $Question->setTitle($_DB->secureInput($_POST['title']));
     $Question->setCourse($_DB->secureInput($_POST['course']));
     $Question->setTerm($_DB->secureInput($_POST['term']));
     $Question->setSession($_DB->secureInput($_POST['session']));
     $Question->setTeacher($_DB->secureInput($_POST['teacher']));
     $Question->setType($_DB->secureInput($_POST['type']));
     $Question->setTag($_DB->secureInput($_POST['tag']));
     $Question->setQuestionDate($_DB->secureInput($_POST['question_date']));
     $Question->setLink($_DB->secureInput($_POST['link']));
     $Question->setCreator($_POST['creator']);
     
     if ($Question->getCreator() == "") 	
     	echo "<br>Please Enter Creator";
     else 
	 	$_QuestionBAO->createQuestion($Question);		 
}


/* deleting an existing Role */
if(isset($_GET['del']))
{

	$Question = new Question();	
	$Question->setID($_GET['del']);	
	$_QuestionBAO->deleteQuestion($Question); //reading the Role object from the result object

	header("Location: view.question.php");
}


/* reading an existing Question information */
if(isset($_GET['edit']))
{
	$Question = new Question();	
	$Question->setID($_GET['edit']);	
	$getROW = $_QuestionBAO->readQuestion($Question)->getResultObject();                                  
}

/*updating an existing Role information*/
if(isset($_POST['update']))
{
	$Question = new Question();	

    $Question->setID ($_GET['edit']);
    $Question->setTitle( $_POST['title'] );
	$Question->setCourse( $_POST['course'] );
	$Question->setTerm( $_POST['term'] );
	$Question->setSession( $_POST['session'] );
	$Question->setTeacher( $_POST['teacher'] );
	$Question->setType( $_POST['type'] );
    $Question->setTag( $_POST['tag'] );
	$Question->setQuestionDate( $_POST['question_date'] );
	$Question->setLink( $_POST['link']);
	$Question->setCreator($_POST['creator']);
	echo 'Update Called';
	//echo $Question->getLink();
	
	$_QuestionBAO->updateQuestion($Question);

	header("Location: question.php");
}


//$_Log->log(LogUtil::$DEBUG," exit blade.Question.inc");

?>