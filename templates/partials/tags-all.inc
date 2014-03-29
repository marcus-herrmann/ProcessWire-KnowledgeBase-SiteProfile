<?php
	if (count($pages->get('1007')->children)) {

		echo '<h3>All Tags</h3>';
		echo '<ul class="module-taglist module">';

		foreach ($pages->get('1007')->children as $t) {
			echo '<li><a href="' . $t->url . '">' . $t->title . '</a></li>';
		}

		echo '</ul>';
	}
?>
