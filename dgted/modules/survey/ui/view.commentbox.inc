<?php

include_once 'blade/view.commentbox.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.survey.inc';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>Comment Box SURVEY QUESTIONS </title>
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
                    <td><input type="text" name="txtsurveyquestion" placeholder="Enter Question Text" value="<?php 
                    if(isset($_GET['edit'])) echo $getROW->getQuestionValue();  ?>" /> </td>
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

	<table width="100%" border="1" cellpadding="15" align="center">
	<?php
	
	
	$Result = $_SurveyQuestionBAO->getAllSurveyQuestions();

	//if DAO access is successful to load all the SurveyQuestions then show them one by one
	if($Result->getIsSuccess()){

		$SurveyQuestionList = $Result->getResultObject();
	?>
		<tr>
			<td>Question Number</td>
			<td>Question</td>
			<td>Answer</td>
		</tr>
		<?php
		for($i = 0; $i < sizeof($SurveyQuestionList); $i++) {
			$SurveyQuestion = $SurveyQuestionList[$i];
			?>
		    <tr>
			    <td><?php echo $SurveyQuestion->getQuestionValue(); ?></td>
			    <td><a href="?edit=<?php echo $SurveyQuestion->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $SurveyQuestion->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
</center>
</body>
</html>