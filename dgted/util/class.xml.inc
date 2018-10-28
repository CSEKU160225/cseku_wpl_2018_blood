<?php

include_once COMMON.'class.common.inc';



/*
 Read XML formatted permission items from the file and 
 map it with the Permission Object. 
 Todo: Make this class generic
*/
class XMLtoPermission{

    var $_filename;
    var $_parsed;
    private $_DB;

    public function __construct($fileToRead){
        
        $this->_filename = $fileToRead;       
    }

    /*
    Read XML file as XML parsing and map the value with Permission object
    */

    private function readXML() {

        // read the XML database of aminoacids
        $data = implode("", file($this->_filename));
        $parser = xml_parser_create();
        xml_parser_set_option($parser, XML_OPTION_CASE_FOLDING, 0);
        xml_parser_set_option($parser, XML_OPTION_SKIP_WHITE, 1);
        xml_parse_into_struct($parser, $data, $values, $tags);
        xml_parser_free($parser);

        // loop through the structures
        foreach ($tags as $key=>$val) {
            //todo: take this value as root in the constructor to make a generic version
            if ($key == "permission") {
                $perm_ranges = $val;
                // each contiguous pair of array entries are the 
                // lower and upper range for each permission definition
                for ($i=0; $i < count($perm_ranges); $i+=2) {
                    $offset = $perm_ranges[$i] + 1;
                    $len = $perm_ranges[$i + 1] - $offset;
                    //todo: change parsePermission to generic form
                    $tdb[] = $this->parsePermission(array_slice($values, $offset, $len));
                }
            } else {
                continue;
            }
        }
        echo '<br> permission load is successful';
        return $tdb;
    }

    /*Creating the tag, value pairs */
    private function parsePermission($pvalues) 
    {
        for ($i=0; $i < count($pvalues); $i++) {
            $perm[$pvalues[$i]["tag"]] = $pvalues[$i]["value"];
        }
        //todo: change permission object to generic form
        return new PermissionXML($perm);
    }

    // loads the xml to the permission objects and return the result
    public function load(){
        
        return $this->readXML();
    }

    //stores the already loaded permission data into the database
    public function saveInDB($Permissions){
        //first time storing all the permissions into the permission database
        
        $this->_DB = DBUtil::getInstance();

            //beginning a transaction   
        $this->_DB->getConnection()->begin_transaction(MYSQLI_TRANS_START_READ_WRITE);


        $this->_DB->doQuery('DELETE from ums_permission');


        for ($i=0; $i < sizeof($Permissions); $i++) { 
            $Permission = $Permissions[$i];

            
            $SQL = "INSERT INTO ums_permission(ID,Name,Category) 
                                        VALUES('".$Permission->id."','".$Permission->name."','".$Permission->category."')"; 
            
        
            $SQL = $this->_DB->doQuery($SQL);
        }   

        //closing the transaction
        $this->_DB->getConnection()->commit();

        echo '<br> permission saved to database';
    }


}


/*
    From XML Menu to Menu Object with submenus
*/
class XMLtoMenuUtil{

    public  static $s_instance;   
    private static $_FileName;
    private static $_Menus;
    private static $_OrganizedMenus;
  
    private function __construct($fileToRead=CONFIG.'xml/menu.xml'){
        
        self::$_FileName = $fileToRead;       
    }

    /*
    Get an instance of the Database
    @return Instance
    */
    public static function getInstance() {
        if(!self::$s_instance) { // If no instance then make one
            self::$s_instance = new self();
            self::load();
        }
        return self::$s_instance;
    }

    // Magic method clone is empty to prevent duplication of connection
    private function __clone() { }

   // loads the xml and initiate the loop through
    private static function load(){
   
        $xml = self::readXML();
        self::$_Menus = self::loop_through($xml);
        
    }   

    /*
    Read XML file as XML parsing and map the value with Permission object
    */

    private static function readXML() {

        // read the menu xml file
        $data = implode('', file(self::$_FileName));
        // use simplexml to read the file
        $xml = simplexml_load_string($data);
        return $xml;
    }

   
 

    /*loop through the menu xml*/
    private static function loop_through($xml){
      
        foreach ($xml as $key => $value) {

            if(strcasecmp($key,'menu')==0){
                //echo ''.$key.'<br>';
                $Menus[] = self::process_menu($value);
            }

        }

        return $Menus;
    }
    /*process menu items iteratively*/
    private static function process_menu($value1){

        $MenuXML = new MenuXML();  
        foreach ($value1 as $key => $value) {
            if(strcasecmp($key,'parentmenu')==0){
                $MenuXML->setParentTitle((string)$value);
                //echo '-p-'.$MenuXML->getParentTitle().'<br>';               
            }
            else if(strcasecmp($key,'title')==0){
                $MenuXML->setTitle((string)$value);
                //echo '..'.$MenuXML->getTitle().'<br>';
            }
            else if(strcasecmp($key,'link')==0){
                $MenuXML->setLink((string)$value);
                //echo '..'.$MenuXML->getTitle().'<br>';
            }
            else if(strcasecmp($key,'permissions')==0){
                $Permissions = self::process_permission($value);                
                $MenuXML->setPermissions($Permissions);
            }
        }

        return $MenuXML;
    }

    /*process permission items iteratively*/
    private static function process_permission($value1){
        
 
        foreach ($value1 as $key => $value) {
            if(strcasecmp($key,'permission')==0){
                $Permission = new Permission();
                $Permission->setID((string)$value);
                $Permission->setName((string)$value);

                $Permissions[]=$Permission;

            }
        }
        
        return $Permissions;

    }

    /*re organize the menus according to their parent child relationship by maching
      parent menu names */
    public static function reorganize_menu(){

        //TODO:: take menus to new array and do array_splice of $this->_Menus

         //looking for the first row menus that are the top ones
         for ($i=0; $i<sizeof(self::$_Menus); $i++) {

            //building the first row
            if(empty(self::$_Menus[$i]->getParentTitle()))
                self::$_OrganizedMenus[]= self::$_Menus[$i];
         
         }


         //going throug the first layer of menus
         for ($i=0; $i<sizeof(self::$_OrganizedMenus); $i++) {

             //looking for the second row menus to whom top row menus are parents
             for ($j=0; $j<sizeof(self::$_Menus); $j++) {

                //building the second row
                 if(!strcasecmp(self::$_OrganizedMenus[$i]->getTitle(),self::$_Menus[$j]->getParentTitle())){

                      self::$_OrganizedMenus[$i]->_Child[]=self::$_Menus[$j];
                                     
                }

             }
        
         }

            
         //going through the first layer
         for ($i=0; $i<sizeof(self::$_OrganizedMenus); $i++) {

             //going through the second layer

             for ($j=0; $j<sizeof(self::$_OrganizedMenus[$i]->_Child); $j++) {

                //building the third layer of menus    
                for($k=0;$k<sizeof(self::$_Menus); $k++){
                    
                     if(!strcasecmp(self::$_OrganizedMenus[$i]->_Child[$j]->getTitle(),
                        self::$_Menus[$k]->getParentTitle())
                        ){                    

                          self::$_OrganizedMenus[$i]->_Child[$j]->_Child[]= self::$_Menus[$k];
                    
                    }

                }
             
             }
            
         
         }


         return self::$_OrganizedMenus;       

    }

    /*
        UserPermission is an array of permission that is available to a logged user 
        to the system
    */
    public static function viewable_menu($UserPermissions){

        //taking each menu from the menu xml file
        for ($i=0; $i<sizeof(self::$_Menus); $i++) {
            
            //going through each permission
            foreach (self::$_Menus[$i]->getPermissions() as $Permission) {
                   
                //if any permission is available in the permission list    
                if(in_array($Permission->getID(), $UserPermissions)){
                    //this menu should be viewable   
                    self::$_Menus[$i]->setVisible(1);
                    break;
                 }

            }  

        }

    }




    /* return back all the menus*/
    public static function get_Menus(){
        return self::$_Menus;
    }

  

}

    
//$menu = new XMLtoMenu("c:/wamp64/www/2017_education/config/xml/menu.xml");
//$menu->load();
//$menu->viewable_menu(['COURSE_C','ROLE_C']);
//print_r($menu->reorganize_menu());



?>