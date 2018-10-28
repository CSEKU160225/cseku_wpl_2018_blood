	<?php
// write dao object for each class
include_once '/../common/class.common.php';
include_once '/../util/class.util.php';
//include_once 'class.newsdao.php';

Class NewsDAO{

	private $_DB;
	private $_News;
	private $_Keyword;
	private $_start; 


	function NewsDAO(){

		$this->_DB = DBUtil::getInstance();
		$this->_News = new News();
		

	}


	// get all the users from the database using the database query
	public function getAllNews(){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		    //$this->_News->setPath($row['Path']); 
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}
	public function getEditedNews($Title){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where Title = '$Title'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		    //$this->_News->setPath($row['Path']); 
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}

	public function getNews($ID){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND ID='$ID'");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		    //$this->_News->setPath($row['Path']); 
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}

	public function getPagedNews($page1){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true limit $page1 ,10 ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		    //$this->_News->setPath($row['Path']); 
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}
public function getSearchedNews($Keyword){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND Title LIKE '%{$Keyword}%' OR Description LIKE '%{$Keyword}%' OR HappeningDate LIKE '%{$Keyword}%' OR Tag LIKE '%{$Keyword}%' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		   // $this->_News->setPath($row['Path']);   
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}

		//todo: LOG util with level of log
		//echo '<br> log::complete getAllUsers::'.print_r($UserList);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}

public function getSportsNews(){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND Tag LIKE '%sport%' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		   // $this->_News->setPath($row['Path']);   
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}

		//todo: LOG util with level of log
		//echo '<br> log::complete getAllUsers::'.print_r($UserList);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}
	public function getAllumniNews(){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND Tag LIKE '%allumni%' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']);
		   // $this->_News->setPath($row['Path']);    
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}

		//todo: LOG util with level of log
		//echo '<br> log::complete getAllUsers::'.print_r($UserList);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}
	public function getTeachersNews(){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND Tag LIKE '%teachers%' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']); 
		    //$this->_News->setPath($row['Path']);   
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}

		//todo: LOG util with level of log
		//echo '<br> log::complete getAllUsers::'.print_r($UserList);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}
	public function getNoticeNews(){

		$NewsList = array();

		$this->_DB->doQuery("SELECT * FROM tbl_News where IsVisible = true AND Tag LIKE '%notice%' ");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_News = new News();

		    $this->_News->setID($row['ID']);
		    $this->_News->setImage($row['Image']);  
		   // $this->_News->setPath($row['Path']);  
		    $this->_News->setTitle($row['Title']);
		    $this->_News->setDescription($row['Description']);
		    $this->_News->setCreationDate($row['CreationDate']);
		    $this->_News->setHappeningDate($row['HappeningDate']);
		    $this->_News->setTag($row['Tag']);
		    $this->_News->setIsvisible($row['IsVisible']);

		    $NewsList[]=$this->_News;
   
		}

		//todo: LOG util with level of log
		//echo '<br> log::complete getAllUsers::'.print_r($UserList);

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($NewsList);

		return $Result;
	}


	//create user funtion with the user object
	public function createNews($News){

		$ID=$News->getID();
		$Image=$News->getImage();
		//$Path=$News->getPath();
		$Title=$News->getTitle();
		$Description=$News->getDescription();
		$CreationDate=$News->getCreationDate();
		$HappeningDate=$News->getHappeningDate();
		$Tag=$News->getTag();
		$IsVisible=$News->getIsVisible();
		

		$SQL = "INSERT INTO tbl_news(ID,Image,Title,Description,CreationDate,HappeningDate,Tag,IsVisible) 
		 	VALUES('$ID','$Image','$Title','$Description','$CreationDate','$HappeningDate','$Tag','$IsVisible')";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//creating the user
		$SQL = $this->_DB->doQuery($SQL);

			
				
		//closing the transaction
		$this->_DB->getConnection()->commit();



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	


	//update an user object based on its id information
	public function updateNews($News){

		$SQL = "UPDATE tbl_News SET Image='".$News->getImage()."', 
			Title='".$News->getTitle()."',
			Description='".$News->getDescription()."',
			Tag='".$News->getTag()."',
			HappeningDate='".$News->getHappeningDate()." '
			WHERE Title='".$News->getTitle()."'";

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);
		//updating the user
		$SQL = $this->_DB->doQuery($SQL);

		//removing previous roles 

		

				
		//closing the transaction
		$this->_DB->getConnection()->commit();



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);
		return $Result;

	}

	

}

echo '<br> log:: exit the class.newsdao.php';

?>