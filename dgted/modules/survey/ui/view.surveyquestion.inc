<?php

include_once 'blade/view.surveyquestion.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>SURVEY QUESTIONS </title>
		<link rel="stylesheet" href="style.css" type="text/css" />
		
	</head>

<body>
<center>
	<div id="header">
		<label>By : Kazi Masudul Alam</a></label>
	</div>

	<div id="form">
		<form method="post" name="formPermissions">
			<table width="100%" border="1" cellpadding="15">
			<tr>
				<td><label> Survey Name </label></td>
			</tr>
			<tr>
				<td><label> Question Number </label></td>
			</tr>
			<tr>
					<td>
							<label>Question Types:: </label>
						    

						    <?php
						    // this block of code prints the list box of Positions with current assigned  Positions

						    $var = '<select name="selectedQuestionType[]" id="select-from-QuestionType" multiple>';
							$Result = $_SurveyQuestionTypeBAO->getAllSurveyQuestionTypes();
								//if DAO access is successful to load all the Positions then show them one by one
							if($Result->getIsSuccess()){

								$SurveyQuestionTypes = $Result->getResultObject();
							
						       for ($i=0; $i < sizeof($SurveyQuestionTypes); $i++) { 
						       		
						       		$SurveyQuestionType = $SurveyQuestionTypes[$i];
						    
						    		$var = $var. '<option value="'.$SurveyQuestionType->getID().'"';   			

						       		if(isset($_GET['edit']) && isSurveyQuestionTypeAvailable($SurveyQuestionType,$globalUser->getSurveyQuestionTypes())) {
						          		$var = $var.' selected="selected"';
						          	} 

						          	$var = $var.'>'.$SurveyQuestionType->getType().'</option>';
					
								}

								$var = $var.'</select>';
							}
							echo $var;
							?>	
					</td>
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

<br />

	
	</div>
</center>
</body>
</html>