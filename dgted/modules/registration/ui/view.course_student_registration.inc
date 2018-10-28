<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.course_student_registration.blade.inc';

//course status evolve: pending, submitted, approved/rejected, registered, passed/failed

?>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Searching Available Courses</strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseNo">Course No:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseNo" class="form-control"  placeholder="cse-33% or cse-3310"/>
			 	</div>
			</div>
	        <div class="form-group">        
              	<div class="col-sm-offset-2 col-sm-10">	

						<button type="submit" name="search">Search Course</button>

				</div>
			</div>              		
		</form>	
	</div>

	<div>
	<div><strong>Searched Courses</strong></div> 
	<table class="table table-bordered">

		<?php

	//courses available according to the selection
		if(isset($_SESSION['Result_Search_Course']))
		{
			$Result_Search_Course = $_SESSION['Result_Search_Course'];

					$Courses = $Result_Search_Course->getResultObject();
					?>
					<tr>
						<th>Course No</th>
						<th>Title</th>
						<th>Credit</th>
						<th>Course Type</th>
						<th>Discipline</th>
						<th>Is Deleted?</th>
					</tr>
					<?php 
					for($i = 0; $i < sizeof($Courses); $i++) {
						$Course = $Courses[$i];
		//echo '<br>'. $Course->getCourseNo().$Course->getISdeleted();
						?>
						<tr>
							<td><?php echo $Course->getCourseNo(); ?></td>
							<td><?php echo $Course->getTitle(); ?></td>
							<td><?php echo $Course->getCredit(); ?></td>
							<td><?php echo $Course->getCourseTypeID(); ?></td>
							<td><?php echo $Course->getDisciplineID(); ?></td>
							<?php

							if($Course->getISdeleted() == 1)
								$deletertik = "checked";
							else 
								$deletertik = "";
							?>
							<td><input type="checkbox" name="name1" onclick="return false;" 
								<?php 
								if($Course->getISdeleted() == 1)
								{
									?>
									checked = "checked"
									<?php
								}
								?>/></td>

								<td><a href="?add=<?php echo $Course->getID(); ?>" onclick="return confirm('sure to add to the cart !'); " >Add to Cart</a></td>
							</tr>
							<?php

						}

		}
		else{

			echo 'No Courses Found!';
		}

	?>
	</table>
	</div>
	<div>
		<?php 
				if(isset($Result_Course_Cart)){
					
					echo $Result_Course_Cart->getResultObject();

				}

			?>
	</div>
</div>
</div>

<div class="panel panel-default">
    
    <div class="panel-heading"><strong>Failed Courses (You should register these courses first)</strong></div>    
    <div class="panel-body">

		<table class="table table-bordered">

				<?php

		 	$CourseStudentRegistration = new CourseStudentRegistration();
		    
		    $Student = new User();

		    if(isset($_GET['mode'])&&strcasecmp($_GET['mode'], 'admin')==0&&isset($_GET['id']))
		    	$Student->setID($_GET['id']);
		    else
		    	$Student->setID($globalUser->getID());


		    $CourseStudentRegistration->setStudent($Student);

		 	$CourseStudentRegistration->setStatus('failed');
		 
		   //reading all the added courses in the database cart
		    $Result_Student_Cart = $_CourseStudentRegistrationBAO
		                                ->searchRegistrationCart($CourseStudentRegistration);  

				//courses that are added to the cart
				if(isset($Result_Student_Cart)&&$Result_Student_Cart->getIsSuccess())
				{
					$CourseStudentRegistrations = $Result_Student_Cart->getResultObject();
					?>
					<tr>
						<th>Course No</th>
						<th>Course Title</th>
						<th>Course Credit</th>
						<th>Registration Coordinator</th>
						<th>Session</th>
						<th>Year</th>
						<th>Term</th>
						<th>Status</th>
					</tr>
					<?php 
					for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
						$CourseStudentRegistration = $CourseStudentRegistrations[$i];
						?>
						<tr>
							<td><?php echo $CourseStudentRegistration->getCourse()->getCourseNo(); ?></td>
							<td><?php echo $CourseStudentRegistration->getCourse()->getTitle(); ?></td>
							<td><?php echo $CourseStudentRegistration->getCourse()->getCredit(); ?></td>
							<td><?php echo $CourseStudentRegistration->getTeacher()->getFullName(); ?></td>
							<td><?php echo $CourseStudentRegistration->getSession()->getName(); ?></td>
							<td><?php echo $CourseStudentRegistration->getYear()->getName(); ?></td>
							<td><?php echo $CourseStudentRegistration->getTerm()->getName(); ?></td>
							<td><?php echo $CourseStudentRegistration->getStatus(); ?></td>

							<td>
							<a href="?add=<?php echo $CourseStudentRegistration->getCourse()->getID(); ?>" onclick="return confirm('sure to add to the cart !'); " >Add to Cart
							</a>
							</td>

						</tr>
						<?php

					}

				}
				else{

				echo 'No courses to display!';
			}

			?>
		</table>


    </div>
</div>    	

<div class="panel panel-default">
    
    <div class="panel-heading"><strong>Course Registration Process</strong></div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
			<div class="form-group">
              	<label class="control-label col-sm-4" for="coordinator">Registration Coordinator:</label>
              	<div class="col-sm-6">	
							<?php
							$Result = $_UserBAO->getAllUsersOfRole('teacher'); 
							if ($Result->getIsSuccess())
								$UserList = $Result->getResultObject();					
							?>
							<select name="coordinator" class="form-control" style="width:170px">
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

										if ($getROW->getTeacherID() == $User->getID() ){
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
              	<div class="col-sm-6">	

						<button type="submit" name="approval_request">Get Approved!</button>

				</div>

	          	<div class="col-sm-6">	

						<button type="submit" name="confirm_registration">Registration!</button>

				</div>

			</div>
	</form>
	
	<div>
		<?php 
				if(isset($Result_Confirm_Reg)){
					
					echo $Result_Confirm_Reg->getResultObject();

				}

			?>
	</div>

</div>
</div>

<div>
<div><strong>Registration Cart</strong></div> 
<table class="table table-bordered">

		<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
    $Student = new User();

    if(isset($_GET['mode'])&&strcasecmp($_GET['mode'], 'admin')==0&&isset($_GET['id']))
    	$Student->setID($_GET['id']);
    else
    	$Student->setID($globalUser->getID());


    $CourseStudentRegistration->setStudent($Student);

 	$CourseStudentRegistration->setStatus('pending');
 
   //reading all the added courses in the database cart
    $Result_Student_Cart = $_CourseStudentRegistrationBAO
                                ->searchRegistrationCart($CourseStudentRegistration);  

		//courses that are added to the cart
		if(isset($Result_Student_Cart)&&$Result_Student_Cart->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student_Cart->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Course Title</th>
				<th>Course Credit</th>
				<th>Registration Coordinator</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
				<th>Status</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCourseNo(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getTitle(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCredit(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTeacher()->getFullName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getSession()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getYear()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTerm()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getStatus(); ?></td>

					<td>
					<a href="?remove=true&id=<?php echo $CourseStudentRegistration->getID();?>"
					onclick="return confirm('sure to remove from cart!'); ">Remove from Cart
					</a>
					</td>

				</tr>
				<?php

			}

		}
		else{

		echo 'No courses to display!';
	}

	?>
</table>
</div>

<div>
<div><strong>Registration Request In Process</strong></div> 
<table class="table table-bordered">

		<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
    $Student = new User();

    if(isset($_GET['mode'])&&strcasecmp($_GET['mode'], 'admin')==0&&isset($_GET['id']))
    	$Student->setID($_GET['id']);
    else
    	$Student->setID($globalUser->getID());

    $CourseStudentRegistration->setStudent($Student);

 	$CourseStudentRegistration->setStatus('submitted,approved,rejected');
 
   //reading all the added courses in the database cart
    $Result_Student_Cart = $_CourseStudentRegistrationBAO
                                ->searchRegistrationCart($CourseStudentRegistration);  

		//courses that are added to the cart
		if(isset($Result_Student_Cart)&&$Result_Student_Cart->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student_Cart->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Course Title</th>
				<th>Course Credit</th>
				<th>Registration Coordinator</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
				<th>Status</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCourseNo(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getTitle(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCredit(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTeacher()->getFullName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getSession()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getYear()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTerm()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getStatus(); ?></td>

					<td>
					<a href="?remove=true&id=<?php echo $CourseStudentRegistration->getID();?>"
					onclick="return confirm('sure to remove from registration!'); ">Remove registration
					</a>					
					</td>

					<?php
   					if(isset($_GET['mode'])&&
   						strcasecmp($_GET['mode'], 'admin')==0&&
   						isset($_GET['id']))
					{
					?> 
					<td>
					<a href="?approve=true&id=<?php echo $CourseStudentRegistration->getID();?>"
					onclick="return confirm('sure to approve!'); ">Approve
					</a>					
					</td>


					<td>
					<a href="?reject=true&id=<?php echo $CourseStudentRegistration->getID();?>"
					onclick="return confirm('sure to reject!'); ">Reject
					</a>					
					</td>
					<?php
					}
					?>				

				</tr>
				<?php

			}

		}
		else{

		echo 'No courses to display!';
	}

	?>


</table>

</div>

<div>
<div><strong>Registration Completed</strong></div> 
<table class="table table-bordered">

		<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
    $Student = new User();

    if(isset($_GET['mode'])&&strcasecmp($_GET['mode'], 'admin')==0&&isset($_GET['id']))
    	$Student->setID($_GET['id']);
    else
    	$Student->setID($globalUser->getID());

    $CourseStudentRegistration->setStudent($Student);

 	$CourseStudentRegistration->setStatus('registered');
 
   //reading all the added courses in the database cart
    $Result_Student_Cart = $_CourseStudentRegistrationBAO
                                ->searchRegistrationCart($CourseStudentRegistration);  

		//courses that are added to the cart
		if(isset($Result_Student_Cart)&&$Result_Student_Cart->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student_Cart->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Course Title</th>
				<th>Course Credit</th>
				<th>Registration Coordinator</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
				<th>Status</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCourseNo(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getTitle(); ?></td>
					<td><?php echo $CourseStudentRegistration->getCourse()->getCredit(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTeacher()->getFullName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getSession()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getYear()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getTerm()->getName(); ?></td>
					<td><?php echo $CourseStudentRegistration->getStatus(); ?></td>

					<td>
					<a href="?remove=true&id=<?php echo $CourseStudentRegistration->getID();?>"
					onclick="return confirm('sure to remove from registration!'); ">Remove registration
					</a>					
					</td>
	

				</tr>
				<?php

			}

		}
		else{

		echo 'No courses to display!';
	}

	?>
</table>
</div>



</div>
