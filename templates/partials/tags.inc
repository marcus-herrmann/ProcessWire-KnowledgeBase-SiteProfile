<?php
	if (count($page->tags)) {
		echo '<div class="module-pagetags module">';
		echo '<h3>Tags</h3>';
		echo '<ul class="module-taglist">';

		foreach ($page->tags as $t) {
			echo '<li><a href="' . $t->url . '">' . $t->title . '</a></li>';
		}

		echo '</ul></div>';
	}
?>
