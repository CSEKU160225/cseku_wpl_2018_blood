<?php
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
?>
<?php

$sql = "SELECT * FROM tbl_course_type";
$result = mysqli_query($conn, $sql);
?>

<?php

$sql = "SELECT * FROM tbl_discipline";
$result2 = mysqli_query($conn, $sql);
?>


<!DOCTYPE html>
<html lang="en">
<head>
  <title>Insert Course</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <!--<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>-->
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
    
      <li class="active"><a href="insertCourse.php">Insert Course</a></li>
      <li><a href="insertTeacher.php">Insert Teacher</a></li>
      <li><a href="generateRoutine.php">Generate Routine</a></li>
    </ul>
  </div>
</nav>
  
<div class="container">
  <h2></h2>
  <form class="form-horizontal" action = "process.php" method="post">
    <div class="form-group">
      <label class="control-label col-sm-2" for="email">Course Title:</label>
      <div class="col-sm-10">
        <input type="text" class="form-control" name = "CourseTitle" id="email" placeholder="Enter Course Name">
      </div>
    </div>
    <div class="form-group">
      <label class="control-label col-sm-2" for="courseNo">Course No :</label>
      <div class="col-sm-10">
        <input type="text" class="form-control" name="courseNo" id="courseNo" placeholder="Enter Course No">
      </div>
    </div>
    <div class="form-group">
      <label class="control-label col-sm-2" for="pwd">Credit:</label>
      <div class="col-sm-10">          
        <input type="text" class="form-control" name = "CourseCredit" id="pwd" placeholder="Enter Credit">
      </div>
    </div>
	<div class ="form-group" >
	<label class="control-label col-sm-2" for="pwd">Course Type:</label>
	<div class="col-sm-10">          
      <select name = "CourseType">
          <?php while($row = mysqli_fetch_array($result)):;?>
          <option><?php echo $row[1]; ?></option>
          <?php endwhile; ?>
     </select>
  </div>
      </div>
      <div class ="form-group" >
  <label class="control-label col-sm-2" for="pwd">Discipline:</label>
    <select name = "DisciplineId">
          <?php while($row = mysqli_fetch_array($result2)):;?>
          <option><?php echo $row[1]; ?></option>
          <?php endwhile; ?>
     </select>  
  </div>
	</div>
	
      </div>
	</div>
	
    <div class="form-group">        
      <div class="col-sm-offset-2 col-sm-10">
        <button type="submit" class="btn btn-primary">Submit</button>
      </div>
    </div>
	 
  
  </form>
</div>
  

</body>
</html>
