<?php

include_once 'blade/view.term.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Term Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Term Name:</label>
              	<div class="col-sm-10">       
				<input type="text" name="txtName" class="form-control"  placeholder="Term Name" value="<?php 
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
	
	
	$Result = $_TermBAO->getAllTerms();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$TermList = $Result->getResultObject();
	?>
		<tr>
			<th>Term Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($TermList); $i++) {
			$Term = $TermList[$i];
			?>
		    <tr>
			    <td><?php echo $Term->getName(); ?></td>
			    <td><a href="?edit=<?php echo $Term->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Term->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
