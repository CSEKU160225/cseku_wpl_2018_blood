<!DOCTYPE html>
<html lang="en">
    <head>
    <title>Bootstrap Example</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link rel="stylesheet" href="css/routine.css" type="text/css">
    <script src="js/jquery.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    </head>
<body>

<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "cseku_wpl_2017_education";

    // Create connection
    $conn = mysqli_connect($servername, $username, $password, $dbname);
    
    $query_time = "SELECT course_time FROM tbl_routine_time";
    $result_time = mysqli_query($conn, $query_time);

    $query_day = "SELECT day_of_week FROM tbl_routine_time";
    $result_day = mysqli_query($conn, $query_day);

    $query_term = "SELECT * FROM tbl_routine_data";
    $result_term = mysqli_query($conn, $query_term);
  ?>
  <nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">Routine Maker</a>
    </div>
    <ul class="nav navbar-nav">
      
      <li><a href="insertCourse.php">Insert Course</a></li>
      <li><a href="insertTeacher.php">Insert Teacher</a></li>
      <li><a href="view.php">View Routine</a></li>
        <li  class="active"><a href="generateRoutine.php">Generate Routine</a></li>
    </ul>
  </div>
</nav> 
<div class="container">
  <h2></h2>
  <p></p>            
  <table class="table table-hover">
    <thead>
      <tr>
        <th>Day</th>
        <th>Term</th>
        <?php while($row = mysqli_fetch_array($result_time)){ ?>
             <th><?php echo $row['course_time'];?></th>
        <?php
           
            }
         
        ?>
       
      </tr>
    </thead>
    <tbody>
        
        <?php while($row = mysqli_fetch_array($result_term)) { ?>
            <tr>
                <td><?php echo $row['course_of_day'];?></td>
                <td><?php echo $row['term_detail'];?></td>
                <td><?php echo $row['course_name'];?></td>
            </tr>
            <!--<td><?php echo $row['course_name'];?></td>-->
        <?php }?>


    </tbody>
  
  </table>
</div>

</body>
</html>