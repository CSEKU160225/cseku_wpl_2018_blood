<?php 
	include_once UTILITY.'class.util.inc';
	include_once MODULES_BLOOD.'dao/class.blood_notificationdao.inc';

	class notificationBao{
		private $NOTIFICATIONS;
		public function __construct() {
			$this->NOTIFICATIONS = new notificationDao();
		}

		public function getSent(){
			return $this->NOTIFICATIONS->getSentNotifications();
		}

		public function getReceived(){
			return $this->NOTIFICATIONS->getReceivedNotifications();
		}

		public function updateAcceptStatus($notificationID, $status_message) {
			return $this->NOTIFICATIONS->updateAcceptStatus($notificationID, $status_message);
		}

		public function updateRejectStatus($notificationID) {
			return $this->NOTIFICATIONS->updateRejectStatus($notificationID);
		}		
	}
?>