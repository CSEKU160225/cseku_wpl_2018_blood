<?php 
	include_once 'blade/view.blood_notification.blade.inc'; 
?>
<style>
	/* Style the tab */
	.tab {
	    overflow: hidden;
	    border: 1px solid #ccc;
	    background-color: #f1f1f1;
	}

	/* Style the buttons that are used to open the tab content */
	.tab button {
	    background-color: inherit;
	    float: left;
	    border: none;
	    outline: none;
	    cursor: pointer;
	    padding: 14px 16px;
	    transition: 0.3s;
	}

	/* Change background color of buttons on hover */
	.tab button:hover {
	    background-color: #ddd;
	}

	/* Create an active/current tablink class */
	.tab button.active {
	    background-color: #ccc;
	}

	/* Style the tab content */
	.tabcontent {
	    display: none;
	    padding: 6px 12px;
	    border: 1px solid #ccc;
	    border-top: none;
	}

	.notifications{
		max-width: 800px;
		margin: 0 auto;
	}

	li{
		list-style : none;
		padding:5px;
		cursor:pointer;
		border-bottom : 1px solid black;
	}
	.unread{
		background-color:#E5EAF2;
	}

	.saf:after{
		clear:both;
	}

	.overlay {
	   display:none;   
	   position:fixed;  
	   left:0px;        
	   top:0px;         
	   width:100%;      
	   height:100%;    
	   background:#000; 
	   opacity:0.5;     
	   z-index:99999;  
	}

	.popup {
	   display:none;
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
	   padding-left:40px;   
	}
	#bt{
		height:50px; 
		width:60px; 
		margin: -20px -50px; 
		position:absolute;
		top:90%; 
		left:50%;
		background-color:#11111;
	}
	.accept_color {
		color: green;
	}
	.reject_color {
		color: red;
	}
	.acceptModal {
		position: absolute;
		top: 50%;
		left: 50%;
		transform: translate(-50%, -50%);
		padding: 50px;
		border: 1px solid #666;
		background: #EEE;
		display: none;
	}
	.acceptModal  > textarea {
		width: 500px;
		height: 250px;
		margin: 10px;
		padding: 10px;
	}
	.acceptModal  > button {
		margin-bottom: 10px;
	}
</style>

<div class="panel panel-default">
    <div class="panel-heading">Notifications</div>
    <div class="panel-body">
    	<div class="notifications">
    		<div class="tab" style="text-align: center;">
			  <button class="tablinks" onclick="openCity(event, 'received')" id="defaultOpen">Received Notifications</button>
			  <button class="tablinks" onclick="openCity(event, 'sent')" id="another">Blood Request</button>
			</div>

			<!-- Tab content -->
			<div id="received" class="tabcontent">
				<ul>
			<?php
			  	$idx = 0;
			  	foreach($received_notice as $val){
					echo '<li onclick="showPopup(this);" id="s'.$idx.'" class="'.($val->get_notification_read_unread() == 0 ? "unread" : "read").'" >';
			?>

			<div id="<?php echo "rs".$idx; ?>" class="overlay"></div>
					<div class="popup">
						<h4 style="">Name : <?php  echo $val->get_first_name()." ".$val->get_middle_name()." ".$val->get_last_name(); ?></h4>
							<p style="">Notification date : <?php  $dt =  $val->get_notification_date();
						$ndt = strtotime($dt);
						// var_dump($ndt);
						$nw = date('D., M jS, Y g:i A', $ndt);
						echo $nw;  ?></p>
							<p style="">Notification Message : <?php echo $val->get_notification_text(); ?></p>
							<form action="" method="POST">
								<input type="hidden" name="id" value="<?php echo $val->get_notification_id(); ?>">
								<input style=color:green;padding:5px; type="button" name="accept" value="Accept" onclick="send_msg_popup(this)">
								<input style=color:red;padding:5px; type="submit" name="reject" value="Reject">
								<button type="button" id="bt"onclick="hidePopup(this);">Close</button>
								<div class="acceptModal">
									<textarea name="status_msg" placeholder="type your message"></textarea> 
									<button style="color:green;height:40px;width:90px;position:absolute;left:10%;" type="submit" name="acpt_send_msg">Send</button>
									<button style="color:red;height:40px;width:90px;position:absolute;left:25%;"type="button" onclick="hide_msg_popup(this);">Cancel</button>	
								</div>
							</form>
						
					</div>
				<?php
					if ($val->get_notification_status() == 1) {
						echo '<div class="accept_color">';
					} else if ($val->get_notification_status() == 2) {
						echo '<div class="reject_color">';
					} else {
						echo '<div class="">';
					} 
				?>
					<div class="sasf" style="position:relative;">
						<h4 style=""><?php  echo $val->get_first_name()." ".$val->get_middle_name()." ".$val->get_last_name(); ?></h4>
						<p><?php 
						
						$dt =  $val->get_notification_date();
						$ndt = strtotime($dt);
						// var_dump($ndt);
						$nw = date('D., M jS, Y g:i A', $ndt);
						echo $nw;
						
						?></p>
						<p><?php $p= $val->get_notification_text();
						    $s=substr($p,0,30); 
						    echo $s.".....";?></p>
					</div>
				<?php
					echo '</div>';
				?>
					
					<?php
					echo "</li>";
					$idx = $idx + 1;
				}
			  ?>
			</ul>
			</div>

			<div id="sent" class="tabcontent">
			  <?php
			  	$idx = 0;
			  	foreach($sent_notice as $val){
					echo '<li onclick="showPopup(this);"  id="r'.$idx.'" class="'.($val->get_notification_read_unread() == 0 ? "unread" : "read").'" >';
					?>

				<?php
					if ($val->get_notification_status() == 1) {
						echo '<div class="accept_color">';
					} else if ($val->get_notification_status() == 2) {
						echo '<div class="reject_color">';
					} else {
						echo '<div class="">';
					} 
				?>
					
					<div class="sasf" style="position:relative;">
						<h4 style=""><?php  echo $val->get_first_name()." ".$val->get_middle_name()." ".$val->get_last_name(); ?></h4>
						<p style=""><?php $dt =  $val->get_notification_date();
						$ndt = strtotime($dt);
						// var_dump($ndt);
						$nw = date('D., M jS, Y g:i A', $ndt);
						echo $nw; ?></p>
						<p style=""> Notification Message : <?php $p= $val->get_status_text();
							$s=substr($p,0,30);
							if($val->get_notification_status() == 1)
							echo $s.".........";
							else
							echo $s;?></p>
					</div>
				<?php
					echo '</div>';
				?>
					<div id="<?php echo "r".$idx; ?>" class="overlay"></div>
					<div class="popup">
						<h4 style="">Name : <?php  echo $val->get_first_name()." ".$val->get_middle_name()." ".$val->get_last_name(); ?></h4>
						    <p> Message Status Date : <?php  $dt =  $val->get_notification_date();
						$ndt = strtotime($dt);
						// var_dump($ndt);
						$nw = date('D., M jS, Y g:i A', $ndt);
						echo $nw; ?></p>
						    <p> Notification Message : <?php echo $val->get_status_text();?></p>
							<p> Notification Status : <?php  
							//echo $val->get_notification_status() . '<br>';
							if($val->get_notification_status() == 1){
								echo "Accepted";
							}
							else if($val->get_notification_status() == 2){
								echo "Rejected";
							}
							else{
								echo "Hanging";
							}
							;?></p>

						<p id="myTag"></p>
						<button id="bt" onclick="hidePopup(this);">Close</button>
					</div>
					<?php
					echo "</li>";

					?>

					
					<?php

					$idx = $idx + 1;
				}
			  ?>
			</div>
    	</div>
    </div>
</div>

<script>
	function openCity(evt, cityName) {
    // Declare all variables
    var i, tabcontent, tablinks;

    // Get all elements with class="tabcontent" and hide them
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
        tabcontent[i].style.display = "none";
    }

    // Get all elements with class="tablinks" and remove the class "active"
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
        tablinks[i].className = tablinks[i].className.replace(" active", "");
    }

	// Show the current tab, and add an "active" class to the button that opened the tab
	if(cityName == "sent"){
		localStorage.setItem('saved','another');
	}
	else{
		localStorage.setItem('saved','defaultOpen');
	}
    document.getElementById(cityName).style.display = "block";
    evt.currentTarget.className += " active";
}
if(localStorage.getItem('saved'))
document.getElementById(localStorage.getItem('saved')).click();
else
document.getElementById("defaultOpen").click();

function hidePopup(el){
	el = el.parentNode.parentNode;
	console.log(el);
	 console.log(el.childNodes[3]);
	 console.log(el.childNodes[5]);
	el.childNodes[3].style.display = 'none';
	el.childNodes[5].style.display = 'none';
	
	var frm = document.createElement('form');
	document.body.appendChild(frm);
	frm.submit();
}

function showPopup(el){
	// console.log(el.childNodes[3]);
	// console.log(el.childNodes[5]);
	el.childNodes[3].style.display = 'block';
	el.childNodes[5].style.display = 'block';
} 

function send_msg_popup(el) {
	el = el.parentNode.lastChild.previousSibling;
	el.style.display = 'block';
}
function hide_msg_popup(el) {
	el = el.parentNode;
	el.style.display = 'none';
}
</script>