<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';
include_once UTILITY.'class.util.inc';

Class VideoDAO{

	private $_DB;
	private $_Video;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Video = new Video();

	}

	// get all the Terms from the database using the database query
	public function getAllVideos(){

		$VideoList = array();

		$this->_DB->doQuery("SELECT * FROM vtms_video");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Video = new Video();
		    $this->_Video->setID ( $row['ID']);
		    $this->_Video->setTitle( $row['Title'] );
		    $this->_Video->setDescription( $row['Description'] );
		    $this->_Video->setLink( $row['Link'] );
		    //$this->_Video->setEmbedLink( $row['EmbedLink'] );
		    $this->_Video->setIsEmbed( $row['IsEmbed'] );
		    $this->_Video->setTag( $row['TagID'] );
		    $VideoList[]=$this->_Video;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($VideoList);

		return $Result;
	}

	//create Term funtion with the Term object
	public function createVideo($Video){

		$ID=$Video->getID();
		$Title=$Video->getTitle();
		$Description=$Video->getDescription();
		//$front = '<iframe width="560" height="315" src="https://www.youtube.com/embed/' ;
		//$back = '" frameborder="0" allowfullscreen></iframe>';
		$Link = $Video->getLink();
		//$link2= substr($link,32);
		//$Link=$front.$link2.$back;
		//$EmbedLink=$Video->getEmbedLink();
		$isEmbed=$Video->getIsEmbed();
		$Tag=$Video->getTag();
		
		$Creator=$_SESSION["globalUser"]->getID();

		$SQL = "INSERT INTO vtms_video(ID,TagID,Title,Description,Link,IsEmbed,CreationDate,CreatorID) 
				VALUES('$ID','$Tag','$Title','$Description','$Link','$isEmbed',now(),'$Creator')";

		//echo $SQL;

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Term object based on its id form Term object
	public function readVideo($Video){
		
		
		$SQL = "SELECT * FROM vtms_video WHERE ID='".$Video->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Term from the database
		$row = $this->_DB->getTopRow();

		$this->_Video = new Video();

		//preparing the Term object
	    $this->_Video->setID ( $row['ID']);
		$this->_Video->setTitle( $row['Title'] );
		$this->_Video->setDescription( $row['Description'] );
		//$front = '<iframe width="560" height="315" src="https://www.youtube.com/embed/' ;
		//$back = '" frameborder="0" allowfullscreen></iframe>';
		//$link = $row['Link'] ;
		//$link2= substr($link,32);
		//$Link=$front.$link2.$back;

	    $this->_Video->setLink($row['Link']);
	    $this->_Video->setIsEmbed( $row['IsEmbed'] );
	    $this->_Video->setTag( $row['TagID'] );


	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Video);

		return $Result;
	}

	//update an Term object based on its 
	public function updateVideo($Video){

		$SQL = "UPDATE vtms_video SET Title='".$Video->getTitle()."',
		Description='".$Video->getDescription()."', 
		Link='".$Video->getLink()."',TagID='".$Video->getTag()."' WHERE ID='".$Video->getID()."'";

		//echo $SQL;
        
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Term based on its id of the database
	public function deleteVideo($Video){


		$SQL = "DELETE from vtms_video where ID ='".$Video->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

////$_Log->log(LogUtil::$DEBUG," exit the class.videodao.inc");

?>