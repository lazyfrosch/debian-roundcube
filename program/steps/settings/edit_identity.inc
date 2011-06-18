<?php

/*
 +-----------------------------------------------------------------------+
 | program/steps/settings/edit_identity.inc                              |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005-2007, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 | PURPOSE:                                                              |
 |   Show edit form for a identity record or to add a new one            |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Thomas Bruederli <roundcube@gmail.com>                        |
 +-----------------------------------------------------------------------+

 $Id: edit_identity.inc 940 2007-12-11 04:20:01Z estadtherr $

*/

if (($_GET['_iid'] || $_POST['_iid']) && $_action=='edit-identity')
  {
  $IDENTITY_RECORD = $USER->get_identity(get_input_value('_iid', RCUBE_INPUT_GPC));
  
  if (is_array($IDENTITY_RECORD))
    $OUTPUT->set_env('iid', $IDENTITY_RECORD['identity_id']);

  $OUTPUT->set_pagetitle(rcube_label('edititem'));
  }
else
  $OUTPUT->set_pagetitle(rcube_label('newitem'));


$OUTPUT->include_script('list.js');


function rcube_identity_form($attrib)
  {
  global $IDENTITY_RECORD, $OUTPUT;

  $OUTPUT->include_script('tiny_mce/tiny_mce_src.js');
  $OUTPUT->add_script("tinyMCE.init({ mode : 'specific_textareas'," .
                                    "apply_source_formatting : true," .
                                    "content_css : '\$__skin_path' + '/editor_content.css'," .
                                    "editor_css : '\$__skin_path' + '/editor_ui.css'," .
                                    "theme : 'advanced'," .
                                    "theme_advanced_toolbar_location : 'top'," .
                                    "theme_advanced_toolbar_align : 'left'," .
                                    "theme_advanced_buttons1 : 'bold,italic,underline,strikethrough,justifyleft,justifycenter,justifyright,justifyfull,separator,outdent,indent,charmap,hr'," .
                                    "theme_advanced_buttons2 : 'link,unlink,code,forecolor,fontselect,fontsizeselect'," .
                                    "theme_advanced_buttons3 : '' });");

  if (!$IDENTITY_RECORD && $GLOBALS['_action']!='add-identity')
    return rcube_label('notfound');

  // add some labels to client
  rcube_add_label('noemailwarning', 'nonamewarning');


  list($form_start, $form_end) = get_form_tags($attrib, 'save-identity', array('name' => '_iid', 'value' => $IDENTITY_RECORD['identity_id']));
  unset($attrib['form']);


  // list of available cols
  $a_show_cols = array('name'         => array('type' => 'text'),
                       'email'        => array('type' => 'text'),
                       'organization' => array('type' => 'text'),
                       'reply-to'     => array('type' => 'text', 'label' => 'replyto'),
                       'bcc'          => array('type' => 'text'),
                       'signature'	  => array('type' => 'textarea', 'size' => "40", 'rows' => "6"),
                       'html_signature'=>array('type' => 'checkbox', 'label' => 'htmlsignature', 'onclick' => 'return rcmail.toggle_editor(this, \'_signature\');'),
                       'standard'     => array('type' => 'checkbox', 'label' => 'setdefault'));


  // a specific part is requested
  if ($attrib['part'])
    {
    $colprop = $a_show_cols[$attrib['part']];
    if (is_array($colprop))
      {
      $out = $form_start;
      $out .= rcmail_get_edit_field($attrib['part'], $IDENTITY_RECORD[$attrib['part']], $attrib, $colprop['type']); 
      return $out;
      }
    else
      return '';
    }


  // return the complete edit form as table
  $out = "$form_start<table>\n\n";

  foreach ($a_show_cols as $col => $colprop)
    {
    $attrib['id'] = 'rcmfd_'.$col;

    if (strlen($colprop['onclick']))
      $attrib['onclick'] = $colprop['onclick'];
    else
      unset($attrib['onclick']);

    if ($col == 'signature')
      {
      $attrib['size'] = $colprop['size'];
      $attrib['rows'] = $colprop['rows'];
      $attrib['mce_editable'] = $IDENTITY_RECORD['html_signature'] ? "true" : "false";
      }
    else
      {
      unset($attrib['size']);
      unset($attrib['rows']);
      unset($attrib['mce_editable']);
      }

    $label = strlen($colprop['label']) ? $colprop['label'] : $col;
    $value = rcmail_get_edit_field($col, $IDENTITY_RECORD[$col], $attrib, $colprop['type']);

    $out .= sprintf("<tr><td class=\"title\"><label for=\"%s\">%s</label></td><td>%s</td></tr>\n",
                    $attrib['id'],
                    Q(rcube_label($label)),
                    $value);
    }

  $out .= "\n</table>$form_end";

  return $out;  
  }

$OUTPUT->add_handler('identityform', 'rcube_identity_form');

if ($_action=='add-identity' && template_exists('addidentity'))
  parse_template('addidentity');

parse_template('editidentity');
?>