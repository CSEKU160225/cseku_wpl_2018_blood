<!DOCTYPE html>
<html lang="en">
<head>
  <title>Time Slot</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>
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
$result = mysqli_query($conn,"SELECT * FROM tbl_routine_time");
 $result = mysqli_fetch_all($result,MYSQLI_ASSOC);
?>
<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">Routine Maker</a>
    </div>
    <ul class="nav navbar-nav">
      <li><a href="#">Home</a></li>
      <li><a href="insertCourse.php">Insert Course</a></li>
      <li><a href="insertTeacher.php">Insert Teacher</a></li>
      <li class="active"><a href="timeSlot.php">Time Slot</a></li>
	  <li><a href="generateRoutine.php">Generate Routine</a></li>
    </ul>
  </div>
</nav>

<form action="timeSlotProcess.php" method="post">
<div class="container">
  <table class="table table-hover">
   <thead>
    <tr>
	 <th>Serial</th>
	 <th>Start Time</th>
	 <th>End Time</th>
	</tr>
   </thead>
   <tbody>
    <tr>
	 <td>1</td>
	 <td><input type="text" class="form-control" name="time1" id="email" value="<?php echo $result[0]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>2</td>
	 <td><input type="text" class="form-control" name="time2" id="email" value="<?php echo $result[1]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>3</td>
	 <td><input type="text" class="form-control" name="time3" id="email" value=" <?php echo $result[2]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>4</td>
	 <td><input type="text" class="form-control" name="time4" id="email" value=" <?php echo $result[3]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>5</td>
	 <td><input type="text" class="form-control" name="time5" id="email" value=" <?php echo $result[4]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>6</td>
	 <td><input type="text" class="form-control" name="time6" id="email" value=" <?php echo $result[5]['Name']; ?>"></td>
	</tr>
    <tr>
	 <td>7</td>
	 <td><input type="text" class="form-control" name="time7" id="email" value=" <?php echo $result[6]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>8</td>
	 <td><input type="text" class="form-control" name="time8" id="email" value=" <?php echo $result[7]['Name']; ?>"></td>
	</tr>
	<tr>
	 <td>9</td>
	 <td><input type="text" class="form-control" name="time9" id="email" value=" <?php echo $result[8]['Name']; ?>"></td>
	</tr>
   </tbody>
  </table>

</div>  
<div class="container">
  <h2></h2>
    <div class="form-group">        
      <div class="col-sm-offset-2 col-sm-10">
        <button type="submit" class="btn btn-primary">Submit</button>
      </div>
    </div>
</div>
    </form>

</body>
</html>
