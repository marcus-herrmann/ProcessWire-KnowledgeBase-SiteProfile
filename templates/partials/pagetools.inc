<ul class="module-pagetools">
<?php
if ($page->sticky) {
	$flagLabel = "<i class='fa fa-star'></i> Make unsticky";
} else {
	$flagLabel = "<i class='fa fa-star-o'></i> Make sticky";
}

if ($user->bookmarkedPagesByUser->has($page)) {
	$bookmarkLabel = "<i class='fa fa-bookmark'></i> Remove from bookmarks";
} else {
	$bookmarkLabel = "<i class='fa fa-bookmark-o'></i> Add to bookmarks";
}

if($page->editable() && $page->template == "wiki-page") {
	echo "<li><a href='" . $page->url . "?action=make-sticky'>$flagLabel</a> </li>";
	echo "</li><li><a href='" . $page->url . "?action=bookmark'>$bookmarkLabel</a> </li>";
}

?>
	<li><a href="javascript:print()"><i class="fa fa-print"></i> Print</a></li>
</ul>
