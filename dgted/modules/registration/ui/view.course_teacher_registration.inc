<?php

include_once 'blade/view.course_teacher_registration.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Assign Registration Coordinator</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">

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
										<?php echo $User->getFirstName().' '.$User->getLastName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getTeacherID() == $User->getID() ){
											?>
											<option selected value = "<?php echo $User->getID();?>" > <?php echo $User->getFirstName().' '.$User->getLastName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $User->getID();?>" > 
											<?php $User->getFirstName().' '.$User->getLastName(); ?> 
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

										if ($getROW->getSessionID() == $Session->getID() ){
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
										
										if ($getROW->getYearID() == $Year->getID() ){
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
										
										if ($getROW->getTermID() == $Term->getID() ){
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


		$Result = $_CourseTeacherRegistrationBAO->getAllCourseTeacherRegistrations();

	//if DAO access is successful to load all the Terms then show them one by one
		if($Result->getIsSuccess()){

			$CourseTeacherRegistrations = $Result->getResultObject();
			?>
			<tr>
				<th>Teacher</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseTeacherRegistrations); $i++) {
				$CourseTeacherRegistration = $CourseTeacherRegistrations[$i];
				?>
				<tr>
					<td><?php echo $CourseTeacherRegistration->getTeacherID(); ?></td>
					<td><?php echo $CourseTeacherRegistration->getSessionID(); ?></td>
					<td><?php echo $CourseTeacherRegistration->getYearID(); ?></td>
					<td><?php echo $CourseTeacherRegistration->getTermID(); ?></td>

					<td><a href="?edit=<?php echo $CourseTeacherRegistration->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
					<td><a href="?del=<?php echo $CourseTeacherRegistration->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
