
<?php
  include_once UTILITY.'class.util.inc';
  include_once MODULES_BLOOD.'bao/class.bloodbao.inc';
  
  $result=array();
  $blood = new bloodBAO();
  $search_blood=null;
  $notification=null;
  $notification_status=false;
 // $_SESSION[$_POST['txtsearch']]=$_POST['txtsearch'];
  if(isset($_POST['select_blood']))
  {
  	 $search_blood=$_POST['select_blood'];
     $_SESSION['blood']=$_POST['select_blood'];
     echo "<script>var blood_searched = true;</script>";
  }
  else if(isset($_GET['notification']))
  {
    $search_blood=$_SESSION['blood'];
    $notification= $_GET['notification'];
  }
  else
  {
  	 $search_blood=null;
  	 echo "<script>var blood_searched = false;</script>";
  }

  // send notifications to all selected
  ?>
  <script>
  			localStorage.clear();
  			<?php
		  		if(isset($_POST['send_note']))
			  	{
			  		$selected_users = "";
			  		foreach ($_POST['selected_users'] as $selected_user) {
			  			$blood->sendnotificationBAO($selected_user,$_POST['ntext']);
			  			$selected_users	= $selected_users."&".$selected_user;
			  		}
			  		$notification_status = true;
  				?>
  				var checkboxData = "<?php echo $selected_users; ?>";
  				localStorage.setItem('checked',checkboxData);
  				alert('Notification Successfully Sent !!!');
  			<?php }
  			else if(isset($_POST['cancel_note']))
  			{
  				$selected_users = "";
		  		foreach ($_POST['selected_users'] as $selected_user) {
		  			//$blood->sendnotificationBAO($selected_user,$_POST['ntext']);
		  			$selected_users	= $selected_users."&".$selected_user;
		  		}
		  		$notification_status = false;
		  		?>
		  		var checkboxData = "<?php echo $selected_users; ?>";
  				localStorage.setItem('checked',checkboxData);
		  		<?php
  			}
  			?>
  </script>
<?php

  if(isset($_POST['text']))
  {
  	 $notification_text=$_POST['text'];

    // $_SESSION['blood']=$_POST['txtsearch'];
  }
 // echo $search_blood;
  $result=$blood->bloodSearchBAO($search_blood);

  
?>