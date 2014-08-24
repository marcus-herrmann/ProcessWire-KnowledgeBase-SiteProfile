<?php 

/**
 * Home template
 *
 */

include("./partials/head.inc"); 

if ($user->isLoggedin() && $user->hasRole('wiki-user')) {

	?><div class="container-extras"><?php


		include("./partials/pagetools.inc"); 

	?></div>

	<h2 class="title-page title"><?php echo $page->title;?> <?php
	echo $fredi->setText("<span class='editpage'>(Edit)</span>")->render("siteName|body|guestBody");?></h2>

	<div class="page-content"><?php
	echo $page->body;
	?></div>
	<?php

	include("./partials/updated-pages.inc"); 

	include("./partials/sticky-pages.inc"); 

	include("./partials/foot.inc"); 

} else {

	echo $page->guestBody;
	include("./partials/user-login.inc"); 
}
