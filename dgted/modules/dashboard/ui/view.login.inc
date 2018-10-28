<?php

include_once 'blade/view.login.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div id="form">
  
  <div class="panel panel-default">
    
    <div class="panel-heading"><?php echo LangUtil::get('login_member_login'); ?></div>
    
    <div class="panel-body">
  
        <form method="post" class="form-horizontal">

            <div class="form-group">
              <label class="control-label col-sm-2" for="txtEmail">
              <?php echo LangUtil::get('login_email'); ?>:
              </label>
              <div class="col-sm-10">
                    <input type="email" class="form-control" name="txtEmail" id="txtEmail" placeholder="<?php echo LangUtil::get('login_enter_email'); ?>">
              </div>
            </div>

            <div class="form-group">
              <label class="control-label col-sm-2" for="txtPassword">
              <?php echo LangUtil::get('login_password'); ?>:
              </label>
              <div class="col-sm-10">          
                <input type="password" class="form-control" name="txtPassword" id="txtPassword" placeholder="<?php echo LangUtil::get('login_enter_password'); ?>">
              </div>
            </div>

            <div class="form-group">
              <div class="col-sm-offset-2 col-sm-6">
                <a href="<?php echo PageUtil::$USER_NEW; ?>">Register as a new user</a>
              </div>
              <div class="col-sm-4">  
                <a href="<?php echo PageUtil::$USER_FORGOT_PASSWORD; ?>">Forgot password</a>
              </div>
            </div>

            <div class="form-group">        
              <div class="col-sm-offset-2 col-sm-10">
                <button type="submit" name="login" value="login" class="btn btn-default"><?php echo LangUtil::get('login_submit'); ?></button>
              </div>
            </div>                

        </form>

    </div>

 </div>
    
</div>    
