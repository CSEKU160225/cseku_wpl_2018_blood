<?php

include_once 'blade/view.position.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Position Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Position Name:</label>
              	<div class="col-sm-10"> 
					<input type="text" name="txtName" placeholder="Position Name" value="<?php 
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
	
	
	$Result = $_PositionBAO->getAllPositions();

	//if DAO access is successful to load all the Positions then show them one by one
	if($Result->getIsSuccess()){

		$PositionList = $Result->getResultObject();
	?>
		<tr>
			<th>Position Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($PositionList); $i++) {
			$Position = $PositionList[$i];
			?>
		    <tr>
			    <td><?php echo $Position->getName(); ?></td>
			    <td><a href="?edit=<?php echo $Position->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Position->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
