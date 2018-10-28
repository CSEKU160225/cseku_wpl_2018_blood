<?php

include_once 'blade/view.module.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';

					 	
 	if(isset($_GET['club'])){						 	
		$Club = new Club();	
		$Club->setID($_GET['club']);	
		$Club = $_ClubBAO->readClub($Club)->getResultObject();				
		
	}

?>

<div class="panel panel-default">
    
    <div class="panel-heading">
    Module Information of Club (
    <?php 
    	echo '<b>'.$Club->getName().'</b>' ;  
    ?> )
    </div>
    
    <div class="panel-body">

	<div id="form">

		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-8">
	
				</label>
				 <input type="hidden" name="club_id" class="form-control"
					 value="<?php if(isset($_GET['club'])) echo $_GET['club'];  ?>" /> 
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtModuleName">Module Name:</label>
              		<div class="col-sm-6">
						<input type="text" name="txtModuleName" class="form-control" placeholder="Module Name" value="<?php
							if(isset($_GET['edit'])) echo $getROW->getModuleName();  ?>" />
					</div>		
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtContent">Module Content:</label>
          		<div class="col-sm-6">
					<textarea  cols="40" rows="5" class="form-control" name="txtContent" placeholder="Module Content" ><?php if(isset($_GET['edit'])) echo $getROW->getContent();  ?>					
					</textarea>
				</div>
			</div>

			<div class="form-group">
          	<label class="control-label col-sm-4" for="visible">Is Visible?</label>
          		<div class="col-sm-6">
					<input type="checkbox" class="form-control" value="yes" name="visible"   
					<?php if(isset($_GET['edit'])&&$getROW->getIsVisible()==1) 
						echo 'checked="checked"';  ?> />

				</div>
			</div>	

	        <div class="form-group">        
              <div class="col-sm-offset-2 col-sm-10">
				
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<button type="submit" name="update">Update</button>
							<?php
						}
						else
						{
							?>
							
							<button type="submit" name="save" >Save</button>
							
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
	
	if(isset($_GET['club'])){

		$Club = new Club();	
		$Club->setID($_GET['club']);	
	
		$Result = $_ModuleBAO->getAllModule($Club);

		//if DAO access is successful to load all the Positions then show them one by one
		if($Result->getIsSuccess()){

			$ModuleList = $Result->getResultObject();
		?>
			<tr>
				<th>Module Name</th>
			</tr>
			<?php
			for($i = 0; $i < sizeof($ModuleList); $i++) {
				$Module = $ModuleList[$i];
				?>
			    <tr>
				    <td><?php echo $Module->getModuleName(); ?></td>
				    <td><a href="?club=<?php echo $_GET['club'];?>&edit=<?php echo $Module->getModuleID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
				    <td><a href="?club=<?php echo $_GET['club'];?>&del=<?php echo $Module->getModuleID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
				    
			    </tr>
		    <?php

			}

		}
		else{

			echo $Result->getResultObject(); //giving failure message
		}
	}	
	?>
	</table>
	</div>

</div>
