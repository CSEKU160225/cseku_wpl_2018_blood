<?php

/* @author Kazi Masudul Alam
  (C) CSE Discipline, Khulna University
*/

// Declare the interface 'I_DBConfig'
interface I_DBConfig{

	public function getDBHost();
	public function getDBUserName();
	public function getDBPassword();
	public function getDBName();
}

interface I_LogConfig{
	
	public function isLogEnabled();
	public function getLogLevel();

}

interface I_LanguageConfig{

	public function getDefaultLanguage();

}

// Declare the interface 'I_DBUtil'
interface I_DBUtil{

	public function getConnection();
	public function doQuery($sql);
	public function getNumRows();
	public function getAllRows();
	public function getTopRow();
	public function secureInput($value);
}




/*
Configuration class that reads *.ini file for different
configurations. Only one instance of this class is allowed at any time
*/
class ConfigUtil implements I_DBConfig, I_LogConfig, I_LanguageConfig{

	public static $s_instance;
	private $ini_array;


	private $_host;
	private $_username;
	private $_password;
	private $_database;
	
	private $_log_enabled=false;
	private $_log_level="info";
	private $_log_file_path;

	private $_lang_default="en";


	private function __construct(){

		$this->readConfig();

	}

	/*
	Get an instance of the Database
	@return Instance
	*/
	public static function getInstance() {
		if(!self::$s_instance) { // If no instance then make one
			self::$s_instance = new self();
		}
		return self::$s_instance;
	}

	// Magic method clone is empty to prevent duplication of connection
	private function __clone() { }


	/*
	Reading database related configuration file
	*/
	private function readConfig(){

		$this->_ini_array = parse_ini_file(CONFIG.'system.ini');

		$this->_host =	$this->_ini_array['db_host'];
		$this->_username = $this->_ini_array['db_username'];
		$this->_password = $this->_ini_array['db_password'];
		$this->_database = $this->_ini_array['db_database'];
	
		$this->_log_enabled=$this->_ini_array['log_enabled'];
		$this->_log_level=$this->_ini_array['log_level'];
		$this->_log_file_path=$this->_ini_array['log_path'];
	

		$this->_lang_default=$this->_ini_array['lang_default'];

	}

	// Get the host of database
	public function getDBHost(){

		return $this->_host;
	}

	// Get the user name of database
	public function getDBUserName(){

		return $this->_username;
	}

	// Get the password of the database
	public function getDBPassword(){

		return $this->_password;
	}

	// Get the database name
	public function getDBName(){

		return $this->_database;
	}

	// get whether the log is enabled
	public function isLogEnabled(){

		return $this->_log_enabled;
	}

	// give the log level info, warning, debug, error
	public function getLogLevel(){

		return $this->_log_level;
	}

	// return the log file path

	public function getLogFilePath(){

		return $this->_log_file_path; 
	}
	

	// give the default language EN, BN, FN etc
	public function getDefaultLanguage(){
		return $this->_lang_default;
	}


}


/*
* Mysql Database class - only one connection alowed
* provide interface to do query on the mysql database
* 
*/
class DBUtil implements I_DBUtil {
	private static $s_instance; //The single instance
	private $_host;
	private $_username;
	private $_password;
	private $_database;

	protected $_connection;
	protected $_result;
	protected $_numRows;
	/*
	Get an instance of the Database
	@return Instance
	*/
	public static function getInstance() {
		if(!self::$s_instance) { // If no instance then make one
			self::$s_instance = new self();
		}
		return self::$s_instance;
	}

	// Constructor
	private function __construct() {

		$this->readDBConfig();
		$this->setConnection();
	}

	private function readDBConfig(){

		$_config = ConfigUtil::getInstance();
		$this->_host = $_config->getDBHost();
		$this->_username = $_config->getDBUserName();
		$this->_password = $_config->getDBPassword();
		$this->_database = $_config->getDBName();
	}


	// Creating the database connection using mysqli
	private function setConnection(){
		$this->_connection = new mysqli($this->_host, $this->_username, 
			$this->_password, $this->_database);
	
		// Error handling
		if(mysqli_connect_error()) {
			trigger_error("Failed to conencto to MySQL: " . mysql_connect_error(),
				 E_USER_ERROR);
		}

	}


	// Magic method clone is empty to prevent duplication of connection
	private function __clone() { }

	// Get mysqli connection
	public function getConnection() {
		return $this->_connection;
	}

	// Sends the query to the connection
	public function doQuery($sql) {

		$this->_result = $this->_connection->query($sql) or die(mysqli_error($this->_connection));		
		return $this->_result;

	}

	public function checkUpdateSuccess(){

		$value = mysqli_affected_rows($this->_connection);
		if($value>0)
			return true;
		else if($value==0)
			return false;
		else
			return null; //error

	}
	
	// Return the number of rows
	public function getNumRows() {
		$this->_numRows = mysqli_num_rows($this->_result);
		return $this->_numRows;
	}
	
	// Fetches all the rows and return them as one array(array())
	public function getAllRows() {
		$rows = array();
		
		for($x = 0; $x < $this->getNumRows(); $x++) {
			$rows[] = mysqli_fetch_assoc($this->_result);
		}
		return $rows;
	}
	
	// fetch the top row from the result
	public function getTopRow() {
		return $this->_result->fetch_array();
	}
	
	// Securing input data
	public function secureInput($value) {
		$value=trim($value);
		return mysqli_real_escape_string($this->_connection, $value);
	}
}



class Util{

//give a unique GUID for CRUD operations on objects
	public static function getGUID(){
	    if (function_exists('com_create_guid')){
	        return com_create_guid();
	    }else{
	        mt_srand((double)microtime()*10000);//optional for php 4.2.0 and up.
	        $charid = strtoupper(md5(uniqid(rand(), true)));
	        $hyphen = chr(45);// "-"
	        $uuid = chr(123)// "{"
	            .substr($charid, 0, 8).$hyphen
	            .substr($charid, 8, 4).$hyphen
	            .substr($charid,12, 4).$hyphen
	            .substr($charid,16, 4).$hyphen
	            .substr($charid,20,12)
	            .chr(125);// "}"
	        return $uuid;
	    }
	}

   //give hashed password for a given password
	public static function getPasswordHash($Password){

		$Hash = password_hash($Password, PASSWORD_BCRYPT);
		return $Hash;
	}

	public static function random_password( $length = 8 ) {
	    $chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-=+;:,.?";
	    $password = substr( str_shuffle( $chars ), 0, $length );
	    return $password;
	}	

	public static function printToast($Message){
		
		echo '<script type="text/javascript" >
				document.write(printToast("'.$Message.'"));
			</script>';
		
	}
	
}

class LogUtil{

	private static $s_instance;

	private $_log_enabled=false;
	private $_log_level="info";
	private $_log_file_path;
	private $_log_file;

	public static $INFO="info";
	public static $DEBUG="debug";
	public static $WARN="warning";
	public static $ERROR="error";



	private function __construct(){

		$this->readLogConfig();
		$this->openFile();

	}


	public static function getInstance(){
		if(!self::$s_instance) { // If no instance then make one
			self::$s_instance = new self();
		}
		return self::$s_instance;

	}

	/*
	Reading Log related configuration file
	*/
	private function readLogConfig(){

		$_config = ConfigUtil::getInstance();

		$this->_log_enabled = $_config->isLogEnabled();
		$this->_log_level = $_config->getLogLevel();
		$this->_log_file_path = $_config->getLogFilePath();
	
	}

	//opening a flile
	private function openFile(){

		//$this->make_path($this->_log_file_path);
		$this->_log_file = fopen($this->_log_file_path, 'a') or die("can't create log file: ".$this->_log_file_path);
		

	}

	//checking whether a file exists or not
	//if exists do nothing, otherwise create a file
	private  function make_path($path){
			// Test if path extist
			if(is_dir($path) || file_exists($path))
			{
				return;
			}
			else
			{
				// Create it
				mkdir($path, 0777, true);
			}
	}

	//managing the log level
	public function log($level,$msg){

		switch ($level) {

		    case self::$INFO:	if(!strcmp($this->_log_level,self::$DEBUG)||!strcmp($this->_log_level,self::$WARN)||
		    						!strcmp($this->_log_level,self::$ERROR)){
		    						break;
		    					}
		    					else{
		    						$this->printMessage($level,$msg);
		        					break;
		    					}
		    							
			        
		    case self::$DEBUG:	if(!strcmp($this->_log_level,self::$WARN)||
		    						!strcmp($this->_log_level,self::$ERROR)){
		    						break;
		    					}
		    					else{
		    						$this->printMessage($level,$msg);
		        					break;
		    					}		        
		    case self::$WARN:	if(!strcmp($this->_log_level,self::$ERROR)){
		    						break;
		    					}
		    					else{
		    						$this->printMessage($level,$msg);
		        					break;
		    					}		        
		    case self::$ERROR:
		    					$this->printMessage($level,$msg);
		        				break;
		}

	}

	//finally writting the message following the level order
	private function printMessage($level,$msg){
		$log_time_stamp = date(DATE_RFC822);
		$log_string = "\n- [$log_time_stamp]\t$level:\t$msg\t@".$this->backtrace_caller();
		// Write (dump) log to file
		fputs($this->_log_file, $log_string);
		fflush($this->_log_file);

	}

	//finding the detailed information related to the debug trace
	private function backtrace_caller($backtrace_level = 1){

			// Fetch debug backtrace stack
			$trace	= debug_backtrace();
			// Extract file, line, class data
			// from from stack with given level
			$file 	= $trace[$backtrace_level]['file'];
			$line 	= $trace[$backtrace_level]['line'];
			$object = $trace[$backtrace_level]['object'];
			// If we are at the root class
			if ($object == null)
			{
				// Define it as root instead of '' or null.
				$object = 'root';
			}
			else if(is_object($object))
			{
				// Get objects class, if it is an object.
				// it is, isn't it. it must be...
				$object = get_class($object);
			}
			return "file:\"".$file."\", object:\"".$object."\", line:".$line;
	}

	//while the system closes the file also closes, otherwise it is open
	function __destruct() {
       // Close log file
			fclose($this->_log_file);
	
   }



}

class LangUtil{

	private static $s_instance; //The single instance

	private $_lang_default;

	private static $_lang_array;

	/*
	Get an instance of the language
	@return Instance
	*/
	public static function getInstance() {
		if(!self::$s_instance) { // If no instance then make one
			self::$s_instance = new self();
		}
		return self::$s_instance;
	}

	// Constructor
	private function __construct() {

		$this->readLangConfig();
	}

	private function readLangConfig(){

		$_config = ConfigUtil::getInstance();

		//getting the default language text
		$this->_lang_default = $_config->getDefaultLanguage();

		self::$_lang_array = parse_ini_file(LANGUAGE.'lang_'.$this->_lang_default.'.txt');

	}

	public static function get($ID){

		if(array_key_exists($ID, self::$_lang_array))
			return self::$_lang_array[$ID];
		else 
			return '['.$ID.']';
	}
}

ConfigUtil::getInstance();
DBUtil::getInstance();
LogUtil::getInstance();
LangUtil::getInstance();

//$_Log->log(LogUtil::$DEBUG," exit the util");

?>