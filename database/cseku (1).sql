-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Oct 28, 2018 at 02:12 PM
-- Server version: 5.7.19
-- PHP Version: 5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cseku`
--

-- --------------------------------------------------------

--
-- Table structure for table `blood`
--

DROP TABLE IF EXISTS `blood`;
CREATE TABLE IF NOT EXISTS `blood` (
  `bloodID` int(11) NOT NULL AUTO_INCREMENT,
  `userID` varchar(40) DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  `blood_donate_date` date DEFAULT NULL,
  PRIMARY KEY (`bloodID`)
) ENGINE=MyISAM AUTO_INCREMENT=30 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `blood`
--

INSERT INTO `blood` (`bloodID`, `userID`, `expire_date`, `blood_donate_date`) VALUES
(25, 'monir150227@gmail.com', '2019-01-24', '2018-10-26'),
(21, 'monir150227@gmail.com', '2018-09-11', '2018-06-13'),
(20, 'monir150227@gmail.com', '2018-09-10', '2018-06-12'),
(23, 'monir150227@gmail.com', '2019-01-23', '2018-10-25'),
(26, 'mehadi.cse16@gmail.com', '2018-09-12', '2018-06-14'),
(27, 'mehadi.cse16@gmail.com', '2019-01-24', '2018-10-26'),
(28, 'mkazi078@uottawa.ca', '2019-01-25', '2018-10-27'),
(29, 'abir@gmail.com', '2018-10-02', '2018-07-04');

-- --------------------------------------------------------

--
-- Table structure for table `jms_job`
--

DROP TABLE IF EXISTS `jms_job`;
CREATE TABLE IF NOT EXISTS `jms_job` (
  `ID` varchar(40) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `Details` varchar(1000) NOT NULL,
  `LastDateOfApplication` date NOT NULL,
  `Salary` float NOT NULL,
  `Qualification` varchar(500) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `notification_for_blood`
--

DROP TABLE IF EXISTS `notification_for_blood`;
CREATE TABLE IF NOT EXISTS `notification_for_blood` (
  `notificationID` int(11) NOT NULL AUTO_INCREMENT,
  `fromuserID` varchar(40) DEFAULT NULL,
  `touserID` varchar(40) DEFAULT NULL,
  `notification` varchar(1000) DEFAULT NULL,
  `read_unread` tinyint(1) DEFAULT NULL,
  `ndate` datetime DEFAULT NULL,
  `status` int(11) NOT NULL DEFAULT '0',
  `status_message` varchar(1000) DEFAULT NULL,
  `status_date` datetime DEFAULT NULL,
  PRIMARY KEY (`notificationID`)
) ENGINE=MyISAM AUTO_INCREMENT=161 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `notification_for_blood`
--

INSERT INTO `notification_for_blood` (`notificationID`, `fromuserID`, `touserID`, `notification`, `read_unread`, `ndate`, `status`, `status_message`, `status_date`) VALUES
(160, 'khalid@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 19:00:18', 0, NULL, NULL),
(159, 'shish150225@gmail.com', 'abir@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-28 18:50:22', 1, 'ok', '2018-10-28 18:55:03'),
(158, 'abir@gmail.com', 'shish150225@gmail.com', 'BLOOD NEEDED!!!O+ Blood need argent', 0, '2018-10-28 18:38:21', 1, 'Ok.I will donate blood', '2018-10-28 18:40:16'),
(157, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:25:36', 1, 'ok\r\n', '2018-10-27 17:26:23'),
(156, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:11:04', 2, NULL, '2018-10-27 17:26:26'),
(155, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 17:09:27', 2, NULL, '2018-10-27 17:26:29'),
(154, 'mehadi.cse16@gmail.com', 'naim16@gmail.com', 'BLOOD NEEDED!!! Wondering you might help!', 0, '2018-10-27 16:49:44', 1, 'cccc', '2018-10-27 16:52:13');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course`
--

DROP TABLE IF EXISTS `reg_course`;
CREATE TABLE IF NOT EXISTS `reg_course` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `Title` varchar(100) NOT NULL,
  `Credit` double NOT NULL,
  `CourseTypeID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL,
  `IsDeleted` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course`
--

INSERT INTO `reg_course` (`ID`, `CourseNo`, `Title`, `Credit`, `CourseTypeID`, `DisciplineID`, `IsDeleted`) VALUES
('{2A038C6A-B6DA-408D-8458-7493D4EE5D6C}', 'cse-3200', 'Web Programming Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 0),
('{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', 'cse-4112', 'Computer Networks Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', 0),
('{683A3D91-D124-44AF-82A3-FB43837A4392}', 'cse-4111', 'Computer Networks', 3, '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 0),
('{B17BDB32-6D88-4537-9545-65D940E17EEF}', 'cse-2115', 'Advanced Programming Lab', 1.5, '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5} ', 0);

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_resource`
--

DROP TABLE IF EXISTS `reg_course_resource`;
CREATE TABLE IF NOT EXISTS `reg_course_resource` (
  `CourseID` varchar(40) NOT NULL,
  `ResourceID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_sessional_type`
--

DROP TABLE IF EXISTS `reg_course_sessional_type`;
CREATE TABLE IF NOT EXISTS `reg_course_sessional_type` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_sessional_type`
--

INSERT INTO `reg_course_sessional_type` (`ID`, `Name`) VALUES
('{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}', 'N/A'),
('{45B2147F-5FE0-4CC9-880C-C19EB6323955}', 'physics'),
('{4B342686-B38E-449C-AAD2-1F7DD77E6594}', 'chemistry'),
('{D1E54E03-CDEB-4155-AD0C-27C70A3A490C}', 'ece'),
('{D3F895D3-7389-487F-A604-0BD546DCC764}', 'software'),
('{F1D0443A-EC5D-41C4-94BA-D6F0D9AB1691}', 'hardware');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_student_registration`
--

DROP TABLE IF EXISTS `reg_course_student_registration`;
CREATE TABLE IF NOT EXISTS `reg_course_student_registration` (
  `ID` varchar(40) NOT NULL,
  `Regs_TeacherID` varchar(40) DEFAULT NULL,
  `StudentID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `SessionID` varchar(40) DEFAULT NULL,
  `YearID` varchar(40) DEFAULT NULL,
  `TermID` varchar(40) DEFAULT NULL,
  `IsRetake` tinyint(1) DEFAULT NULL,
  `Status` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_student_registration`
--

INSERT INTO `reg_course_student_registration` (`ID`, `Regs_TeacherID`, `StudentID`, `CourseID`, `SessionID`, `YearID`, `TermID`, `IsRetake`, `Status`) VALUES
('{31FDEF1E-F280-436A-AFD3-A48BA772D23D}', 'mkazi078@uottawa.ca', 'kashif@gmail.com', '{683A3D91-D124-44AF-82A3-FB43837A4392}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'registered'),
('{3CA3ABF7-7FF8-4A32-B328-235861061B72}', 'mkazi078@uottawa.ca', 'zahid@gmail.com', '{683A3D91-D124-44AF-82A3-FB43837A4392}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'registered'),
('{B7F17833-430E-489A-9CA6-E9BBE0EFA0FD}', 'mkazi078@uottawa.ca', 'kashif@gmail.com', '{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'registered'),
('{B8B362F3-D164-4082-AA6C-08F3EC73E2A8}', 'mkazi078@uottawa.ca', 'aysha@gmail.com', '{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'registered'),
('{C8AE75F9-1644-48C5-87D0-4AFEC777C122}', 'mkazi078@uottawa.ca', 'zahid@gmail.com', '{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'submitted'),
('{DBE4ED93-4A97-41CF-B8E3-5E42AEC0246F}', 'mkazi078@uottawa.ca', 'aysha@gmail.com', '{683A3D91-D124-44AF-82A3-FB43837A4392}', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', NULL, 'registered');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_teacher`
--

DROP TABLE IF EXISTS `reg_course_teacher`;
CREATE TABLE IF NOT EXISTS `reg_course_teacher` (
  `ID` varchar(40) NOT NULL,
  `CourseID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `NoOfTests` int(10) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_teacher`
--

INSERT INTO `reg_course_teacher` (`ID`, `CourseID`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `NoOfTests`) VALUES
('{0BA78ECC-A6E7-4EA8-9BFA-6C599F88F76D}', '{53650FB7-D76E-459D-8B56-BC7A4919C0F6}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 5),
('{C4490FFA-154B-45FE-9773-744B3E6FDFF7}', '{683A3D91-D124-44AF-82A3-FB43837A4392}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', 3);

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_teacher_registration`
--

DROP TABLE IF EXISTS `reg_course_teacher_registration`;
CREATE TABLE IF NOT EXISTS `reg_course_teacher_registration` (
  `ID` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_teacher_registration`
--

INSERT INTO `reg_course_teacher_registration` (`ID`, `TeacherID`, `SessionID`, `YearID`, `TermID`) VALUES
('{4D389527-643B-4B05-80AB-E05A6EF8DE2A}', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}');

-- --------------------------------------------------------

--
-- Table structure for table `reg_course_type`
--

DROP TABLE IF EXISTS `reg_course_type`;
CREATE TABLE IF NOT EXISTS `reg_course_type` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL,
  `SessionalTypeID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_course_type`
--

INSERT INTO `reg_course_type` (`ID`, `Name`, `SessionalTypeID`) VALUES
('{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', 'Theory', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}'),
('{5F886686-4EB1-48C8-A801-8D46233739D1}', 'Thesis', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}'),
('{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', 'Sessional', '{126156BB-18ED-4CAB-8DB9-1C0F72BB63C1}');

-- --------------------------------------------------------

--
-- Table structure for table `reg_registration_session`
--

DROP TABLE IF EXISTS `reg_registration_session`;
CREATE TABLE IF NOT EXISTS `reg_registration_session` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(30) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_registration_session`
--

INSERT INTO `reg_registration_session` (`ID`, `Name`) VALUES
('{05DA37EB-6C62-45E9-A0E3-7C5C6943F6AD}', '2012-2013'),
('{1399EEA3-B939-4155-B9F3-4DAD4928C4D5}', '2014-2015'),
('{65C2BA57-7231-497A-A5A7-90912259684C}', '2011-2012'),
('{A36A7057-CDB5-4E10-9E61-CCC85C74460E}', '2013-2014'),
('{DFF9E45F-6954-46A1-9088-D930EE460C3F}', '2015-2016'),
('{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '2016-2017');

-- --------------------------------------------------------

--
-- Table structure for table `reg_term`
--

DROP TABLE IF EXISTS `reg_term`;
CREATE TABLE IF NOT EXISTS `reg_term` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_term`
--

INSERT INTO `reg_term` (`ID`, `Name`) VALUES
('{6DE3CF58-3A1A-4D6A-88CF-83F22C27E0BA}', 'Special'),
('{AF8B217E-4E76-41B8-A02A-7115BD4A6BE6}', '2nd'),
('{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '1st');

-- --------------------------------------------------------

--
-- Table structure for table `reg_year`
--

DROP TABLE IF EXISTS `reg_year`;
CREATE TABLE IF NOT EXISTS `reg_year` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `reg_year`
--

INSERT INTO `reg_year` (`ID`, `Name`) VALUES
('{1FAC0F1A-9D60-43F6-AB07-C933D5A4AA30}', 'Phd 1st'),
('{326B168F-58CC-42F3-B71A-DFE8DBBC05E8}', 'MSc 1st'),
('{6780C884-E112-4F58-9503-E2110B615547}', '4th'),
('{9F3A6CBC-0115-4EC2-ABB3-8CCA431F6C2B}', '1st'),
('{A21965E4-4FE4-43AC-A77F-DABAC9B356F2}', '3rd'),
('{ADBEDD3E-D8EA-47AA-A068-C4C703DB4AE6}', 'MSc 2nd'),
('{B9D6CC05-7AD4-4666-80AB-80797A872743}', 'Phd 2nd'),
('{CBE08035-94CD-4610-B4E2-A0E844184056}', 'Phd 4th'),
('{E3823AA6-6BE5-4A07-93EA-FA59DE4F616F}', 'Phd 3rd'),
('{EA335D18-A1A8-4D15-9C7B-4A4700AD4543}', '2nd');

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_result`
--

DROP TABLE IF EXISTS `rms_course_marks_result`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_result` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `TeacherID` varchar(40) DEFAULT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksID` varchar(40) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  `Status` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_course_marks_result`
--

INSERT INTO `rms_course_marks_result` (`ID`, `CourseNo`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `StudentID`, `MarksID`, `MarksValue`, `Status`) VALUES
('{44C3C858-AFC6-4592-B160-10B921BF381C}', 'cse-4111', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020202', '{7E24DC07-CD2C-4360-A6E9-05A363C2EA08}', '10,25,25,25', '');

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_result_publish`
--

DROP TABLE IF EXISTS `rms_course_marks_result_publish`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_result_publish` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `TeacherID` varchar(40) DEFAULT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `HeaderID` varchar(200) NOT NULL,
  `HeaderName` varchar(200) NOT NULL,
  `HeaderMax` varchar(200) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  `MarksTotal` varchar(20) NOT NULL,
  `Grades` varchar(200) NOT NULL,
  `GradeRanges` varchar(300) NOT NULL,
  `FinalGrade` varchar(20) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `rms_course_marks_tests`
--

DROP TABLE IF EXISTS `rms_course_marks_tests`;
CREATE TABLE IF NOT EXISTS `rms_course_marks_tests` (
  `ID` varchar(40) NOT NULL,
  `CourseNo` varchar(40) NOT NULL,
  `TeacherID` varchar(40) NOT NULL,
  `SessionID` varchar(40) NOT NULL,
  `YearID` varchar(40) NOT NULL,
  `TermID` varchar(40) NOT NULL,
  `StudentID` varchar(40) NOT NULL,
  `MarksValue` varchar(200) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_course_marks_tests`
--

INSERT INTO `rms_course_marks_tests` (`ID`, `CourseNo`, `TeacherID`, `SessionID`, `YearID`, `TermID`, `StudentID`, `MarksValue`) VALUES
('{037E6C4F-CAAE-4587-B3E1-1CC6E59101A4}', 'cse-4111', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020203', '12,20,20'),
('{222F2596-5F55-442C-80EA-F5AE7F466C70}', 'cse-4111', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020202', '15,25,20'),
('{71D63076-9096-4CAA-8D6D-782A25B076A7}', 'cse-4111', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020208', '15,20,20'),
('{B6BB339D-E40B-4CC4-8D34-07017EE2BE44}', 'cse-4112', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020208', '10,30,30,0,0'),
('{DBF1823F-0DF9-4E8F-9233-5AB1545BC1B7}', 'cse-4112', 'mkazi078@uottawa.ca', '{E11A301F-E0B9-47A5-AA3C-FB0B656B2A2A}', '{6780C884-E112-4F58-9503-E2110B615547}', '{F9121C67-1E89-4F0B-80AA-89FD3B6BD665}', '020202', '20,20,20,0,0');

-- --------------------------------------------------------

--
-- Table structure for table `rms_grade_setup`
--

DROP TABLE IF EXISTS `rms_grade_setup`;
CREATE TABLE IF NOT EXISTS `rms_grade_setup` (
  `ID` varchar(40) NOT NULL,
  `Grades` varchar(200) NOT NULL,
  `Ranges` varchar(300) NOT NULL,
  `IsDefault` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_grade_setup`
--

INSERT INTO `rms_grade_setup` (`ID`, `Grades`, `Ranges`, `IsDefault`) VALUES
('{FC3DBA75-AF9C-4533-825E-D8A01D076F60}', 'F,E,D,C,C+,B,B+,A-,A,A+', '0-39,40-44,45-49,50-54,55-59,60-64,65-69,70-74,75-79,80-100', 1);

-- --------------------------------------------------------

--
-- Table structure for table `rms_marks_setup`
--

DROP TABLE IF EXISTS `rms_marks_setup`;
CREATE TABLE IF NOT EXISTS `rms_marks_setup` (
  `ID` varchar(40) NOT NULL,
  `CourseTypeID` varchar(40) NOT NULL,
  `HeaderID` varchar(200) NOT NULL,
  `HeaderName` varchar(200) NOT NULL,
  `HeaderMax` varchar(200) NOT NULL,
  `IsDefault` tinyint(1) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `rms_marks_setup`
--

INSERT INTO `rms_marks_setup` (`ID`, `CourseTypeID`, `HeaderID`, `HeaderName`, `HeaderMax`, `IsDefault`) VALUES
('{236BBFE8-E4CF-4EEF-9C54-AD83FEF42ADB}', '{EF5CA3BF-A886-4450-ABC4-DED45C7600C0}', 'att,assess,viva', 'Attendance,Assessment,Viva', '10,60,30', 1),
('{7E24DC07-CD2C-4360-A6E9-05A363C2EA08}', '{3DC4DDE5-514F-4BE4-8682-37EA32C3FDB7}', 'att,assess,seca,secb', 'Attendance,Assessment,Section A,Section B', '10,30,30,30,30', 1);

-- --------------------------------------------------------

--
-- Table structure for table `ums_discipline`
--

DROP TABLE IF EXISTS `ums_discipline`;
CREATE TABLE IF NOT EXISTS `ums_discipline` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `ShortCode` varchar(20) DEFAULT NULL,
  `SchoolID` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_discipline`
--

INSERT INTO `ums_discipline` (`ID`, `Name`, `ShortCode`, `SchoolID`) VALUES
('{0CF37516-06FE-41CD-93AD-D2D1652509D6}', 'Mathematics', 'MATH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{560A0FC0-6221-497D-8D41-E584EE4BBEE3}', 'Architecture', 'ARCH', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{63F3C00B-6168-4FBD-AB01-7A1FE413BDDE}', 'Forestry and Wood Technology', 'FWT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{AF41CC9F-3BCD-4952-9D02-17184CC40C79}', 'Urban and Rural Planning', 'URP', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E065BBA7-D0C5-4DFA-9768-81B6F056EB4A}', 'Foresty and Marine Resource Technology', 'FMRT', '{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}'),
('{E7280448-E379-424E-A11D-357F4334AC8D}', 'Physics', 'PHY', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}'),
('{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'Computer Science and Engineering', 'CSE', '{39DDC0C2-CFC2-4246-8748-8812B1751A5C}');

-- --------------------------------------------------------

--
-- Table structure for table `ums_permission`
--

DROP TABLE IF EXISTS `ums_permission`;
CREATE TABLE IF NOT EXISTS `ums_permission` (
  `TableID` int(11) NOT NULL AUTO_INCREMENT,
  `ID` varchar(100) NOT NULL,
  `Name` varchar(100) NOT NULL,
  `Category` varchar(100) NOT NULL,
  PRIMARY KEY (`TableID`)
) ENGINE=InnoDB AUTO_INCREMENT=4909 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_permission`
--

INSERT INTO `ums_permission` (`TableID`, `ID`, `Name`, `Category`) VALUES
(4781, 'COURSE_C', 'COURSE_C', 'COURSE'),
(4782, 'COURSE_R', 'COURSE_R', 'COURSE'),
(4783, 'COURSE_U', 'COURSE_U', 'COURSE'),
(4784, 'COURSE_D', 'COURSE_D', 'COURSE'),
(4785, 'COURSE_TYPE_C', 'COURSE_TYPE_C', 'COURSE TYPE'),
(4786, 'COURSE_TYPE_R', 'COURSE_TYPE_R', 'COURSE TYPE'),
(4787, 'COURSE_TYPE_U', 'COURSE_TYPE_U', 'COURSE TYPE'),
(4788, 'COURSE_TYPE_D', 'COURSE_TYPE_D', 'COURSE TYPE'),
(4789, 'COURSE_SESSIONAL_TYPE_C', 'COURSE_SESSIONAL_TYPE_C', 'COURSE SESSIONAL TYPE'),
(4790, 'COURSE_SESSIONAL_TYPE_R', 'COURSE_SESSIONAL_TYPE_R', 'COURSE SESSIONAL TYPE'),
(4791, 'COURSE_SESSIONAL_TYPE_U', 'COURSE_SESSIONAL_TYPE_U', 'COURSE SESSIONAL TYPE'),
(4792, 'COURSE_SESSIONAL_TYPE_D', 'COURSE_SESSIONAL_TYPE_D', 'COURSE SESSIONAL TYPE'),
(4793, 'CLUB_C', 'CLUB_C', 'CLUB'),
(4794, 'CLUB_R', 'CLUB_R', 'CLUB'),
(4795, 'CLUB_U', 'CLUB_U', 'CLUB'),
(4796, 'CLUB_D', 'CLUB_D', 'CLUB'),
(4797, 'DISCUSSION_C', 'DISCUSSION_C', 'DISCUSSION'),
(4798, 'DISCUSSION_R', 'DISCUSSION_R', 'DISCUSSION'),
(4799, 'DISCUSSION_U', 'DISCUSSION_U', 'DISCUSSION'),
(4800, 'DISCUSSION_D', 'DISCUSSION_D', 'DISCUSSION'),
(4801, 'DISCUSSION_CAT_C', 'DISCUSSION_CAT_C', 'DISCUSSION CATEGORY'),
(4802, 'DISCUSSION_CAT_R', 'DISCUSSION_CAT_R', 'DISCUSSION CATEGORY'),
(4803, 'DISCUSSION_CAT_U', 'DISCUSSION_CAT_U', 'DISCUSSION CATEGORY'),
(4804, 'DISCUSSION_CAT_D', 'DISCUSSION_CAT_D', 'DISCUSSION CATEGORY'),
(4805, 'DISCUSSION_COMMENT_C', 'DISCUSSION_COMMENT_C', 'DISCUSSION COMMENT'),
(4806, 'DISCUSSION_COMMENT_R', 'DISCUSSION_COMMENT_R', 'DISCUSSION COMMENT'),
(4807, 'DISCUSSION_COMMENT_U', 'DISCUSSION_COMMENT_U', 'DISCUSSION COMMENT'),
(4808, 'DISCUSSION_COMMENT_D', 'DISCUSSION_COMMENT_D', 'DISCUSSION COMMENT'),
(4809, 'DISCIPLINE_C', 'DISCIPLINE_C', 'DISCIPLINE'),
(4810, 'DISCIPLINE_R', 'DISCIPLINE_R', 'DISCIPLINE'),
(4811, 'DISCIPLINE_U', 'DISCIPLINE_U', 'DISCIPLINE'),
(4812, 'DISCIPLINE_D', 'DISCIPLINE_D', 'DISCIPLINE'),
(4813, 'FILE_C', 'FILE_C', 'FILE'),
(4814, 'FILE_R', 'FILE_R', 'FILE'),
(4815, 'FILE_U', 'FILE_U', 'FILE'),
(4816, 'FILE_D', 'FILE_D', 'FILE'),
(4817, 'PERMISSION_C', 'PERMISSION_C', 'PERMISSION'),
(4818, 'PERMISSION_R', 'PERMISSION_R', 'PERMISSION'),
(4819, 'PERMISSION_U', 'PERMISSION_U', 'PERMISSION'),
(4820, 'PERMISSION_D', 'PERMISSION_D', 'PERMISSION'),
(4821, 'POSITION_C', 'POSITION_C', 'POSITION'),
(4822, 'POSITION_R', 'POSITION_R', 'POSITION'),
(4823, 'POSITION_U', 'POSITION_U', 'POSITION'),
(4824, 'POSITION_D', 'POSITION_D', 'POSITION'),
(4825, 'PROJECT_C', 'PROJECT_C', 'PROJECT'),
(4826, 'PROJECT_R', 'PROJECT_R', 'PROJECT'),
(4827, 'PROJECT_U', 'PROJECT_U', 'PROJECT'),
(4828, 'PROJECT_D', 'PROJECT_D', 'PROJECT'),
(4829, 'QUESTION_C', 'QUESTION_C', 'QUESTION'),
(4830, 'QUESTION_R', 'QUESTION_R', 'QUESTION'),
(4831, 'QUESTION_U', 'QUESTION_U', 'QUESTION'),
(4832, 'QUESTION_D', 'QUESTION_D', 'QUESTION'),
(4833, 'REGISTRATION_C', 'REGISTRATION_C', 'REGISTRATION'),
(4834, 'REGISTRATION_R', 'REGISTRATION_R', 'REGISTRATION'),
(4835, 'REGISTRATION_U', 'REGISTRATION_U', 'REGISTRATION'),
(4836, 'REGISTRATION_D', 'REGISTRATION_D', 'REGISTRATION'),
(4837, 'RESULT_C', 'RESULT_C', 'RESULT'),
(4838, 'RESULT_R', 'RESULT_R', 'RESULT'),
(4839, 'RESULT_U', 'RESULT_U', 'RESULT'),
(4840, 'RESULT_D', 'RESULT_D', 'RESULT'),
(4841, 'ATTENDANCE_C', 'ATTENDANCE_C', 'ATTENDANCE'),
(4842, 'ATTENDANCE_R', 'ATTENDANCE_R', 'ATTENDANCE'),
(4843, 'ATTENDANCE_U', 'ATTENDANCE_U', 'ATTENDANCE'),
(4844, 'ATTENDANCE_D', 'ATTENDANCE_D', 'ATTENDANCE'),
(4845, 'MARKS_SETUP_C', 'MARKS_SETUP_C', 'MARKS_SETUP'),
(4846, 'MARKS_SETUP_R', 'MARKS_SETUP_R', 'MARKS_SETUP'),
(4847, 'MARKS_SETUP_U', 'MARKS_SETUP_U', 'MARKS_SETUP'),
(4848, 'MARKS_SETUP_D', 'MARKS_SETUP_D', 'MARKS_SETUP'),
(4849, 'GRADE_SETUP_C', 'GRADE_SETUP_C', 'GRADE_SETUP'),
(4850, 'GRADE_SETUP_R', 'GRADE_SETUP_R', 'GRADE_SETUP'),
(4851, 'GRADE_SETUP_U', 'GRADE_SETUP_U', 'GRADE_SETUP'),
(4852, 'GRADE_SETUP_D', 'GRADE_SETUP_D', 'GRADE_SETUP'),
(4853, 'ROLE_C', 'ROLE_C', 'ROLE'),
(4854, 'ROLE_R', 'ROLE_R', 'ROLE'),
(4855, 'ROLE_U', 'ROLE_U', 'ROLE'),
(4856, 'ROLE_D', 'ROLE_D', 'ROLE'),
(4857, 'SCHOOL_C', 'SCHOOL_C', 'SCHOOL'),
(4858, 'SCHOOL_R', 'SCHOOL_R', 'SCHOOL'),
(4859, 'SCHOOL_U', 'SCHOOL_U', 'SCHOOL'),
(4860, 'SCHOOL_D', 'SCHOOL_D', 'SCHOOL'),
(4861, 'SESSION_C', 'SESSION_C', 'SESSION'),
(4862, 'SESSION_R', 'SESSION_R', 'SESSION'),
(4863, 'SESSION_U', 'SESSION_U', 'SESSION'),
(4864, 'SESSION_D', 'SESSION_D', 'SESSION'),
(4865, 'SURVEY_C', 'SURVEY_C', 'SURVEY'),
(4866, 'SURVEY_R', 'SURVEY_R', 'SURVEY'),
(4867, 'SURVEY_U', 'SURVEY_U', 'SURVEY'),
(4868, 'SURVEY_D', 'SURVEY_D', 'SURVEY'),
(4869, 'SURVEY_QUESTION_C', 'SURVEY_QUESTION_C', 'SURVEY QUESTION'),
(4870, 'SURVEY_QUESTION_R', 'SURVEY_QUESTION_R', 'SURVEY QUESTION'),
(4871, 'SURVEY_QUESTION_U', 'SURVEY_QUESTION_U', 'SURVEY QUESTION'),
(4872, 'SURVEY_QUESTION_D', 'SURVEY_QUESTION_D', 'SURVEY QUESTION'),
(4873, 'SURVEY_QUESTION_TYPE_C', 'SURVEY_QUESTION_TYPE_C', 'SURVEY QUESTION TYPE'),
(4874, 'SURVEY_QUESTION_TYPE_R', 'SURVEY_QUESTION_TYPE_R', 'SURVEY QUESTION TYPE'),
(4875, 'SURVEY_QUESTION_TYPE_U', 'SURVEY_QUESTION_TYPE_U', 'SURVEY QUESTION TYPE'),
(4876, 'SURVEY_QUESTION_TYPE_D', 'SURVEY_QUESTION_TYPE_D', 'SURVEY QUESTION TYPE'),
(4877, 'SURVEY_QUESTION_FILLUP_C', 'SURVEY_QUESTION_FILLUP_C', 'SURVEY QUESTION FILLUP'),
(4878, 'SURVEY_QUESTION_FILLUP_R', 'SURVEY_QUESTION_FILLUP_R', 'SURVEY QUESTION FILLUP'),
(4879, 'SURVEY_QUESTION_FILLUP_U', 'SURVEY_QUESTION_FILLUP_U', 'SURVEY QUESTION FILLUP'),
(4880, 'SURVEY_QUESTION_FILLUP_D', 'SURVEY_QUESTION_FILLUP_D', 'SURVEY QUESTION FILLUP'),
(4881, 'TERM_C', 'TERM_C', 'TERM'),
(4882, 'TERM_R', 'TERM_R', 'TERM'),
(4883, 'TERM_U', 'TERM_U', 'TERM'),
(4884, 'TERM_D', 'TERM_D', 'TERM'),
(4885, 'USER_C', 'USER_C', 'USER'),
(4886, 'USER_R', 'USER_R', 'USER'),
(4887, 'USER_U', 'USER_U', 'USER'),
(4888, 'USER_D', 'USER_D', 'USER'),
(4889, 'YEAR_C', 'YEAR_C', 'YEAR'),
(4890, 'YEAR_R', 'YEAR_R', 'YEAR'),
(4891, 'YEAR_U', 'YEAR_U', 'YEAR'),
(4892, 'YEAR_D', 'YEAR_D', 'YEAR'),
(4893, 'VIDEO_C', 'VIDEO_C', 'VIDEO'),
(4894, 'VIDEO_R', 'VIDEO_R', 'VIDEO'),
(4895, 'VIDEO_U', 'VIDEO_U', 'VIDEO'),
(4896, 'VIDEO_D', 'VIDEO_D', 'VIDEO'),
(4897, 'VIDEO_COMMENT_C', 'VIDEO_COMMENT_C', 'VIDEO COMMENT'),
(4898, 'VIDEO_COMMENT_R', 'VIDEO_COMMENT_R', 'VIDEO COMMENT'),
(4899, 'VIDEO_COMMENT_U', 'VIDEO_COMMENT_U', 'VIDEO COMMENT'),
(4900, 'VIDEO_COMMENT_D', 'VIDEO_COMMENT_D', 'VIDEO COMMENT'),
(4901, 'JOB_C', 'JOB_C', 'JOB'),
(4902, 'JOB_R', 'JOB_R', 'JOB'),
(4903, 'JOB_U', 'JOB_U', 'JOB'),
(4904, 'JOB_D', 'JOB_D', 'JOB'),
(4905, 'BLOOD_C', 'BLOOD_C', 'BLOOD'),
(4906, 'BLOOD_R', 'BLOOD_R', 'BLOOD'),
(4907, 'BLOOD_U', 'BLOOD_U', 'BLOOD'),
(4908, 'BLOOD_D', 'BLOOD_D', 'BLOOD');

-- --------------------------------------------------------

--
-- Table structure for table `ums_position`
--

DROP TABLE IF EXISTS `ums_position`;
CREATE TABLE IF NOT EXISTS `ums_position` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_position`
--

INSERT INTO `ums_position` (`ID`, `Name`) VALUES
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
-- Table structure for table `ums_role`
--

DROP TABLE IF EXISTS `ums_role`;
CREATE TABLE IF NOT EXISTS `ums_role` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_role`
--

INSERT INTO `ums_role` (`ID`, `Name`) VALUES
('administrator', 'Administrator'),
('registration coordinator', 'Registration Coordinator'),
('student', 'Student'),
('stuff', 'Stuff'),
('tabulator', 'Tabulator'),
('teacher', 'Teacher');

-- --------------------------------------------------------

--
-- Table structure for table `ums_role_permission`
--

DROP TABLE IF EXISTS `ums_role_permission`;
CREATE TABLE IF NOT EXISTS `ums_role_permission` (
  `Row` int(11) NOT NULL AUTO_INCREMENT,
  `RoleID` varchar(40) NOT NULL,
  `PermissionID` varchar(100) NOT NULL,
  PRIMARY KEY (`Row`)
) ENGINE=InnoDB AUTO_INCREMENT=2523 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_role_permission`
--

INSERT INTO `ums_role_permission` (`Row`, `RoleID`, `PermissionID`) VALUES
(2147, 'administrator', 'ATTENDANCE_C'),
(2148, 'administrator', 'ATTENDANCE_R'),
(2149, 'administrator', 'ATTENDANCE_U'),
(2150, 'administrator', 'ATTENDANCE_D'),
(2151, 'administrator', 'BLOOD_C'),
(2152, 'administrator', 'BLOOD_R'),
(2153, 'administrator', 'BLOOD_U'),
(2154, 'administrator', 'BLOOD_D'),
(2155, 'administrator', 'CLUB_C'),
(2156, 'administrator', 'CLUB_R'),
(2157, 'administrator', 'CLUB_U'),
(2158, 'administrator', 'CLUB_D'),
(2159, 'administrator', 'COURSE_C'),
(2160, 'administrator', 'COURSE_R'),
(2161, 'administrator', 'COURSE_U'),
(2162, 'administrator', 'COURSE_D'),
(2163, 'administrator', 'COURSE_SESSIONAL_TYPE_C'),
(2164, 'administrator', 'COURSE_SESSIONAL_TYPE_R'),
(2165, 'administrator', 'COURSE_SESSIONAL_TYPE_U'),
(2166, 'administrator', 'COURSE_SESSIONAL_TYPE_D'),
(2167, 'administrator', 'COURSE_TYPE_C'),
(2168, 'administrator', 'COURSE_TYPE_R'),
(2169, 'administrator', 'COURSE_TYPE_U'),
(2170, 'administrator', 'COURSE_TYPE_D'),
(2171, 'administrator', 'DISCIPLINE_C'),
(2172, 'administrator', 'DISCIPLINE_R'),
(2173, 'administrator', 'DISCIPLINE_U'),
(2174, 'administrator', 'DISCIPLINE_D'),
(2175, 'administrator', 'DISCUSSION_C'),
(2176, 'administrator', 'DISCUSSION_R'),
(2177, 'administrator', 'DISCUSSION_U'),
(2178, 'administrator', 'DISCUSSION_D'),
(2179, 'administrator', 'DISCUSSION_CAT_C'),
(2180, 'administrator', 'DISCUSSION_CAT_R'),
(2181, 'administrator', 'DISCUSSION_CAT_U'),
(2182, 'administrator', 'DISCUSSION_CAT_D'),
(2183, 'administrator', 'DISCUSSION_COMMENT_C'),
(2184, 'administrator', 'DISCUSSION_COMMENT_R'),
(2185, 'administrator', 'DISCUSSION_COMMENT_U'),
(2186, 'administrator', 'DISCUSSION_COMMENT_D'),
(2187, 'administrator', 'FILE_C'),
(2188, 'administrator', 'FILE_R'),
(2189, 'administrator', 'FILE_U'),
(2190, 'administrator', 'FILE_D'),
(2191, 'administrator', 'GRADE_SETUP_C'),
(2192, 'administrator', 'GRADE_SETUP_R'),
(2193, 'administrator', 'GRADE_SETUP_U'),
(2194, 'administrator', 'GRADE_SETUP_D'),
(2195, 'administrator', 'JOB_C'),
(2196, 'administrator', 'JOB_R'),
(2197, 'administrator', 'JOB_U'),
(2198, 'administrator', 'JOB_D'),
(2199, 'administrator', 'MARKS_SETUP_C'),
(2200, 'administrator', 'MARKS_SETUP_R'),
(2201, 'administrator', 'MARKS_SETUP_U'),
(2202, 'administrator', 'MARKS_SETUP_D'),
(2203, 'administrator', 'PERMISSION_C'),
(2204, 'administrator', 'PERMISSION_R'),
(2205, 'administrator', 'PERMISSION_U'),
(2206, 'administrator', 'PERMISSION_D'),
(2207, 'administrator', 'POSITION_C'),
(2208, 'administrator', 'POSITION_R'),
(2209, 'administrator', 'POSITION_U'),
(2210, 'administrator', 'POSITION_D'),
(2211, 'administrator', 'PROJECT_C'),
(2212, 'administrator', 'PROJECT_R'),
(2213, 'administrator', 'PROJECT_U'),
(2214, 'administrator', 'PROJECT_D'),
(2215, 'administrator', 'QUESTION_C'),
(2216, 'administrator', 'QUESTION_R'),
(2217, 'administrator', 'QUESTION_U'),
(2218, 'administrator', 'QUESTION_D'),
(2219, 'administrator', 'REGISTRATION_C'),
(2220, 'administrator', 'REGISTRATION_R'),
(2221, 'administrator', 'REGISTRATION_U'),
(2222, 'administrator', 'REGISTRATION_D'),
(2223, 'administrator', 'RESULT_C'),
(2224, 'administrator', 'RESULT_R'),
(2225, 'administrator', 'RESULT_U'),
(2226, 'administrator', 'RESULT_D'),
(2227, 'administrator', 'ROLE_C'),
(2228, 'administrator', 'ROLE_R'),
(2229, 'administrator', 'ROLE_U'),
(2230, 'administrator', 'ROLE_D'),
(2231, 'administrator', 'SCHOOL_C'),
(2232, 'administrator', 'SCHOOL_R'),
(2233, 'administrator', 'SCHOOL_U'),
(2234, 'administrator', 'SCHOOL_D'),
(2235, 'administrator', 'SESSION_C'),
(2236, 'administrator', 'SESSION_R'),
(2237, 'administrator', 'SESSION_U'),
(2238, 'administrator', 'SESSION_D'),
(2239, 'administrator', 'SURVEY_C'),
(2240, 'administrator', 'SURVEY_R'),
(2241, 'administrator', 'SURVEY_U'),
(2242, 'administrator', 'SURVEY_D'),
(2243, 'administrator', 'SURVEY_QUESTION_C'),
(2244, 'administrator', 'SURVEY_QUESTION_R'),
(2245, 'administrator', 'SURVEY_QUESTION_U'),
(2246, 'administrator', 'SURVEY_QUESTION_D'),
(2247, 'administrator', 'SURVEY_QUESTION_FILLUP_C'),
(2248, 'administrator', 'SURVEY_QUESTION_FILLUP_R'),
(2249, 'administrator', 'SURVEY_QUESTION_FILLUP_U'),
(2250, 'administrator', 'SURVEY_QUESTION_FILLUP_D'),
(2251, 'administrator', 'SURVEY_QUESTION_TYPE_C'),
(2252, 'administrator', 'SURVEY_QUESTION_TYPE_R'),
(2253, 'administrator', 'SURVEY_QUESTION_TYPE_U'),
(2254, 'administrator', 'SURVEY_QUESTION_TYPE_D'),
(2255, 'administrator', 'TERM_C'),
(2256, 'administrator', 'TERM_R'),
(2257, 'administrator', 'TERM_U'),
(2258, 'administrator', 'TERM_D'),
(2259, 'administrator', 'USER_C'),
(2260, 'administrator', 'USER_R'),
(2261, 'administrator', 'USER_U'),
(2262, 'administrator', 'USER_D'),
(2263, 'administrator', 'VIDEO_C'),
(2264, 'administrator', 'VIDEO_R'),
(2265, 'administrator', 'VIDEO_U'),
(2266, 'administrator', 'VIDEO_D'),
(2267, 'administrator', 'VIDEO_COMMENT_C'),
(2268, 'administrator', 'VIDEO_COMMENT_R'),
(2269, 'administrator', 'VIDEO_COMMENT_U'),
(2270, 'administrator', 'VIDEO_COMMENT_D'),
(2271, 'administrator', 'YEAR_C'),
(2272, 'administrator', 'YEAR_R'),
(2273, 'administrator', 'YEAR_U'),
(2274, 'administrator', 'YEAR_D'),
(2275, 'student', 'BLOOD_C'),
(2276, 'student', 'BLOOD_R'),
(2277, 'student', 'BLOOD_U'),
(2278, 'student', 'BLOOD_D'),
(2279, 'student', 'CLUB_C'),
(2280, 'student', 'CLUB_R'),
(2281, 'student', 'CLUB_U'),
(2282, 'student', 'CLUB_D'),
(2283, 'student', 'DISCUSSION_C'),
(2284, 'student', 'DISCUSSION_R'),
(2285, 'student', 'DISCUSSION_U'),
(2286, 'student', 'DISCUSSION_D'),
(2287, 'student', 'DISCUSSION_COMMENT_C'),
(2288, 'student', 'DISCUSSION_COMMENT_R'),
(2289, 'student', 'DISCUSSION_COMMENT_U'),
(2290, 'student', 'DISCUSSION_COMMENT_D'),
(2291, 'student', 'JOB_R'),
(2292, 'student', 'PROJECT_C'),
(2293, 'student', 'PROJECT_R'),
(2294, 'student', 'PROJECT_U'),
(2295, 'student', 'PROJECT_D'),
(2296, 'student', 'QUESTION_C'),
(2297, 'student', 'QUESTION_R'),
(2298, 'student', 'QUESTION_U'),
(2299, 'student', 'QUESTION_D'),
(2300, 'student', 'REGISTRATION_R'),
(2301, 'student', 'RESULT_R'),
(2302, 'student', 'USER_R'),
(2303, 'student', 'VIDEO_C'),
(2304, 'student', 'VIDEO_R'),
(2305, 'student', 'VIDEO_U'),
(2306, 'student', 'VIDEO_D'),
(2307, 'stuff', 'BLOOD_C'),
(2308, 'stuff', 'BLOOD_R'),
(2309, 'stuff', 'BLOOD_U'),
(2310, 'stuff', 'BLOOD_D'),
(2351, 'teacher', 'BLOOD_C'),
(2352, 'teacher', 'BLOOD_R'),
(2353, 'teacher', 'BLOOD_U'),
(2354, 'teacher', 'BLOOD_D'),
(2355, 'teacher', 'COURSE_C'),
(2356, 'teacher', 'COURSE_R'),
(2357, 'teacher', 'COURSE_U'),
(2358, 'teacher', 'COURSE_D'),
(2359, 'teacher', 'DISCUSSION_C'),
(2360, 'teacher', 'DISCUSSION_R'),
(2361, 'teacher', 'DISCUSSION_U'),
(2362, 'teacher', 'DISCUSSION_D'),
(2363, 'teacher', 'DISCUSSION_CAT_C'),
(2364, 'teacher', 'DISCUSSION_CAT_R'),
(2365, 'teacher', 'DISCUSSION_CAT_U'),
(2366, 'teacher', 'DISCUSSION_CAT_D'),
(2367, 'teacher', 'DISCUSSION_COMMENT_C'),
(2368, 'teacher', 'DISCUSSION_COMMENT_R'),
(2369, 'teacher', 'DISCUSSION_COMMENT_U'),
(2370, 'teacher', 'DISCUSSION_COMMENT_D'),
(2371, 'teacher', 'FILE_C'),
(2372, 'teacher', 'FILE_R'),
(2373, 'teacher', 'FILE_U'),
(2374, 'teacher', 'FILE_D'),
(2375, 'teacher', 'JOB_C'),
(2376, 'teacher', 'JOB_R'),
(2377, 'teacher', 'JOB_U'),
(2378, 'teacher', 'JOB_D'),
(2379, 'teacher', 'PROJECT_C'),
(2380, 'teacher', 'PROJECT_R'),
(2381, 'teacher', 'PROJECT_U'),
(2382, 'teacher', 'PROJECT_D'),
(2383, 'teacher', 'QUESTION_C'),
(2384, 'teacher', 'QUESTION_R'),
(2385, 'teacher', 'QUESTION_U'),
(2386, 'teacher', 'QUESTION_D'),
(2387, 'teacher', 'REGISTRATION_C'),
(2388, 'teacher', 'REGISTRATION_R'),
(2389, 'teacher', 'REGISTRATION_U'),
(2390, 'teacher', 'REGISTRATION_D'),
(2391, 'teacher', 'RESULT_C'),
(2392, 'teacher', 'RESULT_R'),
(2393, 'teacher', 'RESULT_U'),
(2394, 'teacher', 'RESULT_D'),
(2395, '', 'ATTENDANCE_C'),
(2396, '', 'ATTENDANCE_R'),
(2397, '', 'ATTENDANCE_U'),
(2398, '', 'ATTENDANCE_D'),
(2399, '', 'BLOOD_C'),
(2400, '', 'BLOOD_R'),
(2401, '', 'BLOOD_U'),
(2402, '', 'BLOOD_D'),
(2403, '', 'CLUB_C'),
(2404, '', 'CLUB_R'),
(2405, '', 'CLUB_U'),
(2406, '', 'CLUB_D'),
(2407, '', 'COURSE_C'),
(2408, '', 'COURSE_R'),
(2409, '', 'COURSE_U'),
(2410, '', 'COURSE_D'),
(2411, '', 'COURSE_SESSIONAL_TYPE_C'),
(2412, '', 'COURSE_SESSIONAL_TYPE_R'),
(2413, '', 'COURSE_SESSIONAL_TYPE_U'),
(2414, '', 'COURSE_SESSIONAL_TYPE_D'),
(2415, '', 'COURSE_TYPE_C'),
(2416, '', 'COURSE_TYPE_R'),
(2417, '', 'COURSE_TYPE_U'),
(2418, '', 'COURSE_TYPE_D'),
(2419, '', 'DISCIPLINE_C'),
(2420, '', 'DISCIPLINE_R'),
(2421, '', 'DISCIPLINE_U'),
(2422, '', 'DISCIPLINE_D'),
(2423, '', 'DISCUSSION_C'),
(2424, '', 'DISCUSSION_R'),
(2425, '', 'DISCUSSION_U'),
(2426, '', 'DISCUSSION_D'),
(2427, '', 'DISCUSSION_CAT_C'),
(2428, '', 'DISCUSSION_CAT_R'),
(2429, '', 'DISCUSSION_CAT_U'),
(2430, '', 'DISCUSSION_CAT_D'),
(2431, '', 'DISCUSSION_COMMENT_C'),
(2432, '', 'DISCUSSION_COMMENT_R'),
(2433, '', 'DISCUSSION_COMMENT_U'),
(2434, '', 'DISCUSSION_COMMENT_D'),
(2435, '', 'FILE_C'),
(2436, '', 'FILE_R'),
(2437, '', 'FILE_U'),
(2438, '', 'FILE_D'),
(2439, '', 'GRADE_SETUP_C'),
(2440, '', 'GRADE_SETUP_R'),
(2441, '', 'GRADE_SETUP_U'),
(2442, '', 'GRADE_SETUP_D'),
(2443, '', 'JOB_C'),
(2444, '', 'JOB_R'),
(2445, '', 'JOB_U'),
(2446, '', 'JOB_D'),
(2447, '', 'MARKS_SETUP_C'),
(2448, '', 'MARKS_SETUP_R'),
(2449, '', 'MARKS_SETUP_U'),
(2450, '', 'MARKS_SETUP_D'),
(2451, '', 'PERMISSION_C'),
(2452, '', 'PERMISSION_R'),
(2453, '', 'PERMISSION_U'),
(2454, '', 'PERMISSION_D'),
(2455, '', 'POSITION_C'),
(2456, '', 'POSITION_R'),
(2457, '', 'POSITION_U'),
(2458, '', 'POSITION_D'),
(2459, '', 'PROJECT_C'),
(2460, '', 'PROJECT_R'),
(2461, '', 'PROJECT_U'),
(2462, '', 'PROJECT_D'),
(2463, '', 'QUESTION_C'),
(2464, '', 'QUESTION_R'),
(2465, '', 'QUESTION_U'),
(2466, '', 'QUESTION_D'),
(2467, '', 'REGISTRATION_C'),
(2468, '', 'REGISTRATION_R'),
(2469, '', 'REGISTRATION_U'),
(2470, '', 'REGISTRATION_D'),
(2471, '', 'RESULT_C'),
(2472, '', 'RESULT_R'),
(2473, '', 'RESULT_U'),
(2474, '', 'RESULT_D'),
(2475, '', 'ROLE_C'),
(2476, '', 'ROLE_R'),
(2477, '', 'ROLE_U'),
(2478, '', 'ROLE_D'),
(2479, '', 'SCHOOL_C'),
(2480, '', 'SCHOOL_R'),
(2481, '', 'SCHOOL_U'),
(2482, '', 'SCHOOL_D'),
(2483, '', 'SESSION_C'),
(2484, '', 'SESSION_R'),
(2485, '', 'SESSION_U'),
(2486, '', 'SESSION_D'),
(2487, '', 'SURVEY_C'),
(2488, '', 'SURVEY_R'),
(2489, '', 'SURVEY_U'),
(2490, '', 'SURVEY_D'),
(2491, '', 'SURVEY_QUESTION_C'),
(2492, '', 'SURVEY_QUESTION_R'),
(2493, '', 'SURVEY_QUESTION_U'),
(2494, '', 'SURVEY_QUESTION_D'),
(2495, '', 'SURVEY_QUESTION_FILLUP_C'),
(2496, '', 'SURVEY_QUESTION_FILLUP_R'),
(2497, '', 'SURVEY_QUESTION_FILLUP_U'),
(2498, '', 'SURVEY_QUESTION_FILLUP_D'),
(2499, '', 'SURVEY_QUESTION_TYPE_C'),
(2500, '', 'SURVEY_QUESTION_TYPE_R'),
(2501, '', 'SURVEY_QUESTION_TYPE_U'),
(2502, '', 'SURVEY_QUESTION_TYPE_D'),
(2503, '', 'TERM_C'),
(2504, '', 'TERM_R'),
(2505, '', 'TERM_U'),
(2506, '', 'TERM_D'),
(2507, '', 'USER_C'),
(2508, '', 'USER_R'),
(2509, '', 'USER_U'),
(2510, '', 'USER_D'),
(2511, '', 'VIDEO_C'),
(2512, '', 'VIDEO_R'),
(2513, '', 'VIDEO_U'),
(2514, '', 'VIDEO_D'),
(2515, '', 'VIDEO_COMMENT_C'),
(2516, '', 'VIDEO_COMMENT_R'),
(2517, '', 'VIDEO_COMMENT_U'),
(2518, '', 'VIDEO_COMMENT_D'),
(2519, '', 'YEAR_C'),
(2520, '', 'YEAR_R'),
(2521, '', 'YEAR_U'),
(2522, '', 'YEAR_D');

-- --------------------------------------------------------

--
-- Table structure for table `ums_school`
--

DROP TABLE IF EXISTS `ums_school`;
CREATE TABLE IF NOT EXISTS `ums_school` (
  `ID` varchar(40) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `DeanID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_school`
--

INSERT INTO `ums_school` (`ID`, `Name`, `DeanID`) VALUES
('{39DDC0C2-CFC2-4246-8748-8812B1751A5C}', 'Science Engineering and Technology', ''),
('{4D46079B-AFA3-40F1-B8D1-6CC9E9F56812}', 'Life Science', ''),
('{86E0F021-B30D-48D2-B177-247180633C5E}', 'Social Science', ''),
('{879375F7-0A15-4705-AC90-C6786D279EF1}', 'Law and Humanities', ''),
('{CE09AA38-205B-4F50-A0E0-14DB8686C912}', 'Fine Arts', '');

-- --------------------------------------------------------

--
-- Table structure for table `ums_user`
--

DROP TABLE IF EXISTS `ums_user`;
CREATE TABLE IF NOT EXISTS `ums_user` (
  `ID` varchar(40) NOT NULL,
  `UniversityID` varchar(20) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Password` varchar(255) NOT NULL,
  `FirstName` varchar(50) DEFAULT NULL,
  `MiddleName` varchar(50) DEFAULT NULL,
  `LastName` varchar(50) DEFAULT NULL,
  `DisciplineID` varchar(40) DEFAULT NULL,
  `Status` varchar(20) DEFAULT NULL,
  `IsLogged` varchar(10) DEFAULT NULL,
  `IsArchived` varchar(10) DEFAULT NULL,
  `IsDeleted` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Email` (`Email`),
  UNIQUE KEY `UniversityID` (`UniversityID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user`
--

INSERT INTO `ums_user` (`ID`, `UniversityID`, `Email`, `Password`, `FirstName`, `MiddleName`, `LastName`, `DisciplineID`, `Status`, `IsLogged`, `IsArchived`, `IsDeleted`) VALUES
('abir@gmail.com', '150235', 'abir@gmail.com', '$2y$10$5bU1xXYm4MIqPe20UrDYO.qIslHS0pnQT0pkUongY0Vp.Mou8V4NK', 'Md', 'ABIR', 'Hasan', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('aysha@gmail.com', '020208', 'aysha@gmail.com', '$2y$10$pJX46d.T.jkANrRShAm0qOMYkYJ/YbNfu09BFmcmMiYGKfuuEcWgO', 'Aysha', 'mrs', 'Akther', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('khalid@gmail.com', '130502', 'khalid@gmail.com', '$2y$10$5Au.uz2J36H8zgIc9Z9c8eCzKuYW3T7d2GTyeQTOh9UriVq5ERKRe', 'Khalid', 'Al', 'Hasan', '{560A0FC0-6221-497D-8D41-E584EE4BBEE3}', 'approved', NULL, NULL, NULL),
('mahmud05@gmail.com', '150205', 'mahmud05@gmail.com', '$2y$10$QugvWVpxoadUQcRraBkxWuMZd2GzijTtzxPUHwcKIFDgofoaEte9W', 'Abdullah-', 'Al-', 'Mahmud', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('mehadi.cse16@gmail.com', '160225', 'mehadi.cse16@gmail.com', '$2y$10$/cq5gkjhMenExH3eE0YaJea8MJ1oFpqmyYQeD3ws/l36sjaHrIdJG', 'S.M.', 'Mehadi', 'Hasan', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('mkazi078@uottawa.ca', '020229', 'mkazi078@uottawa.ca', '$2y$10$l0gFzILMq03DcwcBGxIdgunnOd9G5kF8J8ucZZvCKkt8mNGlI74/W', 'Kazi', 'Masudul', 'Alam', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('monir150227@gmail.com', '150227', 'monir150227@gmail.com', '$2y$10$HeL3GxO0RUiuzyyRCMQPl..6R4ne87le1iwiTvhsMzXYIPE8oqsjS', 'Md:', 'Moni', 'Ruzzaman', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('naim16@gmail.com', '150228', 'naim16@gmail.com', '$2y$10$keEhGNGyteHjqDrqGMRUlu2uIlHVu9GBE3NGOo4e5eG1nsJxLPKZ2', 'Md:', 'Naim', 'Islam', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL),
('rumon@gmail.com', '140349', 'rumon@gmail.com', '$2y$10$hwiIx9OfwQ/F2EvDQ/TJZu0B7fihGVbBaPoXp1T40m/cAvhxgW7IG', 'Md:', 'Rumon', 'Ahmed', '{E7280448-E379-424E-A11D-357F4334AC8D}', 'approved', NULL, NULL, NULL),
('shish150225@gmail.com', '150225', 'shish150225@gmail.com', '$2y$10$jOAdhf80eHVPG/E3n1TWAuKa3Lq9iODhXb52J4r8Ie6m1qiFhXV.q', 'Shish', 'Been', 'BahaUddin', '{FFDB1CB8-AF34-4381-8971-9784DCB516C5}', 'approved', NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_details`
--

DROP TABLE IF EXISTS `ums_user_details`;
CREATE TABLE IF NOT EXISTS `ums_user_details` (
  `ID` varchar(40) NOT NULL,
  `FatherName` varchar(100) DEFAULT NULL,
  `MotherName` varchar(100) DEFAULT NULL,
  `PermanentAddress` varchar(200) DEFAULT NULL,
  `HomePhone` varchar(20) DEFAULT NULL,
  `CurrentAddress` varchar(200) DEFAULT NULL,
  `MobilePhone` varchar(20) DEFAULT NULL,
  `blood_group` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_details`
--

INSERT INTO `ums_user_details` (`ID`, `FatherName`, `MotherName`, `PermanentAddress`, `HomePhone`, `CurrentAddress`, `MobilePhone`, `blood_group`) VALUES
('abir@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'O+'),
('aysha@gmail.com', 'f', 'm', 'Dr. Kazi Masudul Alam', '12313123123', 'Computer Science and Engineering Discipline, Khulna University', '45 ', 'B+'),
('khalid@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'O-'),
('mahmud05@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'B+'),
('mehadi.cse16@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'A+'),
('mkazi078@uottawa.ca', 'Kazi Shahidul Alam', 'Hosneara Jahan', '49/2, Rokon Uddin Sarak, East Baniakhamar, Khulna', '0417223344', 'Same', '01711149360 ', 'O+'),
('monir150227@gmail.com', 'Shahidul Islam', 'Zohora Begum', 'Khulna University', '01797539802', 'Khulna University', '01797539802 ', 'O+'),
('naim16@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'A+'),
('rumon@gmail.com', 'Mr Abu Limon', 'Mrs Srabony', 'Dhap', '09867456', 'Khulna University', '01797838764 ', 'O+'),
('shish150225@gmail.com', NULL, NULL, NULL, NULL, NULL, NULL, 'O+');

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_discipline`
--

DROP TABLE IF EXISTS `ums_user_discipline`;
CREATE TABLE IF NOT EXISTS `ums_user_discipline` (
  `UserID` varchar(40) NOT NULL,
  `DisciplineID` varchar(40) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_position`
--

DROP TABLE IF EXISTS `ums_user_position`;
CREATE TABLE IF NOT EXISTS `ums_user_position` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `PositionID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=52 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_position`
--

INSERT INTO `ums_user_position` (`ID`, `UserID`, `PositionID`) VALUES
(50, 'aysha@gmail.com', '{7CDA1F32-A2F8-4469-B5A8-C2038FCE1F9A}'),
(51, 'mkazi078@uottawa.ca', '{C27B6BCF-FB83-4F3D-85CA-B7870D8B12D0}');

-- --------------------------------------------------------

--
-- Table structure for table `ums_user_role`
--

DROP TABLE IF EXISTS `ums_user_role`;
CREATE TABLE IF NOT EXISTS `ums_user_role` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `UserID` varchar(40) NOT NULL,
  `RoleID` varchar(40) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=206 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `ums_user_role`
--

INSERT INTO `ums_user_role` (`ID`, `UserID`, `RoleID`) VALUES
(122, 'middle@test.com', 'student'),
(123, 'middle@test.com', 'student'),
(124, 'middle@test.com', 'student'),
(125, 'middle@test.com', 'student'),
(126, 'middle@test.com', 'student'),
(127, 'middle@test.com', 'student'),
(128, 'middle@test.com', 'student'),
(129, 'middle@test.com', 'student'),
(130, 'middle@test.com', 'student'),
(131, 'middle@test.com', 'student'),
(132, 'middle@test.com', 'student'),
(133, 'middle@test.com', 'student'),
(134, 'middle@test.com', 'student'),
(135, 'middle@test.com', 'student'),
(136, 'middle@test.com', 'student'),
(137, 'middle@test.com', 'student'),
(138, 'middle@test.com', 'student'),
(142, 'zahid@gmail.com', 'student'),
(144, 'middle1@test.com', 'student'),
(145, 'kashif@gmail.com', 'student'),
(164, 'aysha@gmail.com', 'administrator'),
(165, 'mkazi078@uottawa.ca', 'administrator'),
(173, 'vyui899@gmail.com', 'student'),
(175, 'monir15@gmail.com', 'student'),
(176, 'monir1@gmail.com', 'student'),
(177, 'monir111@gmail.com', 'student'),
(179, 'm&s@gmail.com', 'student'),
(182, 'raha@gmail.com', 'student'),
(183, 'e@gmail.com', 'student'),
(184, 'xy@gmail.com', 'student'),
(185, 'z@gmail.com', 'student'),
(186, 'k@gmail.com', 'teacher'),
(187, 'g@gmail.com', 'student'),
(188, 'm&s@gmail.com', 'student'),
(196, 'monir150227@gmail.com', 'student'),
(197, 'monir150227@gmail.com', 'teacher'),
(198, 'mahmud05@gmail.com', 'student'),
(199, 'mehadi.cse16@gmail.com', 'student'),
(200, 'naim16@gmail.com', 'student'),
(201, 'shish150225@gmail.com', 'student'),
(202, 'abir@gmail.com', 'student'),
(204, 'rumon@gmail.com', 'student'),
(205, 'khalid@gmail.com', 'student');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
