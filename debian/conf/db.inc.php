<?php

/*
 +-----------------------------------------------------------------------+
 | Configuration file for database access                                |
 |                                                                       |
 | This file is part of the RoundCube Webmail client                     |
 | Copyright (C) 2005, RoundCube Dev. - Switzerland                      |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 +-----------------------------------------------------------------------+

*/

$rcmail_config = array();

/* Do not set db_dsnw here, use dpkg-reconfigure roundcube to configure database ! */

include_once("/etc/roundcube/debian-db.php");

switch ($dbtype) {
 case "sqlite":
   $rcmail_config['db_dsnw'] = "sqlite:///$basepath/$dbname?mode=0640";
   break;
 default:
   if ($dbport != '') $dbport=":$dbport";
   if ($dbserver == '') $dbserver="localhost";
   $rcmail_config['db_dsnw'] = "$dbtype://$dbuser:$dbpass@$dbserver$dbport/$dbname";
   break;
 }

// PEAR database DSN for read only operations (if empty write database will be used)
// useful for database replication
$rcmail_config['db_dsnr'] = '';

// database backend to use (only db or mdb2 are supported)
$rcmail_config['db_backend'] = 'db';

// maximum length of a query in bytes
$rcmail_config['db_max_length'] = 512000;  // 500K

// use persistent db-connections
$rcmail_config['db_persistent'] = TRUE;


// you can define specific table names used to store webmail data
$rcmail_config['db_table_users'] = 'users';

$rcmail_config['db_table_identities'] = 'identities';

$rcmail_config['db_table_contacts'] = 'contacts';

$rcmail_config['db_table_session'] = 'session';

$rcmail_config['db_table_cache'] = 'cache';

$rcmail_config['db_table_messages'] = 'messages';


// you can define specific sequence names used in PostgreSQL
$rcmail_config['db_sequence_users'] = 'user_ids';

$rcmail_config['db_sequence_identities'] = 'identity_ids';

$rcmail_config['db_sequence_contacts'] = 'contact_ids';

$rcmail_config['db_sequence_cache'] = 'cache_ids';

$rcmail_config['db_sequence_messages'] = 'message_ids';


// end db config file
?>
