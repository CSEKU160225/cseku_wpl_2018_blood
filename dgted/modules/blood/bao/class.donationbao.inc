<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_BLOOD.'dao/class.donationdao.inc';

 class donationBAO{


     public function adddateBAO($blood)
     {
     	$donation=new donationDAO();
     	$donation->adddateDAO($blood);

     }

     public function getAlldates(){
         $donation = new donationDAO();
         return $donation->allDonationDates();
     }

}

?>
