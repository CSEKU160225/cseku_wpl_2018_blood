<?php
// write dao object for each class
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.course.inc';
include_once COMMON.'class.common.result.inc';
include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'dao/class.course_typedao.inc'; //module dependency
include_once MODULES_REGISTRATION.'dao/class.coursedao.inc';
include_once MODULES_REGISTRATION.'dao/class.registration_sessiondao.inc';
include_once MODULES_REGISTRATION.'dao/class.yeardao.inc';
include_once MODULES_REGISTRATION.'dao/class.termdao.inc';
include_once MODULES_USER.'dao/class.userdao.inc'; //module dependency



Class MarksEntryDAO{

	private $_DB;
	private $_MarksEntry;
	private $_CourseTypeDAO;

	private $_CourseTeacher;
	private $_CourseDAO;
	private $_UserDAO;
	private $_RegistrationSessionDAO;
	private $_YearDAO;
	private $_TermDAO;


	public function __construct(){

		$this->_DB = DBUtil::getInstance();
		$this->_MarksEntry = new MarksEntry();
		$this->_CourseTypeDAO = new CourseTypeDAO();

		$this->_CourseTeacher = new CourseTeacher();
		$this->_CourseDAO = new CourseDAO();
		$this->_UserDAO = new UserDAO();
		$this->_RegistrationSessionDAO = new RegistrationSessionDAO();
		$this->_YearDAO = new YearDAO();
		$this->_TermDAO = new TermDAO();


	}

	// get marks setup of a course
	public function getCourseMarksSetup($CourseNo){

		$SQL = "SELECT m.* FROM reg_course c, rms_marks_setup m where c.CourseNo like'$CourseNo' AND 
				c.CourseTypeID=m.CourseTypeID AND m.IsDefault=1 LIMIT 1";

		$this->_DB->doQuery($SQL);

		$row = $this->_DB->getTopRow();

		$MarksSetup = new MarksSetup();

		$MarksSetup->setID ( $row['ID']);

		$CourseType = new CourseType();
		$CourseType->setID($row['CourseTypeID']);

		$MarksSetup->setCourseType( $this->_CourseTypeDAO
										->readCourseType($CourseType)
										->getResultObject());

		$MarksSetup->setHeaderID( $row['HeaderID'] );

		$MarksSetup->setHeaderName( $row['HeaderName'] );

		$MarksSetup->setHeaderMax( $row['HeaderMax'] );

		$MarksSetup->setIsDefault( $row['IsDefault'] );
	


		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($MarksSetup);

		return $Result;
	}


	// update marks table for a course for all the registered students
	public function updateCourseAllMarksEntry($MarksEntryList){


		foreach ($MarksEntryList as $MarksEntry) {
			
			$Result=$this->existsMarksEntry($MarksEntry);

			if($Result->getIsSuccess()==1){
				//update
				$ID = $Result->getResultObject(); //id of the row
				$MarksEntry->setID($ID);
				$this->updateTestsEntry($MarksEntry); //update with the content
 			}
			else{
				//insert
			  $this->createMarksEntry($MarksEntry);
			}

		}

		
		$Result->setIsSuccess(1);
		$Result->setResultObject("bulk operation successful");

		return $Result;
	}

	// update test table for a course for all the registered students
	public function updateCourseAllTestsEntry($MarksEntryList){

		//for each student from the list
		foreach ($MarksEntryList as $MarksEntry) {
			
			$Result=$this->existsTestsEntry($MarksEntry);

			if($Result->getIsSuccess()==1){
				//update
				$ID = $Result->getResultObject(); //id of the row
				$MarksEntry->setID($ID);
				$this->updateTestsEntry($MarksEntry); //update with the content
 			}
			else{
				//insert
			  $this->createTestsEntry($MarksEntry);
			}

		}

		
		$Result->setIsSuccess(1);
		$Result->setResultObject("bulk operation successful");

		return $Result;
	}


	// publish marks table for a course for all the registered students
	public function publishCourseAllMarksEntry($MarksEntryList){


		foreach ($MarksEntryList as $MarksEntry) {
			
			$Result=$this->existsMarksEntry_to_Publish($MarksEntry);

			if($Result->getIsSuccess()==1){
				//update
				$ID = $Result->getResultObject(); //id of the row
				$MarksEntry->setID($ID);
				$this->updateMarksEntry_to_Publish($MarksEntry); //update with the content
 			}
			else{
				//insert
			  $this->createMarksEntry_to_Publish($MarksEntry);
			}

		}

		
		$Result->setIsSuccess(1);
		$Result->setResultObject("bulk operation successful");

		return $Result;
	}


	// delete all marks entry from the marks table
	public function deleteCourseAllMarksEntry($MarksEntryList){


		foreach ($MarksEntryList as $MarksEntry) {
			
			$Result=$this->existsMarksEntry($MarksEntry);

			if($Result->getIsSuccess()==1){
				//delete
				$ID = $Result->getResultObject(); //id of the row
				$MarksEntry->setID($ID);
				$this->deleteMarksEntry($MarksEntry); //update with the content
				$Result->setResultObject("Bulk operation successful!");
 			}
			else{

				$Result->setResultObject("Nothing to delete!");
			}

		}

		return $Result;
	}


	//get marks of a specific student
	public function getAStudentCoursePublishedMarks($CourseID,$Session,$Year,$Term,$Student){
	
		//retrieving course no of the course id
		$SQL ="SELECT CourseNo from reg_course where ID='$CourseID' LIMIT 1";
		$SQL = $this->_DB->doQuery($SQL);
		$row = $this->_DB->getTopRow();

	 	$Result = new Result();		

		if($this->_DB->getNumRows()>0) 
		{
			$CourseNo = $row['CourseNo'];

			$SQL = "SELECT * FROM rms_course_marks_result_publish cmrp WHERE 
					cmrp.CourseNo='$CourseNo' AND
					cmrp.SessionID='$Session' AND
					cmrp.YearID='$Year' AND
					cmrp.TermID='$Term' AND
					cmrp.StudentID='$Student' LIMIT 1";

				
			$SQL = $this->_DB->doQuery($SQL);

			if($this->_DB->getNumRows()>0) 
			{

				$row = $this->_DB->getTopRow();

				$MarksEntry = new MarksEntry();

				$MarksEntry->setID ( $row['ID']);

				$MarksEntry->setSession ( $row['SessionID']);

				$MarksEntry->setYear ( $row['YearID']);			

				$MarksEntry->setTerm ( $row['TermID']);	

				$MarksEntry->setStudent ( $row['StudentID']);	

				$MarksEntry->setMarksValue( $row['MarksValue']);

				$MarksEntry->setHeaderID( $row['HeaderID'] );

				$MarksEntry->setHeaderName( $row['HeaderName'] );

				$MarksEntry->setHeaderMax( $row['HeaderMax'] );

				$MarksEntry->setMarksTotal ( $row['MarksTotal'] );

				$MarksEntry->setFinalGrade ( $row['FinalGrade'] );

				$Result->setIsSuccess(1);	
				$Result->setResultObject($MarksEntry);	
			}
			else{ 

				$Result->setIsSuccess(0);
				$Result->setResultObject("Marks not found!");
			}

		}

		return $Result;

	}


	//get tests marks of a specific student
	public function getAStudentCourseTestMarks($CourseID,$Session,$Year,$Term,$Student){
	
		//retrieving course no of the course id
		$SQL ="SELECT CourseNo from reg_course where ID='$CourseID' LIMIT 1";
		$SQL = $this->_DB->doQuery($SQL);
		$row = $this->_DB->getTopRow();

	 	$Result = new Result();		

		if($this->_DB->getNumRows()>0) 
		{
			$CourseNo = $row['CourseNo'];

			$SQL = "SELECT * FROM rms_course_marks_tests WHERE 
					CourseNo='$CourseNo' AND
					SessionID='$Session' AND
					YearID='$Year' AND
					TermID='$Term' AND
					StudentID='$Student' LIMIT 1";

				
			$SQL = $this->_DB->doQuery($SQL);

			if($this->_DB->getNumRows()>0) 
			{

				$row = $this->_DB->getTopRow();

				$MarksEntry = new MarksEntry();

				$MarksEntry->setID ( $row['ID']);

				$MarksEntry->setSession ( $row['SessionID']);

				$MarksEntry->setYear ( $row['YearID']);			

				$MarksEntry->setTerm ( $row['TermID']);	

				$MarksEntry->setStudent ( $row['StudentID']);	

				$MarksEntry->setMarksValue( $row['MarksValue']);

	
				$Result->setIsSuccess(1);	
				$Result->setResultObject($MarksEntry);	
			}
			else{ 

				$Result->setIsSuccess(0);
				$Result->setResultObject("Marks not found!");
			}

		}

		return $Result;

	}


	// get marks for course of the students
	public function getCourseStudentMarks($CourseNo,$Session,$Year,$Term,$StudentList){

		$MarksEntryList = array();

		for ($i=0; $i < sizeof($StudentList) ; $i++) { 

			$Student = $StudentList[$i];

			$Student = $Student->getStudent()->getUniversityID(); // inside the object wrapped

			
			$SQL = "SELECT cmr.*, ms.HeaderID, ms.HeaderName, ms.HeaderMax
					FROM rms_marks_setup ms, rms_course_marks_result cmr 
					Where cmr.CourseNo='$CourseNo' AND
					cmr.SessionID='$Session'AND
					cmr.YearID='$Year' AND
					cmr.TermID='$Term' AND
					cmr.StudentID='$Student' AND
					cmr.MarksID=ms.ID LIMIT 1";

			$this->_DB->doQuery($SQL);

			$row = $this->_DB->getTopRow();

			if(isset($row) && $this->_DB->getNumRows()>0){

				$MarksEntry = new MarksEntry();

				$MarksEntry->setID ( $row['ID']);

				$MarksEntry->setSession ( $row['SessionID']);

				$MarksEntry->setYear ( $row['YearID']);			

				$MarksEntry->setTerm ( $row['TermID']);	

				$MarksEntry->setStudent ( $row['StudentID']);	

				$MarksEntry->setMarksID( $row['MarksID']);

				$MarksEntry->setMarksValue( $row['MarksValue']);

				$MarksEntry->setStatus( $row['Status']);

				$MarksEntry->setHeaderID( $row['HeaderID'] );

				$MarksEntry->setHeaderName( $row['HeaderName'] );

				$MarksEntry->setHeaderMax( $row['HeaderMax'] );

				$MarksEntryList[] = $MarksEntry;

			}

		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($MarksEntryList);

		return $Result;
	}

	// get class tests for course of the students
	public function getCourseStudentTests($CourseNo,$Session,$Year,$Term,$StudentList){

		$MarksEntryList = array();

		for ($i=0; $i < sizeof($StudentList) ; $i++) { 

			$Student = $StudentList[$i];

			$Student = $Student->getStudent()->getUniversityID(); // inside the object wrapped

			
			$SQL = "SELECT * FROM rms_course_marks_tests 
					WHERE CourseNo='$CourseNo' AND
					SessionID='$Session'AND
					YearID='$Year' AND
					TermID='$Term' AND
					StudentID='$Student' LIMIT 1";

			$this->_DB->doQuery($SQL);

			$row = $this->_DB->getTopRow();

			if(isset($row) && $this->_DB->getNumRows()>0){

				$MarksEntry = new MarksEntry();

				$MarksEntry->setID ( $row['ID']);

				$MarksEntry->setSession ( $row['SessionID']);

				$MarksEntry->setYear ( $row['YearID']);			

				$MarksEntry->setTerm ( $row['TermID']);	

				$MarksEntry->setStudent ( $row['StudentID']);	

				$MarksEntry->setMarksValue( $row['MarksValue']);

				$MarksEntryList[] = $MarksEntry;

			}

		}

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($MarksEntryList);

		return $Result;
	}

	//return course teacher row from the table based on the given criteria
	public function readCourseTeacher($CourseNo,$TeacherID,$SessionID,$YearID,$TermID){

		$Result = new Result();

		$SQL = "SELECT * FROM reg_course WHERE CourseNo='$CourseNo' LIMIT 1";

		$SQL = $this->_DB->doQuery($SQL);

		if($this->_DB->getNumRows()>0)
		{
			
			$row = $this->_DB->getTopRow();

			$CourseID=$row['ID'];	


			$SQL = "SELECT * FROM reg_course_teacher where TeacherID='$TeacherID' AND
					CourseID='$CourseID' AND
					SessionID='$SessionID' AND
					YearID='$YearID' AND
					TermID='$TermID' LIMIT 1";

			$this->_DB->doQuery($SQL);

			//reading the top row for this Course from the database
			$row = $this->_DB->getTopRow();

			$this->_CourseTeacher = new CourseTeacher();

			//preparing the Course object
			$this->_CourseTeacher->setID($row['ID']);
			
			$Course = new Course();
	 		$Course->setID($row['CourseID']);
			$Result_course = $this->_CourseDAO->readCourse($Course)->getResultObject();
			$this->_CourseTeacher->setCourse($Result_course);
		    
			$User = new User();
			$User->setID($row['TeacherID']);

			$Result_teacher = $this->_UserDAO->readUser($User)->getResultObject();
			$this->_CourseTeacher->setTeacher($Result_teacher);


			$Session = new RegistrationSession();
			$Session->setID($row['SessionID']);
			$Result_Session = $this->_RegistrationSessionDAO->
										readRegistrationSession($Session)->getResultObject();
		    $this->_CourseTeacher->setSession($Result_Session);
		    
		    $Year = new Year();
		    $Year->setID($row['YearID']);
			$Result_year = $this->_YearDAO->readYear($Year)->getResultObject();
		    $this->_CourseTeacher->setYear($Result_year);


		    $Term = new Term();
		    $Term->setID($row['TermID']);
			$Result_term = $this->_TermDAO->readTerm($Term)->getResultObject();
		    $this->_CourseTeacher->setTerm($Result_term);


		    $this->_CourseTeacher->setNoOfTests($row['NoOfTests']);

		}

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($this->_CourseTeacher);

		return $Result;

	}


	//create MarksEntry funtion with the MarksEntry object
	public function createMarksEntry($MarksEntry){

		$ID=Util::getGUID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Teacher=$MarksEntry->getTeacher();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksID = $MarksEntry->getMarksID();
	    $MarksValue=$MarksEntry->getMarksValue();
	    $Status=$MarksEntry->getStatus();

		$SQL = "INSERT INTO rms_course_marks_result(ID,CourseNo,TeacherID,SessionID,YearID,TermID,StudentID,MarksID,MarksValue,Status) 
							VALUES('$ID','$CourseNo','$Teacher','$Session','$Year','$Term','$Student','$MarksID',
							'$MarksValue','$Status')";

		//echo $SQL;
							
		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	//create MarksEntry funtion with the MarksEntry object for the tests table
	public function createTestsEntry($MarksEntry){

		$ID=Util::getGUID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Teacher=$MarksEntry->getTeacher();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksValue=$MarksEntry->getMarksValue();
	 
		$SQL = "INSERT INTO rms_course_marks_tests(ID,CourseNo,TeacherID,SessionID,YearID,TermID,StudentID,MarksValue) 
							VALUES('$ID','$CourseNo','$Teacher','$Session','$Year','$Term','$Student',
							'$MarksValue')";

		//echo $SQL;
							
		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		
		//read student details
		$User_Student = new User();
		$User_Student->setID($Student);
		$User_Student = $this->_UserDAO->readUser($User_Student)->getResultObject();

		//read session details
		$User_Session = new RegistrationSession();
		$User_Session->setID($Session);
		$User_Session = $this->_RegistrationSessionDAO->readRegistrationSession($User_Session)
								->getResultObject();

		//send email to the student about update in the course
		$this->send_email_to_student_for_tests_update($User_Student,$User_Session,$CourseNo);		


		return $Result;
	}

	private function send_email_to_student_for_tests_update($User_Student,$User_Session,$CourseNo){

		$subject = 'Test marks updated';
		$msg = $User_Student->getFullName().' ('. $User_Student->getUniversityID() .') your test marks for course: '.$CourseNo.' updated for session: '.$User_Session->getName();
		$headers = 'From: kucse@dgted.com';

		mail($User_Student->getEmail(),$subject,$msg,$headers);

	
	}



	//create MarksEntry funtion with the MarksEntry object for the publish result table
	public function createMarksEntry_to_Publish($MarksEntry){

		$ID=Util::getGUID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();

	    $HeaderID=$MarksEntry->getHeaderID();
	    $HeaderName=$MarksEntry->getHeaderName();
	    $HeaderMax=$MarksEntry->getHeaderMax();
	    
	    $MarksValue=$MarksEntry->getMarksValue();
	    $MarksTotal=$MarksEntry->getMarksTotal();


	    $Grades=$MarksEntry->getGrades();
	    $GradeRanges=$MarksEntry->getGradeRanges();
	    $FinalGrade=$MarksEntry->getFinalGrade();

		$SQL = "INSERT INTO rms_course_marks_result_publish(ID,CourseNo,SessionID,YearID,TermID,
						StudentID,HeaderID,HeaderName,HeaderMax,MarksValue,MarksTotal,
						Grades,GradeRanges,FinalGrade) 
							VALUES('$ID','$CourseNo','$Session','$Year','$Term',
							'$Student','$HeaderID','$HeaderName','$HeaderMax','$MarksValue','$MarksTotal',
							'$Grades','$GradeRanges','$FinalGrade')";

		//echo $SQL;
							
		$SQL = $this->_DB->doQuery($SQL);		
		
	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;
	}

	
	//read an MarksEntry object based on its details
	public function existsMarksEntry($MarksEntry){
		
		$ID=$MarksEntry->getID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksID = $MarksEntry->getMarksID();
	    $MarksValue=$MarksEntry->getMarksValue();		
		
		$SQL = "SELECT * FROM rms_course_marks_result cmr WHERE 
				cmr.CourseNo='$CourseNo' AND
				cmr.SessionID='$Session'AND
				cmr.YearID='$Year' AND
				cmr.TermID='$Term' AND
				cmr.StudentID='$Student' AND 
				cmr.MarksID='$MarksID'";
		
		$SQL = $this->_DB->doQuery($SQL);
		$Row = $this->_DB->getTopRow();

	 	$Result = new Result();		


		if($this->_DB->getNumRows()>0) 
		{
			$Result->setIsSuccess(1);
			$Result->setResultObject($Row['ID']);
		
		}
		else{ 

			$Result->setIsSuccess(0);
		}

		return $Result;
	}


	//read an MarksEntry object based on its details from the tests table
	public function existsTestsEntry($MarksEntry){
		
   
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksValue=$MarksEntry->getMarksValue();		
		
		$SQL = "SELECT * FROM rms_course_marks_tests WHERE 
				CourseNo='$CourseNo' AND
				SessionID='$Session'AND
				YearID='$Year' AND
				TermID='$Term' AND
				StudentID='$Student'";
		
		$SQL = $this->_DB->doQuery($SQL);
		$Row = $this->_DB->getTopRow();

	 	$Result = new Result();		


		if($this->_DB->getNumRows()>0) 
		{
			$Result->setIsSuccess(1);
			$Result->setResultObject($Row['ID']);
		
		}
		else{ 

			$Result->setIsSuccess(0);
		}

		return $Result;
	}


	//read an MarksEntry object based on its details from the published result table
	public function existsMarksEntry_to_Publish($MarksEntry){
		
		$ID=$MarksEntry->getID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksID = $MarksEntry->getMarksID();	
		
		$SQL = "SELECT * FROM rms_course_marks_result_publish cmrp WHERE 
				cmrp.CourseNo='$CourseNo' AND
				cmrp.SessionID='$Session'AND
				cmrp.YearID='$Year' AND
				cmrp.TermID='$Term' AND
				cmrp.StudentID='$Student'";
		
		$SQL = $this->_DB->doQuery($SQL);
		$Row = $this->_DB->getTopRow();

	 	$Result = new Result();		


		if($this->_DB->getNumRows()>0) 
		{
			$Result->setIsSuccess(1);
			$Result->setResultObject($Row['ID']);
		
		}
		else{ 

			$Result->setIsSuccess(0);
		}

		return $Result;
	}


	
	//update an MarksEntry object based on its content
	public function updateMarksEntry($MarksEntry){

		$ID=$MarksEntry->getID();	   
	    
	    $CourseNo=$MarksEntry->getCourse();
	    $Teacher=$MarksEntry->getTeacher();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksID = $MarksEntry->getMarksID();
	    $MarksValue=$MarksEntry->getMarksValue();
	    $Status=$MarksEntry->getStatus();

		$SQL = "UPDATE rms_course_marks_result SET CourseNo='$CourseNo',TeacherID='$Teacher',
				SessionID='$Session',YearID='$Year',TermID='$Term',StudentID='$Student',
				MarksValue='$MarksValue',Status='$Status' WHERE ID='$ID'"; 

				

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	//update an MarksEntry object based on its content for the tests
	public function updateTestsEntry($MarksEntry){

		$ID=$MarksEntry->getID();	   
	    
	    $CourseNo=$MarksEntry->getCourse();
	    $Teacher=$MarksEntry->getTeacher();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksValue=$MarksEntry->getMarksValue();

	    //read the current mark in the database
	    $SQL = "SELECT MarksValue from rms_course_marks_tests where ID='$ID'";

	    $SQL = $this->_DB->doQuery($SQL); 	    

	    if($this->_DB->getNumRows()>0){ // if there is marks

	    	$Row = $this->_DB->getTopRow();

	    	$Value = $Row['MarksValue'];

	    	if(strcasecmp($Value, $MarksValue)!=0) //if marks changed
	    	{

				$SQL = "UPDATE rms_course_marks_tests SET CourseNo='$CourseNo',TeacherID='$Teacher',
					SessionID='$Session',YearID='$Year',TermID='$Term',StudentID='$Student',
					MarksValue='$MarksValue' WHERE ID='$ID'"; 

				$SQL = $this->_DB->doQuery($SQL); //update with new marks

				//read student details
				$User_Student = new User();
				$User_Student->setUniversityID($Student);
				$User_Student = $this->_UserDAO->readUser_By_UniversityID($User_Student)
												->getResultObject();

				//read session details
				$User_Session = new RegistrationSession();
				$User_Session->setID($Session);
				$User_Session = $this->_RegistrationSessionDAO
									->readRegistrationSession($User_Session)
									->getResultObject();

				//send email to the student about update in the course
				$this->send_email_to_student_for_tests_update($User_Student,$User_Session,$CourseNo);	

			}
			
		}			

		$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


	//update an MarksEntry object based on its content for the result publish table
	public function updateMarksEntry_to_Publish($MarksEntry){

		$ID=$MarksEntry->getID();	   
	    
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();

	    $HeaderID=$MarksEntry->getHeaderID();
	    $HeaderName=$MarksEntry->getHeaderName();
	    $HeaderMax=$MarksEntry->getHeaderMax();
	    
	    $MarksValue=$MarksEntry->getMarksValue();
	    $MarksTotal=$MarksEntry->getMarksTotal();


	    $Grades=$MarksEntry->getGrades();
	    $GradeRanges=$MarksEntry->getGradeRanges();
	    $FinalGrade=$MarksEntry->getFinalGrade();


		$SQL = "UPDATE rms_course_marks_result_publish 
				SET CourseNo='$CourseNo', 
				SessionID='$Session',YearID='$Year',TermID='$Term',StudentID='$Student',
				HeaderID='$HeaderID',HeaderName='$HeaderName',HeaderMax='$HeaderMax',
				MarksValue='$MarksValue',MarksTotal='$MarksTotal',
				Grades='$Grades',GradeRanges='$GradeRanges',FinalGrade='$FinalGrade'
				WHERE ID='$ID'"; 

		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}


   //delete a MarksEntry object based on its content
	public function deleteMarksEntry($MarksEntry){
 
	    $ID=$MarksEntry->getID();	   
	    $CourseNo=$MarksEntry->getCourse();
	    $Session=$MarksEntry->getSession();
	    $Year=$MarksEntry->getYear();
	    $Term=$MarksEntry->getTerm();
	    $Student = $MarksEntry->getStudent();
	    $MarksID = $MarksEntry->getMarksID();


		$SQL = "DELETE from rms_course_marks_result WHERE ID='$ID'"; 


		$SQL = $this->_DB->doQuery($SQL);

	 	$Result = new Result();
		$Result->setIsSuccess(1);
		$Result->setResultObject($SQL);

		return $Result;

	}

}

//$_Log->log(LogUtil::$DEBUG," exit the class.MarksEntrydao.inc");

?>