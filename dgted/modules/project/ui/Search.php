<?php
ob_start();
session_start();
include_once 'connect.php';
$query = mysqli_query($connection,"SELECT ID FROM tbl_course");
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
    width:90%;
    font-size:16px;
    height: 35px;
}

input[type=date] {
    width:100%;
    font-size:16px;
    height: 35px;
}

input[type=checkbox] {
    width:10%;
    
    height: 20px;
    width: 20px;
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
    width: 90%;
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


<h3>Search By</h3>


<button name="center button" onclick="location.href='Main.php'" style="font-size:12pt;text-align: center;  color:black;background-color:white;border:2px solid #336600;padding:2px 15px;cursor:pointer; vertical-align:top; float: right">Home Page</button>

<button name="center button" onclick="location.href='Upload.php'" style="font-size:12pt;text-align: center;  color:black;background-color:white;border:2px solid #336600;padding:2px 15px;cursor:pointer; vertical-align:top; float: right">Page For Upload</button>

</header>



<form action="Search.php"method="POST">

<body>
<div id="form">
    
      <table width="100%" border="1" cellpadding="15" bgcolor=" #d9b3ff">


        <tr>
          
          
            <td>

            <input type="text" name="Tag" placeholder="Project Tag"/>
            <input type="checkbox" name="tag_check">

            </td>


          </tr>

          <tr>
          <td>
               <select id="select" type="text" name="CourseID" >

                <option value="">Select Course</option>
             <?php
               
              
                $que = "SELECT tbl_project.CourseID,tbl_course.CourseNo FROM tbl_project,tbl_course WHERE tbl_project.CourseID=tbl_course.ID";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['CourseID']."'>".$row['CourseNo']."</option>";

                 }
                 ?>          
          
               </select>

              <input type="checkbox" name="course_check">
        </tr>
         
         </td>
               

                <tr>
              <td >

           <select id="select" type="text" name="TermID" >
            <option value="">Select Term</option>
            <?php
               
              
                $que = "SELECT tbl_term.ID,tbl_term.Name,tbl_project.TermID FROM tbl_project,tbl_term WHERE tbl_project.TermID=tbl_term.ID";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['TermID']."'>".$row['Name']."</option>";

                 }
                 ?>          
          
               </select>
               <input type="checkbox" name="term_check">
          </td>
        </tr>

        <tr>
          <td >


           <select id="select" type="text" name="SessionID" >
            <option value="">Select Session</option>
            <?php
               
              
                $que = "SELECT SessionID FROM tbl_project";
                $res = mysqli_query($connection, $que);
                 while($row=mysqli_fetch_assoc($res)){                                                 
                 echo "<option value='".$row['SessionID']."'>".$row['SessionID']."</option>";

                 }
                 ?>          
          
               </select>
               <input type="checkbox" name="session_check">
          </td>
        </tr>
         <tr>
         <td>

         <input type="submit" name="search">
         </tr>
         </td>



        


</table>


<br>
<br>

</div>
</body>



</html>




<?php
$tag_string = "";
$course_string = "";
$term_string = "";
$course_string = "";

$query =" ";




if (isset($_POST['search']) && isset($_POST['tag_check'])=="" && isset($_POST['course_check'])=="" && isset($_POST['term_check'])=="" && isset($_POST['session_check'])==""){

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



}







else if (isset($_POST['search']))
  {
    $flag = 0;
  if (isset($_POST['tag_check']))
  {
    $tag_string = $_POST['Tag'];
    $tag_string = "\"$tag_string\"";
    if ($flag == 1)
      $query = $query." and tbl_project.Tag= ".$tag_string." ";
    else
     $query = $query." tbl_project.Tag = ".$tag_string." ";

    $flag =1;
    
  }
  if (isset($_POST['course_check']))
  {
    $course_string = $_POST['CourseID'];
    $course_string = "\"$course_string\"";
    if ($flag == 1)
      $query = $query." and tbl_project.CourseID= ".$course_string." ";
    else
     $query = $query." tbl_project.CourseID = ".$course_string." ";

    $flag =1;
  }
  if (isset($_POST['term_check']))
  {
    $term_string= $_POST['TermID'];
    $term_string = "\"$term_string\"";
    if ($flag == 1)
      $query = $query." and tbl_project.TermID = ".$term_string." ";
    else
      $query = $query." tbl_project.TermID = ".$term_string." ";
    $flag = 1;
  }

  if (isset($_POST['session_check']))
  {
    $session_string= $_POST['SessionID'];
    $session_string = "\"$session_string\"";
    if ($flag == 1)
      $query = $query." and tbl_project.SessionID = ".$session_string." ";
    else
      $query = $query." tbl_project.SessionID = ".$session_string." ";
    $flag = 1;
  }

    


  //$select="SELECT * FROM tbl_project "." WHERE ".$query;

 $sql = "SELECT tbl_project.ID as pro_ID,tbl_project_student.StudentID,tbl_user.FirstName,tbl_user.LastName,tbl_course.CourseNo,tbl_course.Title,tbl_course_type.Name,tbl_project.Title as pro_title,tbl_project.Description,tbl_project.Link,tbl_project.Tag,tbl_term.Name as term_name,tbl_project.SessionID,tbl_project.CreationDate,tbl_project.ProjectDate FROM tbl_user,tbl_term,tbl_project,tbl_course,tbl_project_student,tbl_course_type,tbl_course_teacher WHERE tbl_project.ID=tbl_project_student.ProjectID and tbl_project.CourseID=tbl_course_teacher.CourseID and tbl_project.SessionID=tbl_course_teacher.SessionID and tbl_project.CourseID=tbl_course.ID and tbl_course.CourseTypeID=tbl_course_type.ID and tbl_project.TermID=tbl_term.ID and tbl_user.ID=tbl_course_teacher.TeacherID and ".$query;
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


}


?>

