<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_CLUB.'bao/class.clubbao.inc';
include_once MODULES_CLUB.'bao/class.modulebao.inc';

$_ClubBAO = new ClubBAO();
$_ModuleBAO = new ModuleBAO();
$Club = new Club();


  if(isset($_GET['club'])){             

    $Club = new Club(); 
    $Club->setID($_GET['club']);  

    //reading the club details
    $Club = $_ClubBAO->readClub($Club)->getResultObject();        

    //reading all the modules of the club
	$ModuleList = $_ModuleBAO->getAllModule($Club)->getResultObject();
    
  }


//$_Log->log(LogUtil::$DEBUG," exit blade.club.inc");

?>