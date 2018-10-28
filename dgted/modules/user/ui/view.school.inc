<?php

include_once 'blade/view.school.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">School Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Term Name:</label>
              	<div class="col-sm-10"> 
              	<input type="text" name="txtName" placeholder="School Name" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getName();  ?>" />
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
	
	
	$Result = $_SchoolBAO->getAllSchools();

	//if DAO access is successful to load all the Schools then show them one by one
	if($Result->getIsSuccess()){

		$SchoolList = $Result->getResultObject();
	?>
		<tr>
			<th>School Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($SchoolList); $i++) {
			$School = $SchoolList[$i];
			?>
		    <tr>
			    <td><?php echo $School->getName(); ?></td>
			    <td><a href="?edit=<?php echo $School->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $School->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

