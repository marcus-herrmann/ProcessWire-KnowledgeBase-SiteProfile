<?php
	if (!function_exists('truncateText')) {
		function truncateText($text, $maxlength = 200) {
			$text = substr(strip_tags($text), 0, $maxlength);
			if(strlen(rtrim($text, ' .!?,;')) == $maxlength) {
				$text = substr($text, 0, strrpos($text, ' ')); 
			}
			return trim($text); 
		}
	}
	
	$summary = truncateText($p->body);
	echo "<li>
	<h3><a href='" . $p->url . "'>" . $p->title . "</a></h3>
	<p class='summary'>$summary</p>
	</li>";
?>
