<?php

include_once 'blade/view.grade_setup.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.result.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading"><strong>Grade Setup</strong></div>
    
    <div class="panel-body col-sm-12">

	<div id="form">
		<form method="post" class="form-horizontal">


			<div class="form-group">
              	<label class="control-label col-sm-2" for="txtGrades">Grades List:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtGrades" placeholder="e.g. F,E,D,C" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getGrades();  ?>" />
				</div>				
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-2" for="txtRanges">Ranges:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtRanges" placeholder="e.g. 0-39,40-44,45-49" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getRanges();  ?>" />
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
	
	
	$Result = $_GradeSetupBAO->getAllGradeSetups();

	//if DAO access is successful to load all the mark setups then show them one by one
	if($Result->getIsSuccess()){

		$GradeSetupList = $Result->getResultObject();
	?>
		<tr>
			<th>Grades</th>
			<th>Ranges</th>
			<th>Is Default?</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($GradeSetupList); $i++) {
			$GradeSetup = $GradeSetupList[$i];
			?>
		    <tr>
			    <td><?php echo $GradeSetup->getGrades(); ?></td>
			    <td><?php echo $GradeSetup->getRanges(); ?></td>
				<td>
					<input type="checkbox" name="name1" onclick="return false;" 
					<?php 
					if($GradeSetup->getIsDefault() == 1)
					{
						?>
						checked = "checked"
						<?php
					}
					?>/>
				</td>			    
			    <td><a href="?edit=<?php echo $GradeSetup->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $GradeSetup->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
