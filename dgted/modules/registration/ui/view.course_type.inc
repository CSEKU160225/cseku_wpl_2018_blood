<?php

include_once 'blade/view.course_type.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Course Type Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtName">Course Type Name:</label>
          	<div class="col-sm-6">       
			<input type="text" name="txtName" class="form-control"  placeholder="Course Type Name" value="<?php 
				if(isset($_GET['edit'])) echo $getROW->getName();  ?>" />
			</div>
			</div>
			<div class="form-group">
              	<label class="control-label col-sm-4" for="sessionaltype">Sessional Type:</label>
              	<div class="col-sm-6">	

							<?php
							$Result = $_SessionalTypeBAO->getAllSessionalTypes();
							if ($Result->getIsSuccess())
								$SessionlTypeList = $Result->getResultObject();					
							?>
							<select name="sessionaltype" class="form-control"  style="width:170px">
								<?php
								for ($i = 0; $i<sizeof($SessionlTypeList); $i++){
									$SessionlType = $SessionlTypeList[$i];
									?>
									<?php
									if (!isset($_GET['edit'])){

										?>
										<option value="<?php echo $SessionlType->getID();?>" > <?php echo $SessionlType->getName(); ?> 
										</option>
										<?php
									}
									if (isset($_GET['edit'])){

										if ($getROW->getSessionalTypeID() == $SessionlType->getID() ){
											?>
											<option selected value = "<?php echo $SessionlType->getID();?>" > <?php echo $SessionlType->getName();?> 
											</option>
											<?php
										}
										else {

											?>
											<option value="<?php echo $SessionlType->getID();?>" > <?php echo $SessionlType->getName(); ?> 
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
	
	
	$Result = $_CourseTypeBAO->getAllCourseTypes();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$CourseList = $Result->getResultObject();
	?>
		<tr>
			<th>Course Type</th>
			<th>Sessional Type</th>
		</tr>
		<?php 
		for($i = 0; $i < sizeof($CourseList); $i++) {
			$Course = $CourseList[$i];
			?>
		    <tr>
			    <td><?php echo $Course->getName(); ?></td>
			    <td><?php echo $Course->getSessionalTypeID(); ?></td>
			    
			    
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
