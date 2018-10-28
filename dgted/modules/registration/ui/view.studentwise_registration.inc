<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.studentwise_registration.blade.inc';

?>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Studentwise Registration</strong></div>
<div class="panel-body col-sm-12">
	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtStudentID">Student ID:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtStudentID" class="form-control"  placeholder="Example: 140201"/>
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
              	<label class="control-label col-sm-4" for="year">Year:</label>
              	<div class="col-sm-6">	

				<?php
						$Result = $_YearBAO->getAllYears();
						if ($Result->getIsSuccess())
							$YearList = $Result->getResultObject();					
						?>
							<select name="year" class="form-control" style="width:170px">
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
              	<label class="control-label col-sm-4" for="term">Term:</label>
              	<div class="col-sm-6">
				<?php
						$Result = $_TermBAO->getAllTerms();
						if ($Result->getIsSuccess())
							$TermList = $Result->getResultObject();					
						?>

							<select name="term" class="form-control" style="width:170px">
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
						<button type="submit" name="search">Search Registration</button>
				</div>
			</div>              		
		</form>	
	</div>

	<div>
	<div><strong>Courses Registered</strong></div> 
	<table class="table table-bordered">

	<?php

 		if(isset($_SESSION['Result_Search_Studentwise']))
		{
			$Result_Search_Course = $_SESSION['Result_Search_Studentwise'];
			$CourseStudentRegistrations = $Result_Search_Course->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Title</th>
				<th>Credit</th>
				<th>Status</th>
				<th>Is Deleted?</th>
			</tr>

					<?php 
					for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
						$CourseStudentRegistration = $CourseStudentRegistrations[$i];
		
						?>
						<tr>
							<td><?php echo $CourseStudentRegistration->getCourse()->getCourseNo(); ?></td>
							<td><?php echo $CourseStudentRegistration->getCourse()->getTitle(); ?></td>
							<td><?php echo $CourseStudentRegistration->getCourse()->getCredit(); ?></td>
							<td><?php echo $CourseStudentRegistration->getStatus(); ?></td>
							<td><input type="checkbox" name="name1" onclick="return false;" 
								<?php 
								if($CourseStudentRegistration->getCourse()->getISdeleted() == 1)
								{
									?>
									checked = "checked"
									<?php
								}
								?>/></td>
						</tr>
							<?php

						}

		}
		else{

		echo 'No Courses to display!';
		}

	?>

	</table>
	</div>
</div>
</div>


