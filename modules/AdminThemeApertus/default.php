<?php

/**
 * default.php
 * 
 * Main markup template file for AdminThemeDefault
 * 
 * __('FOR TRANSLATORS: please translate the file /wire/templates-admin/default.php rather than this one.');
 * 
 * 
 */

if(!defined("PROCESSWIRE")) die();

if(!isset($content)) $content = '';
	
$searchForm = $user->hasPermission('page-edit') ? $modules->get('ProcessPageSearch')->renderSearchForm() : '';

$config->styles->prepend($config->urls->adminTemplates . "styles/main.css");
$config->styles->append($config->urls->root . "wire/templates-admin/styles/font-awesome/css/font-awesome.min.css"); 
$config->scripts->append($config->urls->root . "wire/templates-admin/scripts/inputfields.js?v=5"); 
$config->scripts->append($config->urls->adminTemplates . "scripts/main.js?v=5");
	
require_once(dirname(__FILE__) . "/AdminThemeApertusHelpers.php");
$helpers = new AdminThemeApertusHelpers();

?><!DOCTYPE html>
<html lang="<?php echo $helpers->_('en'); 
	/* this intentionally on a separate line */ ?>">
<head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<meta name="robots" content="noindex, nofollow" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<title><?php echo $helpers->renderBrowserTitle(); ?></title>

	<script type="text/javascript"><?php echo $helpers->renderJSConfig(); ?></script>
	<?php foreach($config->styles as $file) echo "\n\t<link type='text/css' href='$file' rel='stylesheet' />"; ?>
	<?php foreach($config->scripts as $file) echo "\n\t<script type='text/javascript' src='$file'></script>"; ?>
	<link href="//maxcdn.bootstrapcdn.com/font-awesome/4.1.0/css/font-awesome.min.css" rel="stylesheet">

	<style>
		a,
		.Inputfields .InputfieldStateToggle i.toggle-icon,
		input[type="text"],
		input[type="password"] {
			color: <?php $helpers->renderMainColor(); ?>;
		}

		.header-main,
		.header-main a {
			color: #fff;
		}

		.header-main {
			background: <?php $helpers->renderMainColor(); ?>;
		}

		button,
		.ui-button,
		li.action a, .actions a,
		.PageList .actions a,
		.PageListMoveNote a,
		.header-main,
		ul.WireTabs li .on {
			background: <?php $helpers->renderMainColor(); ?>;
		}

		input[type="text"],
		input[type="password"],
		textarea {
			border: 1px solid <?php $helpers->renderMainColor(); ?>;
		}

	</style>

</head>
<body class='<?php echo $helpers->renderBodyClass(); ?>'>

	<div class="header-main ui-helper-clearfix">
		<?php
		$helpers->renderEnvironmentIndicator();
		?>
		<div class="container">

			<h1 class="logo-main">
				<a href='<?php echo $config->urls->admin?>'>
					<?php $helpers->renderSiteName(); ?>
				</a>
			</h1>

			<section class="module-pagetree">
			<?php
			if($user->isLoggedin()) {
				echo "<h2 class='section-headline'>" . $this->_('Search Project') . "</h2>";
				echo $searchForm;
				echo "\n\n<ul id='topnav'>" . $helpers->renderTopNavItems() . "</ul>";
			}
			?>
			</section>

			<?php if($config->debug && $this->user->isSuperuser())
				include($config->paths->root . '/wire/templates-admin/debug.inc'); ?>

			<section class="module-forumsearch">
			<?php echo "<h2 class='section-headline'>" . $this->_('Search Forums') . "</h2>";
				$helpers->renderForumSearch(); 
			?>
			</section>

			<section class="module-usefullinks">
			<?php echo  "<h2 class='section-headline'>" . $this->_('Useful links') . "</h2>";
				$helpers->renderUsefulLinks(); 
			?>
			</section>

			<?php 	if($user->isSuperuser()) : ?>

			<section class="module-apertus-meta">
			<?php
				$helpers->renderAdminThemeConfigLink();
			?>
			</section>

			<?php endif; ?>

			<section class="module-processwire-meta">
				ProcessWire
				<?php echo $config->version . ' <!--v' . $config->systemVersion; ?>--> &copy; <?php echo date("Y"); ?>
			</section>

		</div>
	</div>


	<div class="main-content fouc_fix">
		<?php echo $helpers->renderAdminNotices($notices); ?>

		<div class="module-breadcrumbs">
			<div class='container'>

				<?php
				if($page->process == 'ProcessPageList' || ($page->name == 'lister' && $page->parent->name == 'page')) {
					echo $helpers->renderAdminShortcuts();
				}
				?>

				<ul class='nav'><?php echo $helpers->renderBreadcrumbs(); ?></ul>

			</div>
		</div><!--/#breadcrumbs-->

		<div class="container">

			<?php 
			if(trim($page->summary)) echo "<h2>{$page->summary}</h2>"; 
			if($page->body) echo $page->body; 
			echo $content; 
			?>

		</div>

		<footer class="footer-main">

			<nav class="module-footnav">
				<ul>
					<li><a href="<?php echo $config->urls->admin; ?>module/?reset=2" title="Search for new Modules"><i class="fa fa-refresh"></i><span>Search for new Modules</span></a></li>
					<li><a href="<?php echo $pages->get('/')->url; ?>" title="View Site"><i class="fa fa-eye"></i><span>View Site</span></a></li>

					<li><a href="<?php echo $config->urls->admin; ?>access/users" title="Users"><i class="fa fa-user"></i><span>Users</span></a></li>
					<li><a href="<?php echo $config->urls->admin; ?>login/logout" title="Logout"><i class="fa fa-power-off"></i><span>Logout</span></a></li>
				</ul>
			</nav>

		</footer>

	</div><!--/#content-->




</body>
</html>
