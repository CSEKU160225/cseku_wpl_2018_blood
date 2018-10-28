<?php
//menu based on the permission value from the globaluser variable

$globalUser='';
$globalPermission='';
$globalMenu ='';
$globalPage ='';
$logoutMenu='';

if (session_status() == PHP_SESSION_NONE) {
    session_start();
}

//if there is one logged in user
if (isset($_SESSION["globalUser"])){
	//retreving the logged user from the session 
	$globalUser = $_SESSION["globalUser"];


	if (isset($_SESSION["globalPermission"])){	
		//retreiveing the permission of the user from the session
		$globalPermission = $_SESSION["globalPermission"]; 
	}

	if (isset($_SESSION["globalMenu"])){	
		//retreving the total menu setup of the sysetm that is initiated
		$globalMenu =  $_SESSION["globalMenu"];
	  	
	}

	// generating logout menu part
	$logoutMenu = build_top_logout_menu($globalUser);

}

if (isset($_SESSION["globalPage"])){	
	//retreving the current page
	$globalPage =  $_SESSION["globalPage"];
  	
}


//print the top menu
function print_top_menu($globalMenu,$logoutMenu)
{
	$menu_content='';

	
	if(isset($globalMenu)){
		
		//buiding full menu layout, first part menu, next part user logout menu
		$menu_content = 	'<div class="dropdown"><div class="row">';
		$menu_content = 	$menu_content.'<div class="col-sm-10">';
		$menu_content = 	$menu_content.build_top_nav_menu($globalMenu);
		$menu_content = 	$menu_content.'</div>';
		$menu_content = 	$menu_content.'<div style="text-align:right;" class="col-sm-2">'.$logoutMenu;
		$menu_content = 	$menu_content.'</div>';
		$menu_content = 	$menu_content.'</div></div>';
	}

	return $menu_content;
}

//logout menu part
function build_top_logout_menu($CurrentUser){

   $logout_content = '<button class="btn btn-default  dropdown-toggle" type="button" data-toggle="dropdown">'.
   					 $CurrentUser->getFullName().'<span class="caret"></span></button>';
   $logout_content = $logout_content.'<ul class="dropdown-menu">'; 
   $logout_content = $logout_content.'<li><a tabindex="-1" href="home.php">Home</a></li>';
   $logout_content = $logout_content.'<li><a tabindex="-1" href="user_details.php">User Details</a></li>';
   $logout_content = $logout_content.'<li><a tabindex="-1" href="forgot_password.php">Forgot Password</a></li>';
   $logout_content = $logout_content.'<li><a tabindex="-1" href="logout.php">Log Out</a></li>';

   $logout_content = $logout_content.'</ul>'; 

   return $logout_content;					 
}


//build the the top menu using bootstrap css based on permission and menu visibility
function build_top_nav_menu($globalMenu){

	$superLayer = '<div class="row">';

	for ($i=0; $i < sizeof($globalMenu) ; $i++) {

		// if the first layer is visible then go inside -- build table row by row for the category
		if($globalMenu[$i]->isVisible()){ 
			
 			//$firstLayer  = '<div class="col-sm-'.(12/sizeof($globalMenu)).'">';
 			$firstLayer  = '<div class="col-sm-2">';
    		$firstLayer  =  $firstLayer.'<button class="dropdown-toggle btn btn-default btn-block" type="button" data-toggle="dropdown">'.$globalMenu[$i]->getTitle().'<span class="caret"></span></button>';
    		$firstLayer  =  $firstLayer.'<ul class="dropdown-menu">';

			for ($j=0; $j <sizeof($globalMenu[$i]->_Child) ; $j++) {	

				//if the second layer is visible go inside -- build table row by row
				if($globalMenu[$i]->_Child[$j]->isVisible()){

					if(sizeof($globalMenu[$i]->_Child[$j]->_Child)>0){

						$secondLayer  =  '<li class="dropdown-submenu">
					        <a class="test" tabindex="-1" href="#">'.$globalMenu[$i]->_Child[$j]->getTitle().
					        '<span class="caret"></span></a>';
					    $secondLayer = $secondLayer.'<ul class="dropdown-menu">';    	

						for ($k=0; $k <sizeof($globalMenu[$i]->_Child[$j]->_Child) ; $k++) {

						//if the third layer is visible -- build table column by column
							if($globalMenu[$i]->_Child[$j]->_Child[$k]->isVisible()){

							$thirdLayer  = '<li><a tabindex="-1" href="'.
											$globalMenu[$i]->_Child[$j]->_Child[$k]->getLink().'">'.
											$globalMenu[$i]->_Child[$j]->_Child[$k]->getTitle().
											'</a></li>' ;

							$secondLayer  = $secondLayer  . $thirdLayer;
							
							}
						}	

						$secondLayer = $secondLayer.'</ul></li>';
					}	
					else{
						$secondLayer  = '<li><a tabindex="-1" href="#">'.$globalMenu[$i]->_Child[$j]->getTitle().
									'</a></li>';
	  				}
									
				$firstLayer  = $firstLayer  . $secondLayer;
				}
			}
			

		$firstLayer = $firstLayer . '<ul></div>';
		$superLayer = $superLayer . $firstLayer;	
		}
	}

	$superLayer = $superLayer . '</div>';

	return $superLayer;


}

				
?>