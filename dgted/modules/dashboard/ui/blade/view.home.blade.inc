<?php

include_once COMMON.'class.common.inc'; 
//very important include in every new page before using session globaluser



$globalUser='';
$globalPermission='';
$globalMenu ='';

if (session_status() == PHP_SESSION_NONE) {
    session_start();
}


if (isset($_SESSION["globalUser"])){
	//retreving the logged user from the session 
	$globalUser = $_SESSION["globalUser"];
}

if (isset($_SESSION["globalPermission"])){	
	//retreiveing the permission from the session
	$globalPermission = $_SESSION["globalPermission"]; 
}

if (isset($_SESSION["globalMenu"])){	
	//retreving the menu setup	
	$globalMenu =  $_SESSION["globalMenu"];
  	
}


//build dashboard link access vertically
function print_dashboard_vertical($globalMenu){


	$superLayer ='<table><tr><td>Options</td></tr>';
	//going through first layer of menus
	
	for ($i=0; $i < sizeof($globalMenu) ; $i++) {

		// if the first layer is visible then go inside -- build table row by row for the category
		if($globalMenu[$i]->isVisible()){ 
		
		$firstLayer  = '<tr><td><table>';
		$firstLayer  = $firstLayer . '<tr><td>'.$globalMenu[$i]->getTitle().'</td></tr>';



			for ($j=0; $j <sizeof($globalMenu[$i]->_Child) ; $j++) {	

				//if the second layer is visible go inside -- build table row by row
				if($globalMenu[$i]->_Child[$j]->isVisible()){

				$secondLayer  = '<tr><td><table>' ;

				$secondLayer = $secondLayer . '<tr><td>'.
								$globalMenu[$i]->_Child[$j]->getTitle().
								'</td></tr>';

				$secondLayer = $secondLayer . '<tr>';				
				
				for ($k=0; $k <sizeof($globalMenu[$i]->_Child[$j]->_Child) ; $k++) {

					//if the third layer is visible -- build table column by column
					if($globalMenu[$i]->_Child[$j]->_Child[$k]->isVisible()){

					$thirdLayer  = '<td><table>' ;

					$thirdLayer = $thirdLayer . '<tr><td>'.
									$globalMenu[$i]->_Child[$j]->_Child[$k]->getTitle().
									'</td></tr>';
										
					
					$thirdLayer = $thirdLayer .'</table></td>';
					$secondLayer  = $secondLayer  . $thirdLayer;
					
					}
				}
									
				$secondLayer = $secondLayer . '</tr>';

				$secondLayer = $secondLayer .'</table></td></tr>';
				$firstLayer  = $firstLayer  . $secondLayer;
				}
			}
			

		$firstLayer = $firstLayer . '</table></td></tr>';
		$superLayer = $superLayer . $firstLayer;	
		}
	}

	$superLayer = $superLayer . '</td></tr></table>';
	
	return $superLayer;
}

// build dashboard body as a tab
function print_dashboard_body_tab($globalMenu){


	$superLayer = '<ul class="nav nav-tabs">';

	//printing the tabs
	for ($i=0; $i < sizeof($globalMenu) ; $i++) {

		// if the first layer is visible then go inside -- build table row by row for the category
		if($globalMenu[$i]->isVisible()){ 
			
			$tabID = str_replace(" ","_",$globalMenu[$i]->getTitle());
			//make the first one active		
			if($i==0){
			$superLayer = $superLayer.'<li class="active"><a data-toggle="tab" href="#'.
						$tabID.'">'.$globalMenu[$i]->getTitle().'</a></li>';
			}
			else{
			$superLayer = $superLayer.'<li><a data-toggle="tab" href="#'.
						$tabID.'">'.$globalMenu[$i]->getTitle().'</a></li>';
			}
		}				
	}

	$superLayer = $superLayer. '</ul>';

	$superLayer = $superLayer. '<div class="tab-content">';

	//printing tab contents



	for ($i=0; $i < sizeof($globalMenu) ; $i++) {

		// if the first layer is visible then go inside -- build table row by row for the category
		if($globalMenu[$i]->isVisible()){ 
			
			$tabID = str_replace(" ","_",$globalMenu[$i]->getTitle());

			if($i==0){
			$firstLayer  = '<div id="'.$tabID.'" class="tab-pane fade in active">';
			}
			else{
			$firstLayer  = '<div id="'.$tabID.'" class="tab-pane fade">';
			}
			
		

			for ($j=0; $j <sizeof($globalMenu[$i]->_Child) ; $j++) {	

				//if the second layer is visible go inside -- build table row by row
				if($globalMenu[$i]->_Child[$j]->isVisible()){

				$secondLayer  = '<div class="col-sm-3"><h4>'.$globalMenu[$i]->_Child[$j]->getTitle().'</h4>';

				$secondLayer = $secondLayer . '<div class="panel panel-default">';

				$secondLayer = $secondLayer . '<div class="panel-body">';				
				
				for ($k=0; $k <sizeof($globalMenu[$i]->_Child[$j]->_Child) ; $k++) {

					//if the third layer is visible -- build table column by column
					if($globalMenu[$i]->_Child[$j]->_Child[$k]->isVisible()){

					$thirdLayer  = '<div>' ;

					$thirdLayer = $thirdLayer.'<a href="'.
								  $globalMenu[$i]->_Child[$j]->_Child[$k]->getLink().'">'.
								  $globalMenu[$i]->_Child[$j]->_Child[$k]->getTitle().'</a>';
															
					$thirdLayer = $thirdLayer .'</div>';
					$secondLayer  = $secondLayer  . $thirdLayer;
					
					}
				}
									
				$secondLayer = $secondLayer . '</div>';

				$secondLayer = $secondLayer .'</div></div>';
				$firstLayer  = $firstLayer  . $secondLayer;
				}
			}
			

		$firstLayer = $firstLayer . '</div>';
		$superLayer = $superLayer . $firstLayer;	
		}
	}

	$superLayer = $superLayer . '</div>';

	return $superLayer;
}


function console_log( $data ){
  echo '<script>';
  echo 'console.log('. json_encode( $data ) .')';
  echo '</script>';
}




?>