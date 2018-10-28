<?php 
	include_once COMMON.'class.common.inc';
	include_once COMMON.'class.common.blood.inc';
	include_once UTILITY.'class.util.inc';

	class notificationDao{
		private $sent,$received,$current_user;
		private $DB,$BLOOD;
		public function __construct() {
			$this->_DB = DBUtil::getInstance();
			$globalUser = $_SESSION["globalUser"];
    		$this->current_user = $globalUser->getID();
		}

		public function getSentNotifications(){
			$sql = "SELECT * FROM `notification_for_blood`  WHERE `notification_for_blood`.`fromuserID` = '$this->current_user' ORDER BY `notification_for_blood`.`ndate` DESC";
			$this->_DB->doQuery($sql);
			$rows = $this->_DB->getAllRows();
			$sent = array();
			for($i = 0; $i < sizeof($rows); $i++) {
				$this->BLOOD=new Blood();
				$row = $rows[$i];
				$id=$row['touserID'];

				$this->_DB->doQuery("SELECT * FROM ums_user WHERE ID='$id'");
	            $rows1 = $this->_DB->getAllRows();
	            foreach ($rows1 as $val) {
	            	$this->BLOOD->set_user_id($val['ID']);
	            	$this->BLOOD->set_first_name($val['FirstName']);
	            	$this->BLOOD->set_middle_name($val['MiddleName']);
	            	$this->BLOOD->set_last_name($val['LastName']);
	            }
	            $this->BLOOD->set_notification_text($row['notification']);
	            $this->BLOOD->set_status_text($row['status_message']);
	            $this->BLOOD->set_notification_date($row['ndate']);
	            $this->BLOOD->set_status_date($row['status_date']);
	            $this->BLOOD->set_notification_read_unread($row['read_unread']);
	            $this->BLOOD->set_notification_status($row['status']);

	            $sent[] = $this->BLOOD;
	  		}
			return $sent;
		}

		public function getReceivedNotifications(){
			$sql = "SELECT * FROM `notification_for_blood`  WHERE `notification_for_blood`.`touserID` = '$this->current_user' ORDER BY `notification_for_blood`.`ndate` DESC";
			$this->_DB->doQuery($sql);
			$rows = $this->_DB->getAllRows();
			$received = array();
			for($i = 0; $i < sizeof($rows); $i++) {
				$this->BLOOD=new Blood();
				$row = $rows[$i];
				$id=$row['fromuserID'];

				$this->_DB->doQuery("SELECT * FROM ums_user WHERE ID='$id'");
	            $rows1 = $this->_DB->getAllRows();
	            foreach ($rows1 as $val) {
	            	$this->BLOOD->set_user_id($val['ID']);
	            	$this->BLOOD->set_first_name($val['FirstName']);
	            	$this->BLOOD->set_middle_name($val['MiddleName']);
	            	$this->BLOOD->set_last_name($val['LastName']);
	            }
	            $this->BLOOD->set_notification_id($row['notificationID']);
	            $this->BLOOD->set_notification_text($row['notification']);
	            $this->BLOOD->set_status_text($row['status_message']);
	            $this->BLOOD->set_notification_date($row['ndate']);
	            $this->BLOOD->set_status_date($row['status_date']);
	            $this->BLOOD->set_notification_read_unread($row['read_unread']);
	            $this->BLOOD->set_notification_status($row['status']);


	            $received[] = $this->BLOOD;
	  		}
			return $received;
		}

		public function updateAcceptStatus($notificationID, $status_message) {
			$date= date('Y-m-d h:i:s');
			echo $date;
			$sql = "UPDATE `notification_for_blood` SET `status` = 1, `status_message` = '$status_message', `status_date` = NOW() WHERE `notificationID` = '$notificationID'";
			$sql = $this->_DB->doQuery($sql);
			return $sql;
		}

		public function updateRejectStatus($notificationID) {
			$date= date('Y-m-d h:i:s');
			$sql = "UPDATE `notification_for_blood` SET `status` = 2,`status_date` = NOW() WHERE `notificationID` = '$notificationID'";
			$sql = $this->_DB->doQuery($sql);
			return $sql;
		}
	}
?>