<div class="module-searchform module">
	<h3 class="title title-search">Search</h3>
	<form id='search_form' action='<?php echo $config->urls->root?>meta/search/' method='get'>
		<input type='text' name='q' id='search_query' value='<?php echo htmlentities($input->whitelist('q'), ENT_QUOTES, 'UTF-8'); ?>' />
		<button type='submit' id='search_submit'><i class="fa fa-search"><span>Search<span></i></button>
	</form>
</div>
