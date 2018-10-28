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
				<select name="title" class="form-control">
					<option selected disabled>Select Course Title</option>
					<?php
						for ($i = 0; $i<sizeof($CourseList); $i++){
							$Course = $CourseList[$i];
						if (!isset($_GET['edit'])){

					?>
						<option value="<?php echo $Course->getID();?>" > <?php echo $Course->getTitle(); ?> 
						</option>
						<?php
						}
						if (isset($_GET['edit'])){
							
							if ($getROW->getTitle() == $Course->getID() ){
					?>
						<option selected value = "<?php echo $Course->getID();?>" > 
							<?php echo $Course->getTitle();?> 
						</option>
							<?php
							}
							else {

							?>
					<option value="<?php echo $Course->getID();?>" > 
						<?php echo $Course->getTitle(); ?> 
					</option>
					<?php
							}	
						}
						}
					?>	
				</select>

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
				
					<select name="course" class="form-control">
					<option selected disabled>Select Course No</option>
					<?php
					for ($i = 0; $i<sizeof($CourseList); $i++){
							$Course = $CourseList[$i];

						if (!isset($_GET['edit'])){

					?>
						<option value="<?php echo $Course->getID();?>" > 
						<?php echo $Course->getCourseNo(); ?> 
						</option>
					<?php
						}
	
						if (isset($_GET['edit'])){
							
							if ($getROW->getCourse() == $Course->getID() ){
					?>
						<option selected value = "<?php echo $Course->getID();?>" > 
						<?php echo $Course->getCourseNo();?> 
						</option>
					<?php

						}
					
						else {

					?>
					<option value="<?php echo $Course->getID();?>" > 
					<?php echo $Course->getCourseNo(); ?> 
					</option>
				<?php
						}	
					}
					}
				?>	
				</select>
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
		
					<select name="term" class="form-control">
					<option selected disabled>Select Term</option>
					<?php
						for ($i = 0; $i<sizeof($TermList); $i++){
							$Term = $TermList[$i];
	
						if (!isset($_GET['edit'])){

					?>
						<option value="<?php echo $Term->getID();?>" > 
						<?php echo $Term->getName(); ?> 
						</option>
					<?php
					}
						if (isset($_GET['edit'])){
							
							if ($getROW->getTerm() == $Term->getID() ){
					?>
						<option selected value = "<?php echo $Term->getID();?>" > 
						<?php echo $Term->getName();?> 
						</option>
					<?php
					}
						else {

					?>
					<option value="<?php echo $Term->getID();?>" > 
					<?php echo $Term->getName(); ?> 
					</option>
				<?php
						}	
					}
					}
				?>	
				</select>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="selectSession">Select Session:</label>
              	<div class="col-sm-6">	

				<?php
						$Result = $_QuestionBAO->getAllSession();
						if ($Result->getIsSuccess())
							$SessionList = $Result->getResultObject();					
				?>

					<select name="session" class="form-control">
					<option selected disabled>Select Session</option>
					<?php
						for ($i = 0; $i<sizeof($SessionList); $i++){
							$Session = $SessionList[$i];

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
		
					<select name="teacher" class="form-control">
					<option selected disabled>Select Teacher</option>
					<?php
						for ($i = 0; $i<sizeof($UserList); $i++){
							$User = $UserList[$i];

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
				</div>
			</div>

			<div>
              	<label class="control-label col-sm-4" for="selectQuestionType">Select Question Type:</label>
              	<div class="col-sm-6">
					<select name="type" class="form-control" required>
					<option selected disabled>Select Question Type</option>
					<?php
						if (!isset($_GET['edit'])){
					?>
					<option value="CT">CT</option>
					<option value="Term-Final">Term-Final</option>
					<?php
					}
					if (isset($_GET['edit'])){
						if ($getROW->getType() == 'CT'){	
					?>
					<option selected value="CT">CT</option>
					<option value="Term-Final">Term-Final</option>
					<?php
				}
				else {
					?>
					<option value="CT">CT</option>
					<option selected="Term-Final">Term-Final</option>
					<?php
				}
			}
				?>
				</select>
				</div>
			</div>
			<div class="form-group">
              	<div class="col-sm-10">  		
				<input type="hidden" name="creator" value="<?php echo $_SESSION['globalUser']->getID(); ?>">
				</div>
			</div>	
			<div class="form-group">
              	<label class="control-label col-sm-4" for="tag">Tag:</label>
              	<div class="col-sm-6">  
              		<input type="text" name="tag" class="form-control" placeholder="Tag" value="<?php 
						if(isset($_GET['edit'])) echo $getROW->getTag();  ?>" >
				</div>		
			</div>	

			<div class="form-group">
              	<label class="control-label col-sm-4" for="question_date">Date:</label>
              	<div class="col-sm-6"> 				
				<input type="date" name="question_date" class="form-control" placeholder="Date" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getQuestionDate(); ?>" >
				</div>
			</div>	


			<div class="form-group">
              	<label class="control-label col-sm-4" for="link">Question Link:</label>
              	<div class="col-sm-6"> 
              	<input type="text" name="link" class="form-control" placeholder="Question Link" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getLink(); ?>" >
				</div>
			</div>
	        <div class="form-group">        
              <div class="col-sm-4">					
					
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<button type="submit" name="update" >update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" name="save" >save</button>
							<?php
						}
						?>
				</div>	
	          	<div class="col-sm-8">       
					<button type="submit" name="search">Search Question</button>
				</div>				
			</div>			
							
		</form>

	</div>
	</div>

	<div class="panel-body">
	
	<table class="table table-bordered">
	<?php
	
	
	$Result = $_QuestionBAO->getAllQuestions();

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
			<th>Creator</th>

		</tr>
		<?php
		for($i = 0; $i < sizeof($QuestionList); $i++) {
			$Question = $QuestionList[$i];
			//echo $Question->getLink();
			?>
		    <tr>
			    
			    <td><a href="<?php echo $Question->getLink(); ?>" target="_blank"> <?php echo $_QuestionBAO->getTitleFromID( $Question->getTitle());?> </a></td>
			    <td><?php echo $_QuestionBAO->getCourseFromID($Question->getCourse());?></td>
			    <td><?php echo $_QuestionBAO->getTermFromID($Question->getTerm()); ?></td>
			    <td><?php echo $_QuestionBAO->getSessionFromID($Question->getSession()); ?></td>
			    <td><?php echo $_QuestionBAO->getTeacherFromID($Question->getTeacher()); ?></td>
			    <td><?php echo $Question->getType(); ?></td>
			    <td><?php echo $Question->getTag(); ?></td>
			    <td><?php echo $Question->getQuestionDate(); ?></td>
			    <td><?php echo $_QuestionBAO->getTeacherFromID($Question->getCreator()); ?></td>
			    <td><a href="?edit=<?php echo $Question->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Question->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

</div>



