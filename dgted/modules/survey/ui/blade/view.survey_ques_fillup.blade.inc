<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_SURVEY.'bao/class.survey_ques_createbao.inc';

if(isset($_POST['submit'])){
    $queOb = new QuestionBAO();

    $Result = $queOb->getAllQuestions($_REQUEST['sid']);
    $ResultOb = $Result->getResultObject();
    $numOfQues = count($ResultOb);

    $que = "Question";
    $opt = "Opt";

    for($i=0;$i<$numOfQues;$i++){

        $Result2 = $queOb->getAllOption($_REQUEST['sid'], $ResultOb[$i]->getID());
        $ResultOb2 = $Result2->getResultObject();
        $numOfOption = count($ResultOb2);

        for($j=0;$j<$numOfOption;$j++){
            $str = $que . ($i+1) . $opt . ($j+1);
            
            $val='';

            if(isset($_POST[$str])){
                $val = $_POST[$str];                        
                $obj = new SurveyQuestionFilled();
                $obj->setSurveyID($ResultOb[$i]->getSurveyID());
                $obj->setQuestionID($ResultOb[$i]->getID());
                $obj->setFilledValue($val);
                $obj->setFilledUserID($_SESSION['globalUser']->getID());
                $obj->setFilledTime(date("Y-m-d H:i:s"));

                $queOb->createSurveyQuestionFilled($obj);
            }

        }


    }
}