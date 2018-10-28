<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.manage_registration_request.blade.inc';

?>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Manage Registration Request</strong></div>
<div class="panel-body"><strong>Submitted Registrations</strong>
<table class="table table-bordered">

	<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
     //reading all the students that submitted registration request
    $Result_Student = $_CourseStudentRegistrationBAO
                                ->searchRegistrationRequest($globalUser,'submitted');  

		//courses that are added to the cart
		if(isset($Result_Student)&&$Result_Student->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student->getResultObject();
			?>
			<tr>
				<th>University ID</th>
				<th>Full Name</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td>
					<?php echo $CourseStudentRegistration->getStudent()->getUniversityID(); ?>				
					</td>
					<td><?php echo $CourseStudentRegistration->getStudent()->getFullName(); ?></td>

					<td>
					<a href="course_student_registration.php?id=
					<?php echo $CourseStudentRegistration->getStudent()->getID();?>&mode=admin">Admin</a>
					</td>

				</tr>
				<?php

			}

		}
		else{

		echo 'No students to display!';
	}

	?>
</table>
</div>

<div class="panel-body"><strong>Approved Registrations</strong>
<table class="table table-bordered">

	<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
     //reading all the students that submitted registration request
    $Result_Student = $_CourseStudentRegistrationBAO
                                ->searchRegistrationRequest($globalUser,'approved');  

		//courses that are added to the cart
		if(isset($Result_Student)&&$Result_Student->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student->getResultObject();
			?>
			<tr>
				<th>University ID</th>
				<th>Full Name</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td>
					<?php echo $CourseStudentRegistration->getStudent()->getUniversityID(); ?>				
					</td>
					<td><?php echo $CourseStudentRegistration->getStudent()->getFullName(); ?></td>

					<td>
					<a href="course_student_registration.php?id=
					<?php echo $CourseStudentRegistration->getStudent()->getID();?>&mode=admin">Admin</a>
					</td>

				</tr>
				<?php

			}

		}
		else{

		echo 'No students to display!';
	}

	?>
</table>
</div>

<div class="panel-body"><strong>Rejected Registrations</strong>
<table class="table table-bordered">

	<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
     //reading all the students that submitted registration request
    $Result_Student = $_CourseStudentRegistrationBAO
                                ->searchRegistrationRequest($globalUser,'rejected');  

		//courses that are added to the cart
		if(isset($Result_Student)&&$Result_Student->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student->getResultObject();
			?>
			<tr>
				<th>University ID</th>
				<th>Full Name</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td>
					<?php echo $CourseStudentRegistration->getStudent()->getUniversityID(); ?>				
					</td>
					<td><?php echo $CourseStudentRegistration->getStudent()->getFullName(); ?></td>

					<td>
					<a href="course_student_registration.php?id=
					<?php echo $CourseStudentRegistration->getStudent()->getID();?>&mode=admin">Admin</a>
					</td>

				</tr>
				<?php

			}

		}
		else{

		echo 'No students to display!';
	}

	?>
</table>
</div>

<div class="panel-body"><strong>Completed Registrations</strong>
<table class="table table-bordered">

	<?php

 	$CourseStudentRegistration = new CourseStudentRegistration();
    
     //reading all the students that submitted registration request
    $Result_Student = $_CourseStudentRegistrationBAO
                                ->searchRegistrationRequest($globalUser,'registered');  

		//courses that are added to the cart
		if(isset($Result_Student)&&$Result_Student->getIsSuccess())
		{
			$CourseStudentRegistrations = $Result_Student->getResultObject();
			?>
			<tr>
				<th>University ID</th>
				<th>Full Name</th>
			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
				$CourseStudentRegistration = $CourseStudentRegistrations[$i];
				?>
				<tr>
					<td>
					<?php echo $CourseStudentRegistration->getStudent()->getUniversityID(); ?>				
					</td>
					<td><?php echo $CourseStudentRegistration->getStudent()->getFullName(); ?></td>

					<td>
					<a href="course_student_registration.php?id=
					<?php echo $CourseStudentRegistration->getStudent()->getID();?>&mode=admin">Admin</a>
					</td>

				</tr>
				<?php

			}

		}
		else{

		echo 'No students to display!';
	}

	?>
</table>
</div>


</div>
