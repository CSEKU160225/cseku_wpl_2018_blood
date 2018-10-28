<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.tests_entry.blade.inc';


?>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Coursewise Marks Update</strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" name="form1" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseNo">Course No:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseNo" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Course)) echo $Course->getCourseNo(); ?>" readonly/>
				<input type="hidden" name="hiddenCourseNo" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Course)) echo $Course->getCourseNo(); ?>" readonly/>				
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseTitle">Course Title:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseTitle" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Course)) echo $Course->getTitle(); ?>" readonly/>
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtSession">Session:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtSession" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Session)) echo $Session->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenSession" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Session)) echo $Session->getID(); ?>" readonly/>				
			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtYear">Year:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtYear" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Year)) echo $Year->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenYear" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Year)) echo $Year->getID(); ?>" readonly/>

			 	</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtTerm">Term:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtTerm" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Term)) echo $Term->getName(); ?>" readonly/>
				<input type="hidden" name="hiddenTerm" class="form-control" 
				value="<?php if(isset($_GET['update'])&&isset($Term)) echo $Term->getID(); ?>" readonly/>

			 	</div>
			</div>				

	        <div class="form-group">        
              	<div class="col-sm-4">	
						<button type="submit" name="save_marks">Save</button>
	
				</div>
              	<div class="col-sm-4">	

						<button type="submit" name="notify_marks">Notify</button>
	
				</div>
              	<div class="col-sm-4">	

						<button type="submit" name="delete_marks" onclick="return confirm('Sure to delete! All the test marks from the database for this registration will be deleted?'); ">Delete</button>
	
				</div>
             		
			</div> 
	
	</div>

</div>

<div>
<div><strong>Currently Registered Students</strong></div> 
<table class="table table-bordered">
<div>
		<!--form method="post" name="form2" class="form-horizontal"-->
<?php
	//searching the marks entry in the result list that match student id
	function findMarksEntry($MarksEntryList,$StudentID){

		for ($i=0; $i < sizeof($MarksEntryList) ; $i++) { 
			
			$MarksEntry = $MarksEntryList[$i];
			if($MarksEntry->getStudent()==$StudentID)
				return $MarksEntry;
		}

		return null;
	}

	

	if(isset($Result_Course_Students) && isset($Result_Course_Teacher)&&isset($Result_Course_Student_Tests))
	{
		$StudentIDList=null;
		$CourseStudentRegistrations = $Result_Course_Students->getResultObject();

		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentIDList[] = $CourseStudentRegistration->getStudent()->getUniversityID();
		}	

	    $MarksEntryList= $Result_Course_Student_Tests->getResultObject(); //all student registered

		$NoOfTests = $Result_Course_Teacher->getNoOfTests();

		?>
				
		<input type="hidden" name="hidden_all_students" value="<?php echo implode(",", $StudentIDList); ?>" />
		<input type="hidden" name="hidden_no_of_tests" value="<?php echo $NoOfTests; ?>" />
		<tr>

			<th>University ID</th>
			<th>Name</th>
		
		<?php	for ($i=1; $i <= $NoOfTests ; $i++) { 
				echo '<th>Test ('.$i.')</th>';
			}
		?>	

		</tr>
		<?php 
		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentID = $CourseStudentRegistration->getStudent()->getUniversityID();
			$StudentEmail = $CourseStudentRegistration->getStudent()->getID();

			$MarksEntry = findMarksEntry($MarksEntryList,$StudentID);//marks entry, marks value
			

			?>
			<tr>

				<td>
				<input type="text" name="<?php echo $StudentID.'[\'0\']'; ?>" 
						value="<?php echo $StudentID; ?>" size="8" readonly/>
				</td>
				<td><?php echo $CourseStudentRegistration->getStudent()->getFullName()
				.' ('.$StudentEmail.')'; ?> 
				</td>
				
				<?php	
					$MarksValueList = null;
					if(isset($MarksEntry))
						$MarksValueList = explode(",",$MarksEntry->getMarksValue());

					for ($j=0; $j < $NoOfTests ; $j++) {
						if(isset($MarksValueList)&&isset($MarksValueList[$j])){
							echo '<td><input type="text" name="'.$StudentID.'[\''.($j+1).'\']" 
								  value="'.$MarksValueList[$j].'" size="3"	/></td>';
						}
						else{
							echo '<td><input type="text" name="'.$StudentID.'[\''.($j+1).'\']" 
								  value="X" size="3"	/></td>';

						}		  
					}
				?>	

			</tr>
			<?php

		}

	}
	else{

	echo 'No students to display!';
	}

?>
</form>
</table>
</div>

</div>
