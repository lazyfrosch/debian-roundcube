<?php

/*

+-----------------------------------------------------------------------+
| language/ar/messages.inc                                              |
|                                                                       |
| Language file of the RoundCube Webmail client                         |
| Copyright (C) 2005-2008, RoundCube Dev. - Switzerland                 |
| Licensed under the GNU GPL                                            |
|                                                                       |
+-----------------------------------------------------------------------+
| Author: Ossama Khayat <okhayat@yahoo.com>                             |
+-----------------------------------------------------------------------+

@version $Id: messages.inc 1474 2008-06-05 06:55:51Z yllar $

*/

$messages = array();
$messages['loginfailed'] = 'فشل تسجيل الدخول';
$messages['cookiesdisabled'] = 'المتصفح الخاص بك لا يقبل الكوكيز';
$messages['sessionerror'] = 'انتهت صلاحية الجلسة الحالية أو أنها غير صالحة';
$messages['imaperror'] = 'فشل الاتصال بخادم IMAP';
$messages['nomessagesfound'] = 'لم يعثر على أية رسائل في صندوق البريد هذا';
$messages['loggedout'] = 'لقد قمت بإنهاء هذه الجلسة بنجاح. إلى اللقاء!';
$messages['mailboxempty'] = 'صندوق البريد فارغ';
$messages['loading'] = 'جاري العمل...';
$messages['loadingdata'] = 'تحميل البيانات...';
$messages['checkingmail'] = 'التحقق من وجود رسائل جديدة...';
$messages['sendingmessage'] = 'إرسال الرسالة...';
$messages['messagesent'] = 'تم إرسال الرسالة بنجاح';
$messages['savingmessage'] = 'حفظ الرسالة...';
$messages['messagesaved'] = 'تم حفظ الرسالة في المسودات';
$messages['successfullysaved'] = 'تم الحفظ بنجاح';
$messages['addedsuccessfully'] = 'تمت إضافة المراسل إلى دفتر العناوين بنجاح';
$messages['contactexists'] = 'هناك مراسل له نفس هذا البريد الالكتروني موجود مسبقاً';
$messages['blockedimages'] = 'لحماية خصوصيتك، تم حجب الصور الغير مضمنة (البعيدة) في هذه الرسالة.';
$messages['encryptedmessage'] = 'هذه الرسالة مشفرة ولا يمكن عرضها. عذراً!';
$messages['nocontactsfound'] = 'لم يعثر على أي مراسل';
$messages['contactnotfound'] = 'تعذر العثور على المراسل المطلوب';
$messages['sendingfailed'] = 'فشل إرسال الرسالة';
$messages['errorsaving'] = 'حدث خطأ أثناء الحفظ';
$messages['errormoving'] = 'تعذر نقل هذه الرسالة';
$messages['errordeleting'] = 'تعذر حذف هذه الرسالة';
$messages['deletecontactconfirm'] = 'هل تريد حقاً حذف المراسلـ(ين) المحدد(ين)؟';
$messages['deletemessagesconfirm'] = 'هل تريد حذف الرسائل المحددة؟';
$messages['deletefolderconfirm'] = 'هل تريد حقاً حذف هذا المجلد؟';
$messages['purgefolderconfirm'] = 'هل تريد حقاً حذف جميع الرسائل في هذا المجلد؟';
$messages['formincomplete'] = 'لم يتم تعبئة بيانات الاستمارة بالكامل';
$messages['noemailwarning'] = 'الرجاء إدخال عنوان بريد إلكتروني صالح';
$messages['nonamewarning'] = 'الرجاء إدخال اسم';
$messages['nopagesizewarning'] = 'الرجاء إدخال حجم الصفحة';
$messages['norecipientwarning'] = 'الرجاء إدخال اسم مستقبل واحد على الأقل';
$messages['nosubjectwarning'] = 'حقل \"الموضوع\" فارغ. هل تريد كتابة موضوع للرسالة؟';
$messages['nobodywarning'] = 'إرسال هذه الرسالة دون نص؟';
$messages['notsentwarning'] = 'لم يتم إرسال الرسالة. هل تريد تجاهل الرسالة؟';
$messages['noldapserver'] = 'الرجاء اختيار خادم ldap للبحث فيه';
$messages['nocontactsreturned'] = 'لم يعثر على أي مراسلين';
$messages['nosearchname'] = 'الرجاء إدخال اسم مراسل أو عنوان بريد إلكتروني';
$messages['searchsuccessful'] = 'عثر على $nr رسائل';
$messages['searchnomatch'] = 'لم يعثر على شيء';
$messages['searching'] = 'جاري البحث...';
$messages['checking'] = 'جاري التحقق...';
$messages['nospellerrors'] = 'لم يعثر على أية أخطاء إملائية';
$messages['folderdeleted'] = 'تم حذف المجلد بنجاح';
$messages['deletedsuccessfully'] = 'تم الحذف بنجاح';
$messages['converting'] = 'إزالة التنسيق من الرسالة...';
$messages['messageopenerror'] = 'تعذرت قراءة الرسالة من الخادم';
$messages['fileuploaderror'] = 'فشل رفع الملف';
$messages['filesizeerror'] = 'حجم الملف الذي تحاول رفعه أكبر من الحجم الأقصى $size';
$messages['copysuccess'] = 'تم نسخ $nr رسائل بنجاح';
$messages['copyerror'] = 'لم يمكن نسخ أية عناوين';
$messages['sourceisreadonly'] = 'لا يمكن تعديل مصدر العنوان هذا';
$messages['errorsavingcontact'] = 'تعذر حفظ عنوان المراسل';
$messages['movingmessage'] = 'جاري نقل الرسالة...';
$messages['receiptsent'] = 'أرسل إيصال الاستلام بنجاح';
$messages['errorsendingreceipt'] = 'تعذر إرسال إيصال الاستلام';
$messages['nodeletelastidentity'] = 'لا يمكن حذف هذا السجل حيث أنه الوحيد المتبقي.';
$messages['addsubfolderhint'] = 'سيتم إنشاء هذا المجلد كمجلد فرعي للمحدد.';
$messages['forbiddencharacter'] = 'اسم المجلّد يحتوي حروفاً ممنوعة';

?>