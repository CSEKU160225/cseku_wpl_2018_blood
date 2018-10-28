<?php

include_once 'blade/view.year.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Year Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Year Name:</label>
              	<div class="col-sm-10">       
				<input type="text" name="txtName" class="form-control"  placeholder="Year Name" value="<?php 
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
	
	
	$Result = $_YearBAO->getAllYears();

	//if DAO access is successful to load all the Years then show them one by one
	if($Result->getIsSuccess()){

		$YearList = $Result->getResultObject();
	?>
		<tr>
			<th>Year Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($YearList); $i++) {
			$Year = $YearList[$i];
			?>
		    <tr>
			    <td><?php echo $Year->getName(); ?></td>
			    <td><a href="?edit=<?php echo $Year->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Year->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
