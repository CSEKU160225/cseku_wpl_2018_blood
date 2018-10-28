<?php

include_once 'blade/view.discussion.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">All the Discussions</div>
    
    <div class="panel-body">

	<table class="table table-bordered">

	<?php
	
	
	$Result = $_DiscussionBAO->getAllDiscussions();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$DiscussionList = $Result->getResultObject();
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
			    	$Result2 = $_DiscussionBAO->getNameFromCatagoryID($id);
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
</div>

<div class="panel panel-default">
    
    <div class="panel-heading">Search Discussions</div>
    
    <div class="panel-body">
	
		<table class="table table-bordered">
			<tr><th>Category</th></tr>
			<tr><?php
				$Result = $_DiscussionCategoryBAO->getAllDiscussionCategorys();
									//if DAO access is successful to load all the Roles then show them one by one
				if($Result->getIsSuccess())
				{

					$DiscussionCategorys = $Result->getResultObject();
								
			        for ($i=0; $i < sizeof($DiscussionCategorys); $i++) 
					{ 
						$DiscussionCategory = $DiscussionCategorys[$i];?>
						<tr><td><a href="search_discussion.php?Category=<?php echo $DiscussionCategory->getID(); ?>" onclick="return; "> <?php echo $DiscussionCategory->getName() ?> </a></td></tr>
					<?php
					}
				}

				?>
			</tr>
		</table>
	
	</div>
</div>	
