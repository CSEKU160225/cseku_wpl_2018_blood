<?php

include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.blood.inc';
include_once UTILITY.'class.util.inc';

class bloodDAO{
	
	private $BLOOD;
	private $DB;
  private $current_user;

	public function __construct(){
        
        
		$this->_DB = DBUtil::getInstance();

	}

	public function bloodSearchDAO($blood){

       $BloodList = array();
       $expdate=date('Y-m-d H:i:s');
       $globalUser = $_SESSION["globalUser"];
       $this->current_user = $globalUser->getID();

		$this->_DB->doQuery("SELECT * FROM ums_user_details WHERE blood_group='$blood'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
		    	$row = $rows[$i];
			    $id=$row['ID'];
          if($this->current_user!=$id){
            $this->BLOOD=new Blood();
            $this->BLOOD->set_phone($row['MobilePhone']);

            $dis_id;


            $this->_DB->doQuery("SELECT * FROM blood WHERE userID='$id'");
           $rows2 = $this->_DB->getAllRows();
            for($j = 0; $j < sizeof($rows2); $j++) {
               $row2 = $rows2[$j];
               $expdate=$row2['expire_date'];
              }

              $pdate=date('Y-m-d H:i:s');

              $this->_DB->doQuery("SELECT * FROM ums_user WHERE ID='$id'");
              $rows1 = $this->_DB->getAllRows();
              foreach ($rows1 as $val) {

                $dis_id = $val['DisciplineID'];
                
                $this->BLOOD->set_user_id($val['ID']);
                $this->BLOOD->set_first_name($val['FirstName']);
                $this->BLOOD->set_middle_name($val['MiddleName']);
                $this->BLOOD->set_last_name($val['LastName']);
                

            }

            $sql = "SELECT * FROM `ums_discipline` WHERE `ID` = '$dis_id'";
            $this->_DB->doQuery($sql);
            $resultx = $this->_DB->getTopRow();
            $this->BLOOD->set_discipline($resultx['Name']); 

      //echo $id;

      $sql = "SELECT * FROM `blood` WHERE `blood`.`userID` = '$id' ORDER BY `blood`.`blood_donate_date` DESC";
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


      $BloodList[] = $this->BLOOD;

          }


    }
    return $BloodList;
  }

  public function notificationDAO($notification,$text){
  //	echo $notification;
    $date = date('Y-m-d H:i:s', time());
    echo $date;
    $globalUser = $_SESSION["globalUser"];
    $sender = $globalUser->getID();
    $swl="INSERT INTO notification_for_blood (fromuserId,touserId,notification,read_unread,ndate) VALUES ('$sender','$notification','$text',0,NOW());";
  	$this->_DB->doQuery($swl);

  }
}


?>