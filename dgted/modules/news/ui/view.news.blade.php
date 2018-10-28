<?php


include_once '/../../util/class.util.php';
include_once '/../../bao/class.newsbao.php';


$_NewsBAO = new NewsBAO();
$_DB = DBUtil::getInstance();

 
if(isset($_GET['txt']))
{
	$Keyword=$_GET['txt'];

	$_NewsBAO->getSearchedNews($Keyword);
}

if(isset($_POST['searchID']))
{
	$varButton="Update";
	$News = new News();
	$varTitle=$_POST['varTitle'];
	$SQL= "SELECT * FROM tbl_news WHERE Title = '$varTitle'";
	$sth = $_DB->doQuery($SQL);
	$result=mysqli_fetch_array($sth);
	$varTitle=$result['Title'];
	$varDescription=$result['Description'];
	$varHappeningDate=$result['HappeningDate'];
	$varTag=$result['Tag'];
	//$varImage=


	//$_NewsBAO->getSearchedNews($Keyword);
}
else
{
	$varButton="Create";
	$varTitle="";
	$varDescription="";
	$varHappeningDate="";
	$varTag="";
	//$varImage="";

}
if(isset($_POST['Create']))
{
	
	 $News = new News();	
	 $News->setID(Util::getGUID());
	 //$fileImage=addslashes(file_get_contents($_FILES['Image']['tmp_name']));
	 $target="image/".basename($_FILES['Image']['name']);
	 move_uploaded_file($_FILES['Image']['tmp_name'], $target);
	 $News->setImage($_DB->secureInput($target));
     $News->setTitle($_DB->secureInput($_POST['txtTitle']));
     //$fileDescription=addslashes(file_get_contents($_FILES["txtDescription"]["name"]));
     $News->setDescription($_DB->secureInput($_POST['txtDescription']));
     $News->setCreationDate($_DB->secureInput(date("Y/m/d")));
     $News->setHappeningDate($_DB->secureInput($_POST['txtDate']));
     $News->setTag($_DB->secureInput($_POST['txtTag']));
     $News->setIsVisible($_DB->secureInput("1"));
	 $_NewsBAO->createNews($News);	

			 
}
if(isset($_POST['Update']))
{
	
	 $News = new News();	
	// $News->setID(Util::getGUID());
	 //$fileImage=addslashes(file_get_contents($_FILES['Image']['tmp_name']));
	 $target="image/".basename($_FILES['Image']['name']);
	 move_uploaded_file($_FILES['Image']['tmp_name'], $target);
	 $News->setImage($_DB->secureInput($target));
     $News->setTitle($_DB->secureInput($_POST['txtTitle']));
     //$fileDescription=addslashes(file_get_contents($_FILES["txtDescription"]["name"]));
     $News->setDescription($_DB->secureInput($_POST['txtDescription']));
     $News->setCreationDate($_DB->secureInput(date("Y/m/d")));
     $News->setHappeningDate($_DB->secureInput($_POST['txtDate']));
     $News->setTag($_DB->secureInput($_POST['txtTag']));
     $News->setIsVisible($_DB->secureInput("1"));
	 $_NewsBAO->updateNews($News);	

			 
}

if(isset($_POST['saveID']))
{
	$varTitle=$_POST['varTitle'];
	
	$SQL= "UPDATE tbl_news SET IsVisible = false  WHERE Title = '$varTitle'";
	$sth = $_DB->doQuery($SQL);
	
}
?>