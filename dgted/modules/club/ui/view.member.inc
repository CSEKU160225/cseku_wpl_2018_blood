<?php

include_once 'blade/view.member.blade.inc';
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
    Member Information of Club (
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
              	<label class="control-label col-sm-4" for="txtName">Name of the Member:</label>
            	<div class="col-sm-6">
					<input type="text" name="txtName" class="form-control" placeholder="Name of the Member" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getName();  ?>" />
				</div>
			</div>
				
			<div class="form-group">
          	<label class="control-label col-sm-4" for="txtDes">Designation:</label>
          		<div class="col-sm-6">
				<input type="text" name="txtDes" class="form-control" placeholder="Designation" value="<?php 
					if(isset($_GET['edit'])) echo $getROW->getDesignation();  ?>" />
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
	if(isset($_GET['club'])){

		$Club = new Club();	
		$Club->setID($_GET['club']);	
		
		
		$Result = $_MembersBAO->getAllMembers($Club);

		//if DAO access is successful to load all the Positions then show them one by one
		if($Result->getIsSuccess()){

			$MembersList = $Result->getResultObject();
		?>
			<tr>
				<th>Member</th>
				<th>Designation</th>
			</tr>
			<?php
			for($i = 0; $i < sizeof($MembersList); $i++) {
				$Members = $MembersList[$i];
				?>
			    <tr>
				    <td><?php echo $Members->getName(); ?></td>
				    <td><?php echo $Members->getDesignation(); ?></td>
				    <td><a href="?club=<?php echo $_GET['club']; ?>&edit=<?php echo $Members->getMemberID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
				    <td><a href="?club=<?php echo $_GET['club']; ?>&del=<?php echo $Members->getMemberID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
