<?php

if($user->isLoggedin()) {
	$session->redirect("/"); 
}

if($input->post->user && $input->post->pass) {

	$user = $sanitizer->username($input->post->user);
	$pass = $input->post->pass; 

	if($session->login($user, $pass)) {
		$session->redirect("/"); 
	}
}

?>

	<form action='./' method='post' class='module-login module'>
		<?php if($input->post->user) echo "<p class='error'>Login failed</p>"; ?>
		<p><label for="user">User</label><input type='text' name='user' /></p>
		<p><label for="pass">Password</label><input type='password' name='pass' /></p>
		<p><input type='submit' name='submit' value='Login' /></p>
	</form>
