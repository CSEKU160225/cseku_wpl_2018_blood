<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.survey_ques_createbao.inc';


$_DB = DBUtil::getInstance();
$_QueBAOOb = new QuestionBAO();

if(isset($_POST['submit'])){
    $questionOb = new SurveyQuestion();
    $surQueOptOb = new SurveyQuestionOption();

    $ta = "textarea";
    $opt = "Opt";
    $numOpt = "NumOpt";
    $que = "Question";

    $num_of_ques = $_POST['totalQuestions'];
    $sID = $_REQUEST['sid'];

    for($i=1;$i<=$num_of_ques;$i++){
        $queVal = $_POST[$que.$i.$ta];
        $no = $_POST[$que.$i.$numOpt];

        $questionOb->setID(Util::getGUID());
        $questionOb->setSurveyID($_DB->secureInput($sID));
        $questionOb->setQuestionNo($_DB->secureInput($i));
        $questionOb->setQuestionType($_DB->secureInput('MCQ'));
        $questionOb->setQuestionValue($_DB->secureInput($queVal));
        $questionOb->setNumberOfOptions($_DB->secureInput($no));

        $_QueBAOOb->createQuestion($questionOb);

        for($j=1;$j<=$no;$j++){
            $surQueOptOb->setID(Util::getGUID());
            $surQueOptOb->setSurveyID($questionOb->getSurveyID());
            $surQueOptOb->setQuestionID($questionOb->getID());
            $surQueOptOb->setQuestionFieldValue($_POST[$que.$i.$opt.$j]);

            $_QueBAOOb->createQuestionOption($surQueOptOb);
        }

    }
}
