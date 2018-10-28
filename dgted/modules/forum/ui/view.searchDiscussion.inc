<?php
//session_start();
include_once 'blade/view.searchDiscussion.blade.inc';
include_once COMMON.'class.common.inc';

$Discussion1 = $Discussion; 

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Search Discussion</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">		
				<label class="control-label col-sm-4" for="txtSearch">Tag based Search:</label>
				<div  class="col-sm-6">
				<input type="text" class="form-control" name="txtSearch" placeholder="Search Tag"/>
				</div>
			</div>

	        <div class="form-group">        
             	<div class="col-sm-offset-2 col-sm-10">
				<button type="submit" name="search">Search</button>
				</div>
			</div>	
		</form>
	</div>
	</div>

	<div class="panel-body">

	<table class="table table-bordered">
		

			<?php
				$tag = null;
				
				if(isset($_GET["tag"]))
				{
					$tag = $_GET["tag"];
				}

			//var_dump($tag);
			if(!isset($tag)){
			//if(!$_GET["tag"]){
				$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
				$Catagory2 = substr($id, -38);
			?>
	
	<?php
		$Result2 = $_searchDiscussionBAO->readCategorywiseDiscussion($Catagory2);
			    	if($Result2->getIsSuccess()){

								$DiscussionList = $Result2->getResultObject();
							?> 
								<tr>
									<th>Questions</th>
									<th>Category</th>
									<th>Tags</th>
								</tr>
								<?php
								for($i = 0; $i < sizeof($DiscussionList); $i++) {
									$Discussion = $DiscussionList[$i];
									?>
								    <tr>
								    <td><a href="discussion_comment.php?view=<?php echo $Discussion->getID(); ?>" onclick="return ; " >
								    <?php echo $Discussion->getName(); ?></a></td>
									    <td><?php $id = $Discussion->getCategory();
									    	$Result2 = $_searchDiscussionBAO->getNameFromCatagoryID($id);
									    	if ($Result2->getIsSuccess()) {
									    		$DiscussionCategory = $Result2->getResultObject();

									    		echo $DiscussionCategory->getName();
									    	}
									    	//echo $_DiscussionBAO->getNameFromCatagoryID($id); ?></td>
									    <td><?php echo $Discussion->getTag(); ?></td>
									    
									    
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

	<div class="panel-body">

	<table class="table table-bordered">

	
	<?php 

	} 

	?>
	
	<?php
	if(isset($tag)){
		//var_dump($tag);
		 $Result2 = $_searchDiscussionBAO->readTagwiseDiscussion($tag);
			    	if($Result2->getIsSuccess()){

								$DiscussionList = $Result2->getResultObject();
							?> 
		 
								<tr>
									<th>Questions</th>
									<th>Category</th>
									<th>Tags</th>
								</tr>
								<?php
								for($i = 0; $i < sizeof($DiscussionList); $i++) {
									$Discussion = $DiscussionList[$i];
									?>
								    <tr>
								    <td><a href="discussion_comment.php?view=<?php echo $Discussion->getID(); ?>" onclick="return ; " >
								    <?php echo $Discussion->getName(); ?></a></td>
									    <td><?php $id = $Discussion->getCategory();
									    	$Result2 = $_searchDiscussionBAO->getNameFromCatagoryID($id);
									    	if ($Result2->getIsSuccess()) {
									    		$DiscussionCategory = $Result2->getResultObject();

									    		echo $DiscussionCategory->getName();
									    	}
									    	//echo $_DiscussionBAO->getNameFromCatagoryID($id); ?></td>
									    <td><?php echo $Discussion->getTag(); ?></td>
									    
									   
								    </tr>
							    <?php

								}

							}
							else{

								echo $Result->getResultObject(); //giving failure message
							}
			    	?>
	
	</table>
	<?php  } ?>

	
	</div>

</div>