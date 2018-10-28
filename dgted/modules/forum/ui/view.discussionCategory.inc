<?php

include_once 'blade/view.discussionCategory.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.forum.inc';

?>
<div class="panel panel-default">
    
    <div class="panel-heading">Discussion Category</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtCat">Category Name:</label>
              	<div class="col-sm-6">
					<input type="text" name="txtCat" class="form-control"
					 placeholder="Category Name" value="<?php 
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
	
	
	$Result = $_DiscussionCategoryBAO->getAllDiscussionCategorys();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$DiscussionCategoryList = $Result->getResultObject();
	?> 
		<tr>
			<th>Category Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($DiscussionCategoryList); $i++) {
			$DiscussionCategory = $DiscussionCategoryList[$i];
			?>
		    <tr>
			    <td><?php echo $DiscussionCategory->getName(); ?></td>
			    <td><a href="?edit=<?php echo $DiscussionCategory->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $DiscussionCategory->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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

