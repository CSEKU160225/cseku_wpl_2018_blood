<?php 
include 'db.php';

if(isset($_GET['id'])){
	$deletePage = $db->prepare("
		DELETE FROM events
		WHERE id = :id
		");

	$deletePage->execute(['id' => $_GET['id']]);
}

header('Location: add-event.php');


 ?>