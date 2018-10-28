<?php

include_once 'blade/view.file.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';

?>

	<div id="form">
		<form method="post" enctype="multipart/form-data">
			<table width="100%" border="1" cellpadding="15">
				<tr>
					<td>
						<h3>To</h3>
					</td>
					
					<td>
						<select name="users">
						<?php $Result = $_UserBAO->getAllUsers();

								//if DAO access is successful to load all the Disciplines then show them one by one
								if($Result->getIsSuccess()){

									$UserList = $Result->getResultObject();
								

						for($i = 0; $i < sizeof($UserList); $i++) {
								$User = $UserList[$i];
							# code...?>
							
							<option value="<?php echo $User->getID(); ?>">
							<?php echo $User->getFirstName() ." ". $User->getLastName(); ?>
							</option> <?php
						}
						}
						else{

							echo $Result->getResultObject(); //giving failure message

						}
						?>
						</select>
					</td>
				</tr>
				<tr>
					<td>
						<h3>Link</h3>
					</td>
					<td>
						<!-- <input type="file" name="link" id="linkId"> -->

						
    <input type="file" name="fileToUpload" id="fileToUpload">
    
					</td>
				</tr>
				<tr>
					<td>
						<h3>Discipline</h3>
					</td>
					<td>
						<select name="discipline">
							<?php
								
								
								$Result = $_DisciplineBAO->getAllDisciplines();

								//if DAO access is successful to load all the Disciplines then show them one by one
								if($Result->getIsSuccess()){

									$DisciplineList = $Result->getResultObject();
								

						for($i = 0; $i < sizeof($DisciplineList); $i++) {
								$Discipline = $DisciplineList[$i];
							# code...?>
							
							<option value="<?php echo $Discipline->getID(); ?>">
							<?php echo $Discipline->getName(); ?>
							</option> <?php
						}	
						}
						else{

							echo $Result->getResultObject(); //giving failure message

						}
						?>
						</select>
					</td>
				</tr>
				<tr>
					<td>
						<h3>Comments</h3>
					</td>
					<td>
						<input type="text" name="Comment" id="Comment">
					</td>
				</tr>
				<tr>
					<td>
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
					</td>
				</tr>
			</table>
		</form>

<br />
</div>
<div id="notification">
	<table width="100%" border="1" cellpadding="15" align="center">
	<?php
	
	
	$Result = $_FileBAO->getAllFiles();

	//if DAO access is successful to load all the Terms then show them one by one
	if($Result->getIsSuccess()){

		$FileList = $Result->getResultObject();
	?>
		<tr>
			<td>Creator</td>
			<td>Assign Name</td>
			<td>Link</td>
			<td>Discipline</td>
		</tr>
		<?php 
		for($i = 0; $i < sizeof($FileList); $i++) {
			$File = $FileList[$i];
			?>
		    <tr>
			    <td><?php 
			    	$User = new user();
			    	$User->setID($File->getCreator());
			    	$User = $_UserBAO->readUser($User);
			    	$User = $User->getResultObject();


			    	echo $User->getFirstName() ." ". $User->getLastName(); ?></td>
			    <td><?php
			    	$User = new user();
			    	$User->setID($File->getName());
			    	$User = $_UserBAO->readUser($User);
			    	$User = $User->getResultObject();


			    	echo $User->getFirstName() ." ". $User->getLastName(); ?></td>
			    <td>
			    <a href='<?php echo "".$File->getLink(); ?>' target="_blank"><?php echo "".$File->getLink(); ?></a>


			    </td>
			    <td><?php 
				    $Discipline = new discipline();
				    $Discipline->setID($File->getDiscipline());
				    $Discipline = $_DisciplineBAO->readDiscipline($Discipline);
				    $Discipline = $Discipline->getResultObject();
			    	echo $Discipline->getName(); ?>
			    		
			    </td>
			    
			    <td><a href="?edit=<?php echo $File->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $File->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
			    <td>
			    	<a href="file_notify.php?history=<?php echo $File->getID(); ?>" onclick="return ; " >history</a>
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
