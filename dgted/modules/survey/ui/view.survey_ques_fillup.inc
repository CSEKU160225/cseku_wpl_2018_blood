<?php

include_once 'blade/view.survey_ques_fillup.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';

function createArea(){
    $queOb = new QuestionBAO();

    $Result = $queOb->getAllQuestions($_REQUEST['sid']);
    $ResultOb = $Result->getResultObject();

    $numOfQues = count($ResultOb);

    $que = "Question";
    $opt = "Opt";

    if($numOfQues==0){
        ?>
        <h1>This Survey is empty now.</h1>
        <?php
    }else{
        ?>
        <h1 class="text-center"><?php $queOb->getSurveyTitle($_REQUEST['sid']);?></h1>


        <?php

        for($i=0;$i<$numOfQues;$i++){
            $Result2 = $queOb->getAllOption($_REQUEST['sid'], $ResultOb[$i]->getID());
            $ResultOb2 = $Result2->getResultObject();
            $numOfOption = count($ResultOb2);

            ?>
            <h3>Question number <?php echo $i;?></h3>
            <h4><?php echo $ResultOb[$i]->getQuestionValue();?></h4>


            <?php

            for($j=0;$j<$numOfOption;$j++){
                $str = $que . ($i+1) . $opt . ($j+1);
                ?>
                <input class="form-check-input" type="radio" name="<?php echo $str;?>" value="<?php echo $ResultOb2[$j]->getQuestionFieldValue();?>">
                <?php echo $ResultOb2[$j]->getQuestionFieldValue();?>
                <br/>
                <?php
            }

        }
        ?>

        <input type="submit" class="btn btn-primary" name="submit" value="Submit">


        <?php

    }

}

?>


<div class="container">
    <form method="post">
        <?php
            createArea();
        ?>
    </form>
</div>
