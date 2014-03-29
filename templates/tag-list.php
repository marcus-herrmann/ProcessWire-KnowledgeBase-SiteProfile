<?php 

/**
 * Tag listing template
 *
 */

include("./partials/head.inc"); 

$tagName = $page->title;

echo "<h2>Tagged with " . $tagName . "</h2>";

$pagesTaggedWithTagName = $pages->find("tags='$tagName'");

	echo "<ul>";

	if (count($pagesTaggedWithTagName)) {

	foreach ($pagesTaggedWithTagName as $p) {
		include("./partials/page-list.inc"); 
	}

	echo "</ul>";

} else {
	echo "No pages tagged with " . $tagName;
}

include("./partials/foot.inc"); 
