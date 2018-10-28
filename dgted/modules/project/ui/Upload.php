<?php
ob_start();
session_start();
include_once 'connect.php';
?>

<html>
<style> 



@charset "utf-8";
/* CSS Document */

#form
{
  width:500px;
  
  margin:0px auto;
  text-align:center;
  
}
#form form input
{
  width:100%;
  height:35px;
}
input[type=submit]
{
  width:30%;
  height:30px;
  font-size: 16px;
}

table, th, td,tr {

     border: solid   #abadaf   1px;
    text-align: center;
}

input[type=text] {
    width:100%;
    font-size:16px;
    height: 35px;
}

input[type=date] {
    width:100%;
    font-size:16px;
    height: 35px;
}

label{
    width:100%;
    font-size:16px;
    height: 35px;
    color: gray;
}

header {
    
    text-align: center;

  }

select{
    width: 100%;
    height: 35px;
    font-size:16px;
  }
  body{
    background-color: #FDD7E4;
  }
  
  
  
</style>
<header>
	<h1>Project Archive            
  

</h1>


<button name="center button" onclick="location.href='Main.php'" style="font-size:12pt;text-align: center;  color:black;background-color:white;border:2px solid #336600;padding:2px 15px;cursor:pointer; vertical-align:top; float: right">Home Page</button>

<button name="center button" onclick="location.href='Search.php'" style="font-size:12pt;text-align: center;  color:black;background-color:white;border:2px solid #336600;padding:2px 15px;cursor:pointer; vertical-align:top; float: right">Next Page For Search</button>

</header>






<form action="Upload.php" method="POST">

<body>
<div id="form">
    
      <table width="100%" border="1" cellpadding="15" bgcolor=" #d9b3ff">
        
        
        <tr>
          <td><input type="text" name="Title" placeholder="Project Title"/></td>
        </tr>


        <tr>
          <td><input type="text" name="Description" placeholder="Project Description"/></td>
        </tr>

        <tr>
          <td><input type="text" name="Link" placeholder="Project Link"/></td>
        </tr>

        <tr>
          <td>

           <input type="text" name="Tag" placeholder="Project Tag"/>
          </td>
        </tr>


        <tr>
          <td>
               <select id="select" type="text" name="CourseID" >

                <option value="">Course</option>
             <?php
               
              
                $que = "SELECT ID,CourseNo FROM tbl_course";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['ID']."'>".$row['CourseNo']."</option>";

                 }
                 ?>          
          
               </select>

        </tr>

        <tr>
          <td >


           <select id="select" type="text" name="TermID" >
            <option value="">Term</option>
            <?php
               
              
                $que = "SELECT * FROM tbl_term";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['ID']."'>".$row['Name']."</option>";

                 }
                 ?>          
          
               </select>
          </td>
        </tr>

        <tr>
          <td>
            <select id="select" type="text" name="SessionID" >

                <option value="">Session</option>
             <?php
               
              
                $que = "SELECT SessionID FROM tbl_course_marks_setup";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['SessionID']."'>".$row['SessionID']."</option>";

                 }
                 ?>          
          
               </select>


          </td>
        </tr>

        <tr>
          
          <td>
          <label > Creation Date </label>
          <input type="date" name="CreationDate" /></td>
        </tr>

        <tr>
          <td>
          <label > Project Date </label>
          <input type="date" name="ProjectDate" /></td></td>
        </tr>
  

        <tr>
          <td>

           <input type="submit" name="Insert" value="SAVE" />
          </td>
        </tr>




</table>
    


</div>
<br/>
<br/>







<?php

ob_start();



  if(isset($_POST['Insert'])!='')
  {


  $ID=mysqli_real_escape_string($connection,getGUID());
  $Title=mysqli_real_escape_string($connection,$_POST['Title']); 
  $Description=mysqli_real_escape_string($connection,$_POST['Description']);
                  
  $Link=mysqli_real_escape_string($connection,$_POST['Link']);
  
  $Tag=mysqli_real_escape_string($connection,$_POST['Tag']);
  $CourseID=mysqli_real_escape_string($connection,$_POST['CourseID']);
  $TermID=mysqli_real_escape_string($connection,$_POST['TermID']);
  $SessionID=mysqli_real_escape_string($connection,$_POST['SessionID']);
  $CreationDate=mysqli_real_escape_string($connection,$_POST['CreationDate']);
  $ProjectDate=mysqli_real_escape_string($connection,$_POST['ProjectDate']);
  //$type=$_POST['type'];
  if($Title==''||$Description==''||$Link==''||$Tag==''||$CourseID==''||$TermID==''||$SessionID==''||$CreationDate==''||$ProjectDate=='')
   { echo'<script language="javascript">';
echo'alert("wrong entry ")';
echo '</script>';


 }
 else {
  $add=mysqli_query($connection,"INSERT INTO tbl_project (ID,Title,Description,Link,Tag,CourseID,TermID,SessionID,CreationDate,ProjectDate)VALUES
                                      ('$ID','$Title','$Description','$Link','$Tag','$CourseID','$TermID','$SessionID','$CreationDate','$ProjectDate')");
  
  if($add)
  {
      $msg_success="Successfully added!!";
      echo "<script type='text/javascript'>alert('$msg_success');</script>";
    
  }
  else
  {
     $errormsg="Not added!!";
      echo "<script type='text/javascript'>alert('$errormsg');</script>";
  }
  }
}


$sql = "SELECT tbl_project.ID as pro_ID,tbl_project_student.StudentID,tbl_user.FirstName,tbl_user.LastName,tbl_course.CourseNo,tbl_course.Title,tbl_course_type.Name,tbl_project.Title as pro_title,tbl_project.Description,tbl_project.Link,tbl_project.Tag,tbl_term.Name as term_name,tbl_project.SessionID,tbl_project.CreationDate,tbl_project.ProjectDate FROM tbl_user,tbl_term,tbl_project,tbl_course,tbl_project_student,tbl_course_type,tbl_course_teacher WHERE tbl_project.ID=tbl_project_student.ProjectID and tbl_project.CourseID=tbl_course_teacher.CourseID and tbl_project.SessionID=tbl_course_teacher.SessionID and tbl_project.CourseID=tbl_course.ID and tbl_course.CourseTypeID=tbl_course_type.ID and tbl_project.TermID=tbl_term.ID and tbl_user.ID=tbl_course_teacher.TeacherID";
$result = $connection->query($sql);

if ($result->num_rows > 0) {
     // output data of each row
            echo "<table bgcolor=#D6F3FF ; ><tr><th>StudentID</th><th>Teacher</th><th>Course</th><th>CourseTitle</th><th>CourseType</th><th>Title</th><th>Description</th><th>Link</th><th>Tag</th><th>Term</th><th>Session</th><th>CreationDate</th><th>ProjectDate</th>    </tr>";
     // output data of each row
     while($row = $result->fetch_assoc()) {
         echo "<tr> <td>" . $row["StudentID"]. "</td>  <td>" . $row["FirstName"]. " " . $row["LastName"]. "</td> <td>" . $row["CourseNo"]. "</td> <td>" . $row["Title"]. "</td> <td>" . $row["Name"]. "</td> <td>" . $row["pro_title"]. "</td> <td> " . $row["Description"]. "</td> <td><a class='btn btn-primary btn-lg' href='".$row['Link']."'>LINK </a></td> <td> " . $row["Tag"]."</td>  <td>" . $row["term_name"]. "</td> <td>" . $row["SessionID"]. "</td> <td>" . $row["CreationDate"]. "</td> <td>" . $row["ProjectDate"]. "</td>   <td><a class='btn btn-primary btn-lg' href='Update.php?id=".$row['pro_ID']."' >Update</a></td> <td><a class='btn btn-primary btn-lg' href='Delete.php?id=".$row['pro_ID']."' >Delete</a></td> </tr>";
     }


     echo "</table>";
} 



 ob_end_flush();
?>


</body>



</html>




