
<?php 

	$servername = "localhost";
	$username = "root";
	$password = "";
	$dbname = "cseku_wpl_2017_education";

	//connection
	$connection = mysqli_connect($servername,$username,$password,$dbname);

	//check connection
	if(!$connection)
	{
		die("Connection Failed :".mysqli_connect_error());
	}	
	

   function getGUID(){
	    if (function_exists('com_create_guid')){
	        return com_create_guid();
	    }else{
	        mt_srand((double)microtime()*10000);//optional for php 4.2.0 and up.
	        $charid = strtoupper(md5(uniqid(rand(), true)));
	        $hyphen = chr(45);// "-"
	        $uuid = chr(123)// "{"
	            .substr($charid, 0, 8).$hyphen
	            .substr($charid, 8, 4).$hyphen
	            .substr($charid,12, 4).$hyphen
	            .substr($charid,16, 4).$hyphen
	            .substr($charid,20,12)
	            .chr(125);// "}"
	        return $uuid;
	    }
	}
?>