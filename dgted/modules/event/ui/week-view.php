<?php include "db.php"; ?>
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
<!--     <form class="search">
  <input type="text" name="" placeholder="search">
  <input type="button" name="" value="Search">
</form> -->


<div class="search view">
  <!-- <a href="index.php" class="btn btn-primary" role="button">Home</a> -->
  <a href="index.php" class="btn btn-info" role="button">Month View</a>
  <a href="day-view.php" class="btn btn-success" role="button">Day View</a>


</div>
<div class="add-event float-right">
  <a href="add-event.php" class="btn btn-success" role="button">Add Event</a>
</div>

 <!-- <h3 class="float-center text-center">Current Week</h3> -->
<section class="calender-wrap">
  <div class="controll">
<!--     <div class="prev">
      <button><=</button>
</div> -->
    <!-- <h3>Current Month year</h3> -->
<!--     <div class="next">
  <button>=></button>
</div> -->
  </div>





<?php 
      $rows = $db->query("
          SELECT *
          FROM events
      ")->fetchAll(PDO::FETCH_ASSOC);
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
//$dt->modify("-1 days");
?>

<div class="next-pre clearfix">
<div class="pre-week pull-left">
<a href="<?php echo $_SERVER['PHP_SELF'].'?week='.($week-1).'&year='.$year; ?>">Pre Week</a>
</div>

<div class="next-week pull-right">
<a href="<?php echo $_SERVER['PHP_SELF'].'?week='.($week+1).'&year='.$year; ?>">Next Week</a>
</div>
</div>

<?php
$numDay = 1;
do {
    
?>
      <div class="calender">
        <table class="weeks">
          <tr>
<?php if($dt->format('d M Y') == date('d M Y')){ ?>
            <td class="color cell"><?php echo $dt->format('l'); ?>   <strong class="margin5"> <?php echo $dt->format('d M Y'); ?> </strong></td>
            <td class="default cell">
                Events:
                <?php
                $x=1;
foreach ($rows as $row):
  if($dt->format('d-m-Y') == $row['date']){
    ?>              
    <br/>
<a href=""></a>
  <?php if($x>4){   ?>


  <?php } else{ ?>
  <a href="event.php?url=<?php echo $row['title']; ?>"><?php echo "$x. ".$row['title'].": ".$row['description']; ?></a>
  <?php } ?>

      <!-- <a href="index.php"></a> -->
    <?php $x++; }
     endforeach; 
     ?>
</td>
<?php } else{ ?>
            <td class="default cell"><?php echo $dt->format('l'); ?>   <strong class="margin5"> <?php echo $dt->format('d M Y');  ?> </strong></td>
            <td class="default cell">
                Events:
                <?php
                $x=1;
                foreach ($rows as $row):
                if($dt->format('d-m-Y') == $row['date']){
                 ?>
                
                <br/>
                <?php if($x<=4){   ?>
                <a href="event.php?url=<?php echo $row['title']; ?>"><?php echo "$x. ".$row['title'].": ".$row['description']; ?></a>
                <?php } else {?>
                <!-- day-view.php?date='.$this->currentDate -->
                <a href="day-view.php?date=<?php echo $dt->format('d-m-Y'); ?>">more</a>
                <?php
                 }
                 $x++;
                 }
                 endforeach; 
                 ?>
            </td>
<?php } ?>
          </tr>
        </table>
      </div>
        
<?php
/*echo "<td>" . $dt->format('l') . "<br>" . $dt->format('d M Y') . "</td>\n";*/
    $dt->modify('+1 days');
    $numDay++;

} while ($numDay<=7);


echo "<br/><br/>";
?>


<!--       <div class="calender">
    <table class="weeks">
      <tr>
        <td>Sun    <strong class="margin5"> sun </strong></td>
        <td>Events</td>
      </tr>
    </table>
  </div>
     -->  


    </section>
  </div>
</body>

</html>
