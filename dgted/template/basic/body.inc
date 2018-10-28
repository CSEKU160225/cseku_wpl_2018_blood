 
<div class="row">
	<div class="col-sm-12">
		<?php
			//TODO: check whether routing is active
			if(isset($page)){
				$routed_page = RouteUtil::get($page);
				include $routed_page;
			}	
		?>
	</div>
</div>
