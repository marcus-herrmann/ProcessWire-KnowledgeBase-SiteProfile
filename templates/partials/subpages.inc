<?php if ($page->showChildPages) { ?>
	<div class="module-subpages module">
	<h3 class="title title-subpages">Subpages</h3>
	<ul><?php
		
		$children = $page->children;

		foreach($children as $child) {
			$class = $child === $page->rootParent ? " class='on'" : '';
			echo "<li><a$class href='{$child->url}'>{$child->title}</a></li>";
		}

	?>
	</ul>
	</div>
<?php } ?>
