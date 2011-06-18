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

 $Id: show.inc 2115 2008-12-04 10:21:34Z alec $

*/

$PRINT_MODE = $RCMAIL->action=='print' ? TRUE : FALSE;

// similar code as in program/steps/mail/get.inc
if ($_GET['_uid']) {
  $MESSAGE = new rcube_message(get_input_value('_uid', RCUBE_INPUT_GET));

  // set message charset as default
  if (!empty($MESSAGE->headers->charset))
    $IMAP->set_charset($MESSAGE->headers->charset);

  // go back to list if message not found (wrong UID)
  if (empty($MESSAGE->headers)) {
    $OUTPUT->show_message('messageopenerror', 'error');
    if ($RCMAIL->action=='preview' && $OUTPUT->template_exists('messagepreview'))
        $OUTPUT->send('messagepreview');
    else {
      rcmail_overwrite_action('');
      return;
    }
  }
    
  $mbox_name = $IMAP->get_mailbox_name();
  
  // show images?
  $show_images = $RCMAIL->config->get('show_images');
  if(!$MESSAGE->is_safe
	&& !empty($show_images)
	&& $MESSAGE->has_html_part())
  {
    switch($show_images) {
      case '1': // known senders only
        $CONTACTS = new rcube_contacts($DB, $_SESSION['user_id']);
	if ($CONTACTS->search('email', $MESSAGE->sender['mailto'], true, false)->count) {
          $MESSAGE->set_safe(true);
	  }
      break;
      case '2': // always
        $MESSAGE->set_safe(true);
      break;
    }
  }

  // calculate Etag for this request
  $etag = md5($MESSAGE->uid.$mbox_name.session_id()
    .intval($MESSAGE->headers->mdn_sent)
    .intval($MESSAGE->is_safe)
    .(!empty($MESSAGE->attachments) ? intval($CONFIG['inline_images']) : '')
    .intval($PRINT_MODE));

  // allow caching, unless remote images are present
  if ((bool)$MESSAGE->is_safe)
    send_nocacheing_headers();
  else if (empty($CONFIG['devel_mode']))
    send_modified_header($_SESSION['login_time'], $etag, !$MESSAGE->headers->seen);

  $OUTPUT->set_pagetitle($MESSAGE->subject);
  
  // give message uid to the client
  $OUTPUT->set_env('uid', $MESSAGE->uid);
  // set environement
  $OUTPUT->set_env('safemode', $MESSAGE->is_safe);
  $OUTPUT->set_env('sender', $MESSAGE->sender['string']);
  $OUTPUT->set_env('permaurl', rcmail_url('show', array('_uid' => $MESSAGE->uid, '_mbox' => $mbox_name)));
  $OUTPUT->set_env('mailbox', $mbox_name);
  if ($CONFIG['trash_mbox'])
    $OUTPUT->set_env('trash_mailbox', $CONFIG['trash_mbox']);
  if (!$OUTPUT->ajax_call)
    $OUTPUT->add_label('checkingmail', 'deletemessage', 'movemessagetotrash', 'movingmessage');
    
  // check for unset disposition notification
  if ($MESSAGE->headers->mdn_to &&
      !$MESSAGE->headers->mdn_sent && !$MESSAGE->headers->seen &&
      $IMAP->check_permflag('MDNSENT') &&
      $mbox_name != $CONFIG['drafts_mbox'] &&
      $mbox_name != $CONFIG['sent_mbox'])
  {
    if (intval($CONFIG['mdn_requests']) === 1)
    {
      if (rcmail_send_mdn($MESSAGE->uid))
        $OUTPUT->show_message('receiptsent', 'confirmation');
      else
        $OUTPUT->show_message('errorsendingreceipt', 'error');
    }
    else if (empty($CONFIG['mdn_requests']))
    {
      $OUTPUT->add_label('mdnrequest');
      $OUTPUT->set_env('mdn_request', true);
    }
  }

  // get previous, first, next and last message UID
  if ($RCMAIL->action != 'preview' && $RCMAIL->action != 'print')
    {
    $next = $prev = $first = $last = -1;

    if ((!($_SESSION['sort_col'] == 'date' && $_SESSION['sort_order'] == 'DESC') &&
      $IMAP->get_capability('sort')) || !empty($_REQUEST['_search']))
      {
      // Only if we use custom sorting
      $a_msg_index = $IMAP->message_index(NULL, $_SESSION['sort_col'], $_SESSION['sort_order']);

      $MESSAGE->index = array_search($IMAP->get_id($MESSAGE->uid), $a_msg_index);

      $prev = isset($a_msg_index[$MESSAGE->index-1]) ? $IMAP->get_uid($a_msg_index[$MESSAGE->index-1]) : -1 ;
      $first = count($a_msg_index)>0 ? $IMAP->get_uid($a_msg_index[0]) : -1;
      $next = isset($a_msg_index[$MESSAGE->index+1]) ? $IMAP->get_uid($a_msg_index[$MESSAGE->index+1]) : -1 ;
      $last = count($a_msg_index)>0 ? $IMAP->get_uid($a_msg_index[count($a_msg_index)-1]) : -1;
      }
    else
      {
      // this assumes that we are sorted by date_DESC
      $cnt = $IMAP->messagecount();
      $seq = $IMAP->get_id($MESSAGE->uid);
      $MESSAGE->index = $cnt - $seq;

      $prev = $IMAP->get_uid($seq + 1);
      $first = $IMAP->get_uid($cnt);
      $next = $IMAP->get_uid($seq - 1);
      $last = $IMAP->get_uid(1);
      }

    if ($prev > 0)
      $OUTPUT->set_env('prev_uid', $prev);
    if ($first > 0)
      $OUTPUT->set_env('first_uid', $first);
    if ($next > 0)
      $OUTPUT->set_env('next_uid', $next);
    if ($last > 0)
      $OUTPUT->set_env('last_uid', $last);
    }

  // mark message as read
  if (!$MESSAGE->headers->seen)
    $IMAP->set_flag($MESSAGE->uid, 'SEEN');
  }



function rcmail_message_attachments($attrib)
{
  global $PRINT_MODE, $MESSAGE;
  
  $out = $ol = '';

  if (sizeof($MESSAGE->attachments)) {
    foreach ($MESSAGE->attachments as $attach_prop) {
      if ($PRINT_MODE) {
        $ol .= html::tag('li', null, sprintf("%s (%s)", Q($attach_prop->filename), Q(show_bytes($attach_prop->size))));
      }
      else {
        if (rc_strlen($attach_prop->filename) > 50) {
          $filename = abbreviate_string($attach_prop->filename, 50);
          $title = $attach_prop->filename;
      }
      else {
        $filename = $attach_prop->filename;
        $title = '';
      }

        $ol .= html::tag('li', null,
          html::a(array(
            'href' => $MESSAGE->get_part_url($attach_prop->mime_id),
            'onclick' => sprintf(
              'return %s.command(\'load-attachment\',{part:\'%s\', mimetype:\'%s\'},this)',
              JS_OBJECT_NAME,
              $attach_prop->mime_id,
              $attach_prop->mimetype),
              'title' => Q($title),
            ),
            Q($filename)));
      }
    }

    $out = html::tag('ul', $attrib, $ol, html::$common_attrib);
  } 
  
  return $out;
}



function rcmail_remote_objects_msg($attrib)
{
  global $MESSAGE, $RCMAIL;
  
  if (!$attrib['id'])
    $attrib['id'] = 'rcmremoteobjmsg';
  
  $msg = Q(rcube_label('blockedimages')) . '&nbsp;';
  $msg .= html::a(array('href' => "#loadimages", 'onclick' => JS_OBJECT_NAME.".command('load-images')"), Q(rcube_label('showimages')));
  
  // add link to save sender in addressbook and reload message
  if ($MESSAGE->sender['mailto'] && $RCMAIL->config->get('show_images') == 1) {
    $msg .= ' ' . html::a(array('href' => "#alwaysload", 'onclick' => JS_OBJECT_NAME.".command('always-load')", 'style' => "white-space:nowrap"),
      Q(rcube_label(array('name' => 'alwaysshow', 'vars' => array('sender' => $MESSAGE->sender['mailto'])))));
  }
  
  $RCMAIL->output->add_gui_object('remoteobjectsmsg', $attrib['id']);
  return html::div($attrib, $msg);
}


$OUTPUT->add_handlers(array(
  'messageattachments' => 'rcmail_message_attachments',
  'mailboxname' => 'rcmail_mailbox_name_display',
  'blockedobjects' => 'rcmail_remote_objects_msg'));


if ($RCMAIL->action=='print' && $OUTPUT->template_exists('printmessage'))
  $OUTPUT->send('printmessage');
else if ($RCMAIL->action=='preview' && $OUTPUT->template_exists('messagepreview'))
  $OUTPUT->send('messagepreview');
else
  $OUTPUT->send('message');
?>