<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.marks_entry.blade.inc';

//course status evolve: pending, submitted, approved/rejected, registered, passed/failed

?>

<div class="panel  panel-default">
<div class="panel-heading"><strong>Coursewise Marks Update</strong></div>
<div class="panel-body">
	<div id="form">
		<form method="post" name="form1" class="form-horizontal">

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtCourseNo">Course No:</label>
          		<div class="col-sm-6">       
				<input type="text" name="txtCourseNo" class="form-control"  placeholder="cse-3310"
				value="<?php if(isset($_POST['txtCourseNo'])) echo $_POST['txtCourseNo']; ?>"/>
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
              	<div class="col-sm-6">	

						<button type="submit" name="load_marks">Load Marks</button>
	
				</div>
              	<div class=" col-sm-6">	

						<button type="submit" name="save_marks">Save Marks</button>
	
				</div>
			</div>
			<div class="form-group">
              	<div class=" col-sm-6">	

						<button type="submit" name="notify_marks">Notify Marks</button>
	
				</div>
              	<div class=" col-sm-6">	

						<button type="submit" name="delete_marks" onclick="return confirm('Sure to delete! All the marks from the database for this registration will be deleted?'); ">Delete Marks</button>
	
				</div>

			</div>              		
			<div class="form-group">
              	<div class="col-sm-12">	

						<button type="submit" name="publish_marks">Publish Marks</button>
	
				</div>

			</div> 
		 <!--/form-->	
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

	//returning the marks value from the marks entry
	function findMarks($MarksEntry, $FindHeaderID){

		if(isset($MarksEntry)){
			$MarksValueList = explode(",",$MarksEntry->getMarksValue());
			$HeaderIDList = explode(",",$MarksEntry->getHeaderID());

			for ($i=0; $i < sizeof($HeaderIDList) ; $i++) { 
				
				$HeaderID = $HeaderIDList[$i];
				$MarksValue = $MarksValueList[$i];

				if($HeaderID==$FindHeaderID){
					return $MarksValue;
				}
			}
		}
		else
			return "X";	
	}

	function findGrade($TotalMarks, $GradeRangesList, $GradeList){
				
	$GradePos = searchGrade($GradeRangesList,$TotalMarks );
		
			if($GradePos>=0)
				return $GradeList[$GradePos]; //grade position
	
		return "X";
	}

	function searchGrade($GradeRangesList,$TotalMarks ){
		$j=0;
		foreach ($GradeRangesList as $Range) { //extracting the list
			if(strpos($Range, '-')!==false){ //if - is present
				$X = explode("-", $Range);	
				if(count($X)===2){//both from and to are found
					if($TotalMarks>=$X[0] && $TotalMarks<= $X[1]) //searching the grade position
						return $j;
				}
			}
			$j++;
		}

		return -1;			
	}

	function sumMarks($MarksEntry){
		if(isset($MarksEntry)){
			
			$MarksValueList = explode(",",$MarksEntry->getMarksValue());
			$MarksValueList = array_map('intval',$MarksValueList); //converting string arrya to num array
			$TotalMarks=array_sum($MarksValueList); //adding all the numbers

			return $TotalMarks;
		}	

	}

	if(isset($Result_Course_Students) && isset($Result_Marks_Setup)&&isset($Result_Grade_Setup))
	{
		$StudentIDList=null;
		$CourseStudentRegistrations = $Result_Course_Students->getResultObject();

		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentIDList[] = $CourseStudentRegistration->getStudent()->getUniversityID();
		}	

		$MarksSetup = $Result_Marks_Setup->getResultObject(); //marks setup
		$MarksEntryList= $Result_Course_Student_Marks->getResultObject(); //all student registered
		$GradeSetup = $Result_Grade_Setup->getResultObject(); //grade distribution setup

		$MarksHeaderID= $MarksSetup->getHeaderID(); //getting header id
		$MarksHeaderName= $MarksSetup->getHeaderName(); //header name
		$MarksHeaderMax= $MarksSetup->getHeaderMax(); //maximum heade value

		$Grades = $GradeSetup->getGrades();
		$GradeRanges= $GradeSetup->getRanges();

		
		$HeaderIDList = explode(",",$MarksHeaderID); //getting header ids
		$HeaderList = explode(",",$MarksHeaderName); //getting header names
		$HeaderMaxList = explode(",",$MarksHeaderMax); //getting header maxs

		$GradeList = explode(",",$Grades); //getting grades
		$GradeRangesList=explode(",",$GradeRanges); //getting grade ranges


		?>
		
		<input type="hidden" name="all_header_id" value="<?php echo $MarksHeaderID; ?>" />
		<input type="hidden" name="all_header_name" value="<?php echo $MarksHeaderName; ?>" />
		<input type="hidden" name="all_header_max" value="<?php echo $MarksHeaderMax; ?>" />
		<input type="hidden" name="all_grades" value="<?php echo $Grades; ?>" />
		<input type="hidden" name="all_grade_ranges" value="<?php echo $GradeRanges; ?>" />
		

		<input type="hidden" name="marks_id" value="<?php echo $MarksSetup->getID(); ?>" />

		<input type="hidden" name="all_students" value="<?php echo implode(",", $StudentIDList); ?>" />
		<tr>

			<th>University ID</th>
			<th>Name</th>
		
		<?php	for ($i=0; $i < sizeof($HeaderList) ; $i++) { 
				$Header = $HeaderList[$i];
				$HeaderMax = $HeaderMaxList[$i];
				echo '<th>'.$Header.' ('.$HeaderMax.')</th>';
			}
		?>	
			<th>Total</th>
			<th>Grade</th>
		</tr>
		<?php 
		for($i = 0; $i < sizeof($CourseStudentRegistrations); $i++) {
			$CourseStudentRegistration = $CourseStudentRegistrations[$i];
			$StudentID = $CourseStudentRegistration->getStudent()->getUniversityID();
			$StudentEmail = $CourseStudentRegistration->getStudent()->getID();
			$MarksEntry = findMarksEntry($MarksEntryList,$StudentID);//marks entry, marks value
			$TotalMarks = sumMarks($MarksEntry); // sum of all the marks

			?>
			<tr>

				<td>
				<input type="text" name="<?php echo $StudentID.'[\'0\']'; ?>" 
						value="<?php echo $StudentID; ?>" size="8" readonly/>
				</td>
				<td><?php echo $CourseStudentRegistration->getStudent()->getFullName()
				.' ('.$StudentEmail.')'; ?> 
				</td>

				<?php	for ($j=0; $j < sizeof($HeaderList) ; $j++) {
						$HeaderID= $HeaderIDList[$j]; 
						echo '<td><input type="text" name="'.$StudentID.'[\''.($j+1).'\']" 
							  value="'.findMarks($MarksEntry, $HeaderID).'" size="3"	/></td>';
					}
				?>

				<td><input type="text" name="<?php echo $StudentID.'[\''.(sizeof($HeaderList)+1).'\']'; ?>" 
						value="<?php echo $TotalMarks; ?>" size="3" readonly/>
				</td>
				<td><input type="text" name="<?php echo $StudentID.'[\''.(sizeof($HeaderList)+2).'\']'; ?>" 
						value="<?php echo findGrade($TotalMarks, $GradeRangesList, $GradeList); ?>" 
						size="3"
						readonly/>
				</td>		

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
