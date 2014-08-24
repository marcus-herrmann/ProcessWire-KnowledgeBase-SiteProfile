# ApertusAdminTheme for ProcessWire
An AdminTheme meant for developers

![Screenshot](http://demo.marcus-herrmann.com/apertus/apertus_scr1.png)

## Requirements
* Current ProcessWire 2.4.X Developement version
* A modern browser (but I think that's the last thing a developer is missing)

## Features
Some of us work on a large number of ProcessWire installations at once. The following to options aim to customize your backends to that extend that you can tell them apart within miliseconds and without looking at the URL.

### Environment indicator
When using a development, staging and production version of a project, use this little switch in the theme's setting to indicate which installation you're currently on.

### Set main color
In order to not confuse installations using Apertus, "color brand" them. Use hex, rgb(a), hsl(a), or named CSS values to your liking, but remember to apply a relatively dark color to prevail contrast.

### Set project name
Lastly, name project backends.

### Shortcuts
* Search the forums from within every page of your ProcessWire backend
* Have all the important API documentation links at hand
* Check for new modules from every page using the tools upper right (refresh icon)

![Options](http://demo.marcus-herrmann.com/apertus/apertus_options.jpg)

## Installation

* Copy all files from the ZIP archive to your `/site/modules/ApertusAdminTheme/ directory.
* Click "Check for new modules" in ProcessWire Admin Modules screen. Click install for the module labeled: "ApertusAdminTheme".

## Background
The design of this Admin Theme is based on my [Knowledge Base Site Profile](https://github.com/marcus-herrmann/ProcessWire-KnowledgeBase-SiteProfile). Also, it is created to accompany a newer version of said Site Profile.

**This is the first version of Apertus, not yet heavily tested and therefore bleeding edge. Please use with caution**.

I named it "Apertus" ([latin for open, uncovered](http://en.wiktionary.org/wiki/apertus)) because of the default state of the main navigation (Page, Modules, Access,...).

This is a pre-release (0.0.1) needing current dev version of PW to prepare for ProcessWire 2.5. **Please help me improving the theme by [reporting bugs on GitHub](https://github.com/marcus-herrmann/ProcessWire-ApertusAdminTheme/issues).** Thanks! :)

## Roadmap
Things I intend/change to implement in future versions:

* Making useful links configurable
* Proper responsive behaviour
* Refactoring JS
* Remove Compass dependency when compiling theme's CSS
