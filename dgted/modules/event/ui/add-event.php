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
<div class="float-right home-btn">
  <a href="index.php" class="btn btn-success" role="button">Home</a>
</div>
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
		<div class="add-event-form">
		<form action="add-event.php" method='POST' autocomplete="off">

			<label for="title">
				Title
				<input type="text" class="form-control" name="title" id="title" value="<?php 
					if(isset($_GET['id'])) echo $page['title'];  ?>" style="width: 200%;">
			</label>
		<br/><br/>
			<label for="shorttitle">
				shorttitle
				<input type="text" class="form-control" name="shorttitle" id="shorttitle" value="<?php 
					if(isset($_GET['id'])) echo $page['shorttitle'];  ?>" style="width: 200%;">
			</label>
		<br/><br/>
			<label for="date">
				date (Please type a date format as: dd-mm-yyyy)
				<input type="text" class="form-control" name="date" id="date" value="<?php 
					if(isset($_GET['id'])) echo $page['date'];  ?>" style="width: 100%;">
			</label>
		<br/><br/>
		<!-- title, shorttitle, date, time_from, time_to, location, link, Description -->
			<label for="time_from">
				time_from
				<input type="text" class="form-control" name="time_from" id="time_from" value="<?php 
					if(isset($_GET['id'])) echo $page['time_from'];  ?>" style="width: 200%;">
			</label>

		<br/><br/>
			<label for="time_to">
				time_to
				<input type="text" class="form-control" name="time_to" id="time_to" value="<?php 
					if(isset($_GET['id'])) echo $page['time_to'];  ?>" style="width: 200%;">
			</label>
		<br/><br/>
			<label for="location">
				location
				<input type="text" class="form-control" name="location" id="location" value="<?php 
					if(isset($_GET['id'])) echo $page['location'];  ?>" style="width: 200%;">
			</label>
		<br/><br/>
			<label for="link">
				link (Please insert http:// before every link)
				<input type="text" class="form-control" name="link" id="link" value="<?php 
					if(isset($_GET['id'])) echo $page['link'];  ?>" style="width: 100%;">
			</label>
		<br/><br/>
			<label for="description">
				Description
					<input type="text" class="form-control" name="description" id="description" value="<?php 
					if(isset($_GET['id'])) echo $page['description'];  ?>" height="200px !important" style="width: 200%;">
			</label>
		<br/><br/>

<?php if(isset($_GET['id'])){
	?>
<input type="hidden" class="form-control" name="id" value="<?php echo $page['id']; ?>">
	<?php
	} ?>

			<input type="submit" class="form-control" value="<?php 
					if(isset($_GET['id'])){ echo "Update"; }else{echo "Add";} ?>" style="width: 50%;">

		</form>
	   </div>
	   </div>
	</div>
</div>
	

<?php

if(!isset($_GET['id']) and !empty($_POST)){
	$shorttitle = $_POST['shorttitle'];
	$title = $_POST['title'];
	$date = $_POST['date'];
	$time_from = $_POST['time_from'];
	$time_to = $_POST['time_to'];
	$location = $_POST['location'];
	$link = $_POST['link'];
	$description = $_POST['description'];

/* 1. title, 2. shorttitle, 3. date, 4. time_from, 5. time_to, 6. location, 7. link, 8. description */
	$insertPage = $db->prepare("
			INSERT INTO events (shorttitle, title, date, time_from, time_to, location, link, description)
			VALUES (:shorttitle, :title, :date, :time_from, :time_to, :location, :link, :description)
		");

	$insertPage->execute([
			'shorttitle' => $shorttitle,
			'title' => $title,
			'date' => $date,
			'time_from' => $time_from,
			'time_to' => $time_to,
			'location' => $location,
			'link' => $link,
			'description' => $description,
		]);

	/*header ('Location: ' .BASE_URL . '/admin/index.php');*/
	header ('Location: add-event.php');

}

 ?>






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
			<td><a href="delete-event.php?id=<?php echo $page['id']; ?>">Delete</a></td>
		</tr>
	<?php endforeach; ?>
	</tbody>
</table>
<?php endif; ?>
</div>

</body>
</html>
