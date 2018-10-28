<?php

include_once 'blade/view.video.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Video Tutorial Manager</div>
    
    <div class="panel-body">

	
	<div id="form" >
		<form method="post" class="form-horizontal">

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtName">Video Title:</label>
              	<div class="col-sm-8">  
				
					<input type="text" class="form-control" name="txtName" placeholder="Video Title" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getTitle();  ?>" />
				</div>
				</div>	

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtdes">Video Description:</label>
              	<div class="col-sm-8">  

					<input type="text" name="txtdes" class="form-control" placeholder="Video Description" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getDescription();  ?>" />
				</div>
				</div>

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtlink">Video Link:</label>
              	<div class="col-sm-8">  

				<input type="text" name="txtlink" class="form-control"  placeholder="Link" value="<?php
					
					if(isset($_GET['edit'])){
						$link = $getROW->getLink();
						echo $link;
						} ?>" />
				</div>
				</div>				

				<div class="form-group">
              	<label class="control-label col-sm-4" for="txttag">Video Tags:</label>
              	<div class="col-sm-8">  

					<input type="text" name="txttag" class="form-control" placeholder="TagName" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getTag();  ?>" />
				</div>
				</div>
				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtembed">Is Embedded:</label>
              	<div class="col-sm-1">  
						<select name="txtembed">
							<option>0</option>
							<option>1</option>
						</select>
				</div>
				</div>
		        <div class="form-group">        
	              <div class="col-sm-offset-4 col-sm-4">					

						<?php
						if(isset($_GET['edit']))
						{
							?>
							<input  type="submit" id="savebutton" name="update" value="Update">
							<?php
						}
						else
						{
							?>
							<input type="submit"  id="savebutton" name="save" value="Save">
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
	<tr>
		<th>Video Title</th>
	</tr>

	<?php
	
	$Result = $_VideoBAO->getAllVideos();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$VideoList = $Result->getResultObject();
	?>
		<?php
		for($i = 0; $i < sizeof($VideoList); $i++) {
			$Video = $VideoList[$i];
			?>
		    <tr>
			    <td><?php echo $Video->getTitle(); ?></td>
			    
			    <td><a href="video_comment.php?view=<?php echo $Video->getID(); ?>" onclick="return ; " >view</a></td>
			    <td><a href="?edit=<?php echo $Video->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Video->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

