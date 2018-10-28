<?php
include_once 'path.php';
include_once UTILITY.'class.xml.inc';
//including the common file
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.result.inc';
include_once COMMON.'class.common.user.inc';
include_once COMMON.'class.common.club.inc';

//current template path
$template_link= TEMPLATE.'basic/';



ob_start(); //converts php output to a buffer and later publish it

// start session always
if (session_status() == PHP_SESSION_NONE) {
    session_start();
}

//browser request
$_URI = $_SERVER['REQUEST_URI'];

//get the previous link if it is a php file request
if(isset($_SESSION['globalPage']) && strpos($_URI, '.php')!==false){
    $_SESSION['previousPage']=$_SESSION['globalPage'];
    $_SESSION['globalPage']=$_URI;
}
elseif (strpos($_URI, '.php')!==false) {
    $_SESSION['globalPage']=$_URI; //store current php link in the sessions
}




//finding the page description such as login.php, index.php, user.php, home.php etc. 
$page = unparse_url(parse_url($_URI));

//////// check whether current user has permission to access  the browser entered link
//if the page is not accessible by everyone 
if(isset($_SESSION["globalPermission"])&& !every_one_has_access($page) ){

   // or the page access permission is not given to current user
   if(userHasAccessToLink($page)==false)  
        $page=PageUtil::$ERROR;
   
}

/////////////////

if(isset($page)){
    //TODO: check whether middleware application is active
    //apply middleware 
    $page = apply_middleware($page);
}

// adding menu code here
include_once $template_link.'menu.inc'; 

?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Digital University</title>
        <link rel="stylesheet" href="resources/css/bootstrap.min.css">
        <link rel="stylesheet" href="resources/css/style.css" type="text/css" />        
        <script src="resources/js/jquery.min.js"></script>
        <script src="resources/js/bootstrap.min.js"></script>
        <script src="resources/js/myscript.js"></script>
        <script src="resources/js/question_js_2.js" rel="script"></script>                            
    </head>

<body>

<div class="container-fluid" >
    <div class="row">
        <div class="col-sm-12">
        <div id="menu" style="background-color:LightSteelBlue">
            <?php 
                //do not show the menu for pages like login, new user, forget password, print regs etc
                if(!no_layout_page($page))
                    echo print_top_menu($globalMenu,$logoutMenu);
                    
                
            ?>
        </div>
        <div id="header">
            <?php 

                //do not show the header for login page
                if(!no_layout_page($page))
                    include $template_link.'header.inc'; 
                
            ?>        
        </div>        
      
        <div id="body" style="background-color:AliceBlue"> 
            <?php 
                include $template_link.'body.inc'; 

            ?>	                    
        </div>

        <div id="footer" style="background-color:LightSteelBlue">

        	<?php 
                if(strcasecmp($page, PageUtil::$PRINT_REGISTRATION)!=0){

        		      include $template_link.'footer.inc'; 

                }

        	?>
        </div>  
        </div>   
    </div>      
</div>    
</body>
</html>