<?php

include_once 'blade/view.share.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.file.inc';

?>
	<div id="form">
		<form method="post">
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
						
							?>
							<button type="submit" name="save">save</button>
							<?php
						
						?>
					</td>
				</tr>
			</table>
		</form>

<br />
</div>
