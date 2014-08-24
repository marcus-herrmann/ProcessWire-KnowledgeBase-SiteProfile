<?php 

/**
 * Wiki Page template
 *
 */



include("./partials/head.inc"); 

if ($user->isLoggedin() && $user->hasRole('foo-user')) {

	?><div class="container-extras"><?php

		include("./partials/pagetools.inc");

		include("./partials/sources.inc"); 

	?></div><?php

	include("./partials/breadcrumbs.inc"); 

	include("./partials/_processing.inc"); 

	?>
	<h2 class="title-page title"><?php echo $page->title;?> <?php
	echo $fredi->setText("<span class='editpage'>(Edit)</span>")->render("title|body|showChildPages|repeaterSources|tags");?></h2>
	
	<?php
		echo "<span class='page-meta'>Last edit by " . $page->modifiedUser->name . " on " . date('F j, Y, g:i a', $page->modified) . "</span>"; 
	?>

	<div class="page-content"><?php
	echo $page->body;
	?></div>

	<?php

	include("./partials/subpages.inc"); 

	include("./partials/tags.inc"); 

	include("./partials/foot.inc"); 

} else {
	echo "Please log in";
}
