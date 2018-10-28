jQuery(document).ready(function($) {
	$('.tabs button').click(function(event) {
		var selector = $(this).data('open');
		$('.tab-container .content').removeClass('active');
		$(selector).addClass('active');
	});
});