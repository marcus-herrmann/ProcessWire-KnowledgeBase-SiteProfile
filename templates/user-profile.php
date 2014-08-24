<?php 

/**
 * Page template
 *
 */

include("./partials/head.inc"); 

include("./partials/breadcrumbs.inc"); 

if ($user->isLoggedin() && $user->hasRole('wiki-user')) {

	echo "<h2>Welcome, " . $user->name . "!</h2>";

	?><a href="<?php echo $config->urls->admin; ?>access/users/edit/?id=<?php echo $user->id; ?>">Edit</a></p>

	<?php 
	if (count($user->bookmarkedPagesByUser)) {
		echo "<div class='module-bookmarklist module'>";
		echo "<h4>My Bookmarks (" . count($user->bookmarkedPagesByUser) . ")</h4>";
		echo "<ul>";
		foreach ($user->bookmarkedPagesByUser as $b) {
			echo "<li><a href='" . $b->url . "'>" . $b->title . "</a> <a href='" . $b->url . "/?action=bookmark' class='editpage'> <i class='fa fa-eraser remove-bookmark'></i></a></li>";
		}
		echo "</ul></div>";
	}

}

include("./partials/foot.inc"); 
