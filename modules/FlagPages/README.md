FlagPages 0.2.1
=========

Module for ProcessWire: lets logged-in users flag pages.

**With this module, a logged in user can flag/unflag pages, on whose template the flag link (see below) has been placed. These flags serve as "personal bookmarks" and are not a site-wide sticky setting.**

Proof of concept - do not use in production environments without testing thoroughly.

![Example Screenshot](http://assets.marcus-herrmann.com/FlagPages/flagscreen.jpg)

## Usage

On the module's config page you can set the user roles allowed to flag pages. 

On the markup side, FlagPages module consists of two parts: Rendering the link and rendering a list with your current bookmarks.

First of all, load the module via:

```
$flags = $modules->get("FlagPages");
```

### Rendering flag toggle link

Then, use the renderLink method and place the output in your template. By adding the link to all or just certain templates, you can control which templates can be flagged and which can't.

```
echo $flags->renderLink();
```

The default output will be "Add {Name} to flags", or "Remove {Name} from flags". You can override these labels with parameters. For example:

```
echo $flags->renderLink("Add %s to my bookmarks", "Remove %s from my bookmarks");
```


### Rendering the flagged pages list

```
echo $flags->renderList();
```

This will output a simple unordered list with links to pages the currently logged-in user has set a flag to.


## Installation

* Requirement: ProcessWire 2.4 (although I haven't tested it in older versions, frankly)

### Within module area in ProcessWire Backend

Click "New" and search for `FlagPages` class name.

### Manually

1. Download or git clone, rename the module folder to "FlagPages" and put it into your `site/modules ` folder
2. Go to modules overview page and click "Check for new modules"
3. Install the module. The module will appear under "Flag" section.

### By Module Class Name
*Coming Soon*

## Forum topic
https://processwire.com/talk/topic/7044-release-flagpages/

## Changelog

### 0.2.1
Using ASM select for chosing user roles with flagging permission

### 0.2.0
Added setting to limit flagging ability to certain user roles

### 0.1.1
Simplified renderList() param logic (thanks, [teppo](https://processwire.com/talk/topic/7044-release-flagpages/#entry67965))

### 0.1.0
Add basic functionality
