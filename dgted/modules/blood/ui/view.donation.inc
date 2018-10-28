<?php 
	include_once 'blade/view.donation.blade.inc'; 
?>
<div class="panel panel-default">
	<div class="panel-heading">Blood Donation Date</div>
	<div class="panel-body">
	<style>
			h4 span{
				background-color:#d3d3d3;
				padding:6px;
			}

			.given_dates{
				width:50%;
				margin: 0 auto;
				text-align:center;
			}
		</style>
		<div class="given_dates">
		
		<h3> Donation Dates : </h3> <br>
		<h4>
			<?php
				
				foreach($dates as $dt){
					echo '<span>'.$dt.'</span> &nbsp';
				}
			?>
		</h4>
		<br>
			
			<h3 style="text-align:center;"><?php echo $availability; ?></h3>
			<br><br>
		</div>
		<?php if($avlb == -1 || !$avlb){ ?>
		<div id="form">
			<form method="post" action="http://localhost/dgted/donation.php" class="form-horizontal">
				<div class="form-group">
					<?php

				  	      echo '<label class="control-label col-sm-4" for="search">Add Date:</label>';
				    ?>

					<div class="col-sm-8">
						<?php
				  	      echo '<input type="date" name="date" class="form-control" id="select-from-blood" required>';
	              	?>

					</div>
				</div>

				<div class="form-group">
					<div class="col-sm-offset-6 col-sm-4">
						<?php
	            	   	 echo '<input  type="submit"  name="submit" value="Submit">';
	            	?>

					</div>
				</div>
			</form>
		</div>
			<?php } ?>


	</div>
</div>

</form>

</div>
</div>