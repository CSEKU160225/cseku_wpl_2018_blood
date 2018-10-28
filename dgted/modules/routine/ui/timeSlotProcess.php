<!DOCTYPE html>
<html>
<head>
<title>Online Discussion Forum</title>
</head>
<body>
<h1>Online Discussion Forum</h1>


</body>
</html>


<?php
//include_once 'insertCourse.php';
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "cseku_wpl_2017_education";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
//$sql = "SELECT * FROM tbl_course_type";
//$result = mysqli_query($conn, $sql);
?>
<?php
//create a variable

if($_SERVER['REQUEST_METHOD']=='POST'){
	$time1 = $_POST['time1'];
	$time2 = $_POST['time2'];
	$time3 = $_POST['time3'];
	$time4 = $_POST['time4'];
	$time5 = $_POST['time5'];
	$time6 = $_POST['time6'];
	$time7 = $_POST['time7'];
	$time8 = $_POST['time8'];
	$time9 = $_POST['time9'];

	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time1' WHERE ID='1'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time2' WHERE ID='2'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time3' WHERE ID='3'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time4' WHERE ID='4'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time5' WHERE ID='5'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time6' WHERE ID='6'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time7' WHERE ID='7'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time8' WHERE ID='8'");
	mysqli_query($conn,"UPDATE tbl_routine_time SET Name='$time9' WHERE ID='9'");

	
    header('Location: timeSlot.php');
    exit();
}


?>