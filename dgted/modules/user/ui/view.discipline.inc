<?php

include_once 'blade/view.discipline.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';


?>

<div class="panel panel-default">
    
    <div class="panel-heading">Discipline Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				<div class="form-group">
	              	<label class="control-label col-sm-2" for="selectedSchool">Schools:</label>
	              	<div class="col-sm-10">   
					    <?php

					    $var = '<select name="selectedSchool" id="select-from-schools">';
						$Result = $_SchoolBAO->getAllSchools();
							//building the school options
						if($Result->getIsSuccess()){

							$Schools = $Result->getResultObject();

							$var = $var.'<option value="select">Select</option>';
						
					       for ($i=0; $i < sizeof($Schools); $i++) { 
					       		
					       		$School = $Schools[$i];
					    
					    		$var = $var. '<option value="'.$School->getID().'"';   

					    		if(isset($_GET['edit']) && 
					    			!strcmp($School->getID(),$getROW->getSchool()->getID())//loaded discipline
					    		  ) {
					          		$var = $var.' selected="selected"';
					          	} 			

					          	$var = $var.'>'.$School->getName().'</option>';
				
							}

							$var = $var.'</select>';
						}
						echo $var;
						?>	
					</div>	
				</div>
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Discipline Name:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtName" placeholder="Discipline Name" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getName();  ?>" />
				</div>				
				</div>
				<div>
				<label class="control-label col-sm-2" for="txtShortCode">Discipline Code:</label>
				<div class="col-sm-10">
					<input type="text" name="txtShortCode" placeholder="Short code name" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getShortCode();  ?>" />
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
	
	
	$Result = $_DisciplineBAO->getAllDisciplines();

	//if DAO access is successful to load all the Disciplines then show them one by one
	if($Result->getIsSuccess()){

		$DisciplineList = $Result->getResultObject();
	?>
		<tr>
			<th>Discipline Name</th>
			<th>School Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($DisciplineList); $i++) {
			$Discipline = $DisciplineList[$i];
			?>
		    <tr>
			    <td><?php echo $Discipline->getName(); ?></td>
			    <td><?php echo $Discipline->getSchool()->getName(); ?></td>
			    <td><a href="?edit=<?php echo $Discipline->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Discipline->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
