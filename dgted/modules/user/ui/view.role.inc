<?php

include_once 'blade/view.role.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Role Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Role Name:</label>
              	<div class="col-sm-10"> 
				<input type="text" name="txtName" placeholder="Role Name" value="<?php 
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
	
	
	$Result = $_RoleBAO->getAllRoles();

	//if DAO access is successful to load all the Roles then show them one by one
	if($Result->getIsSuccess()){

		$RoleList = $Result->getResultObject();
	?>
		<tr>
			<th>Role Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($RoleList); $i++) {
			$Role = $RoleList[$i];
			?>
		    <tr>
			    <td><?php echo $Role->getName(); ?></td>
			    <td><a href="?edit=<?php echo $Role->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Role->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
