<?php include "db.php"; ?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>this is title</title>
  <!-- <link rel="stylesheet" type="text/css" href="style.css"> -->
  <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css" href="css/style.css">
  <link rel="stylesheet" type="text/css" href="calendar.css">
</head>

<body>
  <div class="container">
    <header>
      <form>
        <input type="text" name="" placeholder="username">
        <input type="password" name="" placeholder="password">
        <input type="button" name="" value="Login">
      </form>
    </header>

<!--     <form class="search">
  <input type="text" name="" placeholder="search">
  <input type="button" name="" value="Search">
</form>
 -->

<div class="search view">
  <!-- <a href="index.php" class="btn btn-primary" role="button">Home</a> -->
  <a href="index.php" class="btn btn-info" role="button">Month View</a>
  <a href="week-view.php" class="btn btn-primary" role="button">Week View</a>
</div>
<!-- <div class="float-right today-btn">
  <a href="day-view.php" class="btn btn-primary" role="button">Today</a>
</div> -->

<?php
$url = $_GET['url'];
$url = explode("/",$url);

$sTitle = $url[0];
/*echo " ".$sTitle;*/

      $rows = $db->query("
          SELECT *
          FROM events
      ")->fetchAll(PDO::FETCH_ASSOC);
 ?>



    <section class="calender-wrap">
      <h3 class="text-center">Event</h3>
      <div class="calender single-event">
      	<table class="weeks">
        <h2></h2>
      		<tr>
  <?php 
  foreach ($rows as $row):
  if($sTitle == $row['title']){
  echo "Title: ".$row['title']."<br/>";
  echo "shorttitle: ".$row['shorttitle']."<br/>";
  echo "date: ".$row['date']."<br/>";
  echo "time_from: ".$row['time_from']."<br/>";
  echo "time_to: ".$row['time_to']."<br/>";
  echo "location: ".$row['location']."<br/>";
  echo "link: ".$row['link']."<br/>";
  echo "Description: ".$row['description']."<br/>";
  }
  endforeach; 
   ?>
            
          </tr>
            
      	</table>
      </div>
    </section>
  </div>
</body>

</html>
