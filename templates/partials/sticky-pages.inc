<?php
	$stickyPages = $pages->find('sticky="1", sort=-modified');

	if (count($stickyPages)) {
		echo "<div class='module-stickypages module'>";
		echo "<h3>Sticky pages</h3>";
		echo "<ul>";

		foreach ($stickyPages as $s) {
			echo "<li><a href='" . $s->url . "'>" . $s->title . "</a></li>";
		}

		echo "</ul></div>";
	}
?>
