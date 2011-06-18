<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/settings/func.inc                                       |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Provide functionality for user's settings & preferences             |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: func.inc 1255 2008-04-05 12:49:21Z thomasb $

*/


if ($USER->ID)
  $OUTPUT->set_pagetitle(rcube_label('settingsfor') . " ". $USER->get_username());



function rcmail_user_prefs_form($attrib)
  {
  global $DB, $CONFIG, $sess_user_lang;

  $no_override = is_array($CONFIG['dont_override']) ? array_flip($CONFIG['dont_override']) : array();

  // add some labels to client
  rcube_add_label('nopagesizewarning');
  
  list($form_start, $form_end) = get_form_tags($attrib, 'save-prefs');
  unset($attrib['form']);

  // allow the following attributes to be added to the <table> tag
  $attrib_str = create_attrib_string($attrib, array('style', 'class', 'id', 'cellpadding', 'cellspacing', 'border', 'summary'));

  // return the complete edit form as table
  $out = "$form_start<table" . $attrib_str . ">\n\n";

  // show language selection
  if (!isset($no_override['language']))
    {
    $a_lang = rcube_list_languages();
    asort($a_lang);
  
    $field_id = 'rcmfd_lang';
    $select_lang = new select(array('name' => '_language', 'id' => $field_id));
    $select_lang->add(array_values($a_lang), array_keys($a_lang));
  
    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('language')),
                    $select_lang->show($sess_user_lang));
    }


  // show page size selection
  if (!isset($no_override['timezone']))
    {
    $field_id = 'rcmfd_timezone';
    $select_timezone = new select(array('name' => '_timezone', 'id' => $field_id));
    $select_timezone->add('(GMT -11:00) Midway Island, Samoa', '-11');
    $select_timezone->add('(GMT -10:00) Hawaii', '-10');
    $select_timezone->add('(GMT -9:30) Marquesas Islands', '-9.5');
    $select_timezone->add('(GMT -9:00) Alaska', '-9');
    $select_timezone->add('(GMT -8:00) Pacific Time (US/Canada)', '-8');
    $select_timezone->add('(GMT -7:00) Mountain Time (US/Canada)', '-7');
    $select_timezone->add('(GMT -6:00) Central Time (US/Canada), Mexico City', '-6');
    $select_timezone->add('(GMT -5:00) Eastern Time (US/Canada), Bogota, Lima', '-5');
    $select_timezone->add('(GMT -4:30) Caracas', '-4.5');
    $select_timezone->add('(GMT -4:00) Atlantic Time (Canada), La Paz', '-4');
    $select_timezone->add('(GMT -3:30) Nfld Time (Canada), Nfld, S. Labador', '-3.5');
    $select_timezone->add('(GMT -3:00) Brazil, Buenos Aires, Georgetown', '-3');
    $select_timezone->add('(GMT -2:00) Mid-Atlantic', '-2');
    $select_timezone->add('(GMT -1:00) Azores, Cape Verde Islands', '-1');
    $select_timezone->add('(GMT) Western Europe, London, Lisbon, Casablanca', '0');
    $select_timezone->add('(GMT +1:00) Central European Time', '1');
    $select_timezone->add('(GMT +2:00) EET: Kaliningrad, South Africa', '2');
    $select_timezone->add('(GMT +3:00) Baghdad, Kuwait, Riyadh, Moscow, Nairobi', '3');
    $select_timezone->add('(GMT +3:30) Tehran', '3.5');
    $select_timezone->add('(GMT +4:00) Abu Dhabi, Muscat, Baku, Tbilisi', '4');
    $select_timezone->add('(GMT +4:30) Kabul', '4.5');
    $select_timezone->add('(GMT +5:00) Ekaterinburg, Islamabad, Karachi', '5');
    $select_timezone->add('(GMT +5:30) Chennai, Kolkata, Mumbai, New Delhi', '5.5');
    $select_timezone->add('(GMT +5:45) Kathmandu', '5.75');
    $select_timezone->add('(GMT +6:00) Almaty, Dhaka, Colombo', '6');
    $select_timezone->add('(GMT +6:30) Cocos Islands, Myanmar', '6.5');
    $select_timezone->add('(GMT +7:00) Bangkok, Hanoi, Jakarta', '7');
    $select_timezone->add('(GMT +8:00) Beijing, Perth, Singapore, Taipei', '8');
    $select_timezone->add('(GMT +8:45) Caiguna, Eucla, Border Village', '8.75');
    $select_timezone->add('(GMT +9:00) Tokyo, Seoul, Yakutsk', '9');
    $select_timezone->add('(GMT +9:30) Adelaide, Darwin', '9.5');
    $select_timezone->add('(GMT +10:00) EAST/AEST: Sydney, Guam, Vladivostok', '10');
    $select_timezone->add('(GMT +10:30) New South Wales', '10.5');
    $select_timezone->add('(GMT +11:00) Magadan, Solomon Islands', '11');
    $select_timezone->add('(GMT +11:30) Norfolk Island', '11.5');
    $select_timezone->add('(GMT +12:00) Auckland, Wellington, Kamchatka', '12');
    $select_timezone->add('(GMT +12:45) Chatham Islands', '12.75');
    $select_timezone->add('(GMT +13:00) Tonga, Pheonix Islands', '13');
    $select_timezone->add('(GMT +14:00) Kiribati', '14');
  
  
    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('timezone')),
                    $select_timezone->show((string)$CONFIG['timezone']));
    }

  // daylight savings
  if (!isset($no_override['dst_active']))
    {
    $field_id = 'rcmfd_dst';
    $input_dst = new checkbox(array('name' => '_dst_active', 'id' => $field_id, 'value' => 1));
    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('dstactive')),
                    $input_dst->show($CONFIG['dst_active']));
    }

  // show page size selection
  if (!isset($no_override['pagesize']))
    {
    $field_id = 'rcmfd_pgsize';
    $input_pagesize = new textfield(array('name' => '_pagesize', 'id' => $field_id, 'size' => 5));

    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('pagesize')),
                    $input_pagesize->show($CONFIG['pagesize']));
    }

  // MM: Show checkbox for toggling 'pretty dates' 
  if (!isset($no_override['prettydate']))
    {
    $field_id = 'rcmfd_prettydate';
    $input_prettydate = new checkbox(array('name' => '_pretty_date', 'id' => $field_id, 'value' => 1));

    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('prettydate')),
                    $input_prettydate->show($CONFIG['prettydate']?1:0));
    }

  // show checkbox for HTML/plaintext messages
  if (!isset($no_override['prefer_html']))
    {
    $field_id = 'rcmfd_htmlmsg';
    $input_pagesize = new checkbox(array('name' => '_prefer_html', 'id' => $field_id, 'value' => 1));

    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('preferhtml')),
                    $input_pagesize->show($CONFIG['prefer_html']?1:0));
    }

  // Show checkbox for HTML Editor
  if (!isset($no_override['htmleditor']))
    {
    $field_id = 'rcmfd_htmleditor';
    $input_htmleditor = new checkbox(array('name' => '_htmleditor', 'id' => $field_id, 'value' => 1));
    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('htmleditor')),
                    $input_htmleditor->show($CONFIG['htmleditor']?1:0));
    }

  // show config parameter for preview pane
  if (!isset($no_override['preview_pane']))
    {
    $field_id = 'rcmfd_preview';
    $input_preview = new checkbox(array('name' => '_preview_pane', 'id' => $field_id, 'value' => 1));
    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('previewpane')),
                    $input_preview->show($CONFIG['preview_pane']?1:0));
    }
                  
  if (!empty($CONFIG['drafts_mbox']) && !isset($no_override['draft_autosave']))
    {
    $field_id = 'rcmfd_autosave';
    $select_autosave = new select(array('name' => '_draft_autosave', 'id' => $field_id));
    $select_autosave->add(rcube_label('never'), 0);
    foreach (array(3, 5, 10) as $i => $min)
      $select_autosave->add(rcube_label(array('name' => 'everynminutes', 'vars' => array('n' => $min))), $min*60);

    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $field_id,
                    Q(rcube_label('autosavedraft')),
                    $select_autosave->show($CONFIG['draft_autosave']));
    }

  $out .= "\n</table>$form_end";

  return $out;  
  }



function rcmail_identities_list($attrib)
  {
  global $OUTPUT, $USER;

  // add id to message list table if not specified
  if (!strlen($attrib['id']))
    $attrib['id'] = 'rcmIdentitiesList';

  // define list of cols to be displayed
  $a_show_cols = array('name', 'email', 'organization', 'reply-to');

  // create XHTML table  
  $out = rcube_table_output($attrib, $USER->list_identities(), $a_show_cols, 'identity_id');
  
  // set client env
  $OUTPUT->add_gui_object('identitieslist', $attrib['id']);

  return $out;
  }



// similar function as in /steps/addressbook/edit.inc
function get_form_tags($attrib, $action, $add_hidden=array())
  {
  global $OUTPUT, $EDIT_FORM, $SESS_HIDDEN_FIELD;  

  $form_start = '';
  if (!strlen($EDIT_FORM))
    {
    $hiddenfields = new hiddenfield(array('name' => '_task', 'value' => $GLOBALS['_task']));
    $hiddenfields->add(array('name' => '_action', 'value' => $action));
    
    if ($add_hidden)
      $hiddenfields->add($add_hidden);
    
    if ($_GET['_framed'] || $_POST['_framed'])
      $hiddenfields->add(array('name' => '_framed', 'value' => 1));
    
    $form_start = !strlen($attrib['form']) ? '<form name="form" action="./" method="post">' : '';
    $form_start .= "\n$SESS_HIDDEN_FIELD\n";
    $form_start .= $hiddenfields->show();
    }
    
  $form_end = (!strlen($EDIT_FORM) && !strlen($attrib['form'])) ? '</form>' : '';
  $form_name = strlen($attrib['form']) ? $attrib['form'] : 'form';

  if (!strlen($EDIT_FORM))
    $OUTPUT->add_gui_object('editform', $form_name);
  
  $EDIT_FORM = $form_name;

  return array($form_start, $form_end);  
  }


// register UI objects
$OUTPUT->add_handlers(array(
  'userprefs' => 'rcmail_user_prefs_form',
  'identitieslist' => 'rcmail_identities_list',
  'itentitieslist' => 'rcmail_identities_list'  // keep this for backward compatibility
));


?>