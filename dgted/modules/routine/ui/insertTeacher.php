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
  <title>Insert Teacher</title>
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
        
        <li><a href="insertCourse.php">Insert Course</a></li>
        <li class="active"><a href="insertTeacher.php">Insert Teacher</a></li>
        <li><a href="generateRoutine.php">Generate Routine</a></li>
      </ul>
    </div>
  </nav>

  <?php  
    // $teacherEmail=$teacherPass=$firstName= $lastName="";
    if(isset($_POST['submit'])){
      
       $teacherEmail = $_POST['teacherEmail'];
       $teacherPass = $_POST['teacherPass'];
       $firstName = $_POST['firstName'];
       $lastName = $_POST['lastName'];

       $result= mysqli_query($conn,"INSERT INTO tbl_user ( Email, Password, FirstName, LastName) 
						VALUES ('$teacherEmail','$teacherPass','$firstName','$lastName')");
       if($result)
       {
           echo "<p>Inserted Successfully!</p>";
       }
     
    }
  ?>
  <div class="container">
    <form class="form-horizontal teacher_info" action = "insertTeacher.php" method="post">
      <h2 class="text-center">Teacher Information </h2>
      <div class="form-group">
        <label class="control-label col-md-4" for="teacherEmail">Email :</label>
        <div class="col-md-6">
          <input required type="text" class="form-control" style="width:50%;" name="teacherEmail" id="teacherEmail" placeholder="Enter Email">
        </div>
      </div>

      <div class="form-group">
        <label class="control-label col-md-4" for="teacherPass">Password :</label>
        <div class="col-md-6">
          <input required type="text" class="form-control" style="width:50%;" name="teacherPass" id="teacherPass" placeholder="Enter Password">
        </div>
      </div>

      <div class="form-group">
        <label class="control-label col-md-4" for="firstName">First Name :</label>
        <div class="col-md-6">
          <input required type="text" class="form-control" style="width:50%;" name="firstName" id="firstName" placeholder="Enter First Name">
        </div>
      </div>

      <div class="form-group">
        <label class="control-label col-md-4" for="lastName">Last Name:</label>
        <div class="col-md-6">
          <input required type="text" class="form-control" style="width:50%;" name="lastName" id="lastName" placeholder="Enter Last Name">
        </div>
      </div>

      <div class="form-group">        
        <div class="col-md-offset-4 col-md-8">
          <button type="submit" class="btn btn-primary" name="submit">Submit</button>
        </div>
      </div>
    </form>
  </div>
  
</body>
</html>
