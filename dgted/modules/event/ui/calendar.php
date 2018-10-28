<?php 


 ?>
<?php
/*date_default_timzeone_set('Asia/Dhaka');*/
date_default_timezone_set("Asia/Dhaka");
class Calendar {

    public function __construct(){
        $this->naviHref = htmlentities($_SERVER['PHP_SELF']);
    }


    /*private $dayLabels = array("Sun","Tue","Wed","Thu","Fri","Sat","Mon");*/
    private $dayLabels = array("Sun","Mon","Tue","Wed","Thu","Fri","Sat");
    private $currentYear=0;
    private $currentMonth=0;
    private $currentDay=0;
    private $currentDate=null;
    private $daysInMonth=0;
    private $naviHref= null;  
    /*public $eko;*/

   /*protected $toDay=0;*/
    /*private $toDay=0;*/


    public function show() {
        /*$year  == null;
        $month == null;*/

        if (isset($_GET['year'])) {
            $year = $_GET['year'];
        } else {
            $year = date("Y", time());
        }

        if (isset($_GET['month'])) {
            $month = $_GET['month'];
        } else {
            $month = date("m", time());
        }

/*       $rows = $db->query("
          SELECT *
          FROM events
      ")->fetchAll(PDO::FETCH_ASSOC);*/


/*        if(null==$year&&isset($_GET['year'])){
            $year = $_GET['year'];
        }else if(null==$year){
            $year = date("Y",time());
        }

        if(null==$month&&isset($_GET['month'])){
            $month = $_GET['month'];
        }else if(null==$month){
            $month = date("m",time());
        }
*/
        
        $this->currentYear=$year;
        $this->currentMonth=$month;
        $this->daysInMonth=$this->_daysInMonth($month,$year);
        $content='<div id="calendar">'.
            '<div class="box">'.
            $this->_createNavi().
            '</div>'.
            '<div class="box-content">'.
            '<ul class="label">'.$this->_createLabels().'</ul>';
        $content.='<div class="clear"></div>';
        $content.='<ul class="dates">';

        $weeksInMonth = $this->_weeksInMonth($month,$year);
        //  weeks in a month
        for( $i=0; $i<$weeksInMonth+1; $i++ ){

            // days in a week
            for($j=1;$j<=7;$j++){
                $content.=$this->_showDay($i*7+$j);            

               /*if($this->currentDate == date('Y-m-d'))
               {
               $finalDisplay = ' '.$cellContent.' ';
               }*/
            }
        }

        $content.='</ul>';
        $content.='<div class="clear"></div>';
        $content.='</div>';

        $content.='</div>';
        return $content;
    }



/*public function closestDate($day){

    $day = ucfirst($day);
    if(date('l', time()) == $day)
        return date("Y-m-d", time());
    else if(abs(time()-strtotime('next '.$day)) < abs(time()-strtotime('last '.$day)))
        return date("Y-m-d", strtotime('next '.$day));
    else
        return date("Y-m-d", strtotime('last '.$day));
}


if($this->currentDate == date('Y-m-d'))
{
$finalDisplay = ' '.$cellContent.' ';
}    
*/
    private function _showDay($cellNumber)
    {

        if($this->currentDay==0){
            $firstDayOfTheWeek = date('N',strtotime($this->currentYear.'-'.$this->currentMonth.'-02'));
            if(intval($cellNumber) == intval($firstDayOfTheWeek)){
                $this->currentDay=1;
            }
        }

        if( ($this->currentDay!=0)&&($this->currentDay<=$this->daysInMonth) ){
            $this->currentDate = date('d-m-Y',strtotime($this->currentYear.'-'.$this->currentMonth.'-'.($this->currentDay)));
            $cellContent = $this->currentDay;
            $this->currentDay++;
        }else{

            $this->currentDate =null;
            $cellContent=null;
        }

        if($this->currentDate == date('d-m-Y'))
        {
        /*$finalDisplay = ' '.$cellContent.' ';*/
        $toDay = 1;
        /*$today=$this->$toDay;*/
        } else { $toDay=0;}

        if($this->currentDate == date('d-m-Y'))
        {
        /*$finalDisplay = ' '.$cellContent.' ';*/
        $toDay = 1;
        /*$today=$this->$toDay;*/
        } else { $toDay=0;}
$db = new PDO('mysql:host=localhost;dbname=calendar', 'root', '');
$rows = $db->query("
  SELECT *
  FROM events
")->fetchAll(PDO::FETCH_ASSOC);
/*$eko = array();*/
/*foreach ($rows as $row):
    if($this->currentDate == $row['date']){
           $eko['test'] = " ".$row['title'].": ".$row['description']."<br/>";
             }
 endforeach;*/


        $op = '<li id="li-'.$this->currentDate.'" class="'.($cellNumber%7==1?' start ':($cellNumber%7==0?' end ':' ')).
            ($cellContent==null?'mask':'').($toDay==1?'today':'').'">';

        $op.= ' <div class="showTitle float-left">';
    $x=1;
    $more=0;
    foreach ($rows as $row):
        if($this->currentDate == $row['date']){
            if($x<=4){        
               $op.= '<a href="event.php?url='.$row['title'].'">';
               $op.= "$x. ".$row['shorttitle']."<br/>";
               $op.= '</a>';
            } else{
            if($more!=1){
               $op.= '<a href="day-view.php?date='.$this->currentDate.'">';
               $op.= '<p>more</p>';
               $op.= '</a>';
               $more=1;
               }
            }
           $x++;
             }
    endforeach;

        $op.='</div>';
//day-view.php?date=23-04-2017

               $op.= '<span class="celcontnt float-right"><a href="day-view.php?date='.$this->currentDate.'">'.$cellContent.'</a></span></li>';

    return $op;


    }


    private function _createNavi(){

        $nextMonth = $this->currentMonth==12?1:intval($this->currentMonth)+1;
        $nextYear = $this->currentMonth==12?intval($this->currentYear)+1:$this->currentYear;
        $preMonth = $this->currentMonth==1?12:intval($this->currentMonth)-1;
        $preYear = $this->currentMonth==1?intval($this->currentYear)-1:$this->currentYear;

        return
            '<div class="header">'.
            '<a class="prev" href="'.$this->naviHref.'?month='.sprintf('%02d',$preMonth).'&year='.$preYear.'">Prev</a>'.
            '<span class="title">'.date('Y M',strtotime($this->currentYear.'-'.$this->currentMonth.'-1')).'</span>'.
            '<a class="next" href="'.$this->naviHref.'?month='.sprintf("%02d", $nextMonth).'&year='.$nextYear.'">Next</a>'.
            '</div>';
    }


    private function _createLabels(){

        $content='';
        foreach($this->dayLabels as $index=>$label){
            $content.='<li class="'.($label==6?'end title':'start title').' title">'.$label.'</li>';

        }

        return $content;
    }



    private function _weeksInMonth($month=null,$year=null){

        if( null==($year) ) {
            $year =  date("Y",time());
        }

        if(null==($month)) {
            $month = date("m",time());
        }

        // find number of days in this month
        $daysInMonths = $this->_daysInMonth($month,$year);
        $numOfweeks = ($daysInMonths%7==0?0:1) + intval($daysInMonths/7);
        $monthEndingDay= date('N',strtotime($year.'-'.$month.'-'.$daysInMonths));
        $monthStartDay = date('N',strtotime($year.'-'.$month.'-01'));

        if($monthEndingDay<$monthStartDay){
            $numOfweeks++;
        }
        return $numOfweeks;
    }

    /**
     *
     * calculate number of days in a particular month
     *
     */
    
    private function _daysInMonth($month=null,$year=null){

        if(null==($year))
            $year =  date("Y",time());

        if(null==($month))
            $month = date("m",time());

        return date('t',strtotime($year.'-'.$month.'-01'));
    }

}