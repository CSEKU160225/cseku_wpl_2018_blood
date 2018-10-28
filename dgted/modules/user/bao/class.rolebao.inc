<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_USER.'dao/class.roledao.inc';


/*
	Role Business Object 
*/
Class RoleBAO{

	private $_DB;
	private $_RoleDAO;

	public function __construct(){

		$this->_RoleDAO = new RoleDAO();

	}

	//get all Roles value
	public function getAllRoles(){

		$Result = new Result();	
		$Result = $this->_RoleDAO->getAllRoles();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.getAllRoles()");		

		return $Result;
	}

	//get all Permissions value
	public function getAllPermissions(){

		$Result = new Result();	
		$Result = $this->_RoleDAO->getAllPermissions();
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.getAllPermissions()");		

		return $Result;
	}


	//create Role funtion with the Role object
	public function createRole($Role){

		$Result = new Result();	
		$Result = $this->_RoleDAO->createRole($Role);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.createRole()");		

		return $Result;

	
	}

	//assigning a list of permissions to a role
	public function assignPermissionsToRole($Role,$Permissions){

		$Result = new Result();	
		$Result = $this->_RoleDAO->assignPermissionsToRole($Role,$Permissions);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.assignPermissionsToRole()");		

		return $Result;

	
	}

	//read an Role object based on its id form Role object
	public function readRole($Role){


		$Result = new Result();	
		$Result = $this->_RoleDAO->readRole($Role);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.readRole()");		

		return $Result;


	}

	//read an Role object along with the list of permissions
	public function readRolePermissions($Role){

		$Result = new Result();	
		$Result = $this->_RoleDAO->readRolePermissions($Role);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.readRolePermissions()");		

		return $Result;


	}

	//update an Role object based on its current information
	public function updateRole($Role){

		$Result = new Result();	
		$Result = $this->_RoleDAO->updateRole($Role);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.updateRole()");		

		return $Result;
	}

	//delete an existing Role
	public function deleteRole($Role){

		$Result = new Result();	
		$Result = $this->_RoleDAO->deleteRole($Role);
		
		if(!$Result->getIsSuccess())
			$Result->setResultObject("Database failure in RoleDAO.deleteRole()");		

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.rolebao.inc");

?>