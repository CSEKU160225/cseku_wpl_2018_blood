<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.result.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.my_registration.blade.inc';

?>



<div class="panel  panel-default">
<div class="panel-heading"><strong>My Registrations</strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" name="form1" class="form-horizontal">

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
			
									if (isset($_POST['session'])){

										if ($_POST['session'] == $Session->getID() ){
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
									else {

											?>
											<option value="<?php echo $Session->getID();?>" > <?php echo $Session->getName(); ?> 
											</option>
											<?php
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

									if (isset($_POST['year'])){
										
										if ($_POST['year'] == $Year->getID() ){
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
									else {

										?>
										<option value="<?php echo $Year->getID();?>" > <?php echo $Year->getName(); ?> 
										</option>
										<?php
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

									if (isset($_POST['term'])){
										
										if ($_POST['term'] == $Term->getID() ){
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
									else {

											?>
											<option value="<?php echo $Term->getID();?>" > <?php echo $Term->getName(); ?> 
											</option>
											<?php
									}	
								
								}
								?>	
							</select>
				</div>
			</div>	

	        <div class="form-group">        
              	<div class="col-sm-12">	

						<button type="submit" name="my_registration">My Registrations</button>
	
				</div>
			</div> 
		 </form>	
	</div>

</div>

<div>
	<div><strong>Courses Registered</strong></div> 
	<table class="table table-bordered">

	<?php

 		if(isset($_SESSION['Result_Search_Course']))
		{
			$Result_Search_Course = $_SESSION['Result_Search_Course'];
			$CourseStudentRegistrations = $Result_Search_Course->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Title</th>
				<th>Credit</th>
				<th>Status</th>
				<th>Is Deleted?</th>
				<th>My Marks</th>
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
								?>/>
							</td>
							<td>
							|	
							<a href="?marks=true&session=<?php 
							echo $CourseStudentRegistration->getSession()->getID();?>&&year=<?php 
							echo $CourseStudentRegistration->getYear()->getID();?>&&term=<?php 
							echo $CourseStudentRegistration->getTerm()->getID();?>&&course=<?php 
							echo $CourseStudentRegistration->getCourse()->getID();?>">Final Marks</a>
							
							| 

							<a href="?tests=true&session=<?php 
							echo $CourseStudentRegistration->getSession()->getID();?>&&year=<?php 
							echo $CourseStudentRegistration->getYear()->getID();?>&&term=<?php 
							echo $CourseStudentRegistration->getTerm()->getID();?>&&course=<?php 
							echo $CourseStudentRegistration->getCourse()->getID();?>">Tests</a>
							|
							</td>
						</tr>
							<?php

						} ?>
		</table>

		<div> 

			<button type="submit" class="btn btn-info" onclick="window.open('print_registration.php?print=true&&session=<?php 
							if(isset($Print_Session)) echo $Print_Session->getID();?>&&year=<?php 
							if(isset($Print_Year))echo $Print_Year->getID();?>&&term=<?php 
							if(isset($Print_Term))echo $Print_Term->getID();?>')" 
			>
			Print Registration
			</button> 

		</div>	
	
		<?php				
		}
		else{

		echo 'No Courses to display!';
		
		}

	?>



	
</div>
</div>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Final Marks</strong></div>
<div class="panel-body">
	<?php

 		if(isset($_SESSION['Result_Student_Marks']) && isset($_GET['marks']))
		{
			$Result_Student_Marks = $_SESSION['Result_Student_Marks'];
			$MarksEntry = $Result_Student_Marks->getResultObject();

			$MarksValue = $MarksEntry->getMarksValue();
			$MarksHeader = $MarksEntry->getHeaderName();
			$MarksHeaderMax = $MarksEntry->getHeaderMax();
			$MarksTotal = $MarksEntry->getMarksTotal();
			$FinalGrade = $MarksEntry->getFinalGrade();

			$MarksList = explode(",",$MarksValue); //getting header ids
			$HeaderList = explode(",",$MarksHeader); //getting header ids
			$HeaderMaxList = explode(",",$MarksHeaderMax); //getting header maxs

			echo '<i>Course: <strong>'.$Course->getTitle().' ('.$Course->getCourseNo().')</strong><br/>';

			for ($i=0; $i < sizeof($HeaderList); $i++) { 
				$Marks=$MarksList[$i];
				$Header=$HeaderList[$i];
				$HeaderMax=$HeaderMaxList[$i];

				echo '<i>'.$Header.' ('.$HeaderMax.')</i>: <strong>'. $Marks.'</strong><br/>';
			}

			echo '<i>Total Marks</i>: <strong>'. $MarksTotal.'</strong><br/>'; 
			echo '<i>Final Grade</i>: <strong>'. $FinalGrade.'</strong><br/>'; 

		}
		else{
			echo '<strong><i>Marks not found!</i></strong>';
		}
	?>	
</div>
</div>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Test Marks</strong></div>
<div class="panel-body">
	<?php

 		if(isset($_SESSION['Result_Student_Tests']) && isset($_GET['tests']))
		{
			$Result_Student_Tests = $_SESSION['Result_Student_Tests'];
			$MarksEntry = $Result_Student_Tests->getResultObject();

			$MarksValue = $MarksEntry->getMarksValue();


			$MarksList = explode(",",$MarksValue); //getting marks value

			echo '<i>Course: <strong>'.$Course->getTitle().' ('.$Course->getCourseNo().')</strong><br/>';

			for ($i=0; $i < sizeof($MarksList); $i++) { 
				$Marks=$MarksList[$i];

				echo '<i>Test ('.($i+1).')</i>: <strong>'. $Marks.'</strong><br/>';
			}

		}
		else{
			echo '<strong><i>Marks not found!</i></strong>';
		}
	?>	
</div>
</div>

