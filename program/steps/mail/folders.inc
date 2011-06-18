<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/mail/folders.inc                                        |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Implement folder operations line EXPUNGE and Clear                  |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: folders.inc 1020 2008-02-05 22:56:29Z thomasb $
*/

$mbox_name = $IMAP->get_mailbox_name();

// send EXPUNGE command
if ($_action=='expunge' && ($mbox = get_input_value('_mbox', RCUBE_INPUT_POST)))
{
  $success = $IMAP->expunge($mbox);

  // reload message list if current mailbox  
  if ($success && !empty($_REQUEST['_reload']))
  {
    $OUTPUT->command('message_list.clear');
    $_action = 'list';
    return;
  }
  else
    $commands = "// expunged: $success\n";
}

// clear mailbox
else if ($_action=='purge' && ($mbox = get_input_value('_mbox', RCUBE_INPUT_POST)))
{
  // we should only be purging trash and junk
  if($mbox == $CONFIG['trash_mbox'] || $mbox == $CONFIG['junk_mbox']) 
  {
    $success = $IMAP->clear_mailbox($mbox);
  
    if ($success && !empty($_REQUEST['_reload']))
    {
      $OUTPUT->set_env('messagecount', 0);
      $OUTPUT->set_env('pagecount', 0);
      $OUTPUT->command('message_list.clear');
      $OUTPUT->command('set_rowcount', rcmail_get_messagecount_text());
      $OUTPUT->command('set_unread_count', $mbox_name, 0);
    }
    else
      $commands = "// purged: $success";
  }
}

$OUTPUT->send($commands);
?>