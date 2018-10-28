<?php

include_once 'blade/view.permission.blade.inc';
include_once COMMON.'class.common.inc';

?>

	
		<script type="text/javascript">
			

		</script>

	<div class="panel panel-default">
    
    <div class="panel-heading">Position Information</div>
    
    <div class="panel-body">

	<div id="form">

		<form method="post" class="form-horizontal" name="formPermissions">
					<div class="form-group">
		              	<label class="control-label col-sm-2" for="selectedRole">Available Roles:</label>		 <div class="col-sm-10">   
						    <?php
						    // this block of code prints the list box of roles with current assigned  roles
						    //window.location.href+=\'?edit=\'+this.value;
						    $var = '<select name="selectedRole" id="select-from-roles" onChange="onChangeEventHandler(event,this);">';
							$Result = $_RoleBAO->getAllRoles();
								//if DAO access is successful to load all the Roles then show them one by one
							if($Result->getIsSuccess()){

								$Roles = $Result->getResultObject();

								$var = $var.'<option selected disabled>Select Role</option>';
							
						       for ($i=0; $i < sizeof($Roles); $i++) { 
						       		
						       		$Role = $Roles[$i];
						    
						    		$var = $var. '<option value="'.$Role->getID().'"';   

						    		if(isset($_GET['edit']) && !strcmp($_GET['edit'],$Role->getID())) {
						          		$var = $var.' selected="selected"';
						          	} 			

						          	$var = $var.'>'.$Role->getName().'</option>';
					
								}

								$var = $var.'</select>';
							}
							echo $var;
							?>	
						</div>	
					</div>
					
					<div class="form-group">        
	              		<div class="col-sm-10">	
						
						    <?php
						    // this block of code prints the checkbox of permissions
						    $var='<table class="table table-bordered">';

						    $var=$var.'<tr>';
						    $var=$var.'<th>Permissions</th>';
						    $var=$var.'<th>Create</th>';
						    $var=$var.'<th>Read</th>';
						    $var=$var.'<th>Update</th>';
						    $var=$var.'<th>Delete</th>';
						    $var=$var.'</tr>';
						    $Result = $_RoleBAO->getAllPermissions();

								
							if($Result->getIsSuccess()){

								$Permissions = $Result->getResultObject();
								
								//building all the permission block
						       for ($i=0; $i < sizeof($Permissions); ) { 
						       		//selecting one category
						       		$Permission = $Permissions[$i];
						       		$var = $var.'<tr>';
						       		$var = $var.'<td>'.$Permission->getCategory().'</td>';

						       		$j=$i;
						       		//printing related categories	
						       		for ( ; $j < sizeof($Permissions)  ; $j++) { 

						       			if(!strcasecmp($Permissions[$i]->getCategory(), $Permissions[$j]->getCategory())){

						    				$var = $var.'<td><input type="checkbox" name="selectedPermissions[]" 
						    					value="'.$Permissions[$j]->getID().'" 
						    					id="'.$Permissions[$j]->getID().'"';

						    				if(isset($_GET['edit']) && isPermissionAvailable($Permissions[$j],$globalRole->getPermissions())) {
						          				$var = $var.' checked="checked"';
						          			} 

						          			$var = $var.'/></td>';
						       			}
						       			else{

						       				break;
						       			}
						       		}

						       		$i=$j;

						       		$var = $var. '</tr>';
						       		
						    	}

						    	$var = $var.'</table>';	

						    }

						    echo $var;
						    ?>
						</div>	
					</div>	    

					<div class="form-group">        
	              		<div class="col-sm-5">	
				
									<input type="button" name="checkAll" onclick="SetAllCheckBoxes('formPermissions', 'selectedPermissions[]', true);" value="Check All"/> 
						</div>		
						<div class="col-sm-5">		
									<input type="button" name="uncheckAll" onclick="SetAllCheckBoxes('formPermissions', 'selectedPermissions[]', false);" value="Uncheck All"/> 
						</div>
					</div>
					<div class="form-group">        
	              		<div class="col-sm-10">	
							<button type="submit" name="save">save</button>

						</div>
					</div>	
		</form>

	</div>
	</div>
	</div>


