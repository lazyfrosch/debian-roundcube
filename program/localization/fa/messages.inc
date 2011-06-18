<?php

/*
+-----------------------------------------------------------------------+
| language/fa/messages.inc                                              |
|                                                                       |
| Language file of the RoundCube Webmail client                         |
| Copyright (C) 2005-2008, RoundCube Dev. - Switzerland                 |
| Licensed under the GNU GPL                                            |
|                                                                       |
+-----------------------------------------------------------------------+
| Author: Mohammad Ebrahim Mohammadi Panah <mebrahim@gmail.com>         |
|         Anoosh <anoosher2003@yahoo.com>                               |
+-----------------------------------------------------------------------+

@version $Id$

*/

$messages = array();
$messages['loginfailed'] = 'ورود ناموفق بود';
$messages['cookiesdisabled'] = 'مرورگر شما کوکی قبول نمی کند';
$messages['sessionerror'] = 'نشست شما معتبر نیست، یا منقضی شده است';
$messages['imaperror'] = 'ناموفق بود IMAPاتصال به سرور';
$messages['nomessagesfound'] = 'هیچ پیغامی در صندوق نامه پیدا نشد';
$messages['loggedout'] = '!شما با موفقیت نشست را پایان دادید. خدا نگه‌دار';
$messages['mailboxempty'] = 'صندوق نامه خالی است';
$messages['loading'] = '...در حال بارگذاری';
$messages['loadingdata'] = '...در حال بارگذاری داده‌ها';
$messages['checkingmail'] = '...بررسی برای پیغام جدید';
$messages['sendingmessage'] = '...در حال ارسال پیغام';
$messages['messagesent'] = 'پیغام با موفقیت فرستاده شد';
$messages['savingmessage'] = '...درحال ذخیره‌ی پیغام';
$messages['messagesaved'] = 'پیغام در پیش‌نویس‌ها ذخیره شد';
$messages['successfullysaved'] = 'با موفقیت ذخیره شد';
$messages['addedsuccessfully'] = 'تماس با موفقیت به دفتر نشانی‌ها اضافه شد';
$messages['contactexists'] = 'یک تماس با این نشانی ایمیل از قبل وجود دارد';
$messages['blockedimages'] = 'برای حفاظت از حریم شخصی شما، عکس‌های دوردست از پیغام حذف شد';
$messages['encryptedmessage'] = '!این یک پیغام رمزنگاری شده است و قابل نمایش نیست. ببخشید';
$messages['nocontactsfound'] = 'هیج تماسی پیدا نشد';
$messages['contactnotfound'] = 'تماس درخواست شده پیدا نشد';
$messages['sendingfailed'] = 'ناموفق در فرستادن پیغام';
$messages['errorsaving'] = 'هنگام ذخیره‌سازی، اشکالی پیش آمد';
$messages['errormoving'] = 'ناتوان در انتقال پیغام';
$messages['errordeleting'] = 'ناتوان در حذف پیغام';
$messages['deletecontactconfirm'] = 'آیا واقعاً می‌خواهید تماس (های) انتخاب شده را حذف کنید؟';
$messages['deletemessagesconfirm'] = 'آیا واقعاً می‌خواهید پیغام (های) انتخاب شده را حذف کنید؟';
$messages['deletefolderconfirm'] = 'آیا واقعاً می‌خواهید این پوشه را حذف کنید؟';
$messages['purgefolderconfirm'] = 'آیا واقعاً می‌خواهید همه‌ی پیغام‌های داخل این پوشه را حذف کنید؟';
$messages['formincomplete'] = 'فرم کاملاً پر نشده بود';
$messages['noemailwarning'] = 'لطفاً یک نشانی ایمیل معتبر وارد کنید';
$messages['nonamewarning'] = 'لطفاً یک نام وارد کنید';
$messages['nopagesizewarning'] = 'لطفاً یک اندازه برای صفحه وارد کنید';
$messages['norecipientwarning'] = 'لطفاً حداقل یک گیرنده وارد کنید';
$messages['nosubjectwarning'] = 'قسمت \"موضوع\" خالی است. آیا می‌خواهید اکنون وارد کنید؟';
$messages['nobodywarning'] = 'این پیغام بدون متن ارسال شود؟';
$messages['notsentwarning'] = 'پیغام ارسال نشده است. آیا می‌خواهید پیغام را از بین ببرید؟';
$messages['noldapserver'] = 'برای جست و جو انتخاب کنید LDAP لطفاً یک سرور';
$messages['nocontactsreturned'] = 'هیچ تماسی پیدا نشد';
$messages['nosearchname'] = 'لطفا نام یک تماس و یا یک نشانی ایمیل وارد کنید';
$messages['searchsuccessful'] = 'پیغام پیدا شد $nr';
$messages['searchnomatch'] = 'جست و جو هیچ نتیجه‌ای نداشت';
$messages['searching'] = '...در حال جست و جو';
$messages['checking'] = '...در حال بررسی';
$messages['nospellerrors'] = 'هیچ اشکال املایی پیدا نشد';
$messages['folderdeleted'] = 'پوشه با موفقیت حذف شد';
$messages['deletedsuccessfully'] = 'حذف انجام شد';
$messages['converting'] = '...در حال حذف قالب‌بندی‌ها از پیغام';
$messages['messageopenerror'] = 'ناتوان در بارگذاری پیغام از روی سرور';
$messages['fileuploaderror'] = 'بالاگذاری پرونده ناموفق بود';
$messages['filesizeerror'] = 'بیشتر است $size اندازه‌ی پرونده‌ی بالاگذاری شده از بیشینه اندازه‌ی';
$messages['copysuccess'] = 'نشانی با موفقیت رونوشت‌برداری شدند $nr';
$messages['copyerror'] = 'رونوشت‌برداری از نشانی‌ها ناموفق بود';
$messages['sourceisreadonly'] = 'این منبع نشانی فقط‌خواندنی است';
$messages['errorsavingcontact'] = 'ذخیره‌ی نشانی تماس ناموفق بود';
$messages['movingmessage'] = '...در حال انتقال پیغام';
$messages['receiptsent'] = 'رسید خواندن با موفقیت ارسال شد';
$messages['errorsendingreceipt'] = 'ناتوان در ارسال رسید';
$messages['nodeletelastidentity'] = '.نمی‌توانید این هویت را حذف کنید، زیرا آخرین هویت شماست';
$messages['addsubfolderhint'] = 'پوشه به عنوان زیرپوشه ای ساخته خواهد شد که هم اکنون انتخاب شده است';
$messages['forbiddencharacter'] = 'نام پوشه شامل یک حرف غیر مجاز است';

?>