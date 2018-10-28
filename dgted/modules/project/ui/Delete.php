<?php
ob_start();
session_start();
include_once 'connect.php';




  
            //$id=mysqli_real_escape_string($connection,$_GET['id']);
 


 if(isset($_GET['id'])!='')
  {

  $id=mysqli_real_escape_string($connection,$_GET['id']);
  
  
 $delete=mysqli_query($connection,"DELETE FROM tbl_project WHERE ID='$id'" );
  
  if($delete)
  {
      $msg_success="Successfully Deleted Data!!";
      echo "<script type='text/javascript'>alert('$msg_success');</script>";
    
  }
  else
  {
     $errormsg="Something went wrong, Try again";
      echo "<script type='text/javascript'>alert('$errormsg');</script>";
  }
  }


    header('location:Upload.php');
    
?>
 
   