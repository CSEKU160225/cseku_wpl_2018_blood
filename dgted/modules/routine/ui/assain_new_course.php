<!DOCTYPE html>
<html lang="en">
<head>
  <title>Assain New Course</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/bootstrap.min.css">
  <link rel="stylesheet" href="css/routine.css" type="text/css">
  <script src="js/jquery.min.js"></script>
</head>
<body>

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">Routine Maker</a>
    </div>
    <ul class="nav navbar-nav">
      <li><a href="#">Home</a></li>
      <li><a href="insertCourse.php">Insert Course</a></li>
      <li><a href="insertTeacher.php">Insert Teacher</a></li>
      <li><a href="timeSlot.php">Time Slot</a></li>
	    <li  class="active"><a href="generateRoutine.php">Generate Routine</a></li>
    </ul>
  </div>
</nav>
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
$result = mysqli_query($conn,"SELECT * FROM tbl_course");
 $result = mysqli_fetch_all($result,MYSQLI_ASSOC);
?>
<div class="container">
  <h2></h2>
  <form class="form-horizontal">
    
	
	<div class ="form-group" >
	<label class="control-label col-sm-2" for="pwd">Course Title:</label>
	<div class="col-sm-10">          

    <select name = "course">
    <?php
    foreach ($result as $value) {
      ?>
       <option><?php echo $value['Title']; ?></option>
    <?php } ?>
    </select>  
      </div>
	</div>
	
    <div class="form-group">        
      <div class="col-sm-offset-2 col-sm-10">
        <button type="submit" class="btn btn-primary" href="generateRoutine.php">Submit</button>
      </div>
    </div>
	 
  
  </form>
</div>
  

</body>
</html>
