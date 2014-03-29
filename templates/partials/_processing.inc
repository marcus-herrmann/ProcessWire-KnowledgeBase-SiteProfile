<?php
	if ($input->get) {

		switch ($input->get->action) {
			case 'make-sticky':

				$page->setOutputFormatting(false);

				if ($page->sticky) {
					$page->sticky = "0";
				} else {
					$page->sticky = "1";
				}

				$page->save();
				$session->redirect($page->url);

				break;

			case 'bookmark';

				$userBookmarks = $user->bookmarkedPagesByUser;

				$user->setOutputFormatting(false);

				if ($userBookmarks->has($page)) {
					$userBookmarks->remove($page);
				} else {
					$userBookmarks->add($page);
				}

				$user->save();
				$session->redirect($page->url);

				break;
				
			default:
				break;
		}
	}
?>
