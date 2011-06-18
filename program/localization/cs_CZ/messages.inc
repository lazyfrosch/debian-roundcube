<?php

/*

+-----------------------------------------------------------------------+
| language/cs_CZ/messages.inc                                              |
|                                                                       |
| Language file of the RoundCube Webmail client                         |
| Copyright (C) 2005-2008, RoundCube Dev. - Switzerland                 |
| Licensed under the GNU GPL                                            |
|                                                                       |
+-----------------------------------------------------------------------+
| Author: Martin Mrajca <martin@moonlake.cz>                            |
|        joe <joe@humlak.cz>                                            |
|        Jiri Kaderavek <jiri.kaderavek@webstep.net>                    |
+-----------------------------------------------------------------------+

@version $Id: messages.inc 2045 2008-11-11 15:09:24Z yllar $

*/

$messages = array();
$messages['loginfailed'] = 'Přihlášení selhalo';
$messages['cookiesdisabled'] = 'Váš prohlížeč nepodporuje cookies, které jsou pro přihlášení nezbytné';
$messages['sessionerror'] = 'Vaše přihlášení je neplatné nebo vypršelo';
$messages['imaperror'] = 'Připojení na IMAP server selhalo';
$messages['nomessagesfound'] = 'Ve schránce nebyla nalezena žádná zpráva';
$messages['loggedout'] = 'Byli jste úspěšně odhlášeni. Nashledanou!';
$messages['mailboxempty'] = 'Schránka je prázdná';
$messages['loading'] = 'Načítám...';
$messages['loadingdata'] = 'Načítám data...';
$messages['checkingmail'] = 'Kontroluji nové zprávy...';
$messages['sendingmessage'] = 'Odesílám zprávu...';
$messages['messagesent'] = 'Zpráva byla odeslána';
$messages['savingmessage'] = 'Ukládám zprávu...';
$messages['messagesaved'] = 'Zpráva uložena do Rozepsané';
$messages['successfullysaved'] = 'Uloženo';
$messages['addedsuccessfully'] = 'Kontakt byl úspěšně přidán do adresáře';
$messages['contactexists'] = 'Kontakt se zadanou e-mailovou adresou již existuje';
$messages['blockedimages'] = 'Z bezpečnostních důvodů byly zablokovány obrázky ve zprávě.';
$messages['encryptedmessage'] = 'Tato zpráva je zašifrovaná a nelze ji zobrazit.';
$messages['nocontactsfound'] = 'Nemáte žádné kontakty';
$messages['contactnotfound'] = 'Požadovaný kontakt nebyl nalezen.';
$messages['sendingfailed'] = 'Odesílání zprávy selhalo';
$messages['senttooquickly'] = 'Prosím počkejte $sec sekund před odesláním zprávy';
$messages['errorsavingsent'] = 'Nastala chyba při ukládání odeslané zprávy';
$messages['errorsaving'] = 'Vyskytla se chyba při ukládání';
$messages['errormoving'] = 'Nemohu přesunout zprávu';
$messages['errordeleting'] = 'Nemohu smazat zprávu';
$messages['deletecontactconfirm'] = 'Opravdu chcete smazat označené kontakty?';
$messages['deletemessagesconfirm'] = 'Opravdu chcete smazat označené zprávy?';
$messages['deletefolderconfirm'] = 'Chcete opravdu smazat tento adresář?';
$messages['purgefolderconfirm'] = 'Opravdu chcete smazat všechny zprávy v této složce?';
$messages['foldercreating'] = 'Vytvářím složku...';
$messages['folderdeleting'] = 'Mažu složku...';
$messages['folderrenaming'] = 'Přejmenovávám složku...';
$messages['formincomplete'] = 'Formulář nebyl korektně vyplněn';
$messages['noemailwarning'] = 'Zadejte, prosím, platnou adresu';
$messages['nonamewarning'] = 'Zadejte, prosím, jméno';
$messages['nopagesizewarning'] = 'Zadejte, prosím, velikost stránky';
$messages['norecipientwarning'] = 'Zadejte, prosím, alespoň jednoho příjemce';
$messages['nosubjectwarning'] = 'Předmět nebyl vyplňen. Přejete si jej zadat nyní?';
$messages['nobodywarning'] = 'Opravdu chtete odeslat prázdnou zprávu?';
$messages['notsentwarning'] = 'Zpráva nebyla odeslána. Přejete si zprávu zahodit?';
$messages['noldapserver'] = 'Zvolte, prosím, LDAP server k hledání';
$messages['nocontactsreturned'] = 'Nebyly nalezeny žádné kontakty';
$messages['nosearchname'] = 'Zadejte, prosím, jméno nebo e-mail kontaktu';
$messages['searchsuccessful'] = '$nr zpráv nalezeno';
$messages['searchnomatch'] = 'Nenalezena žádná zpráva';
$messages['searching'] = 'Vyhledávám...';
$messages['checking'] = 'Kontroluji...';
$messages['nospellerrors'] = 'Nebyly nalezeny žádné chyby';
$messages['folderdeleted'] = 'Složka byla úspěšně vymazána';
$messages['deletedsuccessfully'] = 'Úspěšně smazáno';
$messages['converting'] = 'Odstranuji formátování ze zprávy...';
$messages['messageopenerror'] = 'Nemohu načíst zprávu ze serveru';
$messages['fileuploaderror'] = 'Nahrávání souboru selhalo';
$messages['filesizeerror'] = 'Soubor přesáhl maximální velikost $size';
$messages['copysuccess'] = 'Úspěšně zkopírováno $nr adres';
$messages['copyerror'] = 'Nemohu zkopírovat žádnou adresu';
$messages['sourceisreadonly'] = 'Tento zdroj adres je pouze pro čtení';
$messages['errorsavingcontact'] = 'Nemohu uložit adresu kontaktu';
$messages['movingmessage'] = 'Přesouvám zprávu...';
$messages['receiptsent'] = 'Potvrzení o přřijetí zprávy odesláno';
$messages['errorsendingreceipt'] = 'Potvrzení o přijetí zprávy nebylo možné odeslat';
$messages['nodeletelastidentity'] = 'Alespoň jedna identita musí být ponechána. Identitu nelze odstranit.';
$messages['addsubfolderhint'] = 'Tato složka bude vytvořena jako podsložka aktuálně zvolené složky';
$messages['forbiddencharacter'] = 'Název složky obsahuje zakázaný znak';
$messages['selectimportfile'] = 'Prosím vyberte soubor k nahrání';
$messages['addresswriterror'] = 'Vybraný seznam kontaktů není zapisovatelný';
$messages['importwait'] = 'Importuji, prosím čekejte...';
$messages['importerror'] = 'Během importu nastala chyba! Nahraný soubor není ve formátu vCard.';
$messages['importconfirm'] = '<b>Úspěšně naimportováno $inserted kontaktů, $skipped existujících záznamů přeskočeno</b>:<p><em>$names</em></p>';
$messages['opnotpermitted'] = 'Operace není povolena!';

?>