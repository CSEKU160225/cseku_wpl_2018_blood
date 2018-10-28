jQuery(document).ready(function($) {
	
	$('#contact').dcContactTabs({
		tabs: [{
					form: {
						name: {type: 'text', label: 'Your name', validate: 'required'},
						emailfrom: {type: 'emailfrom', label: 'Your email'},
						message: {type: 'textarea', label: 'Your message', validate: 'required'},
						url: {type: 'url'},
						ip: {type: 'ip'},
						submit: {type: 'submit', text: 'Submit'}
					},
					title: 'Contact Design Chemical',
					subject: 'Design Chemical Enquiry',
					icon: 'mail.png',
					success: '<h4>Thank you!</h4><p>Your message has been received</p>'
				}],
		imagePath: 'http://www.designchemical.com/blog/wp-content/themes/dc2011/dcjct/images/icons/',
		action: 'http://www.designchemical.com/inc/email.php',
		offset: 60
	});
	var mega = 0;
	$('#header').mouseover(function(){
		if(mega == 0){
			mega = 1;
			$('#slide ul li a:gt(0)').each(function(){
				if(!$('img',this).length){
					var rel = $(this).attr('rel');
					var img = $("<img />").attr('src', 'http://www.designchemical.com/media/images/'+rel).load();
					$(this).prepend(img);
				}
			});
		}
	});
	$('.email').nospam({replaceText: true, filterLevel: 'normal'});
	var content = $(".email");
    content.load("/emailaddress.htm");
	
	$('a[rel*=external]').click(function(){
		this.target = "_blank";
	});
	$(".img-swap").hover(
          function(){this.src = this.src.replace("_off","_on");},
          function(){this.src = this.src.replace("_on","_off");
     });
	$('.demo').each(function(){
		var linkText = $(this).text();
		linkText = '<span>'+linkText+'</span>';
		$(this).empty().append(linkText);
	});
	jQuery('#nav-main-mega').dcMegaMenuCustom({
        rowItems: '4',
        speed: 'fast',
		effect: 'fade',
		subPad: 170
    });
	
  var currentPosition = 0;
  var slideWidth = 402;
  var slides = $('#slide li');
  var numberOfSlides = slides.length;
  slides.wrapAll('<div id="slideInner"></div>').css({'float' : 'left','width' : slideWidth});
  $('#slideInner').css('width', slideWidth * numberOfSlides);
  $('#slide-links ul li a').hover(function(){
	if(!$('#slide-links').hasClass('slide-static')){
		$('#slide-links ul li').removeClass('links-hover');
		var ind = $(this).index('#slide-links ul li a');
		$(this).parent().addClass('links-hover');
		$('#slideInner').stop().animate({'marginLeft' : slideWidth*(-ind)});
	}
  });
  $('#slide-links ul li a').click(function(){
	$('#slide-links').addClass('slide-static');
  });
  $(window).scroll(function(){
	 if($('.dcssb-float').length){
		buttonPosition($('.dcssb-float'));
	}
  });
  $('#social-share').dcSocialShare({buttons: "twitter,facebook,plusone,stumbleupon,digg,linkedin", twitterId: "designchemical", align: "left",offsetLocation: 0,center: 577,floater:false});
  
  // Selector
  	var theme_list_open = false;
		$("#theme_select").click( function (e) {
        		if (theme_list_open == true) {
					$(".center ul li ul").slideUp();
					theme_list_open = false;
        		} else {
					$(".center ul li ul").slideDown();         		
					theme_list_open = true;
        		}
        		e.preventDefault();
        	});
	$('.center ul li ul a').click(function(){
		this.target = "_blank";
	});
		$('body').mouseup(function(e){
					var id = $(e.target).attr('id');
					if(id != 'theme_select' && theme_list_open == true){
						$(".center ul li ul").slideUp();
					theme_list_open = false;
					}
				});
  
});

function buttonPosition(obj){
    var top = $(document).scrollTop();
    var p = top > 303 ? {marginTop: '50px'} : {marginTop: (303-top)+'px'} ;
    obj.css(p);
}
function defaulttextFunction(){
			$(".defaultText").focus(function(srcc) {
				if ($(this).val() == $(this)[0].title) {
					$(this).removeClass("defaultTextActive");
					$(this).val("");
				}
			});
			$(".defaultText").blur(function() {
				if ($(this).val() == "") {
					$(this).addClass("defaultTextActive");
					$(this).val($(this)[0].title);
				}
			});
			$(".defaultText").addClass("defaultTextActive").blur();
		}