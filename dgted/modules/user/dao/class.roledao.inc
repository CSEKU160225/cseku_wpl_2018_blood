<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';

Class RoleDAO{

	private $_DB;
	private $_Role;
	private $_Permission;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_Role = new Role();
		$this->_Permission = new Permission();

	}

	// get all the Roles from the database using the database query
	public function getAllRoles(){

		$RoleList = array();

		$this->_DB->doQuery("SELECT * FROM ums_role order by Name ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Role = new Role();

		    $this->_Role->setID ( $row['ID']);
		    $this->_Role->setName( $row['Name'] );


		    $RoleList[]=$this->_Role;
   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($RoleList);

		return $Result;
	}


	// get all the Permissions from the database using the database query
	public function getAllPermissions(){

		$PermissionList = array();

		$this->_DB->doQuery("SELECT * FROM ums_permission order by Category, TableID ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Permission = new Permission();

		    $this->_Permission->setID ( $row['ID']);
		    $this->_Permission->setName( $row['Name'] );
		    $this->_Permission->setCategory( $row['Category'] );

		    $PermissionList[]=$this->_Permission;
   
		}

	
		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($PermissionList);

		return $Result;
	}



	//create Role funtion with the Role object
	public function createRole($Role){

		$ID=$Role->getID();
		$Name=$Role->getName();


		$SQL = "INSERT INTO ums_role(ID,Name) VALUES('$ID','$Name')";

		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//assign permissions to a role 
	public function assignPermissionsToRole($Role,$Permissions){

		//beginning a transaction 	
		$this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);

		//deleting previously assigned all the permissions from this role
		$SQL = "DELETE from ums_role_permission where RoleID ='".$Role->getID()."'";
		$SQL = $this->_DB->doQuery($SQL);

		//now assigning new permissions to this role
		foreach ($Permissions as $Permission) {
	
			//assigning a permission to a role
			$SQL = "INSERT INTO ums_role_permission(RoleID,PermissionID) 
											VALUES('".$Role->getID()."','".$Permission->getID()."')";							

			$SQL = $this->_DB->doQuery($SQL);		
		}

		//closing the transaction
		$this->_DB->getConnection()->commit();

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Role object based on its id form Role object
	public function readRole($Role){
		
		
		$SQL = "SELECT * FROM ums_role WHERE ID='".$Role->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Role from the database
		$row = $this->_DB->getTopRow();

		$this->_Role = new Role();

		//preparing the Role object
	    $this->_Role->setID ( $row['ID']);
	    $this->_Role->setName( $row['Name'] );



	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Role);

		return $Result;
	}

	//read a role object based on its id with the assigned permissions
	
	public function readRolePermissions($Role){
		
		//getting the role information
		$Result = $this->readRole($Role);

		if($Result->getIsSuccess()){


			$this->_Role = $Result->getResultObject();

					
			$SQL = "SELECT p.ID, p.Name,p.Category  FROM ums_role_permission rp, ums_permission p 
					WHERE  rp.PermissionID=p.ID and rp.RoleID='".$Role->getID()."'";
			
			$this->_DB->doQuery($SQL);

			//reading all the rows 
			$rows = $this->_DB->getAllRows();

			//setting Permissions list object
			$Permissions = array();

			for($i = 0; $i < sizeof($rows); $i++) {

				$row = $rows[$i];
		
				$Permission = new Permission();

			    //filling up Permission information
			    $Permission->setID ( $row['ID']);
			    $Permission->setName ( $row['Name']);
			    $Permission->setCategory ( $row['Category']);

			    //adding new Permissions with every iteration belong to this role	
			    $Permissions[]=$Permission;
	   
			}
	
			//assigning Permission list to the role object
			$this->_Role->setPermissions($Permissions);

		}

		//todo: LOG util with level of log

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Role);

		return $Result;
	}



	//update an Role object based on its 
	public function updateRole($Role){

		$SQL = "UPDATE ums_role SET Name='".$Role->getName()."' WHERE ID='".$Role->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Role based on its id of the database
	public function deleteRole($Role){


		$SQL = "DELETE from ums_role where ID ='".$Role->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.roledao.inc");

?>