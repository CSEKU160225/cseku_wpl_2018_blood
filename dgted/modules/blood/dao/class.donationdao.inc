<?php 
	include_once COMMON.'class.common.inc';
	include_once COMMON.'class.common.blood.inc';
	include_once UTILITY.'class.util.inc';

	class donationDAO{
		private $sent,$received,$current_user;
		private $DB,$BLOOD;
		public function __construct() {
			$this->_DB = DBUtil::getInstance();
			$globalUser = $_SESSION["globalUser"];
    		$this->current_user = $globalUser->getID();
		}

		public function adddateDAO($date){
			$expdate= date('Y-m-d H:i:s', strtotime($date .' +90 day'));
			$sql="INSERT INTO blood (userId,blood_donate_date,expire_date) VALUES ('$this->current_user','$date','$expdate')";
			$this->_DB->doQuery($sql);

			  }
			  
		public function allDonationDates(){
			$this->BLOOD = new Blood();
			
			$sql = "SELECT * FROM `blood` WHERE `blood`.`userID` = '$this->current_user' ORDER BY `blood`.`blood_donate_date` DESC";
			$this->_DB->doQuery($sql);
			$result = $this->_DB->getAllRows();
			
			foreach($result as $res){
				$this->BLOOD->set_given_dates($res['blood_donate_date']); 
			}
			
			if(count($result)){
				$last_date = $result[0]['blood_donate_date'];
				$cdate = date('Y-m-d');

				$datetime1 = date_create($cdate);
				$datetime2 = date_create($last_date);

				if($datetime1 < $datetime2)
				{
					$this->BLOOD->set_availability('-1');
				}
				else{
					$interval = date_diff($datetime1, $datetime2);
					$dif = $interval->format('%a');
					if($dif >= 90) $this->BLOOD->set_availability('-1');
					else $this->BLOOD->set_availability(90 - $dif);
				}
				
			}

			return $this->BLOOD;
		}
			
		}