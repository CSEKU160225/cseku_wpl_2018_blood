<?php

include_once 'blade/view.my_courses.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>
<div class="panel panel-default">
    
    <div class="panel-heading">Courses Assigend To Me</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
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
          	<label class="control-label col-sm-4" for="txtCourseCode">Course Code:</label>
          		<div class="col-sm-6"> 
     
				<input type="text" name="txtCourseCode" class="form-control" 
				value="<?php
          			if(isset($_GET['edit'])){
          				echo $getROW->getCourse()->getCourseNo();	
          			}
          			?> " readonly/>
			 	</div>
			</div>				
			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtTestCount">No of Tests:</label>
          		<div class="col-sm-6"> 
     
				<input type="text" name="txtTestCount" class="form-control"  placeholder="2 or 3 or 4"

				value="<?php
          			//update the number of tests
          			if(isset($_GET['edit'])){
          				echo $getROW->getNoOfTests();	
          			}
          			?> "/>
			 	</div>
			</div>
			 <input type="hidden" name="txtRowID" value="<?php if(isset($_GET['edit'])) echo $_GET['edit']; ?>"
			  />
			  <input type="hidden" name="txtCourseID" value="<?php if(isset($_GET['edit'])) echo $getROW->getCourse()->getID();?>"
			  />
	        <div class="form-group">        
              	<div class="col-sm-6">	

						<button type="submit" name="find_courses">Find Courses</button>

				</div>		
						<?php
							if(isset($_GET['edit'])){
						?>
				<div class="col-sm-6">					
						<button type="submit" name="update">Update</button>
				</div>
						<?php
							}

						?>


				
			</div>	
	</form>
</div>
</div>

<div class="panel-body">
<table class="table table-bordered">
	<?php
	if(isset($Result_My_Courses))
	{
		$Result = $Result_My_Courses;

		if($Result->getIsSuccess()){

			$CourseTeachers = $Result->getResultObject();
			?>
			<tr>
				<th>Course No</th>
				<th>Title</th>
				<th>Credit</th>
				<th>Teacher</th>
				<th>Session</th>
				<th>Year</th>
				<th>Term</th>
				<th>No of Tests</th>

			</tr>
			<?php 
			for($i = 0; $i < sizeof($CourseTeachers); $i++) {
				$CourseTeacher = $CourseTeachers[$i];
				?>
			<tr>
					<td>
					<a href="course.php?view=<?php echo $CourseTeacher->getCourse()->getID(); ?>">
					<?php echo $CourseTeacher->getCourse()->getCourseNo(); ?>						
					</a>
					</td>
					<td><?php echo $CourseTeacher->getCourse()->getTitle();?></td>
					<td><?php echo $CourseTeacher->getCourse()->getCredit(); ?></td>
					<td><?php echo $CourseTeacher->getTeacher()->getFullName(); ?></td>
					<td><?php echo $CourseTeacher->getSession()->getName(); ?></td>
					<td><?php echo $CourseTeacher->getYear()->getName(); ?></td>
					<td><?php echo $CourseTeacher->getTerm()->getName(); ?></td>
					<td><?php echo $CourseTeacher->getNoOfTests(); ?></td>
					<td>
					<a href="?edit=<?php echo $CourseTeacher->getID();?>"
					onclick="return confirm('Do you want to edit?'); ">edit
					</a>					
					</td>
					<td>
					<a href="tests_entry.php?update=true&course=<?php echo $CourseTeacher->getCourse()->getCourseNo();?>
						&teacher=<?php echo $CourseTeacher->getTeacher()->getID();?>
						&session=<?php echo $CourseTeacher->getSession()->getID();?>
						&year=<?php echo $CourseTeacher->getYear()->getID();?>
						&term=<?php echo $CourseTeacher->getTerm()->getID();?>"
					onclick="return ; ">assessments
					</a>					
					</td>
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

