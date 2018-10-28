<?php

include_once 'blade/view.forgot_password.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div id="form">
  
  <div class="panel panel-default">
    
    <div class="panel-heading">Forgot Password</div>
    
    <div class="panel-body">
  
        <form method="post" class="form-horizontal">

            <div class="form-group">
              <label class="control-label col-sm-2" for="txtEmail">
              Email:
              </label>
              <div class="col-sm-10">
                    <input type="email" class="form-control" name="txtEmail" id="txtEmail" placeholder="Enter Email" required>
              </div>
            </div>


            <div class="form-group">        
              <div class="col-sm-offset-2 col-sm-10">
                <button type="submit" name="request" value="request" class="btn btn-default">Request Password</button>
              </div>
            </div>                

        </form>

    </div>

 </div>
    
</div>    
