<?php
	$treeMenu = $modules->get("MarkupSimpleNavigation");
	$addSubpageLink = "";
	$areaTitlePrefix = "";

	if ($page->template == 'wiki-page') { // do not show addSubPageLink in e.g. Meta and Tag section
		$addSubpageLink = '&nbsp;<a href="' .$config->urls->admin .'page/add/?parent_id={id}" title="Add subpage" class="btn btn-addsubpage"><i class="fa fa-plus-circle"></i></a>';
		$areaTitlePrefix = "Area: ";
	}
	$areaTitle = $page->rootParent->title;
	$areaLink = $page->rootParent->url;

	$options = array(
		'parent_class' => 'module-treemenu__item--parent',
		'current_class' => 'module-treemenu__item--current',
		'has_children_class' => 'has_children',
		'levels' => true,
		'levels_prefix' => 'level-',
		'max_levels' => 5,
		'firstlast' => false,
		'collapsed' => false,
		'show_root' => false,
		'selector' => '',
		'selector_field' => 'nav_selector',
		'outer_tpl' => '<ul class="module-treemenu module">||</ul>',
		'inner_tpl' => '<ul>||</ul>',
		'list_tpl' => '<li%s>||</li>',
		'list_field_class' => 'module-treemenu__item',
		'item_tpl' => '<span><a href="{url}">{title}</a>' . $addSubpageLink . '</span>',
		'item_current_tpl' => '<span><a href="{url}" class="module-treemenu__link--current">{title}</a>' . $addSubpageLink . '</span>',
		'xtemplates' => '',
		'xitem_tpl' => '<span>{title}</span>',
		'xitem_current_tpl' => '<span>{title}</span>',
		'date_format' => 'Y/m/d',
		'code_formatting' => false,
		'debug' => false
	);
	echo "<h3 class='title title-area'>
		<span>$areaTitlePrefix
			<a href='$areaLink'>$areaTitle</a>&nbsp;
			<a href='" . $config->urls->admin . "page/add/?parent_id=" . $page->id . "' title='Add subpage' class='btn btn-addsubpage'><i class='fa fa-plus-circle'></i></a></span></h3>";
	echo $treeMenu->render($options, null, $page->rootParent);
?>
