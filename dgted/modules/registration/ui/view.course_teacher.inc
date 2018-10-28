<?php

include_once 'blade/view.course_teacher.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>
<div class="panel panel-default">
    
    <div class="panel-heading">Assign Course Teacher</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
			<div class="form-group">
              	<label class="control-label col-sm-4" for="courseid">Course Name:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_CourseBAO->getAllCourses();
							if ($Result->getIsSuccess())
								$CourseList = $Result->getResultObject();					
							?>
							<select name="courseid" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($CourseList); $i++){
									$Course = $CourseList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Course->getID();?>" > <?php echo $Course->getCourseNo(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getCourse()->getID() == $Course->getID() ){
											?>
											<option selected value = "<?php echo $Course->getID();?>" > <?php echo $Course->getCourseNo();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Course->getID();?>" > <?php echo $Course->getCourseNo(); ?> 
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
              	<label class="control-label col-sm-4" for="teacherid">Teacher Name:</label>
              	<div class="col-sm-6">	
							<?php
							$Result = $_UserBAO->getAllUsersOfRole('teacher');
							if ($Result->getIsSuccess())
								$UserList = $Result->getResultObject();					
							?>
							<select name="teacherid" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($UserList); $i++){
									$User = $UserList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $User->getID();?>" > 
										<?php echo $User->getFirstName().' '.$User->getLastName() ;?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getTeacher()->getID() == $User->getID() ){
											?>
											<option selected value = "<?php echo $User->getID();?>" > <?php echo $User->getFirstName().' '.$User->getLastName() ;?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $User->getID();?>" > 
											<?php echo $User->getFirstName().' '.$User->getLastName() ;?> 
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
              	<label class="control-label col-sm-4" for="session">Session:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_RegistrationSessionBAO->getAllRegistrationSessions();
							if ($Result->getIsSuccess())
								$SessionList = $Result->getResultObject();					
							?>
							<select name="session" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($SessionList); $i++){
									$Session = $SessionList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Session->getID();?>" > <?php echo $Session->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getSession()->getID() == $Session->getID() ){
											?>
											<option selected value = "<?php echo $Session->getID();?>" > <?php echo $Session->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Session->getID();?>" > <?php echo $Session->getName(); ?> 
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
              	<label class="control-label col-sm-4" for="yearid">Year:</label>
              	<div class="col-sm-6">	

				<?php
						$Result = $_YearBAO->getAllYears();
						if ($Result->getIsSuccess())
							$YearList = $Result->getResultObject();					
						?>
							<select name="yearid" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($YearList); $i++){
									$Year = $YearList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Year->getID();?>" > 
										<?php echo $Year->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){
										
										if ($getROW->getYear()->getID() == $Year->getID() ){
											?>
											<option selected value = "<?php echo $Year->getID();?>" > <?php echo $Year->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Year->getID();?>" > <?php echo $Year->getName(); ?> 
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
              	<label class="control-label col-sm-4" for="termid">Term:</label>
              	<div class="col-sm-6">	

				<?php
						$Result = $_TermBAO->getAllTerms();
						if ($Result->getIsSuccess())
							$TermList = $Result->getResultObject();					
						?>
							<select name="termid" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($TermList); $i++){
									$Term = $TermList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){
										
										if ($getROW->getTerm()->getID() == $Term->getID() ){
											?>
											<option selected value = "<?php echo $Term->getID();?>" > <?php echo $Term->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
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
              	<div class="col-sm-offset-2 col-sm-10">	

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
				</div>
			</div>	
	</form>
</div>
</div>

<div class="panel-body">
<table class="table table-bordered">
		<?php

		$Result = $_CourseTeacherBAO->getAllCourseTeachers();

	//if DAO access is successful to load all the Terms then show them one by one
		if($Result->getIsSuccess()){

			$CourseTeachers = $Result->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Teacher</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseTeachers); $i++) {
				$CourseTeacher = $CourseTeachers[$i];
				?>
				
				<tr>
					<td>
					<a href="course.php?edit=<?php echo $CourseTeacher->getCourse()->getID(); ?>">
					<?php echo $CourseTeacher->getCourse()->getCourseNo(); ?>						
					</a>
					</td>
					<td><?php echo $CourseTeacher->getTeacher()->getFullName(); ?></td>
					<td><?php echo $CourseTeacher->getSession()->getName(); ?></td>
					<td><?php echo $CourseTeacher->getYear()->getName(); ?></td>
					<td><?php echo $CourseTeacher->getTerm()->getName(); ?></td>

					<td><a href="?edit=<?php echo $CourseTeacher->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
					<td><a href="?del=<?php echo $CourseTeacher->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

