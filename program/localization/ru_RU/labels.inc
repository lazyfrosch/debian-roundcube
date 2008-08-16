<?php

/*

 +-----------------------------------------------------------------------+
 | language/ru_RU/labels.inc                                             |
 |                                                                       |
 | Language file of the RoundCube Webmail client                         |
 | Copyright (C) 2005-2008, RoundCube Dev. - Switzerland                 |
 | Licensed under the GNU GPL                                            |
 |                                                                       |
 +-----------------------------------------------------------------------+
 | Author: Maxim Zenin <maxx@webmechanics.ru>                            |
 |         Vladimir Kulev <me@lightoze.net>                              |
 |         Artur Smolkin <admin@roundcube.ru>                            |
 +-----------------------------------------------------------------------+

 @version $Id: labels.inc 1429 2008-05-27 05:35:06Z alec $

*/

$labels = array();

// login page
$labels['welcome'] = 'Добро пожаловать в $product!';
$labels['username'] = 'Имя пользователя';
$labels['password'] = 'Пароль';
$labels['server'] = 'Сервер';
$labels['login'] = 'Войти';

// taskbar
$labels['logout'] = 'Выход';
$labels['mail'] = 'Почта';
$labels['settings'] = 'Настройки';
$labels['addressbook'] = 'Контакты';

// mailbox names
$labels['inbox'] = 'Входящие';
$labels['drafts'] = 'Черновики';
$labels['sent'] = 'Отправленные';
$labels['trash'] = 'Корзина';
$labels['junk'] = 'СПАМ';

// message listing
$labels['subject'] = 'Тема';
$labels['from'] = 'От';
$labels['to'] = 'Кому';
$labels['cc'] = 'Копия';
$labels['bcc'] = 'Скрытая';
$labels['replyto'] = 'Обратный адрес';
$labels['date'] = 'Дата';
$labels['size'] = 'Размер';
$labels['priority'] = 'Приоритет';
$labels['organization'] = 'Организация';

// aliases
$labels['reply-to'] = 'Обратный адрес';

$labels['mailboxlist'] = 'Папки';
$labels['messagesfromto'] = 'Сообщения с $from по $to из $count';
$labels['messagenrof'] = 'Сообщение $nr из $count';

$labels['moveto'] = 'Переместить в...';
$labels['download'] = 'Загрузить';

$labels['filename'] = 'Имя файла';
$labels['filesize'] = 'Размер файла';

$labels['preferhtml'] = 'Предпочитать HTML';
$labels['htmlmessage'] = 'Сообщение HTML';
$labels['prettydate'] = 'Красивые даты';

$labels['addtoaddressbook'] = 'Добавить в контакты';

// weekdays short
$labels['sun'] = 'Вс';
$labels['mon'] = 'Пн';
$labels['tue'] = 'Вт';
$labels['wed'] = 'Ср';
$labels['thu'] = 'Чт';
$labels['fri'] = 'Пт';
$labels['sat'] = 'Сб';

// weekdays long
$labels['sunday'] = 'Воскресенье';
$labels['monday'] = 'Понедельник';
$labels['tuesday'] = 'Вторник';
$labels['wednesday'] = 'Среда';
$labels['thursday'] = 'Четверг';
$labels['friday'] = 'Пятница';
$labels['saturday'] = 'Суббота';

// months short
$labels['jan']    = 'Янв';
$labels['feb']    = 'Фев';
$labels['mar']    = 'Мар';
$labels['apr']    = 'Апр';
$labels['may']    = 'Май';
$labels['jun']    = 'Июн';
$labels['jul']    = 'Июл';
$labels['aug']    = 'Авг';
$labels['sep']    = 'Сен';
$labels['oct']    = 'Окт';
$labels['nov']    = 'Ноя';
$labels['dec']    = 'Дек';

// months long
$labels['longjan']    = 'Январь';
$labels['longfeb']    = 'Февраль';
$labels['longmar']    = 'Март';
$labels['longapr']    = 'Апрель';
$labels['longmay']    = 'Май';
$labels['longjun']    = 'Июнь';
$labels['longjul']    = 'Июль';
$labels['longaug']    = 'Август';
$labels['longsep']    = 'Сентябрь';
$labels['longoct']    = 'Октябрь';
$labels['longnov']    = 'Ноябрь';
$labels['longdec']    = 'Декабрь';

$labels['today'] = 'Сегодня';

// toolbar buttons
$labels['checkmail'] = 'Доставить почту';
$labels['writenewmessage'] = 'Новое сообщение';
$labels['replytomessage'] = 'Ответить';
$labels['replytoallmessage'] = 'Ответить всем';
$labels['forwardmessage'] = 'Переслать';
$labels['deletemessage'] = 'В корзину';
$labels['movemessagetotrash'] = 'Переместить сообщение в корзину';
$labels['printmessage'] = 'Печать';
$labels['previousmessage'] = 'Показать предыдущее сообщение';
$labels['previousmessages'] = 'Предыдущее';
$labels['firstmessage'] = 'Показать первое сообщение';
$labels['firstmessages'] = 'Первое сообщение';
$labels['nextmessage'] = 'Показать следующее сообщение';
$labels['nextmessages'] = 'Следующее';
$labels['lastmessage'] = 'Показать последнее сообщение';
$labels['lastmessages'] = 'Последнее сообщение';
$labels['backtolist'] = 'К списку сообщений';
$labels['viewsource'] = 'Исходный текст';
$labels['markmessages'] = 'Отметить сообщение';
$labels['markread'] = 'как прочитанное';
$labels['markunread'] = 'как непрочитанное';

$labels['select'] = 'Выбрать';
$labels['all'] = 'Все';
$labels['none'] = 'Ничего';
$labels['unread'] = 'Непрочитанные';

$labels['compact'] = 'Сжать';
$labels['empty'] = 'Опустошить';
$labels['purge'] = 'Очистить';

$labels['quota'] = 'Квота';
$labels['unknown'] = 'неизвестно';
$labels['unlimited'] = 'без ограничений';

$labels['quicksearch'] = 'Быстрый поиск';
$labels['resetsearch'] = 'Сброс';


// message compose
$labels['compose'] = 'Написать сообщение';
$labels['savemessage'] = 'Сохранить черновик';
$labels['sendmessage'] = 'Отправить сейчас';
$labels['addattachment'] = 'Добавить вложение';
$labels['charset'] = 'Кодировка';
$labels['editortype'] = 'Редактор';
$labels['returnreceipt'] = 'Запрос ответа';

$labels['checkspelling'] = 'Проверить орфографию';
$labels['resumeediting'] = 'Продолжить редактирование';
$labels['revertto'] = 'Отменить правки';

$labels['attachments'] = 'Вложения';
$labels['upload'] = 'Загрузить';
$labels['close'] = 'Закрыть';

$labels['low'] = 'Низкий';
$labels['lowest'] = 'Нижайш.';
$labels['normal'] = 'Норм.';
$labels['high'] = 'Высокий';
$labels['highest'] = 'Высоч.';

$labels['nosubject'] = '(без темы)';
$labels['showimages'] = 'Показать изображения';

$labels['htmltoggle'] = 'HTML';
$labels['plaintoggle'] = 'Обычный текст';

$labels['addcc'] = 'Копия';
$labels['addbcc'] = 'Скрытая копия';
$labels['addreplyto'] = 'Обратный адрес';

// mdn
$labels['mdnrequest'] = 'Отправитель этого сообщения запросил уведомление о прочтении. Отправить уведомление?';
$labels['receiptread'] = 'Уведомление о прочтении';
$labels['yourmessage'] = 'Это уведомление о прочтении вашего сообщения';
$labels['receiptnote'] = 'Это уведомление означает только, что сообщение было открыто получателем, и не гарантирует того, что оно было прочитано и (или) понято.';

// address book
$labels['name'] = 'Отображаемое имя';
$labels['firstname'] = 'Имя';
$labels['surname'] = 'Фамилия';
$labels['email'] = 'E-Mail';

$labels['addcontact'] = 'Добавить выбранные контакты в список контактов';
$labels['editcontact'] = 'Редактировать контакт';

$labels['edit'] = 'Правка';
$labels['cancel'] = 'Отмена';
$labels['save'] = 'Сохранить';
$labels['delete'] = 'Удалить';

$labels['newcontact'] = 'Создать новый контакт';
$labels['deletecontact'] = 'Удалить выбранные контакты';
$labels['composeto'] = 'Создать сообщение для выбранных контактов';
$labels['contactsfromto'] = 'Контакты с $from по $to из $count';
$labels['print'] = 'Печать';
$labels['export'] = 'Экспорт';

$labels['previouspage'] = 'Показать предыдущий';
$labels['firstpage'] = 'Показать первый';
$labels['nextpage'] = 'Показать следующий';
$labels['lastpage'] = 'Показать последний';

$labels['groups'] = 'Группы';
$labels['personaladrbook'] = 'Персональные адреса';


// settings
$labels['settingsfor'] = 'Настройки для';

$labels['preferences'] = 'Настройки';
$labels['userpreferences'] = 'Настройки пользователя';
$labels['editpreferences'] = 'Редактировать настройки пользователя';

$labels['identities'] = 'Профили';
$labels['manageidentities'] = 'Управление профилями';
$labels['newidentity'] = 'Новый профиль';

$labels['newitem'] = 'Новый';
$labels['edititem'] = 'Правка';

$labels['setdefault'] = 'Использовать по умолчанию';
$labels['language'] = 'Язык';
$labels['timezone'] = 'Часовой пояс';
$labels['pagesize'] = 'Строк на странице';
$labels['signature'] = 'Подпись';
$labels['dstactive'] = 'Перевод часов';
$labels['htmleditor'] = 'Создавать сообщения в HTML';
$labels['htmlsignature'] = 'Подпись в HTML';
$labels['previewpane'] = 'Показать панель превью';
$labels['logoutclear'] = 'Очищать корзину при выходе';
$labels['logoutcompact'] = 'Сжать Входящие при выходе';
$labels['uisettings'] = 'Пользовательский интерфейс';
$labels['serversettings'] = 'Настройки сервера';
$labels['mailboxview'] = 'Вид почтового ящика';
$labels['mdnrequests'] = 'Уведомления о прочтении';
$labels['askuser'] = 'спросить перед отправкой';
$labels['autosend'] = 'отправлять автоматически';
$labels['ignore'] = 'игнорировать';
$labels['readwhendeleted'] = 'Помечать как прочитанное при удалении';
$labels['flagfordeletion'] = 'Помечать "для удаления" вместо удаления';

$labels['autosavedraft'] = 'Автосохранение черновика';
$labels['everynminutes'] = 'каждые $n минут';
$labels['never'] = 'никогда';

$labels['folder'] = 'Папка';
$labels['folders'] = 'Папки';
$labels['foldername'] = 'Имя папки';
$labels['subscribed'] = 'Подписан';
$labels['messagecount'] = 'сообщения';
$labels['create'] = 'Создать';
$labels['createfolder'] = 'Создать новую папку';
$labels['rename'] = 'Переименовать';
$labels['renamefolder'] = 'Переименовать папку';
$labels['deletefolder'] = 'Удалить папку';
$labels['managefolders'] = 'Управление папками';

$labels['sortby'] = 'Сортировать по';
$labels['sortasc'] = 'Возрастанию';
$labels['sortdesc'] = 'Убыванию';

?>