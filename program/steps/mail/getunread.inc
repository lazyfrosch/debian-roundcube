<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/mail/getunread.inc                                      |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Check all mailboxes for unread messages and update GUI              |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: getunread.inc 1019 2008-02-05 21:39:08Z thomasb $

*/

$a_folders = $IMAP->list_mailboxes();

if (!empty($a_folders))
{
  foreach ($a_folders as $mbox_row)
    $OUTPUT->command('set_unread_count', $mbox_row, $IMAP->messagecount($mbox_row, 'UNSEEN'), ($IMAP->get_mailbox_name() == 'INBOX' && $mbox_row == 'INBOX'));
}

$OUTPUT->send();
?>