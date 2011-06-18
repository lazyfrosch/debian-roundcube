<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/mail/show.inc                                           |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2008, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Display a mail message similar as a usual mail application does     |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: show.inc 1255 2008-04-05 12:49:21Z thomasb $

*/

require_once('Mail/mimeDecode.php');
require_once('lib/rc_mail_mime.inc');

$PRINT_MODE = $_action=='print' ? TRUE : FALSE;

// similar code as in program/steps/mail/get.inc
if ($_GET['_uid'])
  {
  $MESSAGE = array('UID' => get_input_value('_uid', RCUBE_INPUT_GET));
  $MESSAGE['headers'] = $IMAP->get_headers($MESSAGE['UID']);
  
  // set message charset as default
  if (!empty($MESSAGE['headers']->charset))
    $IMAP->set_charset($MESSAGE['headers']->charset);
  
  // go back to list if message not found (wrong UID)
  if (!$MESSAGE['headers'])
    {
    $OUTPUT->show_message('messageopenerror', 'error');
    if ($_action=='preview' && template_exists('messagepreview'))
        parse_template('messagepreview');
    else
      {
      $_action = 'list';
      return;
      }
    }
    
  // check if safe flag is set
  if ($MESSAGE['is_safe'] = intval($_GET['_safe']))
    $_SESSION['safe_messages'][$MESSAGE['UID']] = true;
  else if ($_SESSION['safe_messages'][$MESSAGE['UID']])
    $MESSAGE['is_safe'] = 1;

  // calculate Etag for this request
  $etag = md5($MESSAGE['UID'].$IMAP->get_mailbox_name().session_id().intval($MESSAGE['headers']->mdn_sent).intval($MESSAGE['is_safe']).intval($PRINT_MODE));

  // allow caching, unless remote images are present
  if ((bool)$MESSAGE['is_safe'])
    send_nocacheing_headers();
  else if (empty($CONFIG['devel_mode']))
    send_modified_header($_SESSION['login_time'], $etag);

  $MESSAGE['subject'] = rcube_imap::decode_mime_string($MESSAGE['headers']->subject, $MESSAGE['headers']->charset);
  $OUTPUT->set_pagetitle($MESSAGE['subject']);
  
  if ($MESSAGE['structure'] = $IMAP->get_structure($MESSAGE['UID']))
    list($MESSAGE['parts'], $MESSAGE['attachments']) = rcmail_parse_message(
      $MESSAGE['structure'],
      array('safe' => $MESSAGE['is_safe'],
            'prefer_html' => $CONFIG['prefer_html'],
            'get_url' => $GET_URL.'&_part=%s')
      );
  else
    $MESSAGE['body'] = $IMAP->get_body($MESSAGE['UID']);


  // mark message as read
  if (!$MESSAGE['headers']->seen && $_action != 'preview')
    $IMAP->set_flag($MESSAGE['UID'], 'SEEN');

  // give message uid to the client
  $OUTPUT->set_env('uid', $MESSAGE['UID']);
  $OUTPUT->set_env('safemode', $MESSAGE['is_safe']);
  
  // check for unset disposition notification
  if ($MESSAGE['headers']->mdn_to && !$MESSAGE['headers']->mdn_sent && $IMAP->get_mailbox_name() != $CONFIG['drafts_mbox'])
  {
    if (intval($CONFIG['mdn_requests']) === 1)
    {
      if (rcmail_send_mdn($MESSAGE['UID']))
        $OUTPUT->show_message('receiptsent', 'confirmation');
    }
    else if (empty($CONFIG['mdn_requests']))
    {
      rcube_add_label('mdnrequest');
      $OUTPUT->set_env('mdn_request', true);
    }
  }


  $next = $prev = $first = $last = -1;
  // get previous, first, next and last message UID
  if ((!($_SESSION['sort_col'] == 'date' && $_SESSION['sort_order'] == 'DESC') &&
      $IMAP->get_capability('sort')) || !empty($_REQUEST['_search']))
    {
    // Only if we use custom sorting
    $a_msg_index = $IMAP->message_index(NULL, $_SESSION['sort_col'], $_SESSION['sort_order']);
 
    $MESSAGE['index'] = array_search((string)$MESSAGE['UID'], $a_msg_index, TRUE);
    $prev = isset($a_msg_index[$MESSAGE['index']-1]) ? $a_msg_index[$MESSAGE['index']-1] : -1 ;
    $first = count($a_msg_index)>0 ? $a_msg_index[0] : -1;
    $next = isset($a_msg_index[$MESSAGE['index']+1]) ? $a_msg_index[$MESSAGE['index']+1] : -1 ;
    $last = count($a_msg_index)>0 ? $a_msg_index[count($a_msg_index)-1] : -1;
    }
  else
    {
    // this assumes that we are sorted by date_DESC
    $seq = $IMAP->get_id($MESSAGE['UID']);
    $prev = $IMAP->get_uid($seq + 1);
    $first = $IMAP->get_uid($IMAP->messagecount());
    $next = $IMAP->get_uid($seq - 1);
    $last = $IMAP->get_uid(1);
    $MESSAGE['index'] = $IMAP->messagecount() - $seq;
    }
  
  if ($prev > 0)
    $OUTPUT->set_env('prev_uid', $prev);
  if ($first >0)
    $OUTPUT->set_env('first_uid', $first);
  if ($next > 0)
    $OUTPUT->set_env('next_uid', $next);
  if ($last >0)
    $OUTPUT->set_env('last_uid', $last);
  }



function rcmail_message_attachments($attrib)
  {
  global $CONFIG, $OUTPUT, $PRINT_MODE, $MESSAGE, $GET_URL;

  if (sizeof($MESSAGE['attachments']))
    {
    // allow the following attributes to be added to the <ul> tag
    $attrib_str = create_attrib_string($attrib, array('style', 'class', 'id'));
    $out = '<ul' . $attrib_str . ">\n";

    foreach ($MESSAGE['attachments'] as $attach_prop)
      {
      if ($PRINT_MODE)
        $out .= sprintf('<li>%s (%s)</li>'."\n",
                        $attach_prop->filename,
                        show_bytes($attach_prop->size));
      else
        $out .= sprintf('<li><a href="%s&amp;_part=%s" onclick="return %s.command(\'load-attachment\',{part:\'%s\', mimetype:\'%s\'},this)">%s</a></li>'."\n",
                        htmlspecialchars($GET_URL),
                        $attach_prop->mime_id,
                        JS_OBJECT_NAME,
                        $attach_prop->mime_id,
                        $attach_prop->mimetype,
                        $attach_prop->filename);
      }

    $out .= "</ul>";
    return $out;
    }  
  }



function rcmail_remote_objects_msg($attrib)
  {
  global $CONFIG, $OUTPUT;
  
  if (!$attrib['id'])
    $attrib['id'] = 'rcmremoteobjmsg';

  // allow the following attributes to be added to the <div> tag
  $attrib_str = create_attrib_string($attrib, array('style', 'class', 'id'));
  $out = '<div' . $attrib_str . ">";
  
  $out .= sprintf('%s&nbsp;<a href="#loadimages" onclick="%s.command(\'load-images\')">%s</a>',
                  Q(rcube_label('blockedimages')),
                  JS_OBJECT_NAME,
                  Q(rcube_label('showimages')));
  
  $out .= '</div>';
  
  $OUTPUT->add_gui_object('remoteobjectsmsg', $attrib['id']);
  return $out;
  }


$OUTPUT->add_handlers(array(
  'messageattachments' => 'rcmail_message_attachments',
  'blockedobjects' => 'rcmail_remote_objects_msg'));


if ($_action=='print' && template_exists('printmessage'))
  parse_template('printmessage');
else if ($_action=='preview' && template_exists('messagepreview'))
    parse_template('messagepreview');
else
  parse_template('message');
?>