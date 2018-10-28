<?php

include_once 'blade/view.survey_ques_type.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';

?>

	<div id="form">
		<form method="post">
			<table width="100%" border="1" cellpadding="15">
				<tr>
					<td><input type="text" name="txtType" placeholder=" Question Type " value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getType();  ?>" /></td>
				</tr>
				<tr>
					<td>
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<button type="submit" name="update">update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" name="save">save</button>
							<?php
						}
						?>
					</td>
				</tr>
			</table>
		</form>

</div>
<div>

	<table width="100%" border="1" cellpadding="15" align="center">
	<?php
	
	
	$Result = $_SurveyQuestionTypeBAO->getAllSurveyQuestionTypes();

	//if DAO access is successful to load all the SurveyQuestionTypes then show them one by one
	if($Result->getIsSuccess()){

		$SurveyQuestionTypeList = $Result->getResultObject();
	?>
		<tr>
			<td>Question Type</td>
		</tr>
		<?php
		for($i = 0; $i < sizeof($SurveyQuestionTypeList); $i++) {
			$SurveyQuestionType = $SurveyQuestionTypeList[$i];
			?>
		    <tr>
			    <td><?php echo $SurveyQuestionType->getType(); ?></td>
			    <td><a href="?edit=<?php echo $SurveyQuestionType->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $SurveyQuestionType->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject(); //giving failure message
	}

	?>
	</table>
</div>
