<?php
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.result.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.inc';
include_once 'blade/view.print_registration.blade.inc';

?>

<style>
table.courses {
    border-collapse: collapse;
    border: 1px solid black;
}

.courses td, th {
    border: 1px solid black;
}

table.years {
    border-collapse: collapse;
    border: 1px solid black;
}

.years td, th {
    border: 1px solid black;
}

table, td, th{
	border-collapse: collapse;
	border: 0px solid black;
}


</style>

 <table align="center" width="100%">
      	
      	<tr>
      		<td>
      			
      			<table align="center">
      				<tr>
      					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
      					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      					</td>
      					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
      						<img src="resources/img/registration/ku_logo.jpg" height="80" width="60">
      					</td>
      					<td style="border-bottom: 1px solid black; line-height: 1.8em;"> 
      						<table style="text-align:center">
      							<tr>
      								<td >
      									<h3><strong>KHULNA UNIVERSITY</strong></h3>
      								</td>
      							</tr>
      							<tr>
      								<td >
      									<h4>COURSE REGISTRATION FORM</h4>
      									
      								</td>
      							</tr>
      							<tr>
      								<td >
      								</td>
      							</tr>

      						</table>
      					</td>
      					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
      					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      					</td>
      				</tr>
      				<tr>
      					<td colspan="2"><br></td>
       				</tr>
      			</table>

      		</td>
      	</tr>
      	<tr>
			<td>
	        	<table width="100%">
	        		<tr>
	        			<td style="border-bottom: 1px solid black; line-height: 1.8em;"><strong>Name of student:</strong></td>
	        			<td><h4>
	        				<i>
	        				
	        				<?php if(isset($Print_Student)) echo strtoupper($Print_Student->getLastName()); ?>
	        				</i>
	        				</h4>
	        				 
	        				
	        			</td>
	        			<td>
	        				<h4>
	        				<i>
	        				
	        				<?php if(isset($Print_Student)) echo strtoupper($Print_Student->getFirstName()); ?>
	        				</i>
	        				</h4>
	        				
	        				
	        			</td>
	        			<td>
	        				<h4>
	        				<i>
	        				
	        				<?php 

	        				if(isset($Print_Student)) 
	        					echo strtoupper($Print_Student->getMiddleName()); 

	        				?>
	        				</i>
	        				</h4>
	        				
	        				
	        			</td>
	        		</tr>
	        		<tr>
	        			<td>&nbsp;</td>
	        			<td style="border-top: 1px solid black; line-height: 1.8em;">
	        				<strong>Last name</strong>
	        			</td>
	        			<td style="border-top: 1px solid black; line-height: 1.8em;">
	        				<strong>First name</strong>
	        			</td>
	        			<td style="border-top: 1px solid black; line-height: 1.8em;">
	        				<strong>Middle name</strong>
	        			</td>
	        		</tr>
	        	</table>	        
	    	</td>
	    </tr>	


	    <tr>
	    	<td>
	    		<table width="100%">
	    			<tr>
	    				<td style="border-bottom: 1px solid black; line-height: 1.8em;">
	    					<strong>Student No:</strong>
	    				</td>
	    				<td style="border-bottom: 1px solid black; line-height: 1.8em;"><h4>
	        				<?php 

	        				if(isset($Print_Student)){ 

	        					$student_id = implode('/',str_split(strtoupper($Print_Student->getUniversityID())));
	        					$student_id = implode(array($student_id, '/'));	
	        					$student_id = implode(array('/',$student_id));	
	        					echo  $student_id;
	        					}	

	        				?>
	        				
	        				</h4>
						</td>
						<td style="border-bottom: 1px solid black; line-height: 1.8em;">
							&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						</td>
	    			</tr>
	    			<tr>
	    				<td><br></td>
	    			</tr>	    			
	    		</table>
	    	</td>    	
	    </tr>
	    <tr>
	    	<td>
	    		<table width="100%">
	    			<tr>
				    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
				    		<strong>Discipline:</strong>
				    	</td>
				    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
				    	<h4>

				    		<?php 

	        				if(isset($Print_Student)){ 

	        						echo $Print_Student->getDiscipline()->getName();
	        					
	        					}	

	        				?>

	        			</h4>

				    	</td>
				    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
				    		<strong>School:</strong>
				    	</td>	    				
				    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
				    	<h4>	
				    	<?php 

	        				if(isset($Print_Student)){ 

	        						echo $Print_Student->getDiscipline()->getSchool()->getName();
	        					
	        					}	

	        				?>
	        			</h4>	

				    	</td>
	    			</tr>
	    			<tr>
	    				<td><br></td>
	    			</tr>

	    		</table>
	    	</td>
	    </tr>
	    <tr>
	    	<td></td>
	    </tr>
	    <tr> 
	    	<td>	
	    		<table width="100%">
	    			<tr>
		        	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
			        <strong>Term:</strong>
			       	</td>
			       	<td style="border-bottom: 1px solid black; line-height: 1.8em;"> 		

			        		<h4>
			        		<?php if(isset($Print_Term)) echo strtoupper($Print_Term->getName()); ?>
			        		</h4>
			        
			    	</td>

		    		<td style="border-bottom: 1px solid black; line-height: 1.8em;">
			        <strong>Year:</strong>
			    	</td>
			    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">

			        		<h4>
			        		<?php if(isset($Print_Year)) echo strtoupper($Print_Year->getName()); ?>
			        		</h4>
			        
		        	</td>


			    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
			        <strong>Session:</strong>
			    	</td>
			    	<td style="border-bottom: 1px solid black; line-height: 1.8em;">
			        		<h4>
			        	
			        		<?php if(isset($Print_Session)) echo strtoupper($Print_Session->getName()); ?>

			        		</h4>
			        	
			        
			    	</td>
			    	</tr>
			    	<tr>
			    		<td><br></td>	
			    	</tr>	

	    		</table>
	    	</td>
    	</tr>
    	<tr>
        	<!-- Course List -->
        	<td>
        	<table width="100%" class="courses">
        		<tr>
        			<th>Course No</th>
        			<th>Course Title</th>
        			<th>Credit Hours</th>
        			<th>Remarks</th>
        		</tr>
			<?php 

			if(isset($_SESSION['Result_Search_Course']))
			{
				$Result_Search_Course = $_SESSION['Result_Search_Course'];
				$CourseStudentRegistrations = $Result_Search_Course->getResultObject();
				
				//have to print fixed number of courses 
				$totalCredit=0;
				for($i = 0; $i < 11; $i++) {
					
					$CourseStudentRegistration = null;

					if(isset($CourseStudentRegistrations[$i]))
						$CourseStudentRegistration = $CourseStudentRegistrations[$i];

				?>
				<tr>
					<td>
						<?php 
							if(isset($CourseStudentRegistration))
							 echo strtoupper($CourseStudentRegistration->getCourse()->getCourseNo());
							else
							 echo '<br>';	
						?>
						
					</td>
					<td>
						<?php 
							if(isset($CourseStudentRegistration))
							echo strtoupper($CourseStudentRegistration->getCourse()->getTitle()); 
							else
							 echo '<br>';
						?>
						
					</td>
					<td>
						<?php 
							if(isset($CourseStudentRegistration)){
							echo strtoupper($CourseStudentRegistration->getCourse()->getCredit()); 
							$totalCredit +=floatval($CourseStudentRegistration->getCourse()->getCredit());
							}
							else
							 echo '<br>';
						?>
						
					</td>
					<td><?php //echo $CourseStudentRegistration->getStatus(); ?></td>
				</tr>
					<?php

				} 

			}
			
			?>

        	</table>
        	</td>
    	</tr>
    	<tr><td><br></td></tr>
    	<tr>
    		<td>
    			<table width="100%">
    				<tr>
			    		<td>
			    			<table>
			    				<tr>
			    					<td>&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td><strong>Credit Hours Completed</strong></td>
			    				</tr>
			    				<tr>
			    					<td><strong>GPA</strong></td>
			    				</tr>
			    			</table>
			    		</td>
			    		<td>
			    			<table style="text-align:center" class="years">
			    				<tr><td colspan="2">YEAR 1</td></tr>
			    				<tr>
			    				<td>TERM I</td>
			    				<td>TERM II</td>
			    				</tr>
			    				<tr>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td></td>
			    					<td></td>
			    				</tr>
			    			</table>	
			    		</td>
			    		<td>
			    			<table style="text-align:center" class="years">
			    				<tr><td colspan="2">YEAR 2</td></tr>
			    				<tr>
			    				<td>TERM I</td>
			    				<td>TERM II</td>
			    				</tr>
			    				<tr>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td></td>
			    					<td></td>
			    				</tr>
			    			</table>	
			    		</td>
			    		<td>
			    			<table style="text-align:center" class="years">
			    				<tr><td colspan="2">YEAR 3</td></tr>
			    				<tr>
			    				<td>TERM I</td>
			    				<td>TERM II</td>
			    				</tr>
			    				<tr>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td></td>
			    					<td></td>
			    				</tr>
			    			</table>	
			    		</td>
			    		<td>
			    			<table style="text-align:center" class="years">
			    				<tr><td colspan="2">YEAR 4</td></tr>
			    				<tr>
			    				<td>TERM I</td>
			    				<td>TERM II</td>
			    				</tr>
			    				<tr>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td></td>
			    					<td></td>
			    				</tr>
			    			</table>	
			    		</td>
			    		<td>
			    			<table style="text-align:center" class="years">
			    				<tr><td colspan="2">YEAR 5</td></tr>
			    				<tr>
			    				<td>TERM I</td>
			    				<td>TERM II</td>
			    				</tr>
			    				<tr>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    					<td>&nbsp;&nbsp;&nbsp;</td>
			    				</tr>
			    				<tr>
			    					<td></td>
			    					<td></td>
			    				</tr>
			    			</table>	
			    		</td>
    				</tr>
    			</table>
    		</td>	
    	</tr>
    	<tr><td><br></td></tr>
    	<tr>
    		<td>
    			<table width="100%">
    					<tr>
    						<td><strong>Credit hours taken in current term</strong></td>
    						<td><table class="courses"><tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $totalCredit; ?>&nbsp;&nbsp;</td></tr></table></td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    						<td><strong>Male</strong></td>
    						<td><table class="courses"><tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td></tr></table></td>
    						<td><strong>Female</strong></td>
    						<td><table class="courses"><tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td></tr></table></td>
    					</tr>
    			</table>
    		</td>
    	</tr>
    	<tr><td><br></td></tr>
    	<tr>
    		<td>
    			<table width="100%">
    				<tr>
    					<td > 
    						<strong>Student Signature & Date:</strong>
    					</td>

    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>

    					<td> 
    						<strong>Contact No :</strong>
    					</td>

    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>
    					
    				</tr>
    			</table>
    		</td>
    	</tr>
    	<tr><td><br></td></tr>
      	<tr>
    		<td>
    			<table width="100%">
    				<tr>
    					<td > 
    						<strong>Hall:</strong>
    					</td>
     					<td style="border-bottom: 1px solid black; line-height: 1.8em;">  					
   						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>   					
    					<td> 
    						<strong>Provost:</strong>
    					</td>
     					<td style="border-bottom: 1px solid black; line-height: 1.8em;">  					
   						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>     					
    					<td> 
    						<strong>Date:</strong>
    					</td>
     					<td style="border-bottom: 1px solid black; line-height: 1.8em;">  					
   						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>    					
    				</tr>

    			</table>
    		</td>
    	</tr>  
    	<tr><td><br></td></tr>
    	<tr>
    		<td>
    			<table width="100%">
    				<tr>
    					<td> <strong>Course Co-ordinator:</strong>
    					</td>
    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>
    					<td> <strong>Date:</strong>
    					</td>
    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>    					
    				</tr>
    			</table>
    		</td>
    	</tr>
    	<tr><td><br></td></tr>
      	<tr>
    		<td>
    			<table width="100%">
    				<tr>
    					<td> <strong>Head of the Discipline:</strong>
    					</td>

    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>    					
    					<td> <strong>Date:</strong>
    					</td>
     					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>     					
    				</tr>
    			</table>
    		</td>
    	</tr> 
    	<tr><td><br></td></tr>
     	<tr>
    		<td>
    			<table width="100%">
    				<tr>
    					<td><strong>Receiving Officer:</strong>
    					</td>
    					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>    					
    					<td> <strong>Date:</strong>
    					</td>
     					<td style="border-bottom: 1px solid black; line-height: 1.8em;">
    						
    						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    					</td>     					
    				</tr>
    			</table>
    		</td>
    	</tr>   	 	    		
</table>
		
