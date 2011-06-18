<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/settings/save_prefs.inc                                 |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Save user preferences to DB and to the current session              |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: save_prefs.inc 938 2007-12-10 15:27:19Z thomasb $

*/

$a_user_prefs = array(
  'timezone'     => isset($_POST['_timezone']) ? floatval($_POST['_timezone']) : $CONFIG['timezone'],
  'dst_active'   => isset($_POST['_dst_active']) ? TRUE : FALSE,
  'pagesize'     => is_numeric($_POST['_pagesize']) ? intval($_POST['_pagesize']) : $CONFIG['pagesize'],
  'prettydate'   => isset($_POST['_pretty_date']) ? TRUE : FALSE,
  'prefer_html'  => isset($_POST['_prefer_html']) ? TRUE : FALSE,
  'htmleditor'   => isset($_POST['_htmleditor']) ? TRUE : FALSE,
  'preview_pane' => isset($_POST['_preview_pane']) ? TRUE : FALSE,
  'draft_autosave' => isset($_POST['_draft_autosave']) ? intval($_POST['_draft_autosave']) : 0
  );

// don't override these parameters
foreach ((array)$CONFIG['dont_override'] as $p)
  $a_user_prefs[$p] = $CONFIG[$p];


// switch UI language
if (isset($_POST['_language']))
  {
  $sess_user_lang = $_SESSION['user_lang'] = get_input_value('_language', RCUBE_INPUT_POST);
  rcmail_set_locale($sess_user_lang);
  }

// force min size
if ($a_user_prefs['pagesize'] < 1)
  $a_user_prefs['pagesize'] = 10;

if (isset($CONFIG['max_pagesize']) && ($a_user_prefs['pagesize'] > $CONFIG['max_pagesize']))
  $a_user_prefs['pagesize'] = (int) $CONFIG['max_pagesize'];

if ($USER->save_prefs($a_user_prefs))
  $OUTPUT->show_message('successfullysaved', 'confirmation');


// go to next step
rcmail_overwrite_action('preferences');

?>