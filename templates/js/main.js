$(document).ready(function() {

	$('pre code').each(function(i, e) {hljs.highlightBlock(e)});

	$('.btn-addsubpage').css("opacity", 0);

	$('.module-treemenu span, .title-area span').hover(function(){
		$(this).find('.btn-addsubpage').css("opacity", 1);
	},function(){
		$(this).find('.btn-addsubpage').css("opacity", 0);
	})

});
