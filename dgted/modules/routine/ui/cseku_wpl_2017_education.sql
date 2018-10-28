-- phpMyAdmin SQL Dump
-- version 3.5.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 17, 2017 at 04:20 PM
-- Server version: 5.5.25a
-- PHP Version: 5.4.4

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `cseku_wpl_2017_education`
--

-- --------------------------------------------------------

--
-- Table structure for table `tbl_club`
--

CREATE TABLE IF NOT EXISTS `tbl_club` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `CoverPhoto` varchar(100) NOT NULL,
  `Description` varchar(300) NOT NULL,
  `CreationDate` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_club_member`
--

CREATE TABLE IF NOT EXISTS `tbl_club_member` (
  `ClubID` varchar(40) NOT NULL,
  `MemberID` varchar(40) NOT NULL,
  `Designation` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_club_module`
--

CREATE TABLE IF NOT EXISTS `tbl_club_module` (
  `ClubID` varchar(20) NOT NULL,
  `ModuleName` varchar(50) NOT NULL,
  `IsVisible` tinyint(1) NOT NULL,
  `PositionX` int(11) NOT NULL,
  `PositionY` int(11) NOT NULL,
  `SizeX` int(11) NOT NULL,
  `SizeY` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course`
--

CREATE TABLE IF NOT EXISTS `tbl_course` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `Title` varchar(255) NOT NULL,
  `Credit` double NOT NULL,
  `CourseTypeID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL,
  `IsDeleted` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_course`
--

INSERT INTO `tbl_course` (`ID`, `CourseNo`, `Title`, `Credit`, `CourseTypeID`, `DisciplineID`, `IsDeleted`) VALUES
('2deff74ee4', 'CSE 2101', 'Data Structure', 3, 'Therory', '', 0),
('8ca21ae4a2', 'CSE 3203', 'Graphics Design', 3, 'Theory', '', 0),
('b36a8b43ef', 'CSE 3211', 'Networking', 3, 'Theory', 'Mathematics', 0),
('be2b228de6', 'CSE 3101', 'Operating System', 3, 'Theory', '', 0);

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_marks_attendance`
--

CREATE TABLE IF NOT EXISTS `tbl_course_marks_attendance` (
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `ClassDate` date NOT NULL,
  `IsPresent` tinyint(1) NOT NULL,
  `UseFace` tinyint(1) NOT NULL,
  `UseFinger` tinyint(1) NOT NULL,
  `UseSheet` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_marks_attendance_publish`
--

CREATE TABLE IF NOT EXISTS `tbl_course_marks_attendance_publish` (
  `CourseID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `TotalAttendance` int(11) NOT NULL,
  `TotalClass` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_marks_result`
--

CREATE TABLE IF NOT EXISTS `tbl_course_marks_result` (
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksID` varchar(50) NOT NULL,
  `MarksValue` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_marks_result_publish`
--

CREATE TABLE IF NOT EXISTS `tbl_course_marks_result_publish` (
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksTotal` double NOT NULL,
  `MarksGrade` varchar(10) NOT NULL,
  `GPA` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_marks_setup`
--

CREATE TABLE IF NOT EXISTS `tbl_course_marks_setup` (
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `MarksID` varchar(50) NOT NULL,
  `MarksHeader` varchar(20) NOT NULL,
  `MarksMax` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_resource`
--

CREATE TABLE IF NOT EXISTS `tbl_course_resource` (
  `CourseID` varchar(40) NOT NULL,
  `ResourceID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_sessional_type`
--

CREATE TABLE IF NOT EXISTS `tbl_course_sessional_type` (
  `ID` varchar(40) NOT NULL,
  `Name` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_student_registration`
--

CREATE TABLE IF NOT EXISTS `tbl_course_student_registration` (
  `StudentID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `IsRetake` tinyint(1) NOT NULL,
  `IsApproved` tinyint(1) NOT NULL,
  `IsDeleted` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_teacher`
--

CREATE TABLE IF NOT EXISTS `tbl_course_teacher` (
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_teacher_registration`
--

CREATE TABLE IF NOT EXISTS `tbl_course_teacher_registration` (
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_course_type`
--

CREATE TABLE IF NOT EXISTS `tbl_course_type` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL,
  `SessionalTypeID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_course_type`
--

INSERT INTO `tbl_course_type` (`ID`, `Name`, `SessionalTypeID`) VALUES
('213312412ewfwe', 'Theory', '2321'),
('2352erg', 'Laboratory', '43534');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discipline`
--

CREATE TABLE IF NOT EXISTS `tbl_discipline` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `SchoolID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_discipline`
--

INSERT INTO `tbl_discipline` (`ID`, `Name`, `SchoolID`) VALUES
('{0CF37516-06FE-41CD-93AD-D2D1652509D6}', 'Mathematics', ''),
('{560A0FC0-6221-497D-8D41-E584EE4BBEE3}', 'Architecture', ''),
('{63F3C00B-6168-4FBD-AB01-7A1FE413BDDE}', 'Statistics', ''),
('{AF41CC9F-3BCD-4952-9D02-17184CC40C79}', 'Urban and Rural Planning', ''),
('{B34A0580-0B92-49BD-84FB-929297B104C5}', 'Electrical and Communication Engineering', ''),
('{E03C2DC3-CAF3-477E-A851-0C11DF93FD3B}', 'Chemistry', ''),
('{E7280448-E379-424E-A11D-357F4334AC8D}', 'Physics', ''),
('{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'Computer Science and Engineering', '');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discipline_resource`
--

CREATE TABLE IF NOT EXISTS `tbl_discipline_resource` (
  `DisciplineID` varchar(40) NOT NULL,
  `ResourceID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion`
--

CREATE TABLE IF NOT EXISTS `tbl_discussion` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(150) NOT NULL,
  `CategoryID` varchar(40) NOT NULL,
  `Description` varchar(300) NOT NULL,
  `Tag` varchar(200) NOT NULL,
  `CreationDate` date NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion_category`
--

CREATE TABLE IF NOT EXISTS `tbl_discussion_category` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_discussion_comment`
--

CREATE TABLE IF NOT EXISTS `tbl_discussion_comment` (
  `CommentID` varchar(50) NOT NULL,
  `DiscussionID` varchar(40) NOT NULL,
  `Comment` varchar(300) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `CommentIDTop` varchar(50) NOT NULL,
  PRIMARY KEY (`CommentID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_file`
--

CREATE TABLE IF NOT EXISTS `tbl_file` (
  `ID` varchar(50) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Link` varchar(150) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_file_assign`
--

CREATE TABLE IF NOT EXISTS `tbl_file_assign` (
  `FileID` varchar(50) NOT NULL,
  `FileComment` varchar(300) NOT NULL,
  `IsApproved` tinyint(1) NOT NULL,
  `IsRejected` tinyint(1) NOT NULL,
  `CurrentUserID` varchar(40) NOT NULL,
  `IsPending` tinyint(1) NOT NULL,
  `HasSeen` tinyint(1) NOT NULL,
  `CreationDate` date NOT NULL,
  `ApproveDate` date NOT NULL,
  `AssignDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_marks_grade`
--

CREATE TABLE IF NOT EXISTS `tbl_marks_grade` (
  `MarksMin` double NOT NULL,
  `MarksMax` double NOT NULL,
  `MarksGrade` varchar(10) NOT NULL,
  `GPA` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_permission`
--

CREATE TABLE IF NOT EXISTS `tbl_permission` (
  `ID` varchar(100) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Category` varchar(100) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_permission`
--

INSERT INTO `tbl_permission` (`ID`, `Name`, `Category`) VALUES
('CLUB_C', 'CLUB_C', 'CLUB'),
('CLUB_D', 'CLUB_D', 'CLUB'),
('CLUB_R', 'CLUB_R', 'CLUB'),
('CLUB_U', 'CLUB_U', 'CLUB'),
('COURSE_C', 'COURSE_C', 'COURSE'),
('COURSE_D', 'COURSE_D', 'COURSE'),
('COURSE_R', 'COURSE_R', 'COURSE'),
('COURSE_U', 'COURSE_U', 'COURSE'),
('DISCIPLINE_C', 'DISCIPLINE_C', 'DISCIPLINE'),
('DISCIPLINE_D', 'DISCIPLINE_D', 'DISCIPLINE'),
('DISCIPLINE_R', 'DISCIPLINE_R', 'DISCIPLINE'),
('DISCIPLINE_U', 'DISCIPLINE_U', 'DISCIPLINE'),
('FILE_C', 'FILE_C', 'FILE'),
('FILE_D', 'FILE_D', 'FILE'),
('FILE_R', 'FILE_R', 'FILE'),
('FILE_U', 'FILE_U', 'FILE'),
('POSITION_C', 'POSITION_C', 'POSITION'),
('POSITION_D', 'POSITION_D', 'POSITION'),
('POSITION_R', 'POSITION_R', 'POSITION'),
('POSITION_U', 'POSITION_U', 'POSITION'),
('PROJECT_C', 'PROJECT_C', 'PROJECT'),
('PROJECT_D', 'PROJECT_D', 'PROJECT'),
('PROJECT_R', 'PROJECT_R', 'PROJECT'),
('PROJECT_U', 'PROJECT_U', 'PROJECT'),
('ROLE_C', 'ROLE_C', 'ROLE'),
('ROLE_D', 'ROLE_D', 'ROLE'),
('ROLE_R', 'ROLE_R', 'ROLE'),
('ROLE_U', 'ROLE_U', 'ROLE'),
('SCHOOL_C', 'SCHOOL_C', 'SCHOOL'),
('SCHOOL_D', 'SCHOOL_D', 'SCHOOL'),
('SCHOOL_R', 'SCHOOL_R', 'SCHOOL'),
('SCHOOL_U', 'SCHOOL_U', 'SCHOOL'),
('SESSION_C', 'SESSION_C', 'SESSION'),
('SESSION_D', 'SESSION_D', 'SESSION'),
('SESSION_R', 'SESSION_R', 'SESSION'),
('SESSION_U', 'SESSION_U', 'SESSION'),
('SURVEY_C', 'SURVEY_C', 'SURVEY'),
('SURVEY_D', 'SURVEY_D', 'SURVEY'),
('SURVEY_R', 'SURVEY_R', 'SURVEY'),
('SURVEY_U', 'SURVEY_U', 'SURVEY'),
('TERM_C', 'TERM_C', 'TERM'),
('TERM_D', 'TERM_D', 'TERM'),
('TERM_R', 'TERM_R', 'TERM'),
('TERM_U', 'TERM_U', 'TERM'),
('USER_C', 'USER_C', 'USER'),
('USER_D', 'USER_D', 'USER'),
('USER_R', 'USER_R', 'USER'),
('USER_U', 'USER_U', 'USER'),
('YEAR_C', 'YEAR_C', 'YEAR'),
('YEAR_D', 'YEAR_D', 'YEAR'),
('YEAR_R', 'YEAR_R', 'YEAR'),
('YEAR_U', 'YEAR_U', 'YEAR');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_position`
--

CREATE TABLE IF NOT EXISTS `tbl_position` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_position`
--

INSERT INTO `tbl_position` (`ID`, `Name`) VALUES
('{1BFE76DB-C2AA-4FAA-A23B-F43E6150A2F6}', 'Section Officer'),
('{2E024DF5-BD45-4EF2-A5E3-43BCA3E9777F}', 'Pro-vice Chancellor'),
('{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}', 'Assistant Professor'),
('{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}', 'Lecturer'),
('{818DE12F-60CC-42E4-BAEC-48EAAED65179}', 'Dean of School'),
('{928EE9FF-E02D-470F-9A6A-AD0EB38B848F}', 'Vice Chancellor'),
('{92FDDA3F-1E91-4AA3-918F-EB595F85790C}', 'Daywise Worker'),
('{932CB0EE-76C2-448E-A40E-2D167EECC479}', 'Registrar'),
('{ADA027D3-21C1-47AF-A21D-759CAFCFE58D}', 'Assistant Registrar'),
('{B76EB035-EA26-4CEB-B029-1C6129574D98}', 'Librarian'),
('{B78C7A7B-4D38-4025-8170-7B8C9F291946}', 'Head of Discipline'),
('{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}', 'Associate Professor'),
('{EB4880E2-01B3-4C6E-A2C9-89B6E5427C0A}', 'Professor');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_project`
--

CREATE TABLE IF NOT EXISTS `tbl_project` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `Description` varchar(200) NOT NULL,
  `Link` varchar(200) NOT NULL,
  `Tag` varchar(200) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `CreationDate` date NOT NULL,
  `ProjectDate` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_project_student`
--

CREATE TABLE IF NOT EXISTS `tbl_project_student` (
  `ProjectID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_question_archive`
--

CREATE TABLE IF NOT EXISTS `tbl_question_archive` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(50) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `Type` varchar(20) NOT NULL,
  `Tag` varchar(200) NOT NULL,
  `QuestionDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_registration_session`
--

CREATE TABLE IF NOT EXISTS `tbl_registration_session` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_resource`
--

CREATE TABLE IF NOT EXISTS `tbl_resource` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(40) NOT NULL,
  `Type` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_role`
--

CREATE TABLE IF NOT EXISTS `tbl_role` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_role`
--

INSERT INTO `tbl_role` (`ID`, `Name`) VALUES
('{1AF8A832-4C03-49C7-8071-C71D4EB4FC57}', 'Staff'),
('{3477F777-3F53-408B-9773-249C5937C2B8}', 'Teacher'),
('{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'Student'),
('{F9C458F2-5298-441F-AE63-7514029760C4}', 'Admin');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_role_permission`
--

CREATE TABLE IF NOT EXISTS `tbl_role_permission` (
  `Row` int(11) NOT NULL AUTO_INCREMENT,
  `RoleID` varchar(40) NOT NULL,
  `PermissionID` varchar(100) NOT NULL,
  PRIMARY KEY (`Row`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=616 ;

--
-- Dumping data for table `tbl_role_permission`
--

INSERT INTO `tbl_role_permission` (`Row`, `RoleID`, `PermissionID`) VALUES
(225, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'COURSE_C'),
(226, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'COURSE_D'),
(227, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'FILE_C'),
(228, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'FILE_D'),
(229, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'FILE_R'),
(230, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'FILE_U'),
(231, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'POSITION_C'),
(232, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'POSITION_D'),
(233, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'POSITION_R'),
(234, '{3477F777-3F53-408B-9773-249C5937C2B8}', 'POSITION_U'),
(441, '{1AF8A832-4C03-49C7-8071-C71D4EB4FC57}', 'FILE_C'),
(442, '{1AF8A832-4C03-49C7-8071-C71D4EB4FC57}', 'FILE_D'),
(443, '{1AF8A832-4C03-49C7-8071-C71D4EB4FC57}', 'SURVEY_U'),
(444, '{1AF8A832-4C03-49C7-8071-C71D4EB4FC57}', 'TERM_U'),
(557, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'CLUB_D'),
(558, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'CLUB_R'),
(559, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'COURSE_D'),
(560, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'PROJECT_C'),
(561, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'PROJECT_D'),
(562, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'PROJECT_R'),
(563, '{9CC63B6A-99BD-4710-B675-9881B5F7337A}', 'PROJECT_U'),
(564, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'CLUB_C'),
(565, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'CLUB_D'),
(566, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'CLUB_R'),
(567, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'CLUB_U'),
(568, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'COURSE_C'),
(569, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'COURSE_D'),
(570, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'COURSE_R'),
(571, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'COURSE_U'),
(572, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'DISCIPLINE_C'),
(573, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'DISCIPLINE_D'),
(574, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'DISCIPLINE_R'),
(575, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'DISCIPLINE_U'),
(576, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'FILE_C'),
(577, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'FILE_D'),
(578, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'FILE_R'),
(579, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'FILE_U'),
(580, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'POSITION_C'),
(581, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'POSITION_D'),
(582, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'POSITION_R'),
(583, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'POSITION_U'),
(584, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'PROJECT_C'),
(585, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'PROJECT_D'),
(586, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'PROJECT_R'),
(587, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'PROJECT_U'),
(588, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'ROLE_C'),
(589, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'ROLE_D'),
(590, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'ROLE_R'),
(591, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'ROLE_U'),
(592, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SCHOOL_C'),
(593, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SCHOOL_D'),
(594, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SCHOOL_R'),
(595, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SCHOOL_U'),
(596, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SESSION_C'),
(597, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SESSION_D'),
(598, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SESSION_R'),
(599, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SESSION_U'),
(600, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SURVEY_C'),
(601, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SURVEY_D'),
(602, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SURVEY_R'),
(603, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'SURVEY_U'),
(604, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'TERM_C'),
(605, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'TERM_D'),
(606, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'TERM_R'),
(607, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'TERM_U'),
(608, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'USER_C'),
(609, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'USER_D'),
(610, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'USER_R'),
(611, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'USER_U'),
(612, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'YEAR_C'),
(613, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'YEAR_D'),
(614, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'YEAR_R'),
(615, '{F9C458F2-5298-441F-AE63-7514029760C4}', 'YEAR_U');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_routine`
--

CREATE TABLE IF NOT EXISTS `tbl_routine` (
  `DayID` varchar(40) NOT NULL,
  `TimeID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `SlotNo` int(11) NOT NULL,
  `TeacherID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_routine_day`
--

CREATE TABLE IF NOT EXISTS `tbl_routine_day` (
  `ID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_routine_time`
--

CREATE TABLE IF NOT EXISTS `tbl_routine_time` (
  `ID` varchar(40) NOT NULL,
  `course_time` varchar(40) NOT NULL,
  `day_of_week` varchar(15) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_routine_time`
--

INSERT INTO `tbl_routine_time` (`ID`, `course_time`, `day_of_week`) VALUES
('1', '08:00 - 8:45', 'Sunday'),
('2', '08:50 - 09:40', 'Monday'),
('3', '09:40 - 10:50', 'Tuesday'),
('4', ' 10:50 - 11:40', 'Wednesday'),
('5', ' 11:40 - 12:20', 'Thursday'),
('6', ' 12:20 - 01:20', ''),
('7', '02:30 - 05:00', '');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_school`
--

CREATE TABLE IF NOT EXISTS `tbl_school` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `DeanID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_school`
--

INSERT INTO `tbl_school` (`ID`, `Name`, `DeanID`) VALUES
('{39DDC0C2-CFC2-4246-8748-8812B1751A5C}', 'Science Engineering and Technology', ''),
('{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}', 'Life Science', ''),
('{86E0F021-B30D-48D2-B177-247180633C5E}', 'Social Science', ''),
('{879375F7-0A15-4705-AC90-C6786D279EF1}', 'Law and Humanities', ''),
('{CE09AA38-205B-4F50-A0E0-14DB8686C912}', 'Fine Arts', '');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_survey`
--

CREATE TABLE IF NOT EXISTS `tbl_survey` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `Description` varchar(300) NOT NULL,
  `Link` varchar(100) NOT NULL,
  `TotalQuestions` int(11) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `CreationDate` date NOT NULL,
  `CompletionDate` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_survey_question`
--

CREATE TABLE IF NOT EXISTS `tbl_survey_question` (
  `ID` varchar(40) NOT NULL,
  `SurveyID` varchar(40) NOT NULL,
  `QuestionNo` int(11) NOT NULL,
  `QuestionType` varchar(20) NOT NULL,
  `IsVisible` tinyint(1) NOT NULL,
  `IsRequired` tinyint(1) NOT NULL,
  `QuestionValue` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_survey_question_filled`
--

CREATE TABLE IF NOT EXISTS `tbl_survey_question_filled` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `SurveyID` varchar(40) NOT NULL,
  `QuestionID` varchar(40) NOT NULL,
  `FilledValue` varchar(200) NOT NULL,
  `FilledUserID` varchar(40) NOT NULL,
  `FilledTime` date NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_survey_question_type`
--

CREATE TABLE IF NOT EXISTS `tbl_survey_question_type` (
  `ID` varchar(40) NOT NULL,
  `Type` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_survey_question_type`
--

INSERT INTO `tbl_survey_question_type` (`ID`, `Type`) VALUES
('ques_dropdown', 'Dropdown'),
('ques_radio', 'Radio'),
('ques_textInput', 'Text Input');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_teacher`
--

CREATE TABLE IF NOT EXISTS `tbl_teacher` (
  `teacher_id` int(11) NOT NULL AUTO_INCREMENT,
  `teacher_name` varchar(45) NOT NULL,
  PRIMARY KEY (`teacher_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_term`
--

CREATE TABLE IF NOT EXISTS `tbl_term` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(255) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_term`
--

INSERT INTO `tbl_term` (`ID`, `Name`) VALUES
('{19B15CDF-264C-4924-8608-258673BCC448}', 'B.Sc 8th'),
('{22EDE2D2-D36C-4160-9D2A-80184B8AD35B}', 'B.Sc 1st'),
('{298E9628-8DE2-4742-8F93-0491C01BB152}', 'M.Sc 1st'),
('{9C84629E-11FA-4459-A593-C9AD9CF0D3F2}', 'B.Sc 4th'),
('{9D35C1A5-8091-47BE-AF7E-160C95789EC3}', 'B.Sc 7th'),
('{B8541009-29AC-4988-B17B-91CA3E1E27E3}', 'B.Sc 5th'),
('{C0C2FBD3-75DB-4A6F-BB2A-3F131027A744}', 'B.Sc 6th'),
('{E2D0D30D-654E-4157-8F71-527023AFAB2F}', 'B.Sc 3rd'),
('{F3C92204-C532-4544-9729-858EFBED98A1}', 'M.Sc 3rd'),
('{F78D6E1A-8B11-46D3-A88A-BD6D8DA4532B}', 'M.Sc 2nd'),
('{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 'B.Sc 2nd');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user`
--

CREATE TABLE IF NOT EXISTS `tbl_user` (
  `teacher_id` int(15) NOT NULL AUTO_INCREMENT,
  `Email` varchar(50) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `FirstName` varchar(50) NOT NULL,
  `LastName` varchar(50) NOT NULL,
  PRIMARY KEY (`teacher_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

--
-- Dumping data for table `tbl_user`
--

INSERT INTO `tbl_user` (`teacher_id`, `Email`, `Password`, `FirstName`, `LastName`) VALUES
(1, 'mohidul@gmail.com', 'test', 'SM Mohidul', 'Islam          '),
(2, 'zahid@gmail.com', 'test', 'Md. Zahid', 'Islam     '),
(3, 'mkazi078@uottawa.ca', 'test', 'Kazi Masudul', 'Alam           '),
(4, 'alamgir@gmail.com', 'test', 'Sk Alamgir', 'Hossain   '),
(5, 'aakth072@uottawa.ca', 'test', 'Aysha', 'Akther     '),
(6, 'saikat@gmail.com', 'test', 'Saikat', 'Mondal  '),
(7, 'rafiq@gmail.com', 'test', 'Md. Rafiqul', 'Islam '),
(8, 'test@gmail.com', 'test', 'test', 'test '),
(10, 'asma@gmail.com', '12345', 'Samim', 'Arif'),
(11, 'asma@gmail.com', '12345', 'Samim', 'Arif'),
(12, 'test11@gmail.com', '12345', 'abc', 'vvv');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_discipline`
--

CREATE TABLE IF NOT EXISTS `tbl_user_discipline` (
  `UserID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_position`
--

CREATE TABLE IF NOT EXISTS `tbl_user_position` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `PositionID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=18 ;

--
-- Dumping data for table `tbl_user_position`
--

INSERT INTO `tbl_user_position` (`ID`, `UserID`, `PositionID`) VALUES
(1, '{9E2E6363-A0FF-4C0F-B58F-D162725FB702}', '{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}'),
(4, '{693F944F-328D-433A-9F94-459D92841645}', '{EB4880E2-01B3-4C6E-A2C9-89B6E5427C0A}'),
(10, '{8104FB4F-8E63-489D-8D90-DB45A9A2327B}', '{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}'),
(11, '{8B24B76D-9969-4F71-ABC4-6EE59355C686}', '{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}'),
(13, '{B51D020E-1BB9-4FA3-86BF-C32949367885}', '{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}'),
(14, '{E0F0AE1A-AECF-46C1-A148-4485036F3CCF}', '{EB4880E2-01B3-4C6E-A2C9-89B6E5427C0A}'),
(16, '{A4F96981-F014-46F6-BB93-87500C3CBB03}', '{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}'),
(17, '{0B2F4F89-2048-4504-AB17-0412CC624A05}', '{64D25DDA-16B6-47B8-BBFC-4E2AAF5680C7}');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user_role`
--

CREATE TABLE IF NOT EXISTS `tbl_user_role` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `RoleID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=50 ;

--
-- Dumping data for table `tbl_user_role`
--

INSERT INTO `tbl_user_role` (`ID`, `UserID`, `RoleID`) VALUES
(40, '{8104FB4F-8E63-489D-8D90-DB45A9A2327B}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(41, '{8B24B76D-9969-4F71-ABC4-6EE59355C686}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(42, '{8B24B76D-9969-4F71-ABC4-6EE59355C686}', '{F9C458F2-5298-441F-AE63-7514029760C4}'),
(43, '{B51D020E-1BB9-4FA3-86BF-C32949367885}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(44, '{E0F0AE1A-AECF-46C1-A148-4485036F3CCF}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(47, '{A4F96981-F014-46F6-BB93-87500C3CBB03}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(48, '{0B2F4F89-2048-4504-AB17-0412CC624A05}', '{3477F777-3F53-408B-9773-249C5937C2B8}'),
(49, '{0B2F4F89-2048-4504-AB17-0412CC624A05}', '{9CC63B6A-99BD-4710-B675-9881B5F7337A}');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_video`
--

CREATE TABLE IF NOT EXISTS `tbl_video` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(150) NOT NULL,
  `Description` varchar(300) NOT NULL,
  `TagID` varchar(40) NOT NULL,
  `Link` varchar(150) NOT NULL,
  `IsEmbed` tinyint(1) NOT NULL,
  `CreationDate` date NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_video_comment`
--

CREATE TABLE IF NOT EXISTS `tbl_video_comment` (
  `CommentID` varchar(40) NOT NULL,
  `Comment` varchar(150) NOT NULL,
  `CreatorID` varchar(40) NOT NULL,
  `VideoID` varchar(40) NOT NULL,
  `CommentIDTop` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tbl_video_tag`
--

CREATE TABLE IF NOT EXISTS `tbl_video_tag` (
  `VideoID` varchar(40) NOT NULL,
  `Tag` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `tb_routine_data`
--

CREATE TABLE IF NOT EXISTS `tb_routine_data` (
  `routine_id` int(11) NOT NULL AUTO_INCREMENT,
  `teacher_name` varchar(255) NOT NULL,
  `course_number` varchar(15) NOT NULL,
  `course_name` varchar(255) NOT NULL,
  `term_detail` varchar(10) NOT NULL,
  `course_of_day` varchar(10) NOT NULL,
  `class_time` varchar(10) NOT NULL,
  PRIMARY KEY (`routine_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `tb_routine_data`
--

INSERT INTO `tb_routine_data` (`routine_id`, `teacher_name`, `course_number`, `course_name`, `term_detail`, `course_of_day`, `class_time`) VALUES
(1, 'Masudul Alam Mani', 'CSE 4221', 'Pattern Recognition', '4-2', 'B.Sc 8th', '10:50 - 11');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
