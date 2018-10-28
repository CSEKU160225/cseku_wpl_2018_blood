<?php

include_once 'blade/view.blood.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.blood.inc';
// $globalUser = $_SESSION["globalUser"];
// var_dump($globalUser);
?>

<style>
	#notification_text_form{
		width: 400px;
	    font-weight: bold;
	    padding: 10px;
	    margin: 0 auto;
	    text-align: center;
	}
	textarea {
	  width: 400px;
	  height: 150px;
	  margin-bottom: 10px;
	}
	th, tr , td {
		text-align: center;
	}
	input[type=checkbox]{
		transform: scale(1.5);
	}
	#overlay {
	   display:block;   
	   position:fixed;  
	   left:0px;        
	   top:0px;         
	   width:100%;      
	   height:100%;    
	   background:#000; 
	   opacity:0.5;     
	   z-index:99999;  
	}

	#popup {
	   display:block;
	   position:fixed;
	    left: 42%;
	    top: 24%;
	    width: 600px;
	    height: 350px;
	   margin-top:-75px;  
	   margin-left:-150px;  
	   background:#FFFFFF;  
	   border:1px solid #000; 
	   z-index:100000; 
	   padding-top:30px;   
	}
</style>

<script>
	function showPopup()
	{
		document.getElementById('popup').style.display = 'block';
		document.getElementById('overlay').style.display = 'block';
	}
</script>

<div class="panel panel-default">
    <div class="panel-heading">Blood Information</div>
    <div class="panel-body">

	<style>
	
	/* The side navigation menu */
.sidenav {
    height: 100%; /* 100% Full-height */
    width: 0; /* 0 width - change this with JavaScript */
    position: fixed; /* Stay in place */
    z-index: 1; /* Stay on top */
    top: 0; /* Stay at the top */
    left: 0;
	color:white;
	text-align:center;
    background-color: #111; /* Black*/
    overflow-x: hidden; /* Disable horizontal scroll */
    padding-top: 60px; /* Place content 60px from the top */
    transition: 0.5s; /* 0.5 second transition effect to slide in the sidenav */
}

/* The navigation menu links */
.sidenav .closebtn {
    padding: 8px 8px 8px 32px;
    text-decoration: none;
    font-size: 25px;
    color: #818181;
    display: block;
    transition: 0.3s;
}

/* When you mouse over the navigation links, change their color */
.sidenav a:hover {
    color: #f1f1f1;
}

/* Position and style the close button (top right corner) */
.sidenav .closebtn {
    position: absolute;
    top: 0;
    right: 25px;
    font-size: 36px;
    margin-left: 50px;
}

h4 span{
				background-color:#d3d3d3;
				padding:6px;
				color:black;
			}

	</style>

	
		<?php
			for($i = 0; $i < sizeof($result); $i++) {
				$dates = $result[$i]->get_given_dates();
				?>
				<div id="mySidenav<?php echo $i; ?>" class="sidenav">
					<a href="javascript:void(0)" class="closebtn" onclick="closeNav('<?php echo $i; ?>')">&times;</a>
				<h2> 
				<?php 
					echo $result[$i]->get_first_name()." ".$result[$i]->get_middle_name()
					." ".$result[$i]->get_last_name(); ?>
					</h2>

					<h3>Blood Given : <?php echo count($dates); ?> times</h3>

					<h4>Donation Dates : </h4> 

					<h4>
			<?php
				
				foreach($dates as $dt){
					echo '<span>'.$dt.'</span> &nbsp';
				}
			?>
		</h4>
		<h4>Phone Number : </h4>
		<h3><a href="tel:<?php echo $result[$i]->get_phone(); ?>"><?php echo $result[$i]->get_phone(); ?></a></h3>
		<h4>Discipline : <?php echo $result[$i]->get_discipline(); ?></h4>
				</div>
				<?php
			}
		?>
	
	

	<div id="form" >
		<form method="post" action="http://localhost/dgted/blood.php" class="form-horizontal">
				<div class="form-group">
					<?php
				//	if(sizeof($result)<=0)
				      // {
				       //	 $_GET['notification']=null;
				      // }

					  // if(!isset($_GET['notification']))
				      // {
				  	     // $x=$_GET['notification'];
				  	      echo '<label class="control-label col-sm-4" for="search">Search Blood:</label>';
				      // }
				    ?>
              	
	              	<div class="col-sm-8"> 
	              	<?php
				  	      echo '<select name="select_blood" class="form-control" id="select-from-blood" required>
							<option selected disabled>Select Group</option>
							<option value="A+">A+</option>
							<option value="A-">A-</option>
							<option value="B+">B+</option>
							<option value="B-">B-</option>
							<option value="AB+">AB+</option>
							<option value="AB-">AB-</option>
							<option value="O+">O+</option>
							<option value="O-">O-</option>
						</select>	';
	              	?>  
					
					</div>
				</div>

		        <div class="form-group">        
	            	<div class="col-sm-offset-6 col-sm-4">
	            	<?php
	            	   	 echo '<input  type="submit" id="savebutton" name="search" value="Search">';
	            	?>								
					
					</div>
				</div>	
		</form>
	</div>
						
				</div>
				</div>		

		</form>

	</div>
	</div>

<div class="panel-body" id="blood_result_panel" style="width: 70%; margin: 0 auto;">

	<h4 style="text-align: center;">Search Result For<?php echo " ".$search_blood; ?></h4>
	<p id="bst" style="display:none; text-align: center; color:red; font-size:20px; font-weight:bold;">
		No Matching Users Found	!!!	
	</p>

<form action="" id="blood_table_searched" method="post">	
	<table class="table table-bordered">
		<thead>
			<th>People</th>
			<th>Availability</th>
			<th>Status</th>
			<th>Send Notification</th>
			
		</thead>
	<?php
		if(sizeof($result) == 0){echo "<script>var NoUsersFound = true;</script>";}
		else {echo "<script>var NoUsersFound = false;</script>";}
		for($i = 0; $i < sizeof($result); $i++) {
			?>
			<tr>
				<td>
					<?php  echo $result[$i]->get_first_name()." ".$result[$i]->get_middle_name()." ".$result[$i]->get_last_name(); ?>
				</td>
				<td>
					<?php 
						$avlb = $result[$i]->get_availability();

						$availability;
					
						if($avlb == -1 || !$avlb) $availability = "Available Now";
						else $availability = "After ".$avlb." Days";

						echo $availability;
					?>
				</td>
				<td>
					<button type="button" onclick="openNav(<?php echo $i; ?>);"   href="javascript:void(0)"
					style="width:auto; height:auto;  border:none; background-color:green; color:white; font-weight: bold;">
					Donor Status
					</button>
				</td>
				<td>
					<input type="checkbox" name="blood_users[]" value="<?php echo $result[$i]->get_user_id();?>">
				</td>
			</tr>
			<?php
	        }
	?>
	<tr>
		<td></td>
		<td></td>
		<td></td>
		<td>
			<button  type="submit" id="sn" name="send_notification" style="width: auto; background-color: grey; border:none; color:white; font-weight: bold;" disabled>
				Send to All Selected
			</button>
		</td>
	</tr>
	</table>
	</form>	
	</div>

<?php
	if(isset($_POST['send_notification']))
	{
		?>

		<div id="send_notification_popup" style="background-color: white; width: 600px;">
		<?php
			if(isset($_POST['blood_users'])){
				?>
				<div id="overlay"></div>
				<div id="popup">
				  <form method="post" id="notification_text_form" action="">
				  	<p for="ntext">Write Notification Text : </p>
				  	<input type="hidden" name="select_blood" value="<?php echo $_SESSION['blood']; ?>">
				  	<?php
				  		foreach($_POST['blood_users'] as $selected_user)
						{
							?>
							<input type="hidden" name="selected_users[]" value="<?php echo $selected_user;  ?>">
							<?php
						}
				  	?>
				  	<textarea name="ntext" id="ntext">BLOOD NEEDED!!! Wondering you might help!</textarea>
				  	<button type="submit" name="send_note" style="background-color: green; border:none; color:white; font-weight: bold;">
				  		Send Notification
						</button>
					<button id="cancel_note" name="cancel_note" onclick="hidePopup();" style=" margin-top:10px;background-color: red; border:none; color:white; font-weight: bold;">
			  			Cancel
					</button>
				  </form>
				</div>
				<script>showPopup();</script>
				<?php
			}
			else{
				echo "<script>alert('Please select at least a checkbox to send notification!');</script>";
			}
		?>
	</div>
	<?php
	}
?>

	<script>
		if(!blood_searched)
		{
			document.getElementById('blood_result_panel').style.display = 'none';
		}
		else if(NoUsersFound)
		{
			document.getElementById('bst').style.display = 'block';
			document.getElementById('blood_table_searched').style.display = 'none';
		}
		function hidePopup()
		{
			document.getElementById('popup').style.display = 'none';
			document.getElementById('overlay').style.display = 'none';
		}
		var checkboxes = document.querySelectorAll('#blood_table_searched input[type="checkbox"]');
		for (var i = 0; i < checkboxes.length; i++) {
		    checkboxes[i].addEventListener('change', function(event) {
		    	// console.log(event.target);
		        checkboxChangeEvent();
		    });
		}
		var checked = localStorage.getItem('checked');
		// console.log(checked);
		if(checked)
		{
			var checked_values = checked.split("&");
			for(var i=0;i<checked_values.length;++i){
				if(checked_values[i].length)
				{
					checkboxes = document.querySelectorAll('#blood_table_searched input[type="checkbox"]');
					 for (var j = 0; j < checkboxes.length; j++) {
					    if(checkboxes[j].value == checked_values[i])
					    {
					    	checkboxes[j].checked = true;
					    }
					}
				}
			}
			document.getElementById('sn').disabled = false;
			document.getElementById('sn').style.backgroundColor = 'green';
		}
		function checkboxChangeEvent()
		{
			var checked = 0;
			checkboxes = document.querySelectorAll('#blood_table_searched input[type="checkbox"]');
			for (var i = 0; i < checkboxes.length; i++) {
				if(checkboxes[i].checked){
					checked++;
				}
			}
			if(checked > 0)
			{
				document.getElementById('sn').disabled = false;
				document.getElementById('sn').style.backgroundColor = 'green';
			}
			else{
				document.getElementById('sn').disabled = true;
				document.getElementById('sn').style.backgroundColor = 'grey';
			}
		}

		function openNav(el) {
    document.getElementById("mySidenav"+el).style.width = "100%";
}

/* Close/hide the sidenav */
function closeNav(el) {
    document.getElementById("mySidenav"+el).style.width = "0";
}
	</script>
</div>	
