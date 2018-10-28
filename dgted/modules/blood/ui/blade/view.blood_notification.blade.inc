<?php 
	include_once MODULES_BLOOD.'bao/class.blood_notificationbao.inc';

	$notice = new notificationBao();


	if (isset($_POST['acpt_send_msg'])) {
		if (isset($_POST['id']) && isset($_POST['status_msg'])) {
			$notice->updateAcceptStatus($_POST['id'], $_POST['status_msg']);
		}
	}

	if (isset($_POST['reject'])) {
		if (isset($_POST['id'])) {
			$notice->updateRejectStatus($_POST['id']);
		}
	}
	
	$sent_notice = $notice->getSent();
	$received_notice = $notice->getReceived();
?>