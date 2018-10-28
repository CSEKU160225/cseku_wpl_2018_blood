<?php

include_once 'blade/view.VideoComment.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.video.inc';


?>
<div class="panel panel-default">
    
    <div class="panel-heading">Video Tutorial Viewer</div>
    
    <div class="panel-body">

	
	<div id="video">

			<?php
				$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
				$Video2 = substr($id, -38);
				
				$Result1 = $_VideoCommentBAO->readvideo($Video2);
				//if DAO access is successful to load all the comments then show them one by one
				if($Result1->getIsSuccess()){

					$Vedio = $Result1->getResultObject();
				?> 
					    <div>
              				<label class="control-label"><?php echo $Vedio->getTitle(); ?></label>
						</div>
						<div>
						    <?php
						    $front = '<iframe width="560" height="315" src="https://www.youtube.com/embed/' ;
							$back = '" frameborder="0" allowfullscreen></iframe>';
							$link = $Vedio->getLink();
							$link2= substr($link,32);
							$Link=$front.$link2.$back;
						     echo $Link; 
						     ?>
					    </div>
		
				    <?php

				}
				else{

					echo $Result->getResultObject(); //giving failure message
				}

				?>
	</div>
	<div>			
				<div>

				<?php
				$id = 'http://'.$_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
				$Video2 = substr($id, -38);
				//echo $Video2;
			
				$Result1 = $_VideoCommentBAO->readVideoComment($Video2);

				//if DAO access is successful to load all the comments then show them one by one
				if($Result1->getIsSuccess()){

					$VideoList = $Result1->getResultObject();
						?> 
						
							<?php
							for($i = 0; $i < sizeof($VideoList); $i++) {
								$Video = $VideoList[$i];

								if($i%2==0){
								?>
								<div class="col-sm-12" style="border-style:solid;background-color: #8aaaaa">
								<?php
								}
								else{ 
								?>
								<div class="col-sm-12" style="border-style:solid;background-color: #878aaa">
								<?php
								}?>								
							    <div class="col-sm-4" style="font-size:12px;font-weight:bold">
								    <?php 
									    $id= $Video->getCreator();
									    $Result5 = $_VideoCommentBAO->readCreator($id);
								    	if ($Result5->getIsSuccess()) {
								    		$user = $Result5->getResultObject();

							    			echo $user->getFirstName().' '.$user->getLastName().'::';
							    		} 

						    		?>
						    	</div>		
							    <div class="col-sm-8" style="font-size:15px;text-align: justify;font-style: italic;color:blue">
								    <?php echo $Video->getComment(); ?>
							    </div>
							    </div>						   
						    <?php

							}	
				}
				else{

					echo $Result->getResultObject(); //giving failure message
				}

				?>

				</div>
	</div>
	<div id="form">			
		<form method="post" class="form-horizontal">
				<div class="form-group">		
				<input type='text' name ="txtvideo" value="<?php echo $Video2 ; ?>" placeholder="<?php echo $Video2 ; ?>"" style="display : none" />		
				<label class="control-label col-sm-3" for="txtAns">Comment : </label>
				<div class="col-sm-9">
					<textarea rows="5" cols="50" name="txtAns" 
					placeholder="Enter your comment" 
					value="<?php if(isset($_GET['edit'])) echo $getROW->getComment();  ?>" >
					</textarea>
				</div>
				</div>

				<div class="form-group">
					<div class="col-sm-offset-4 col-sm-4">
						<input  type="submit" id="savebutton"  name="save" value="Submit">
					</div>
				</div>	
		</form>

	</div>

	</div>

</div>
	