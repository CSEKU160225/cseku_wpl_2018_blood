<?php

include_once 'blade/view.job.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Job Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtTitle">Job Title:</label>
              	<div class="col-sm-10"> 
				<input type="text" name="txtTitle" placeholder="job title" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getTitle();  ?>" />
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
	
	
	$Result = $_jobBAO->getAlljobs();

	//if DAO access is successful to load all the jobs then show them one by one
	if($Result->getIsSuccess()){

		$jobList = $Result->getResultObject();
	?>
		<tr>
			<th>Job Tile</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($jobList); $i++) {
			$job = $jobList[$i];
			?>
		    <tr>
			    <td><?php echo $job->getTitle(); ?></td>
			    <td><a href="?edit=<?php echo $job->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $job->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
