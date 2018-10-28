<?php 


foreach ($rows as $row):
    if($dt->format('d M Y') == $row['date']){
          $eko = " ".$row['title'].": ".$row['description']."<br/>";
             }
 endforeach;
















 ?>