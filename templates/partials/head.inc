<?php
	$fredi = $modules->get("Fredi");
?>

<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="<?php echo $page->summary; ?>">

	<title><?php echo $pages->get('/')->siteName; ?> | <?php echo $page->title; ?></title>

	<!-- Source Sans Pro via Google Fonts -->
	<link rel="stylesheet" href='//fonts.googleapis.com/css?family=Source+Sans+Pro:400,600,700,400italic,600italic,700italic' rel='stylesheet' type='text/css'>

	<!-- Icons via Font Awesome -->
	<link rel="stylesheet" href="//netdna.bootstrapcdn.com/font-awesome/4.0.3/css/font-awesome.css" rel="stylesheet">

	<!-- Our stylesheet -->
	<link rel="stylesheet" href="<?php echo $config->urls->templates?>/dist/css/main.css">

	<link rel="stylesheet" href="http://yandex.st/highlightjs/8.0/styles/default.min.css">
	<script src="http://yandex.st/highlightjs/8.0/highlight.min.js"></script>

	<script type="text/javascript" src="<?php echo $config->urls->templates?>/dist/js/main.min.js"></script>

	<script>
	
	</script>

	<!--[if lt IE 9]>
		<script src="http://cdnjs.cloudflare.com/ajax/libs/html5shiv/3.7/html5shiv.js"></script>
	<![endif]-->
	<?php echo $fredi->renderScript(); ?>
</head>
<body>
<div class="pure-g">
	<div class="container-sidebar pure-u-1-5">
	<h1 class="title title-site"><a href="<?php echo $pages->get('/')->url; ?>"><?php echo $pages->get('/')->siteName; ?></a></h1>


	<?php if ($user->isLoggedin() && $user->hasRole('wiki-user')) { ?>

		<?php
			include("./partials/searchform.inc"); 
		?>

		<?php if ($page->template == "home") { 
		echo "<h3 class='title-area'><span>Areas <a href='" . $config->urls->admin . "page/add/?parent_id=" . $pages->get('/')->id . "' title='Add subpage' class='btn btn-addsubpage'><i class='fa fa-plus-circle'></i></a></span></h3>"; ?>
		<ul class="module-arealist module"><?php
			
			$children = $page->children;
		
			foreach($children as $child) {
				$class = $child === $page->rootParent ? " class='on'" : '';
				echo "<li><a$class href='{$child->url}'>{$child->title}</a></li>";
			}

		?>
		</ul>

		<?php } else { 

			include("./partials/treemenu.inc"); 

		} ?>

		<?php
			include("./partials/tags-all.inc"); 
		?>

	<?php } // logged in ?>

		<?php if ($user->isLoggedin() && $user->hasRole('wiki-user')) { ?>
			<div class="module-usermgmt module">
			<h3>Hello <a href="<?php echo $pages->get('1026')->url; ?>"><?php echo $user->name; ?>!</a></h3>
			<ul>
			<li><a href="<?php echo $pages->get('1026')->url; ?>">Manage my bookmarks</a> <span class='bookmark-count'>(<?php echo $modules->get("FlagPages")->showFlagCount() ?>)</span></li>
			<li><a href="<?php echo $config->urls->admin; ?>access/users/edit/?id=<?php echo $user->id; ?>">Edit my profile</a></li>
			<li><a href="<?php echo $config->urls->admin; ?>">ProcessWire Admin</a></li>
			<li><a href="<?php echo $pages->get('1035')->url; ?>">Logout</a></li>
			</ul>
			</div>
		<?php } ?>
	</div>

	<div class="container-content  pure-u-4-5">

