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
<div class="add-event float-right">
  <a href="add-event.php" class="btn btn-success" role="button">Add Event</a>
</div>
<div class="float-right today-btn">
  <a href="day-view.php" class="btn btn-primary" role="button">Today</a>
</div>

<?php 
      $rows = $db->query("
          SELECT *
          FROM events
      ")->fetchAll(PDO::FETCH_ASSOC);
 ?>



    <section class="calender-wrap">
      <h3 class="text-center">Events of The Day</h3>
      <div class="calender">
      	<table class="weeks">
        <h2></h2>
      		<tr>
            <?php
            $date = isset($_GET['date']) ? $_GET['date'] : date('d-m-Y');
            $prev_date = date('d-m-Y', strtotime($date .' -1 day'));
            $next_date = date('d-m-Y', strtotime($date .' +1 day'));
            ?>

            <div class="contrl">
              <div class="pre float-left">
                <a href="?date=<?=$prev_date;?>">Previous</a>
              </div>
              <div class="nex float-right">
                <a href="?date=<?=$next_date;?>">Next</a>
              </div>
            </div>
          
            <div class="current-day text-center">
            <?php
            echo "<div class='text-center'><br/><br/><strong>$date</strong></div>";
$x=1;
foreach ($rows as $row) {
if($date == $row['date'])
  {
  ?>
  <br/>
  <div class="">
  <tr>

  <td>
  <a href="event.php?url=<?php echo $row['title']; ?>"><?php echo "$x. ".$row['title'].": ".$row['description']; ?></a>
  </td>

  </tr>
  </div>
<?php
$x++;
}
}


            ?>
            </div>
      		</tr>
      	</table>
      </div>
    </section>
  </div>
</body>

</html>
