# ProcessWire Knowledge Base site profile

Rudimentary site profile for CMS/CMF [ProcessWire](http://processwire.com/) in early development. In contrast to most established wiki/knowledge base solutions wiki-articles are set in a hierarchical way.

## Installation

Before running the installer of ProcessWire copy/replace 

~~~
/site-default/install/
/site-default/templates/
/site-default/modules/

~~~

with the folders from this repo.

### Requirements

* ProcessWire 2.4

### Constraints

It's not possible to export user roles with [ProcessWire's Site Export Module](http://modules.processwire.com/modules/process-export-profile/) this profiles templates are checking just whether they are accessed by an anonymous or logged in user.

## Features

* Tagging of wiki-articles
* Set articles to globally sticky ( = for all users)
* Personal bookmarking of articles for logged in users
* When using markdown to author wiki-articles, code highlighting via [highlightjs](highlightjs.org)

## Included modules

* [Fredi](https://github.com/apeisa/Fredi)
* [MarkupSimpleNavigation](https://github.com/somatonic/MarkupSimpleNavigation)

## About

In need for a light knowledge base software and not happy with solutions such as MediaWiki, Dokuwiki or Confluence I decided to build such a tool based on ProcessWire. At the moment this profile is lacking of features, but doing well in the context it is created for - a somewhat protected simple knowledge base for internal use.