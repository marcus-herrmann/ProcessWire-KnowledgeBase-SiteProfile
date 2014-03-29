<?php
	$updatedPages = $pages->get('/')->find('sort=-modified, limit=5, template=wiki-page');

	if (count($updatedPages)) {
		echo "<div class='module-recentpages module'>";
		echo "<h3>Recently updated pages</h3>";
		echo "<ul>";

		foreach ($updatedPages as $u) {
			echo "<li><a href='" . $u->url . "'>" . $u->title . "</a></li>";
		}

		echo "</ul></div>";
	}
?>
