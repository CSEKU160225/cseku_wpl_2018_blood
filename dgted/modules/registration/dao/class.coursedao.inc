<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once UTILITY.'class.util.inc';
include_once 'class.coursedao.inc';
include_once 'class.registration_sessiondao.inc';
include_once 'class.termdao.inc';
include_once 'class.yeardao.inc';
include_once MODULES_USER.'dao/class.userdao.inc'; //module dependecy


Class CourseDAO{

	private $_DB;
	private $_CourseStudentRegistration;
	private $_UserDAO;
	private $_RegistrationSessionDAO;
	private $_YearDAO;
	private $_TermDAO;

	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_CourseStudentRegistration = new CourseStudentRegistration();
		$this->_UserDAO = new UserDAO();
		$this->_RegistrationSessionDAO = new RegistrationSessionDAO();
		$this->_YearDAO = new YearDAO();
		$this->_TermDAO = new TermDAO();

	}

	// get all the Courses from the database using the database query
	public function getAllCourses(){

		$CourseList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course Order by CourseNo ASC");

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Course = new Course();
			$this->_Course->setID($row['ID']);
		    $this->_Course->setCourseNo($row['CourseNo']);
		    $this->_Course->setTitle($row['Title']);
		    $this->_Course->setCredit($row['Credit']);
		    
		    
		    
			$this->_Course->setISdeleted($row['IsDeleted']);
			//echo '<br> DAO = '.$this->_Course->getISdeleted()." -> ". $row['IsDeleted'];
		    $coursetypeid = $row['CourseTypeID'];
		    $this->_DB->doQuery("SELECT * FROM reg_course_type where ID='".$coursetypeid."'");

			$newrows = $this->_DB->getAllRows();

			for($j = 0; $j < sizeof($newrows); $j++) {
				$newrow = $newrows[$j];
			
		    	$value = $newrow['Name'] ;
		    
			}
			$this->_Course->setCourseTypeID($value);
		    
		    $disciplineid = $row['DisciplineID'];
		    $this->_DB->doQuery("SELECT * FROM ums_discipline where ID='".$disciplineid."'");

			$newrows = $this->_DB->getAllRows();

			for($j = 0; $j < sizeof($newrows); $j++) {
				$newrow = $newrows[$j];
			
		    	$value = $newrow['Name'] ;
		    
			}
			$this->_Course->setDisciplineID($value);
			
		    $CourseList[]=$this->_Course;

   
		}

		//todo: LOG util with level of log


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseList);

		return $Result;
	}

	// get all the Courses from the database based on the search query
	public function searchAllCourses($CourseNo){

		$CourseList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course where CourseNo LIKE '$CourseNo'");

		if($this->_DB->getNumRows()>=1)
		{

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
			$this->_Course = new Course();
			$this->_Course->setID($row['ID']);
		    $this->_Course->setCourseNo($row['CourseNo']);
		    $this->_Course->setTitle($row['Title']);
		    $this->_Course->setCredit($row['Credit']);		    
			$this->_Course->setISdeleted($row['IsDeleted']);
			//echo '<br> DAO = '.$this->_Course->getISdeleted()." -> ". $row['IsDeleted'];
		    $coursetypeid = $row['CourseTypeID'];
		    $this->_DB->doQuery("SELECT * FROM reg_course_type where ID='".$coursetypeid."'");

			$newrows = $this->_DB->getAllRows();

			for($j = 0; $j < sizeof($newrows); $j++) {
				$newrow = $newrows[$j];
			
		    	$value = $newrow['Name'] ;
		    
			}
			$this->_Course->setCourseTypeID($value);
		    
		    $disciplineid = $row['DisciplineID'];
		    $this->_DB->doQuery("SELECT * FROM ums_discipline where ID='".$disciplineid."'");

			$newrows = $this->_DB->getAllRows();

			for($j = 0; $j < sizeof($newrows); $j++) {
				$newrow = $newrows[$j];
			
		    	$value = $newrow['Name'] ;
		    
			}
			$this->_Course->setDisciplineID($value);
			
		    $CourseList[]=$this->_Course;

   
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseList);

		}else{

		$Result = new Result();
		$Result->setIsSuccess(0);
		$Result->setResultObject("No courses found!");
		}

		return $Result;
	}

	// get all the Courses from the database for a student and related registration details
	public function searchCoursesOfStudent($StudentID,$SessionID,$YearID,$TermID){

		$CourseStudentRegistrationList = array();

		$this->_DB->doQuery("SELECT ID FROM ums_user where UniversityID='$StudentID' LIMIT 1");

		if($this->_DB->getNumRows()>=1)
		{

		$Student = $this->_DB->getTopRow(); //getting the student details
			
		$StudentID=$Student['ID']; //retrieving student id


		$SQL = 	"SELECT * FROM reg_course_student_registration where StudentID='$StudentID' AND SessionID='$SessionID' AND YearID='$YearID' AND TermID='$TermID'";

		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
	
			$this->_CourseStudentRegistration = new CourseStudentRegistration();

			$Course = new Course();
			$Course->setID($row['CourseID']);
			//getting the course details from existing function
			$Course = $this->readCourse($Course)->getResultObject();   
			$this->_CourseStudentRegistration->setCourse($Course);
	

			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
								readRegistrationSession($Session)->getResultObject();
		    $this->_CourseStudentRegistration->setSession($Result_Session);

		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseStudentRegistration->setYear($Result_year);

		    
		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseStudentRegistration->setTerm($Result_term);


			$User = new User();
			$User->setID($StudentID);
			$this->_CourseStudentRegistration->setStudent($User);

			$this->_CourseStudentRegistration->setStatus($row['Status']);			
		    
		    $CourseStudentRegistrationList[]= $this->_CourseStudentRegistration;
  
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		}else{

		$Result = new Result();
		$Result->setIsSuccess(0);
		$Result->setResultObject("No courses found!");
		}

		return $Result;
	}

	// get all the Courses from the database for a student and related registration details
	// for a given status e.g. registered
	public function searchCoursesOfStudent_Status($StudentID,$SessionID,$YearID,$TermID,$Status){

		$CourseStudentRegistrationList = array();

		$this->_DB->doQuery("SELECT ID FROM ums_user where UniversityID='$StudentID' LIMIT 1");

		if($this->_DB->getNumRows()>=1)
		{

		$Student = $this->_DB->getTopRow(); //getting the student details
			
		$StudentID=$Student['ID']; //retrieving student id


		$SQL = 	"SELECT * FROM reg_course_student_registration 
				where StudentID='$StudentID' 
				AND SessionID='$SessionID' 
				AND YearID='$YearID' 
				AND TermID='$TermID'
				AND Status='$Status'";

		$this->_DB->doQuery($SQL);

		$rows = $this->_DB->getAllRows();

		for($i = 0; $i < sizeof($rows); $i++) {
			$row = $rows[$i];
	
			$this->_CourseStudentRegistration = new CourseStudentRegistration();

			$Course = new Course();
			$Course->setID($row['CourseID']);
			//getting the course details from existing function
			$Course = $this->readCourse($Course)->getResultObject();   
			$this->_CourseStudentRegistration->setCourse($Course);
	

			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
								readRegistrationSession($Session)->getResultObject();
		    $this->_CourseStudentRegistration->setSession($Result_Session);

		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseStudentRegistration->setYear($Result_year);

		    
		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseStudentRegistration->setTerm($Result_term);


			$User = new User();
			$User->setID($StudentID);
			$this->_CourseStudentRegistration->setStudent($User);

			$this->_CourseStudentRegistration->setStatus($row['Status']);			
		    
		    $CourseStudentRegistrationList[]= $this->_CourseStudentRegistration;
  
		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		}else{

		$Result = new Result();
		$Result->setIsSuccess(0);
		$Result->setResultObject("No courses found!");
		}

		return $Result;
	}


	// get all the students that have registered to a certain course based on session, year, term
	public function searchAllStudents($CourseNo,$SessionID,$YearID,$TermID){

		$CourseStudentRegistrationList = array();

		$this->_DB->doQuery("SELECT * FROM reg_course where CourseNo='$CourseNo' LIMIT 1");


		if($this->_DB->getNumRows()>=1) // a course is found that match with the give courseno
		{

			$Course = $this->_DB->getTopRow(); //getting the course details
			
			$CourseID=$Course['ID']; //retrieving course id

			$SQL = "SELECT r.StudentID FROM reg_course_student_registration r, ums_user u where 
			r.StudentID=u.ID AND
			r.CourseID='$CourseID' AND r.SessionID='$SessionID' AND 
			r.YearID='$YearID' AND r.TermID='$TermID' AND 
			r.Status='registered' order by (u.UniversityID * 1) ASC";

			$this->_DB->doQuery($SQL);

			$rows = $this->_DB->getAllRows();

			for($i = 0; $i < sizeof($rows); $i++) {
				$row = $rows[$i];
				
				$this->_CourseStudentRegistration = new CourseStudentRegistration();
				
			    
				$User = new User();
				$User->setID($row['StudentID']);
				$Result_Student = $this->_UserDAO->readUser($User)->getResultObject();
				$this->_CourseStudentRegistration->setStudent($Result_Student);


				/*$Session = new RegistrationSession();
				$Session->setID($row['SessionID']);
				$Result_Session = $this->_RegistrationSessionDAO->
									readRegistrationSession($Session)->getResultObject();
			    $this->_CourseStudentRegistration->setSessionID($Result_Session->getName());

			    $Year = new Year();
			    $Year->setID($row['YearID']);
				$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
			    $this->_CourseStudentRegistration->setYearID($Result_year->getName());

			    
			    $Term = new Term();
			    $Term->setID($row['TermID']);
				$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
			    $this->_CourseStudentRegistration->setTermID($Result_term->getName());
			    */
			    
			    $CourseStudentRegistrationList[]=$this->_CourseStudentRegistration;
	  
			}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($CourseStudentRegistrationList);

		}else{

		$Result = new Result();
		$Result->setIsSuccess(0);
		$Result->setResultObject("No Students Registered!");
		}

		return $Result;
	}



	//create Course funtion with the Course object
	public function createCourse($Course){

		$ID=$Course->getID();
		$CourseNo=$Course->getCourseNo();
		$Title=$Course->getTitle();
		$Credit=$Course->getCredit();
		$CourseTypeID=$Course->getCourseTypeID();
		$DisciplineID = $Course->getDisciplineID();
		$isdlted = $Course->getISdeleted();
		$isdeletednmbr;
		if($isdlted == "Delete")
			$isdeletednmbr=1;
		else 
			$isdeletednmbr=0;


		$SQL = "INSERT INTO reg_course(ID, CourseNo, Title, Credit, CourseTypeID, DisciplineID, IsDeleted) VALUES ('$ID','$CourseNo','$Title','$Credit','$CourseTypeID','$DisciplineID','$isdeletednmbr')";
		


		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//read an Course object based on its id form Course object
	public function readCourse($Course){
		
		
		$SQL = "SELECT * FROM reg_course WHERE ID='".$Course->getID()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Course from the database
		$row = $this->_DB->getTopRow();
		
		$this->_Course = new Course();

		//preparing the Course object
			$this->_Course->setID($row['ID']);
		    $this->_Course->setCourseNo($row['CourseNo']);

		    $this->_Course->setTitle($row['Title']);
		    $this->_Course->setCredit($row['Credit']);
		    $this->_Course->setCourseTypeID($row['CourseTypeID']);
		    $this->_Course->setDisciplineID($row['DisciplineID']);
		    $this->_Course->setISdeleted($row['IsDeleted']);
			

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Course);
		
		return $Result;

	}

	//read an Course object based on its id form Course object
	public function readCourseFromCourseNo($Course){
		
		
		$SQL = "SELECT * FROM reg_course WHERE CourseNo='".$Course->getCourseNo()."'";
		$this->_DB->doQuery($SQL);

		//reading the top row for this Course from the database
		$row = $this->_DB->getTopRow();
		
		$this->_Course = new Course();

		//preparing the Course object
			$this->_Course->setID($row['ID']);
		    $this->_Course->setCourseNo($row['CourseNo']);

		    $this->_Course->setTitle($row['Title']);
		    $this->_Course->setCredit($row['Credit']);
		    $this->_Course->setCourseTypeID($row['CourseTypeID']);
		    $this->_Course->setDisciplineID($row['DisciplineID']);
		    $this->_Course->setISdeleted($row['IsDeleted']);
			

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_Course);
		
		return $Result;

	}


	//update an Course object based on its 
	public function updateCourse($Course){
		echo "<br>".$Course->getISdeleted().$Course->getCourseNo().$Course->getTitle().$Course->getCredit().$Course->getCourseTypeID().$Course->getDisciplineID();
		$SQL = "UPDATE reg_course SET CourseNo='".$Course->getCourseNo()."',
		Title='".$Course->getTitle()."',
		Credit='".$Course->getCredit()."',
		CourseTypeID='".$Course->getCourseTypeID()."',
		DisciplineID='".$Course->getDisciplineID()." ',
		IsDeleted='".$Course->getISdeleted()." '
		WHERE ID='".$Course->getID()."'";


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

	//delete an Course based on its id of the database
	public function deleteCourse($Course){


		$SQL = "DELETE from reg_course where ID ='".$Course->getID()."'";
	
		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.Coursedao.inc");

?>