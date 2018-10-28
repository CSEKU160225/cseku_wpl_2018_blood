<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.surveybao.inc';


$_SurveyBAO = new SurveyBAO();

$_DB = DBUtil::getInstance();
$_Log= LogUtil::getInstance();

$globalSurvey = '';

/* saving a new Survey account*/
if(isset($_POST['save']))
{
     $Survey = new Survey();    
     $Survey->setID(Util::getGUID());
     $Survey->setTitle($_DB->secureInput($_POST['txtTitle']));
     $Survey->setDescription($_DB->secureInput($_POST['txtDescription']));
     $Survey->setTotalQuestions($_DB->secureInput($_POST['txtTotalQuestions']));
     $Survey->setCreator($_DB->secureInput($_POST['txtCreator']));

     $Survey->setCompletionDate($_DB->secureInput($_POST['txtCompletionDate']));

    if ($Survey->getTitle() == "")
        echo "<br>Please Enter All Field";
    else
        $_SurveyBAO->createSurvey($Survey);

}


/* deleting an existing Survey */
if(isset($_GET['del']))
{

    $Survey = new Survey(); 
    $Survey->setID($_GET['del']); 
    $_SurveyBAO->deleteSurvey($Survey); //reading the Survey object from the result object

    header("Location: view.survey.php");
}


/* reading an existing Survey information */
if(isset($_GET['edit']))
{
    $Survey = new Survey(); 
    $Survey->setID($_GET['edit']);    
    $globalSurvey = $_SurveyBAO->readSurvey($Survey)->getResultObject(); //reading the Survey object from the result object
   
}

/*updating an existing Survey information*/
if(isset($_POST['update']))
{
    $Survey = new Survey();    

     $Survey->setID($_GET['edit']);
     $Survey->setTitle($_POST['txtTitle']);
     $Survey->setDescription($_POST['txtDescription']);
    
     $Survey->setTotalQuestions($_POST['txtTotalQuestions']);
     $Survey->setCreator($_POST['txtCreator']);
     $Survey->setCompletionDate($_POST['txtCompletionDate']);


    

    $_SurveyBAO->updateSurvey($Survey);

    header("Location: view.survey.php");
}


//$_Log->log(LogUtil::$DEBUG,"exit blade.survey.inc");

?>