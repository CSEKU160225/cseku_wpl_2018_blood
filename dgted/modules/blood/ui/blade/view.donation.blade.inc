<?php 
	include_once MODULES_BLOOD.'bao/class.donationBAO.inc';

	$donation = new donationBAO();

	if (isset($_POST['date'])) {
			$donation->adddateBAO($_POST['date']);
	}

	$result = $donation->getAlldates();
	$avlb = $result->get_availability();
	$dates = $result->get_given_dates();

	$availability;

	if($avlb == -1 || !$avlb) $availability = "Available to Donate Blood";
	else $availability = "Available after ".$avlb." Days";
?>