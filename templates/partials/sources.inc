<?php
if($page->repeaterSources) {
	echo "<div class='module-sources module'>";
	echo "<h4>Sources</h4><ul>";

	foreach ($page->repeaterSources as $s) {
		echo "<li><a href='$s->sourceUrl'>$s->sourceLabel</a></li>";
	}

	echo "</ul></div>";
}
