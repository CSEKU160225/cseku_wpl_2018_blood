<?php

include_once 'blade/view.question.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.question.inc';
include_once COMMON.'class.common.course.inc';

?>


<div class="panel panel-default">
    
    <div class="panel-heading">Question Archive Manager</div>
    
    <div class="panel-body">

	
	<div id="form" >
		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="title">Select Course Title:</label>
              	<div class="col-sm-6">	
					
					<?php
						$Result = $_QuestionBAO->getAllCourse();
						if ($Result->getIsSuccess())
							$CourseList = $Result->getResultObject();					
				?>
		
				<select name="title" class="form-control" for="title_check">
					<option selected disabled>Select Course Title</option>
					<?php
						for ($i = 0; $i<sizeof($CourseList); $i++){
							$Course = $CourseList[$i];
					?>
				
						<option value="<?php echo $Course->getID();?>" > <?php echo $Course->getTitle(); ?> 
						</option>
					<?php
					
					}
				?>	
				</select>
				
				<input type="checkbox" name="title_check" >
				
				</div>
			</div>	
			<div class="form-group">
              	<label class="control-label col-sm-4" for="course">Select Course No:</label>
              	<div class="col-sm-6">				
	
				<?php
						$Result = $_QuestionBAO->getAllCourse();
						if ($Result->getIsSuccess())
							$CourseList = $Result->getResultObject();					
				?>
				<select name="course" class="form-control" for="course_check">
					<option selected disabled>Select Course No</option>
					<?php
						for ($i = 0; $i<sizeof($CourseList); $i++){
							$Course = $CourseList[$i];
					?>
					
						<option value="<?php echo $Course->getID();?>" > <?php echo $Course->getCourseNo(); ?> 
						</option>
					
				<?php

				}
				?>	
				</select>
				<input type="checkbox" name="course_check">
				</div>
			</div>	

			<div class="form-group">
              	<label class="control-label col-sm-4" for="term">Select Term:</label>
              	<div class="col-sm-6">				

				<?php
						$Result = $_QuestionBAO->getAllTerms();
						if ($Result->getIsSuccess())
							$TermList = $Result->getResultObject();					
				?>
				
					<select name="term" class="form-control" for="term_check">
					<option selected disabled>Select Term</option>
					<?php
						for ($i = 0; $i<sizeof($TermList); $i++){
							$Term = $TermList[$i];
					?>
						<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
						</option>
					
				<?php
					
				}
				
				?>	
				</select>
				<input type="checkbox" name="term_check">
				</div>
			</div>	

			<div class="form-group">
              	<label class="control-label col-sm-4" for="session">Select Session:</label>
              	<div class="col-sm-6">	

					<?php
						$Result = $_QuestionBAO->getAllSession();
						if ($Result->getIsSuccess())
							$SessionList = $Result->getResultObject();					
				?>
				
					<select name="session" class="form-control" for="session_check">
					<option selected disabled>Select Session</option>
					<?php
						for ($i = 0; $i<sizeof($SessionList); $i++){
							$Session = $SessionList[$i];
					?>
					<?php
						if (!isset($_GET['edit'])){

					?>
						<option value="<?php echo $Session->getID();?>" > 
						<?php echo $Session->getName(); ?> 
						</option>
					<?php
					}
						if (isset($_GET['edit'])){
							
							if ($getROW->getSession() == $Session->getID() ){
					?>
						<option selected value = "<?php echo $Session->getID();?>" > 
						<?php echo $Session->getName();?> 
						</option>
					<?php
					}
						else {

					?>
					<option value="<?php echo $Session->getID();?>" > 
					<?php echo $Session->getName(); ?> 
					</option>
				<?php
					}	
					}
				}
				?>	
				</select>
				<input type="checkbox" name="session_check">
				</div>
			</div>
				
			<div class="form-group">
              	<label class="control-label col-sm-4" for="teacher">Select Teacher:</label>
              	<div class="col-sm-6">		
				
				<?php
						$Result = $_QuestionBAO->getAllUser();
						if ($Result->getIsSuccess())
							$UserList = $Result->getResultObject();					
				?>
				
					<select name="teacher" class="form-control" for="teacher_check">
					<option selected disabled>Select Teacher</option>
					<?php
						for ($i = 0; $i<sizeof($UserList); $i++){
							$User = $UserList[$i];
					?>
					<?php
						if (!isset($_GET['edit'])){

					?>
						<option value="<?php echo $User->getID();?>" > 
						<?php echo $User->getFirstName(); ?> 
						</option>
					<?php
					}
						if (isset($_GET['edit'])){
							
							if ($getROW->getTeacher() == $User->getID() ){
					?>
						<option selected value = "<?php echo $User->getID();?>" > 
						<?php echo $User->getFirstName();?> 
						</option>
					<?php
					}
						else {

					?>
					<option value="<?php echo $User->getID();?>" > 
					<?php echo $User->getFirstName(); ?> 
					</option>
				<?php
					}	
					}
				}
				?>	
				</select>
				<input type="checkbox" name="teacher_check">
				</div>
			</div>	

			<div>
              	<label class="control-label col-sm-4" for="type">Select Question Type:</label>
              	<div class="col-sm-6">
					<select name="type" class="form-control" for="type_check">
					<option selected disabled>Select Question Type</option>
					<option value="CT">CT</option>
					<option value="Term-Final">Term-Final</option>	
					</select>
					<input type="checkbox" name="type_check">
				</div>	
			</div>	


			<div class="form-group">
              	<label class="control-label col-sm-4" for="tag">Tag:</label>
              	<div class="col-sm-6">
					<select name="tag" class="form-control" for="tag_check">
					<option disabled selected>Select Tag</option>
					<?php
						$query=" ";
						$Result = $_QuestionBAO->searchQuestions($query);
						if($Result->getIsSuccess())
								$QuestionList = $Result->getResultObject();
						for($i = 0; $i < sizeof($QuestionList); $i++) {
								$Question = $QuestionList[$i];
					?>
					<option value="<?php echo $Question->getTag(); ?>"><?php echo $Question->getTag(); ?></option>
					<?php
				}
					?>
					</select>
					<input type="checkbox" name="tag_check">
				</div>
			</div>
			<div class="form-group">
              	<label class="control-label col-sm-4" for="question_date">Date:</label>
              	<div class="col-sm-6"> 				
				
				<input class="form-control" type="date" name="question_date" placeholder="Date" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getQuestionDate(); ?>">
				<input type="checkbox" name="date_check">
				</div>
			</div>	

        <div class="form-group">        
             <div class="col-sm-4">					
					
				<button type="submit" name="search_upload" >Search</button>

			</div>	
             <div class="col-sm-8">					
					
				<button type="submit" name="upload" >Manage Question</button>

			</div>	

		</div>		
				
		</form>

	</div>
	</div>

 <div class="panel-body">
	
	<table class="table table-bordered">

	<?php

	$query =" ";
	if (isset($_POST['search_upload'])){
		$flag = 0;
	if (isset($_POST['title_check']))
	{
		$flag = 1;
		$title_string = $_POST['title'];
		$title_string = "\"$title_string\"";
		$query = " WHERE "." Title = ".$query.$title_string." ";
	}
	if (isset($_POST['course_check']))
	{
		$course_string = $_POST['course'];
		$course_string = "\"$course_string\"";
		if ($flag == 1)
			$query = $query." and CourseID= ".$course_string." ";
		else
			$query = " WHERE "."CourseID =".$query.$course_string." ";

		$flag =1;
	}
	if (isset($_POST['term_check']))
	{
		$term_string= $_POST['term'];
		$term_string = "\"$term_string\"";
		if ($flag == 1)
			$query = $query." and TermID = ".$term_string." ";
		else
			$query = " WHERE "."TermID =".$query.$term_string." ";
		$flag = 1;
	}
	if (isset($_POST['session_check']))
	{
		$session_string= $_POST['session'];
		$session_string = "\"$session_string\"";
		if ($flag == 1)
			$query = $query." and SessionID = ".$session_string." ";
		else
			$query = " WHERE "."SessionID =".$query.$session_string." ";
		$flag = 1;
	}
	if (isset($_POST['teacher_check']))
	{
		$teacher_string= $_POST['teacher'];
		$teacher_string = "\"$teacher_string\"";
		if ($flag == 1)
			$query = $query." and TeacherID = ".$teacher_string." ";
		else
			$query = " WHERE "."TeacherID =".$query.$teacher_string." ";
		$flag = 1;
	}
	if (isset($_POST['type_check']))
	{
		$type_string= $_POST['type'];
		$type_string = "\"$type_string\"";
		if ($flag == 1)
			$query = $query." and Type = ".$type_string." ";
		else
			$query = " WHERE "."Type =".$query.$type_string." ";
		$flag = 1;
	}
	if (isset($_POST['tag_check']))
	{
		$tag_string= $_POST['tag'];
		$tag_string = "\"$tag_string\"";
		if ($flag == 1)
			$query = $query." and Tag = ".$tag_string." ";
		else
			$query = " WHERE "."Tag =".$query.$tag_string." ";
		$flag = 1;
	}
	if (isset($_POST['date_check']))
	{
		echo $_POST['question_date'];
		$date_string= $_POST['question_date'];
		$date_string = "\"$date_string\"";
		if ($flag == 1)
			$query = $query." and QuestionDate = ".$date_string." ";
		else
			$query = " WHERE "."QuestionDate =".$query.$date_string." ";
		$flag = 1;
	}
	//echo "SELECT * FROM tbl_question_archive"." WHERE ".$query;
	$Result = $_QuestionBAO->searchQuestions($query);

	//if DAO access is successful to load all the Roles then show them one by one
	if($Result->getIsSuccess()){

		$QuestionList = $Result->getResultObject();
	?>
	
		<tr>
			
			<th>Title </th>
			<th>Course </th>
			<th>Term </th>
			<th>Session </th>
			<th>Teacher </th>
			<th>Type</th>
			<th>Tag</th>
			<th>Date</th>

		</tr>
		<?php
		for($i = 0; $i < sizeof($QuestionList); $i++) {
			$Question = $QuestionList[$i];
			//echo $Question->getLink();
			?>
		    <tr>
			    
			    <td><?php echo $_QuestionBAO->getTitleFromID( $Question->getTitle());?></td>
			    <td><?php echo $_QuestionBAO->getCourseFromID($Question->getCourse());?></td>
			    <td><?php echo $_QuestionBAO->getTermFromID($Question->getTerm()); ?></td>
			    <td><?php echo $_QuestionBAO->getSessionFromID($Question->getSession()); ?></td>
			    <td><?php echo $_QuestionBAO->getTeacherFromID($Question->getTeacher()); ?></td>
			    <td><?php echo $Question->getType(); ?></td>
			    <td><?php echo $Question->getTag(); ?></td>
			    <td><?php echo $Question->getQuestionDate(); ?></td>
			    <td><a href="<?php echo $Question->getLink(); ?>" target = "_blank">Download</a></td>
			    
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject(); //giving failure message
	}
}
	?>
	</table>
	</div>

</div>
