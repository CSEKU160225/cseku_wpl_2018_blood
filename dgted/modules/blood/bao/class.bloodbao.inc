<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_BLOOD.'dao/class.blooddao.inc';

 class bloodBAO{

     private $blood=array();

     public function bloodSearchBAO($blood)
     {
     	$blood_DAO=new bloodDAO();
     	$this->blood=$blood_DAO->bloodSearchDAO($blood);
     	return $this->blood;
     }

     public function sendnotificationBAO($notification,$text)
     {
     	$notification_DAO=new bloodDAO();
     	$notification_DAO->notificationDAO($notification,$text);
     }
}

?>
 