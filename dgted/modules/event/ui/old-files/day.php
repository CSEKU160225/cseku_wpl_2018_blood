<?php
$date = isset($_GET['date']) ? $_GET['date'] : date('Y-m-d');
$prev_date = date('Y-m-d', strtotime($date .' -1 day'));
$next_date = date('Y-m-d', strtotime($date .' +1 day'));
?>

<a href="?date=<?=$prev_date;?>">Previous</a>
<a href="?date=<?=$next_date;?>">Next</a>
<?php 
echo "$date";

 ?>