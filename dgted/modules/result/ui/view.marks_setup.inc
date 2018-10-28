<?php

include_once 'blade/view.marks_setup.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.result.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading"><strong>Marks Setup</strong></div>
    
    <div class="panel-body col-sm-12">

	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="coursetype">Course Type:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_CourseTypeBAO->getAllCourseTypes();
							if ($Result->getIsSuccess())
								$CourseTypeList = $Result->getResultObject();					
							?>
							<select name="coursetype" class="form-control">
								<?php
								for ($i = 0; $i<sizeof($CourseTypeList); $i++){
									$CourseType = $CourseTypeList[$i];
									
									if (isset($_GET['edit']) && !strcasecmp($getROW->getCourseType()->getID(), $CourseType->getID()) )
									{
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
								?>	
							</select>
					</div>		
			</div>	

			<div class="form-group">
              	<label class="control-label col-sm-2" for="txtHeaderID">Header ID:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtHeaderID" placeholder="e.g. att,assess" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getHeaderID();  ?>" />
				</div>				
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-2" for="txtHeaderName">Header Name:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtHeaderName" placeholder="e.g. Attendance,Assessment" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getHeaderName();  ?>" />
				</div>				
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-2" for="txtHeaderMax">Header Max:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtHeaderMax" placeholder="e.g. 10,30" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getHeaderMax();  ?>" />
				</div>				
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="IsDefault">Default ?</label>
              	<div class="col-sm-2">	
  
							<input type="checkbox" name="IsDefault"
							<?php
							if (isset($_GET['edit'])){
								if($getROW->getIsDefault() == 1)
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
	
	
	$Result = $_MarksSetupBAO->getAllMarksSetups();

	//if DAO access is successful to load all the mark setups then show them one by one
	if($Result->getIsSuccess()){

		$MarksSetupList = $Result->getResultObject();
	?>
		<tr>
			<th>Header Name</th>
			<th>Header Max Value</th>
			<th>Course Type</th>
			<th>Is Default?</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($MarksSetupList); $i++) {
			$MarksSetup = $MarksSetupList[$i];
			?>
		    <tr>
			    <td><?php echo $MarksSetup->getHeaderName(); ?></td>
			    <td><?php echo $MarksSetup->getHeaderMax(); ?></td>
			    <td><?php echo $MarksSetup->getCourseType()->getName(); ?></td>
				<td>
					<input type="checkbox" name="name1" onclick="return false;" 
					<?php 
					if($MarksSetup->getIsDefault() == 1)
					{
						?>
						checked = "checked"
						<?php
					}
					?>/>
				</td>			    
			    <td><a href="?edit=<?php echo $MarksSetup->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $MarksSetup->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
