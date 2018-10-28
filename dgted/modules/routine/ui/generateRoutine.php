<!DOCTYPE html>
<html lang="en">
<head>
  <title>Generate Routine</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <!--<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">-->
  <!--<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>-->
  <link rel="stylesheet" href="css/bootstrap.min.css">
  <link rel="stylesheet" href="css/routine.css" type="text/css">
  <script src="js/jquery.min.js"></script>
</head>
<body>
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
  $query_course = "SELECT Title FROM tbl_course";
  $result_course = mysqli_query($conn, $query_course);

  $course_no = "SELECT CourseNo FROM tbl_course";
  $result_no = mysqli_query($conn, $course_no);

  $query_teacher = "SELECT * FROM tbl_user";
  $result_teacher = mysqli_query($conn, $query_teacher);

  $query_term = "SELECT * FROM tbl_term";
  $result_term = mysqli_query($conn, $query_term);


  

  $query_day = "SELECT * FROM tbl_routine_time";
  $result_day = mysqli_query($conn, $query_day);

  $query_day = "SELECT day_of_week FROM tbl_routine_time";
  $result_day = mysqli_query($conn, $query_day);

  $query_time = "SELECT course_time FROM tbl_routine_time";
  $result_time = mysqli_query($conn, $query_time);


?>
<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">Routine Maker</a>
    </div>
    <ul class="nav navbar-nav">
      
      <li><a href="insertCourse.php">Insert Course</a></li>
      <li><a href="insertTeacher.php">Insert Teacher</a></li>
	    <li  class="active"><a href="generateRoutine.php">Generate Routine</a></li>
      <li><a href="view.php">View Routine</a></li>
    </ul>
  </div>
</nav> 

<!-- php form submission code -->
<?php 
  if(isset($_POST['generate_routine'])){
    $teacher_name = $_POST['teacher_name'];
    $course_number = $_POST['course_number'];
    $course_name = $_POST['course_name'];
    $term_detail = $_POST['term_detail'];
    $course_of_day = $_POST['course_of_day'];
    $class_time = $_POST['class_time'];


    
    
    $sql = "INSERT INTO tbl_routine_data (teacher_name, course_number, course_name,term_detail,course_of_day,class_time) 
    VALUES ('$teacher_name','$course_number','$course_name','$term_detail','$course_of_day','$class_time')";

    if(mysqli_query($conn, $sql)){

      echo "Records added successfully.";

    }
    else{

      echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);

    }
  


  }
?>

  <div class="container">
    <div class="row">
      <div class="routine_section col-md-offset-2 col-md-8"> 
        <form action="generateRoutine.php" method="POST" class="">
          <h2 class="text-center">Create a New Routine</h2>
          
          <div class="entry_section">
            <div class="form-group term_details">
              <label class="col-md-3"> Term:</label>
              <select name="term_detail">
                 <?php
                  while ($row = mysqli_fetch_array($result_term))
                  { ?>
                   <option value=" <?php echo $row['Name']; ?> "><?php echo $row['Name']; ?></option>
                
                <?php }
                ?>
              </select>
            </div>

            <div class="form-group teacher_selection">
              <label class="col-md-3">Select Teacher:</label>
              <select name="teacher_name">
              <?php while ($row = mysqli_fetch_array($result_teacher))
                  { ?>
                   <option value=" <?php echo $row['FirstName'].''.$row['LastName']; ?> "><?php echo $row['FirstName'].''.$row['LastName']; ?></option>
                <?php
                  }
                ?>
              </select>
            </div>

            <div class="form-group course_name">
              <label class="col-md-3"> Course Title:</label>
              <select name="course_name">
                  <?php
                      while ($row = mysqli_fetch_array($result_course)){
                   ?>
                     <option value=" <?php echo $row['Title']; ?> "><?php echo $row['Title']; ?></option>
                 <?php    
                  }
                ?>
              </select>
            </div>

            <div class="form-group course_selection">
              <label class="col-md-3"> Course No:</label>
              <select name="course_number">
                <?php
                      while ($row = mysqli_fetch_array($result_no)){
                   ?>
                     
                     <option value="<?php echo $row['CourseNo']; ?>"><?php echo $row['CourseNo']; ?></option>
                 <?php    
                  }
                ?>
              </select>
            </div>

            <div class="form-group course_of_day">
              <label class="col-md-3">Choose Day:</label>
              <select name="course_of_day">
                <?php 
                  foreach($result_day as $row_result_day){
                    echo '<option value='.$row_result_day['day_of_week'].'>'.$row_result_day['day_of_week'].'</option>';
                  }
                ?>
              </select>
            </div>

             <div class="form-group class_time">
              <label class="col-md-3">Duration:</label>
              <select name="class_time">
           
                 <?php
                      while ($row = mysqli_fetch_array($result_time)){
                   ?>
                     
                     <option value="<?php echo $row['course_time']; ?>"><?php echo $row['course_time']; ?></option>
                 <?php    
                  }
                ?>
              </select>
            </div>

          </div>

          <button type="submit" class="btn btn-primary btn_submit" name="generate_routine">Submit</button>
       </form>
      </div>
    </div>
  </div>

  

</body>
</html>
