<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>this is title</title>
  <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
  <link rel="stylesheet" type="text/css" href="css/style.css">
  <link rel="stylesheet" href="css/style.css">
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
    <form class="search">
      <input type="text" name="" placeholder="search">
      <input type="button" name="" value="Search">
    </form>
    <form class="filter">

    <select name="forma" onchange="location = this.value;">
     <option value="index.php">Home</option>
     <option value="index.php">Month View</option>
     <option value="day-view.php">Day View</option>
    </select>


      <input type="button" name="" value="Filter">
    </form>

<section class="calender-wrap">
  <div class="controll">
  	<div class="prev">
      <button><=</button>
  	</div>
    <h3>Current Month year</h3>
    <div class="next">
      <button>=></button>
    </div>
  </div>





<?php 
include 'calendar.php';

$calendar = new Calendar();
$sun = $calendar->closestDate('sunday').'<br/>';
$mon = $calendar->closestDate('monday').'<br/>';
$tue = $calendar->closestDate('tuesday').'<br/>';
$wed = $calendar->closestDate('wednesday').'<br/>';
$thu = $calendar->closestDate('thursday').'<br/>';
$fri = $calendar->closestDate('friday').'<br/>';
$sat = $calendar->closestDate('saturday').'<br/>';
//$days = ['Monday' => 1, 'Tuesday' => 2, 'Wednesday' => 3, 'Thursday' => 4, 'Friday' => 5, 'Saturday' => 6, 'Sunday' => 7];
 ?>


<?php 

$dt = new DateTime;
/*$dt->modify("-2 days");
var_dump($dt->format('r'));*/
if (isset($_GET['year']) && isset($_GET['week'])) {
    $dt->setISODate($_GET['year'], $_GET['week']);
} else {
    $dt->setISODate($dt->format('o'), $dt->format('W'));
}
$year = $dt->format('o');
$week = $dt->format('W');
$dt->modify("-1 days");
?>

<div class="pre-week">
<a href="<?php echo $_SERVER['PHP_SELF'].'?week='.($week-1).'&year='.$year; ?>">Pre Week</a>
</div>

<div class="next-week">
<a href="<?php echo $_SERVER['PHP_SELF'].'?week='.($week+1).'&year='.$year; ?>">Next Week</a>
</div>

<?php
$numDay = 1;
do {
    echo "<td>" . $dt->format('l') . "<br>" . $dt->format('d M Y') . "</td>\n";
    $dt->modify('+1 days');
    $numDay++;
} while ($numDay<=7);


echo "<br/><br/>";
?>


      <div class="calender">
      	<table class="weeks">
      		<tr>
      			<td>Sun    <strong class="margin5"><?php echo $sun ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Mon    <strong class="margin5"><?php echo $mon ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Tue    <strong class="margin5"><?php echo $tue ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Wed    <strong class="margin5"><?php echo $wed ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Thu    <strong class="margin5"><?php echo $thu ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Fri    <strong class="margin5"><?php echo $fri ?></strong></td>
      			<td>Events</td>
      		</tr>
      		<tr>
      			<td>Sat    <strong class="margin5"><?php echo $sat ?></strong></td>
      			<td>Events</td>
      		</tr>
      	</table>
      </div>
    </section>
  </div>
</body>

</html>
