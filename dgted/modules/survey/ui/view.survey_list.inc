<?php

include_once 'blade/view.survey_list.blade.inc';



function createArea(){
    $surveyBAOOb = new SurveyBAO();

    $Result = $surveyBAOOb->getAllSurveys();
    $ResultOb = $Result->getResultObject();

    $numOfSur = count($ResultOb);

    for($i=0;$i<$numOfSur;$i++){
        $obj = $ResultOb[$i];
        ?>
        <h2>Survey Title: <?php echo $obj->getTitle();?></h2>
        <h3>Survey Description: <?php echo $obj->getDescription();?></h3>
        <a href="survey_ques_fillup.php?sid=<?php echo $obj->getID()?>" class="btn btn-primary" style="margin-top: 1%">Participate</a>
        <?php
    }
}



?>

<div class="container">

    <?php
        createArea();
    ?>

</div>

