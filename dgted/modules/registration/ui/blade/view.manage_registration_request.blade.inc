<?php

include_once UTILITY.'class.util.inc';
include_once MODULES_REGISTRATION.'bao/class.course_student_registrationbao.inc';
include_once MODULES_REGISTRATION.'bao/class.coursebao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_typebao.inc';
include_once MODULES_REGISTRATION.'bao/class.registration_sessionbao.inc';
include_once MODULES_REGISTRATION.'bao/class.yearbao.inc';
include_once MODULES_REGISTRATION.'bao/class.termbao.inc';
include_once MODULES_REGISTRATION.'bao/class.course_teacherbao.inc';
include_once MODULES_USER.'bao/class.disciplinebao.inc'; //depenency with modules
include_once MODULES_USER.'bao/class.userbao.inc';//depenency with modules

$_CourseBAO = new CourseBAO();
$_CourseTeacherBAO = new CourseTeacherBAO();
$_UserBAO = new UserBAO();
$_RegistrationSessionBAO = new RegistrationSessionBAO();
$_YearBAO = new YearBAO();
$_TermBAO = new TermBAO();
$_CourseStudentRegistrationBAO = new CourseStudentRegistrationBAO();

$_DB = DBUtil::getInstance();


$globalUser = $_SESSION['globalUser'];



////$_Log->log(LogUtil::$DEBUG," exit view.course_student_registration.blade.inc");

?>