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
$sql = "SELECT * FROM tbl_course_type";
$result = mysqli_query($conn, $sql);
?>
<?php
//create a variable

if(isset($_POST['courseNo'])){
$CourseNo = $_POST['courseNo'];}
if(isset($_POST['CourseTitle'])){
	$CourseTitle = $_POST['CourseTitle'];
	//echo $CourseTitle;
}
if(isset($_POST['CourseCredit'])){
$CourseCredit= $_POST['CourseCredit'];}
if(isset($_POST['CourseType'])){
$CourseType = $_POST['CourseType'];}
if(isset($_POST['DisciplineId'])){
$Discipline = $_POST['DisciplineId'];}

$ID = substr(md5(time()), 0, 10);


mysqli_query($conn,"INSERT INTO tbl_course (ID,CourseNo,Title,Credit,CourseTypeID,DisciplineID) 
						VALUES ('$ID','$CourseNo','$CourseTitle','$CourseCredit','$CourseType','$Discipline')");
if(mysqli_affected_rows($conn) > 0)
{	
	echo "<p>Data Added!!</p>";
	#echo "<a href = \"home.php\">Home</a>";
}
else{
	echo "Data Not Added<br />";
	echo mysqli_error($conn);
}
?>