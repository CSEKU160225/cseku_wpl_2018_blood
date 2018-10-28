<?php include 'db.php'; ?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Events Operation</title>
	<link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>

<?php 
if(!empty($_POST)){
	//header('Location: edit-event.php');
	$id = $_POST['id'];
	$shorttitle = $_POST['shorttitle'];
	$title = $_POST['title'];
	$date = $_POST['date'];
	$time_from = $_POST['time_from'];
	$time_to = $_POST['time_to'];
	$location = $_POST['location'];
	$link = $_POST['link'];
	$description = $_POST['description'];

	$updatePage = $db->prepare("
		UPDATE events
		SET 
			shorttitle = :shorttitle,
			title = :title,
			date = :date,
			time_from = :time_from,
			time_to = :time_to,
			location = :location,
			link = :link,
			description = :description
		WHERE id = :id
		");

	$updatePage->execute([
		'id' => $id,
		'shorttitle' => $shorttitle,
		'title' => $title,
		'date' => $date,
		'time_from' => $time_from,
		'time_to' => $time_to,
		'location' => $location,
		'link' => $link,
		'description' => $description,
		]);

	header('Location: add-event.php');
}

if(!isset($_GET['id']) ){
	header('Location: add-event.php');
	/*die();*/

}



 ?>





<?php 
if(isset($_GET['id'])){

$page = $db->prepare("
	SELECT *
	FROM events
	WHERE id = :id
	");
$page->execute(['id' => $_GET['id']]);
$page = $page->fetch(PDO::FETCH_ASSOC);
}

 ?>



<div class="container">
<div class="row">
	<div class="col-md-8">
		
		<h2><?php if(isset($_GET['id'])){ echo "Update Event"; }else{echo "Add Event";} ?></h2>
		<form action="edit-event.php" method='POST' autocomplete="off">

			<label for="title">
				Title
				<input type="text" class="form-control" name="title" id="title" value="<?php 
					if(isset($_GET['id'])) echo $page['title'];  ?>">
			</label>
		<br/><br/>
			<label for="shorttitle">
				shorttitle
				<input type="text" class="form-control" name="shorttitle" id="shorttitle" value="<?php 
					if(isset($_GET['id'])) echo $page['shorttitle'];  ?>">
			</label>
		<br/><br/>
			<label for="date">
				date
				<input type="text" class="form-control" name="date" id="date" value="<?php 
					if(isset($_GET['id'])) echo $page['date'];  ?>">
			</label>
		<br/><br/>
		<!-- title, shorttitle, date, time_from, time_to, location, link, Description -->
			<label for="time_from">
				time_from
				<input type="text" class="form-control" name="time_from" id="time_from" value="<?php 
					if(isset($_GET['id'])) echo $page['time_from'];  ?>">
			</label>
		<br/><br/>
			<label for="time_to">
				time_to
				<input type="text" class="form-control" name="time_to" id="time_to" value="<?php 
					if(isset($_GET['id'])) echo $page['time_to'];  ?>">
			</label>
		<br/><br/>
			<label for="location">
				location
				<input type="text" class="form-control" name="location" id="location" value="<?php 
					if(isset($_GET['id'])) echo $page['location'];  ?>">
			</label>
		<br/><br/>
			<label for="link">
				link
				<input type="text" class="form-control" name="link" id="link" value="<?php 
					if(isset($_GET['id'])) echo $page['link'];  ?>">
			</label>
		<br/><br/>
			<label for="description">
				Description
					<input type="text" class="form-control" name="description" id="description" value="<?php 
					if(isset($_GET['id'])) echo $page['description'];  ?>" height="200px !important">
			</label>
		<br/><br/>

<?php if(isset($_GET['id'])){
	?>
<input type="hidden" name="id" value="<?php echo $page['id']; ?>">
	<?php
	} ?>

			<input type="submit" value="<?php 
					if(isset($_GET['id'])){ echo "Update"; }else{echo "Add";} ?>">

		</form>
	   
	   </div>
	</div>
</div>
	

<?php 
$pages = $db->query("
	SELECT *
	FROM events
	ORDER BY date DESC
	")->fetchAll(PDO::FETCH_ASSOC);

 ?>

<div class="show">
<?php if(empty($pages)): ?>
		<p>No pages at the moment.</p>
<?php else: ?>
<table class="table">
	<thead>
		<tr>
			<th>Title</th>
			<th>shorttitle</th>
			<th>date</th>
			<th>time_from</th>
			<th>time_to</th>
			<th>location</th>
			<th>link</th>
			<th>description</th>
			<th></th>
			<th></th>
		</tr>
	</thead>

	<tbody>
		<?php foreach($pages as $page): ?>
		<tr>
			<td><?php echo $page['title']; ?></td>
			<td><?php echo $page['shorttitle']; ?></td>
			<td><?php echo $page['date']; ?></td>
			<td><?php echo $page['time_from']; ?></td>
			<td><?php echo $page['time_to']; ?></td>
			<td><?php echo $page['location']; ?></td>
			<td><a href="<?php echo $page['link']; ?>"><?php echo "Link"; ?></a></td>
			<td><?php echo $page['description']; ?></td>
			<td><a href="edit-event.php?id=<?php echo $page['id']; ?>">Edit</a></td>
			<td><a href="delete.php?id=<?php echo $page['id']; ?>">Delete</a></td>
		</tr>
	<?php endforeach; ?>
	</tbody>
</table>
<?php endif; ?>
</div>


</body>
</html>
