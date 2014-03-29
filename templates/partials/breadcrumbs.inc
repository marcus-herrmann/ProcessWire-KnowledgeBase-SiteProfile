<ul class="module-breadcrumb">
<?php

	foreach($page->parents as $parent) {
		echo "<li><a href='{$parent->url}' class='module-breadcrumb__link'>{$parent->title}</a> ›&nbsp;</li>";
	}

?>
<li><?php echo $page->title; ?></li>
</ul>
