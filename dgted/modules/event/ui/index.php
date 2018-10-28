<?php include 'db.php'; ?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>this is title</title>
  <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css" href="css/style.css">
  <link href="calendar.css" type="text/css" rel="stylesheet" />
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
  <a href="week-view.php" class="btn btn-primary" role="button">Week View</a>
  <a href="day-view.php" class="btn btn-success" role="button">Day View</a>
</div>
<div class="add-event float-right">
  <a href="add-event.php" class="btn btn-success" role="button">Add Event</a>
</div>


<!-- <form class="filter">
<select name="forma" onchange="location = this.value;">
 <option value="index.php">Home</option>
 <option value="index.php">Month View</option>
 <option value="week-view.php">Week View</option>
 <option value="day-view.php">Day View</option>
</select>
<input type="button" name="" value="Filter">
</form> -->

    <section class="calender-wrap">
<?php
include 'calendar.php';

$calendar = new Calendar();

echo $calendar->show();
/*echo $calendar->closestDate('sunday');*/
?>
    </section>
  </div>

   <script src="js/jquery.min.js"></script>
   <script src="js/bootstrap.min.js" ></script>
</body>

</html>
