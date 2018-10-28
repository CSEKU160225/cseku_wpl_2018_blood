<?php

	include_once 'view.news.blade.php';
	include_once '/../../common/class.common.php';
	include_once '/../../modules/news/news.css';
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
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
		<button class="btn home" onclick="window.location='index.php'">Home</button>
		<button class="btn sprts" onclick="window.location='sports.php'">Sports</button>
		<button class="btn allmn" onclick="window.location='allumni.php'">Allumni</button>
		<button class="btn teachr" onclick="window.location='teachers.php'">Teachers</button>
		<button class="btn notice" onclick="window.location='notice.php'">Notice</button>
		<button class="btn nwscrt" onclick="window.location='newNews.php'">News Create</button>
			
		
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
						<h3>Allumni</h3>
					</td>

				</tr>
				<?php

				$Result=$_NewsBAO->getAllumniNews();

	//if DAO access is successful to load all the Terms then show them one by one
				if($Result->getIsSuccess())
				{

				$NewsList = $Result->getResultObject();
				
			
				//$Result=$_NewsBAO->getPagedNews($start);
				
				
	
	
					for($i = 0; $i < sizeof($NewsList); $i++) {
						
					



						$News = $NewsList[$i];
						$ID= $News->getID();
						$_SESSION['$var'] = $ID;
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
					    ?></td>

					</tr>
					<?php 
				}
					
				
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

				$NewsList = $Result->getResultObject();
				for($i = sizeof($NewsList)-1; $i >=0 ; $i--) {
					$count=0;
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
