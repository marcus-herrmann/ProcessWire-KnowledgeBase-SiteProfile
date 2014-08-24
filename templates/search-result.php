<?php 

/**
 * Tag listing template
 *
 */

if (!function_exists('truncateText')) {
	function truncateText($text, $maxlength = 200) {
		$text = substr(strip_tags($text), 0, $maxlength);
		if(strlen(rtrim($text, ' .!?,;')) == $maxlength) {
			$text = substr($text, 0, strrpos($text, ' ')); 
		}
		return trim($text); 
	}
}

if ($user->isLoggedin() && $user->hasRole('wiki-user')) {

	if($q = $sanitizer->selectorValue($input->get->q)) {

		// Send our sanitized query 'q' variable to the whitelist where it will be
		// picked up and echoed in the search box by the head.inc file.
		$input->whitelist('q', $q); 

		// Search the title, body and sidebar fields for our query text.
		// Limit the results to 50 pages. 
		// Exclude results that use the 'admin' template. 
		$pageMatches = $pages->find("title|body%=$q, limit=50"); 

		$count = count($pageMatches); 

		if($count) {
			$out = "<h2>Found $count pages matching your query:</h2>" . 
				"<ul class='nav'>";

			foreach($pageMatches as $p) {
				$summary = truncateText($p->body);
				$out .= "<li><h3><a href='{$p->url}'>{$p->title}</a></h3><p>$summary</p></li>";
			}

			$out .= "</ul>";

		} else {
			$out .= "<h2>Sorry, no results were found.</h2>";
		}
	} else {
		$out .= "<h2>Please enter a search term in the search box on the left</h2>";
	}
} else {
	$out = "You have to be logged in.";
}

include("./partials/head.inc"); 

echo $out; 

include("./partials/foot.inc"); 

