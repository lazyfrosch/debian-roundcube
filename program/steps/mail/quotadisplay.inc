<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/mail/quotadisplay.inc                                   |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Remote call to return the quota image or text                       |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Robin Elfrink <robin@15augustus.nl>                           |
 +-----------------------------------------------------------------------+

 $Id: quotadisplay.inc 850 2007-10-03 00:13:32Z ihug $

*/

$display = isset($_GET['_display']) ? $_GET['_display'] : 'text';
$id = isset($_GET['_id']) ? $_GET['_id'] : 'rcmquotadisplay';
$quota = rcmail_quota_content($display);
$OUTPUT->remote_response(sprintf("this.gui_objects.%s.innerHTML = '%s';\n", $id, $quota));

exit;
?>