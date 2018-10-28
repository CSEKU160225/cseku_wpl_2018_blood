<?php

include_once 'blade/view.course.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>
<div class="panel panel-default">
    
    <div class="panel-heading">Course Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtName">Course No:</label>
          	<div class="col-sm-6">       
			<input type="text" name="txtName" class="form-control"  placeholder="Course No" value="<?php 
				if(isset($_GET['edit'])) echo $getROW->getCourseNo();  ?>" />
			</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtName">Course Title:</label>
          	<div class="col-sm-6">       
			<input type="text" name="txttitle" class="form-control"  placeholder="Course Title" value="<?php 
				if(isset($_GET['edit'])) echo $getROW->getTitle();  ?>" />
			</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtName">Course Title:</label>
          	<div class="col-sm-6">       
			<input type="text" name="txtcrdit" class="form-control"  placeholder="Course Credit" value="<?php 
				if(isset($_GET['edit'])) echo $getROW->getCredit();  ?>" />
			</div>
			</div>
			<div class="form-group">
              	<label class="control-label col-sm-4" for="coursetype">Course Type:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_CourseTypeBAO->getAllCourseTypes();
							if ($Result->getIsSuccess())
								$CourseTypeList = $Result->getResultObject();					
							?>
							<select name="coursetype" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($CourseTypeList); $i++){
									$CourseType = $CourseTypeList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $CourseType->getID();?>" > <?php echo $CourseType->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getCourseTypeID() == $CourseType->getID() ){
											?>
											<option selected value = "<?php echo $CourseType->getID();?>" > <?php echo $CourseType->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $CourseType->getID();?>" > <?php echo $CourseType->getName(); ?> 
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
              	<label class="control-label col-sm-4" for="discipline">Discipline:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_DisciplineBAO->getAllDisciplines();
							if ($Result->getIsSuccess())
								$DisciplineList = $Result->getResultObject();					
							?>
							<select name="discipline" class="form-control" style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($DisciplineList); $i++){
									$Discipline = $DisciplineList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $Discipline->getID();?>" > <?php echo $Discipline->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getDisciplineID() == $Discipline->getID() ){
											?>
											<option selected value = "<?php echo $Discipline->getID();?>" > <?php echo $Discipline->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $Discipline->getID();?>" > <?php echo $Discipline->getName(); ?> 
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
              	<label class="control-label col-sm-4" for="ISdeleted">Deleted ?</label>
              	<div class="col-sm-2">	
  
							<input type="checkbox" name="ISdeleted"
							<?php
							if (isset($_GET['edit'])){
								if($getROW->getISdeleted() == 1)
								{
									?>
									checked = "checked"
									<?php
								}
							}
							?>
							/>

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


				$Result = $_CourseBAO->getAllCourses();

//if DAO access is successful to load all the Terms then show them one by one
				if($Result->getIsSuccess()){

					$Courses = $Result->getResultObject();
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

								<td><a href="?edit=<?php echo $Course->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
								<td><a href="?del=<?php echo $Course->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

