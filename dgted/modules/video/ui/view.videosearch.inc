<?php
//session_start();
include_once 'blade/view.videosearch.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
//include_once 'blade/view.video.blade.inc';


?>
<div class="panel panel-default">
    
    <div class="panel-heading">Video Search</div>
    
    <div class="panel-body">

	
	<div id="form" >
		<form method="post" class="form-horizontal">

				<div class="form-group">
              	<label class="control-label col-sm-4" for="search">Search Video:</label>
	              	<div class="col-sm-8">  
					<input type="text"  name="txtsearch" placeholder="Search video"></input>
					</div>
				</div>
		        <div class="form-group">        
	            	<div class="col-sm-offset-6 col-sm-4">								
					<input  type="submit" id="savebutton" name="search" value="Search">
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
	
	$tag = null;
				
	if(isset($_GET["tag"]))
	{
		$tag = $_GET["tag"];
	}

	
	$Result = $_VideoBAO->searchVideo($tag);

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$VideoList = $Result->getResultObject();

	?>
		<?php
		for($i = 0; $i < sizeof($VideoList); $i++) {
			$Video = $VideoList[$i];
			?>
		    <tr>
			    <td >
			    <a href="video_comment.php?view=<?php echo $Video->getID(); ?>" onclick="return ; " >
			    <?php echo $Video->getTitle(); ?>
			    	
			    </a>
			    </td>
			    
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
