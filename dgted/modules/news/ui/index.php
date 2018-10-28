<?php

//$target='image/';
//$page1=0;
include_once 'view.news.blade.php';
include_once '/../../common/class.common.php';
include_once '/../../modules/news/news.css';
$_DB = DBUtil::getInstance();



?>
<!DOCTYPE html>
<html>
	<head>
		<!--<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>Term CRUD Operations</title>
		<link rel="stylesheet" href="style.css" type="text/css" />
		-->
	</head>

<body>
<center>
	<div id="header"> 
		<h1>CSE NEWS PORTAL</h1>
		<label>By : Kazi Masudul Alam</a></label>
	</div>

	<div id="navigation">
	<!--<form action="index.php">-->
		<button class="btn home" onclick="window.location='index.php'">Home</button>
		<button class="btn sprts" name="Sports" onclick="window.location='sports.php'">Sports</button>
		<button class="btn allmn" name="Allumni" onclick="window.location='allumni.php'">Allumni</button>
		<button class="btn teachr" name="Teachers" onclick="window.location='teachers.php'">Teachers</button>
		<button class="btn notice" name="Notice" onclick="window.location='notice.php'">Notice</button>
		<button class="btn nwscrt" onclick="window.location='newNews.php'">News Create</button>
			
		
		
	</form>
		<form action="search.php" method="get">
			<table width="100%" border="1" cellpadding="5">
				<tr>
					<td><input type="text" name="txt" placeholder="keyword" autocomplete="on"> </td>
							
					<td><button type="submit" name="search">Search</button></td>
				</tr>
			</table>
		</form>
	</div>
	
	<!--<nav id='navmenu1'>
		<a href='#'>Home</a>
		<a href='#'>Events</a>
		<a href='#'>International</a>
		<a href='#'>Notice</a>
	</nav>
	-->
	
	<hr/>

			<table width="70%" align="left">
				
				<tr>
					<td>
						<h3>Home</h3>
					</td>

				</tr>
				<?php

				//$start=0;

				$Result=$_NewsBAO->getAllNews();
				$page1=0;
				//$Result=$_NewsBAO->getPagedNews($start);

	//if DAO access is successful to load all the Terms then show them one by one
				if($Result->getIsSuccess())
				{

				$NewsList = $Result->getResultObject();
				
			
				$start=ceil(sizeof($NewsList)/5);?>
				<tr>
					<?php
						echo "<br>";
						for($j=1;$j<=$start;$j++)
					{
					
						?>
						<td><h4><a href="index.php?page=<?php echo $j;?>" style="text-decoration: none;"><?php echo $j." ";?></a></h4></td>

						<?php


					}
					?>
					
					</tr>
					<?php
						$page1=0;
						$page=$_GET['page'];

						if($page==""||$page==1)
						{
							$page1=0;
						}
						else
						{
							$page1=($page*5)-5;
						}
				 
					$Result=$_NewsBAO->getPagedNews($page1);
					$NewsList = $Result->getResultObject();
	
	
					for($i = 0; $i < sizeof($NewsList); $i++) {
						
					



						$News = $NewsList[$i];
						$ID= $News->getID();
						//$_SESSION['$var'] = $ID;
						$sql = "SELECT Image FROM tbl_news WHERE ID = '$ID'";
						//$con=$_DB->getConnec

						$sth = $_DB->doQuery($sql);
					
						$result=mysqli_fetch_array($sth);
						//echo $result['Image'];
						$image=$result['Image'];
					?>
				    <tr>
					    <td><h4><?php echo $News->getTitle(); ?></h4></td>
					    

					</tr>
					 <tr>
					 	<?php 
					 	
					 	?>
					    <td><?php 
					  // header('Content-Type: image/jpeg');
					   
					   echo '<img src="'.$image.'" height="250" />';?>
					    	
					    </td>
					    

					</tr>
					 <tr>
					
					    <td><?php
					    	 $strngLngth=str_word_count($News->getDescription()); 
					    	 
					    	 if($strngLngth>40)
					    	 {
					    	 	$strngCut=substr($News->getDescription(),0, 125);

					    	 	$strg=substr($strngCut, 0, strrpos($strngCut, " "));
					    	 	echo $strg;?>...'<a target="_blank" href="readmore.php?var=<?php echo $ID?>">Read More</a>'<?php

					    	 }
					    	 else{
					    	 	echo $News->getDescription();
					    	 }
					    	}
					    ?></td>

					</tr>
					
					<?php 
						
					
				
			}
				else{


					echo $Result->getResultObject(); //giving failure message
				}

				?>
				
					
			</table>
			<table width="30%" align="right">
				
				<tr>
					<td>
						<h3>Recent news</h3>
					</td>
				</tr>
				<?php
				$Result=$_NewsBAO->getAllNews();
				if($Result->getIsSuccess()){
					$count=0;

				$NewsList = $Result->getResultObject();
				for($i = sizeof($NewsList)-1; $i >=0 ; $i--) {
					
					$count++;

						$News = $NewsList[$i];
						if ($count<10) {
							$ID=$News->getID(); 
						
						?>
				<tr>
					    <td><h4><?php echo $News->getTitle(); ?></h4></td>
					    

				</tr>
					 <tr>
					
					    <td><?php
					    	 $strngLngth=str_word_count($News->getDescription()); 
					    	 
					    	 if($strngLngth>20)
					    	 {
					    	 	$strngCut=substr($News->getDescription(),0, 100);

					    	 	$strg=substr($strngCut, 0, strrpos($strngCut, " "));
					    	 	echo $strg;?>...'<a href="readmore.php?var=<?php echo $ID?>">Read More</a>'<?php

					    	 }
					    	 else{
					    	 	echo $News->getDescription();
					    	 }
					    ?></td>

					</tr>
					<?php
				}
			}
		}
					?>

			</table>
		



</center>
</body>
</html>
