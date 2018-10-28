<?php
include_once 'blade/view.clubpage.blade.inc';
include_once COMMON.'class.common.inc';
include_once COMMON.'class.common.club.inc';

?>


<div id="page-wrap">


  <div id="header" class="col-sm-12">
      <nav class="navbar navbar-default">
        <div class="navbar-header">
            <a class="navbar-brand name" href="clubpage.php?club=<?php echo $_GET['club']; ?>">
            <?php echo $Club->getName(); ?>              
            </a>
            <a class="navbar-brand" href="clubpage_member.php?club=<?php echo $_GET['club']; ?>">
            Members              
            </a>   
            <a class="navbar-brand" href="clubpage_about.php?club=<?php echo $_GET['club']; ?>">
            About Us              
            </a>                        
        </div>
      </nav>
        
      <div>
        <?php 
        if(isset($Club))       
        echo '<img src="data:image/jpeg;base64,'.base64_encode( $Club->getCoverPhoto()).'"  />';
        ?>
      </div>

      <div>
          <h3> Description </h3>
                      
          <div class="panel panel-default">
          <div class="panel description">
             <?php

              if(isset($Club))
                echo $Club->getDescription() ; 

            ?>              
          </div>
          </div>

      </div>

  </div>

  <br>

  <div id="body" >
  <?php

    if(isset($ModuleList)){

      for($i = 0; $i < sizeof($ModuleList); $i++) {
          $Module = $ModuleList[$i];
  
  ?>
        <div id="container" class="col-sm-4">
          <div id="leftContent">
            
            <h3> <?php echo $Module->getModuleName();?> </h3>
                        
            <div class="panel panel-default">
            <div class="panel content">
              <?php echo $Module->getContent();?>        
            </div>
            </div>

        </div>
      </div>
<?php 
      }
    }  

?>
  </div>
  <div class = "footer col-sm-12">
      <h3> Contact Us </h3>
                  
      <div class="panel panel-default">
      <div class="panel mail">
          <?php
           if(isset($Club))
            echo $Club->getMail(); 
          ?>            
      </div>
      </div>
  </div>

</div>
