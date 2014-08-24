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

	echo "<h4>My Bookmarks (" . $modules->get("FlagPages")->showFlagCount() . ")</h4>";
	echo $modules->get("FlagPages")->renderList("module-bookmarklist module");

}

include("./partials/foot.inc"); 
