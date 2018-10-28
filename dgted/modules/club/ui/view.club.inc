<?php

include_once 'blade/view.club.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">All Clubs</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal" enctype="multipart/form-data">

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtName">Club Name:</label>
              		<div class="col-sm-6">
              			<input type="text" name="txtName" class="form-control" placeholder="Club Name" value="<?php 
							if(isset($_GET['edit'])) echo $getROW->getName();  ?>" />
					</div>			
				</div>

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtMail">Club Contact:</label>
              		<div class="col-sm-6">
						<input type="text" name="txtMail" class="form-control" placeholder="Club contact" value="		<?php if(isset($_GET['edit'])) echo $getROW->getMail();  ?>" />
					</div>	
				</div>	
				
				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtDes">Club Description:</label>
              		<div class="col-sm-6">
					<textarea cols="50" rows="5" wrap="hard" class="form-control" name="txtDes">
							<?php 
										if(isset($_GET['edit'])) echo $getROW->getDescription();
							?>

					</textarea>
					</div>	
				</div>

				<div class="form-group">
              	<label class="control-label col-sm-4" for="cover_photo">Choose Cover Photo :</label>
              		<div class="col-sm-6">
						<input type="hidden" name="MAX_FILE_SIZE" value="4194304" />  
						<input type="file" name="cover_photo" class="form-control" id="cover_photo" accept="image/*" > 
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
							<button type="submit" name="save" >Create Club</button>
							
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
	
	
	$Result = $_ClubBAO->getAllClub();

	//if DAO access is successful to load all the Positions then show them one by one
	if($Result->getIsSuccess()){

		$ClubList = $Result->getResultObject();
	?>
		<tr>
			<th>Club Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($ClubList); $i++) {
			
			$Club = $ClubList[$i];
			?>
		    <tr>
		    <?php
		    echo '<td><a href="clubpage.php?club='.$Club->getID().'">'.$Club->getName().'</a></td>';

		    ?>
		   
			    
			    <td><a href="?edit=<?php echo $Club->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Club->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
			    <td><a href="club_module.php?club=<?php echo $Club->getID(); ?>" onclick="return confirm('sure to add !'); " >add module</a></td>
			    <td><a href="club_member.php?club=<?php echo $Club->getID(); ?>" onclick="return confirm('sure to add !'); " >add Member</a></td>
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