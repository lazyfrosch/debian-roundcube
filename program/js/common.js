var CONTROL_KEY=1,SHIFT_KEY=2,CONTROL_SHIFT_KEY=3;
function roundcube_browser(){var a=navigator;this.ver=parseFloat(a.appVersion);this.appver=a.appVersion;this.agent=a.userAgent;this.agent_lc=a.userAgent.toLowerCase();this.name=a.appName;this.vendor=a.vendor?a.vendor:"";this.vendver=a.vendorSub?parseFloat(a.vendorSub):0;this.product=a.product?a.product:"";this.platform=String(a.platform).toLowerCase();this.lang=a.language?a.language.substring(0,2):a.browserLanguage?a.browserLanguage.substring(0,2):a.systemLanguage?a.systemLanguage.substring(0,2):
"en";this.win=0<=this.platform.indexOf("win");this.mac=0<=this.platform.indexOf("mac");this.linux=0<=this.platform.indexOf("linux");this.unix=0<=this.platform.indexOf("unix");this.dom=document.getElementById?!0:!1;this.dom2=document.addEventListener&&document.removeEventListener;this.ie4=(this.ie=document.all&&!window.opera)&&!this.dom;this.ie5=this.dom&&0<this.appver.indexOf("MSIE 5");this.ie8=this.dom&&0<this.appver.indexOf("MSIE 8");this.ie9=this.dom&&0<this.appver.indexOf("MSIE 9");this.ie7=this.dom&&
0<this.appver.indexOf("MSIE 7");this.ie6=this.dom&&!this.ie8&&!this.ie7&&0<this.appver.indexOf("MSIE 6");this.ns=5>this.ver&&"Netscape"==this.name||5<=this.ver&&0<=this.vendor.indexOf("Netscape");this.chrome=0<this.agent_lc.indexOf("chrome");this.safari=!this.chrome&&(0<this.agent_lc.indexOf("safari")||0<this.agent_lc.indexOf("applewebkit"));this.konq=0<this.agent_lc.indexOf("konqueror");this.mz=this.dom&&!this.ie&&!this.ns&&!this.chrome&&!this.safari&&!this.konq&&0<=this.agent.indexOf("Mozilla");
this.iphone=this.safari&&(0<this.agent_lc.indexOf("iphone")||0<this.agent_lc.indexOf("ipod"));this.ipad=this.safari&&0<this.agent_lc.indexOf("ipad");(this.opera=window.opera?!0:!1)&&window.RegExp?this.vendver=/opera(\s|\/)([0-9\.]+)/.test(this.agent_lc)?parseFloat(RegExp.$2):-1:this.chrome&&window.RegExp?this.vendver=/chrome\/([0-9\.]+)/.test(this.agent_lc)?parseFloat(RegExp.$1):0:!this.vendver&&this.safari?this.vendver=/(safari|applewebkit)\/([0-9]+)/.test(this.agent_lc)?parseInt(RegExp.$2):0:!this.vendver&&
this.mz||0<this.agent.indexOf("Camino")?this.vendver=/rv:([0-9\.]+)/.test(this.agent)?parseFloat(RegExp.$1):0:this.ie&&window.RegExp?this.vendver=/msie\s+([0-9\.]+)/.test(this.agent_lc)?parseFloat(RegExp.$1):0:this.konq&&window.RegExp&&(this.vendver=/khtml\/([0-9\.]+)/.test(this.agent_lc)?parseFloat(RegExp.$1):0);this.safari&&/;\s+([a-z]{2})-[a-z]{2}\)/.test(this.agent_lc)&&(this.lang=RegExp.$1);this.tablet=/ipad|android|xoom|sch-i800|playbook|tablet|kindle/i.test(this.agent_lc);this.touch=(this.mobile=
/iphone|ipod|blackberry|iemobile|opera mini|opera mobi|mobile/i.test(this.agent_lc))||this.tablet;this.dhtml=this.ie4&&this.win||this.ie5||this.ie6||this.ns4||this.mz;this.vml=this.win&&this.ie&&this.dom&&!this.opera;this.pngalpha=this.mz||this.opera&&6<=this.vendver||this.ie&&this.mac&&5<=this.vendver||this.ie&&this.win&&5.5<=this.vendver||this.safari;this.opacity=this.mz||this.ie&&5.5<=this.vendver&&!this.opera||this.safari&&100<=this.vendver;this.cookies=a.cookieEnabled;this.xmlhttp_test=function(){var a=
new Function("try{var o=new ActiveXObject('Microsoft.XMLHTTP');return true;}catch(err){return false;}");return this.xmlhttp=window.XMLHttpRequest||window.ActiveXObject&&a()};this.set_html_class=function(){var a=" js";this.ie?a+=" ie ie"+parseInt(this.vendver):this.opera?a+=" opera":this.konq?a+=" konqueror":this.safari?a+=" chrome":this.chrome?a+=" chrome":this.mz&&(a+=" mozilla");if(this.iphone)a+=" iphone";else if(this.ipad)a+=" ipad";else if(this.safari||this.chrome)a+=" webkit";this.mobile&&(a+=
" mobile");this.tablet&&(a+=" tablet");document.documentElement&&(document.documentElement.className+=a)}}
var rcube_event={get_target:function(a){return(a=a||window.event)&&a.target?a.target:a.srcElement},get_keycode:function(a){return(a=a||window.event)&&a.keyCode?a.keyCode:a&&a.which?a.which:0},get_button:function(a){return(a=a||window.event)&&void 0!==a.button?a.button:a&&a.which?a.which:0},get_modifier:function(a){var b=0;a=a||window.event;bw.mac&&a?b+=(a.metaKey&&CONTROL_KEY)+(a.shiftKey&&SHIFT_KEY):a&&(b+=(a.ctrlKey&&CONTROL_KEY)+(a.shiftKey&&SHIFT_KEY));return b},get_mouse_pos:function(a){a||(a=
window.event);var b=a.pageX?a.pageX:a.clientX,c=a.pageY?a.pageY:a.clientY;document.body&&document.all&&(b+=document.body.scrollLeft,c+=document.body.scrollTop);a._offset&&(b+=a._offset.left,c+=a._offset.top);return{x:b,y:c}},add_listener:function(a){if(a.object&&a.method){a.element||(a.element=document);a.object._rc_events||(a.object._rc_events=[]);var b=a.event+"*"+a.method;a.object._rc_events[b]||(a.object._rc_events[b]=function(c){return a.object[a.method](c)});a.element.addEventListener?a.element.addEventListener(a.event,
a.object._rc_events[b],!1):a.element.attachEvent?(a.element.detachEvent("on"+a.event,a.object._rc_events[b]),a.element.attachEvent("on"+a.event,a.object._rc_events[b])):a.element["on"+a.event]=a.object._rc_events[b]}},remove_listener:function(a){a.element||(a.element=document);var b=a.event+"*"+a.method;a.object&&a.object._rc_events&&a.object._rc_events[b]&&(a.element.removeEventListener?a.element.removeEventListener(a.event,a.object._rc_events[b],!1):a.element.detachEvent?a.element.detachEvent("on"+
a.event,a.object._rc_events[b]):a.element["on"+a.event]=null)},cancel:function(a){a=a?a:window.event;a.preventDefault&&a.preventDefault();a.stopPropagation&&a.stopPropagation();a.cancelBubble=!0;return a.returnValue=!1},touchevent:function(a){return{pageX:a.pageX,pageY:a.pageY,offsetX:a.pageX-a.target.offsetLeft,offsetY:a.pageY-a.target.offsetTop,target:a.target,istouch:!0}}};function rcube_event_engine(){this._events={}}
rcube_event_engine.prototype={addEventListener:function(a,b,c){this._events||(this._events={});this._events[a]||(this._events[a]=[]);this._events[a][this._events[a].length]={func:b,obj:c?c:window}},removeEventListener:function(a,b,c){void 0===c&&(c=window);for(var d,e=0;this._events&&this._events[a]&&e<this._events[a].length;e++)(d=this._events[a][e])&&d.func==b&&d.obj==c&&(this._events[a][e]=null)},triggerEvent:function(a,b){var c,d;void 0===b?b=this:"object"===typeof b&&(b.event=a);if(this._events&&
this._events[a]&&!this._event_exec){this._event_exec=!0;for(var e=0;e<this._events[a].length;e++)if(d=this._events[a][e])if("function"===typeof d.func?c=d.func.call?d.func.call(d.obj,b):d.func(b):"function"===typeof d.obj[d.func]&&(c=d.obj[d.func](b)),void 0!==c&&!c)break;if(c&&c.event)try{delete c.event}catch(f){$(c).removeAttr("event")}}this._event_exec=!1;if(b.event)try{delete b.event}catch(h){$(b).removeAttr("event")}return c}};
function rcube_layer(a,b){this.name=a;this.create=function(a){var b=a.x?a.x:0,e=a.y?a.y:0,f=a.width,h=a.height,k=a.zindex,g=a.vis;a=a.parent;var l=document.createElement("DIV");l.id=this.name;l.style.position="absolute";l.style.visibility=g?2==g?"inherit":"visible":"hidden";l.style.left=b+"px";l.style.top=e+"px";f&&(l.style.width=f.toString().match(/\%$/)?f:f+"px");h&&(l.style.height=h.toString().match(/\%$/)?h:h+"px");k&&(l.style.zIndex=k);a?a.appendChild(l):document.body.appendChild(l);this.elm=
l};null!=b?(this.create(b),this.name=this.elm.id):this.elm=document.getElementById(a);if(!this.elm)return!1;this.css=this.elm.style;this.event=this.elm;this.width=this.elm.offsetWidth;this.height=this.elm.offsetHeight;this.x=parseInt(this.elm.offsetLeft);this.y=parseInt(this.elm.offsetTop);this.visible="visible"==this.css.visibility||"show"==this.css.visibility||"inherit"==this.css.visibility?!0:!1;this.move=function(a,b){this.x=a;this.y=b;this.css.left=Math.round(this.x)+"px";this.css.top=Math.round(this.y)+
"px"};this.resize=function(a,b){this.css.width=a+"px";this.css.height=b+"px";this.width=a;this.height=b};this.show=function(a){1==a?(this.css.visibility="visible",this.visible=!0):2==a?(this.css.visibility="inherit",this.visible=!0):(this.css.visibility="hidden",this.visible=!1)};this.write=function(a){this.elm.innerHTML=a}}
function rcube_check_email(a,b){return a&&window.RegExp?(b?RegExp("(^|<|[,;s\n])((([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22)(\\x2e([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22))*\\x40(((\\[(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])(.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])){3}\\])|(\\[IPv6:[0-9a-f:.]+\\]))|(([^@\\x2e]+\\x2e)+([^\\x00-\\x40\\x5b-\\x60\\x7b-\\x7f]{2,}|xn--[a-z0-9]{2,}))))|(mailtest\\x40(\\u0645\\u062b\\u0627\\u0644\\x2e\\u0625\\u062e\\u062a\\u0628\\u0627\\u0631|\\u4f8b\\u5b50\\x2e\\u6d4b\\u8bd5|\\u4f8b\\u5b50\\x2e\\u6e2c\\u8a66|\\u03c0\\u03b1\\u03c1\\u03ac\\u03b4\\u03b5\\u03b9\\u03b3\\u03bc\\u03b1\\x2e\\u03b4\\u03bf\\u03ba\\u03b9\\u03bc\\u03ae|\\u0909\\u0926\\u093e\\u0939\\u0930\\u0923\\x2e\\u092a\\u0930\\u0940\\u0915\\u094d\\u0937\\u093e|\\u4f8b\\u3048\\x2e\\u30c6\\u30b9\\u30c8|\\uc2e4\\ub840\\x2e\\ud14c\\uc2a4\\ud2b8|\\u0645\\u062b\\u0627\\u0644\\x2e\\u0622\\u0632\\u0645\\u0627\\u06cc\\u0634\u06cc|\\u043f\\u0440\\u0438\\u043c\\u0435\\u0440\\x2e\\u0438\\u0441\\u043f\\u044b\\u0442\\u0430\\u043d\\u0438\\u0435|\\u0b89\\u0ba4\\u0bbe\\u0bb0\\u0ba3\\u0bae\\u0bcd\\x2e\\u0baa\\u0bb0\\u0bbf\\u0b9f\\u0bcd\\u0b9a\\u0bc8|\\u05d1\\u05f2\\u05b7\\u05e9\\u05e4\\u05bc\\u05d9\\u05dc\\x2e\\u05d8\\u05e2\\u05e1\\u05d8)))($|>|[,;s\n])","i"):
RegExp("^((([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22)(\\x2e([^\\x00-\\x20\\x22\\x28\\x29\\x2c\\x2e\\x3a-\\x3c\\x3e\\x40\\x5b-\\x5d\\x7f-\\xff]+|\\x22([^\\x0d\\x22\\x5c\\x80-\\xff]|\\x5c[\\x00-\\x7f])*\\x22))*\\x40(((\\[(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])(.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])){3}\\])|(\\[IPv6:[0-9a-f:.]+\\]))|(([^@\\x2e]+\\x2e)+([^\\x00-\\x40\\x5b-\\x60\\x7b-\\x7f]{2,}|xn--[a-z0-9]{2,}))))|(mailtest\\x40(\\u0645\\u062b\\u0627\\u0644\\x2e\\u0625\\u062e\\u062a\\u0628\\u0627\\u0631|\\u4f8b\\u5b50\\x2e\\u6d4b\\u8bd5|\\u4f8b\\u5b50\\x2e\\u6e2c\\u8a66|\\u03c0\\u03b1\\u03c1\\u03ac\\u03b4\\u03b5\\u03b9\\u03b3\\u03bc\\u03b1\\x2e\\u03b4\\u03bf\\u03ba\\u03b9\\u03bc\\u03ae|\\u0909\\u0926\\u093e\\u0939\\u0930\\u0923\\x2e\\u092a\\u0930\\u0940\\u0915\\u094d\\u0937\\u093e|\\u4f8b\\u3048\\x2e\\u30c6\\u30b9\\u30c8|\\uc2e4\\ub840\\x2e\\ud14c\\uc2a4\\ud2b8|\\u0645\\u062b\\u0627\\u0644\\x2e\\u0622\\u0632\\u0645\\u0627\\u06cc\\u0634\u06cc|\\u043f\\u0440\\u0438\\u043c\\u0435\\u0440\\x2e\\u0438\\u0441\\u043f\\u044b\\u0442\\u0430\\u043d\\u0438\\u0435|\\u0b89\\u0ba4\\u0bbe\\u0bb0\\u0ba3\\u0bae\\u0bcd\\x2e\\u0baa\\u0bb0\\u0bbf\\u0b9f\\u0bcd\\u0b9a\\u0bc8|\\u05d1\\u05f2\\u05b7\\u05e9\\u05e4\\u05bc\\u05d9\\u05dc\\x2e\\u05d8\\u05e2\\u05e1\\u05d8)))$",
"i")).test(a)?!0:!1:!1}function rcube_clone_object(a){var b={},c;for(c in a)b[c]=a[c]&&"object"===typeof a[c]?clone_object(a[c]):a[c];return b}function urlencode(a){return window.encodeURIComponent?encodeURIComponent(a).replace("*","%2A"):escape(a).replace("+","%2B").replace("*","%2A").replace("/","%2F").replace("@","%40")}
function rcube_find_object(a,b){var c,d;b||(b=document);b.getElementsByName&&(c=b.getElementsByName(a))&&(d=c[0]);!d&&b.getElementById&&(d=b.getElementById(a));!d&&b.all&&(d=b.all[a]);!d&&b.images.length&&(d=b.images[a]);if(!d&&b.forms.length)for(c=0;c<b.forms.length;c++)b.forms[c].name==a?d=b.forms[c]:b.forms[c].elements[a]&&(d=b.forms[c].elements[a]);if(!d&&b.layers)for(b.layers[a]&&(d=b.layers[a]),c=0;!d&&c<b.layers.length;c++)d=rcube_find_object(a,b.layers[c].document);return d}
function rcube_mouse_is_over(a,b){var c=rcube_event.get_mouse_pos(a),d=$(b).offset();return c.x>=d.left&&c.x<d.left+b.offsetWidth&&c.y>=d.top&&c.y<d.top+b.offsetHeight}function setCookie(a,b,c,d,e,f){a=a+"="+escape(b)+(c?"; expires="+c.toGMTString():"")+(d?"; path="+d:"")+(e?"; domain="+e:"")+(f?"; secure":"");document.cookie=a}
function getCookie(a){var b=document.cookie;a+="=";var c=b.indexOf("; "+a);if(-1==c){if(c=b.indexOf(a),0!=c)return null}else c+=2;var d=b.indexOf(";",c);-1==d&&(d=b.length);return unescape(b.substring(c+a.length,d))}roundcube_browser.prototype.set_cookie=setCookie;roundcube_browser.prototype.get_cookie=getCookie;
function rcube_console(){this.log=function(a){var b=rcube_find_object("dbgconsole");b&&(a="\n"==a.charAt(a.length-1)?a+"--------------------------------------\n":a+"\n--------------------------------------\n",bw.konq?(b.innerText+=a,b.value=b.innerText):b.value+=a)};this.reset=function(){var a=rcube_find_object("dbgconsole");a&&(a.innerText=a.value="")}}var bw=new roundcube_browser;bw.set_html_class();RegExp.escape=function(a){return String(a).replace(/([.*+?^=!:${}()|[\]\/\\])/g,"\\$1")};
Date.prototype.getStdTimezoneOffset=function(){for(var a=12,b=new Date(null,a,1),c=b.getTimezoneOffset();--a;)if(b.setUTCMonth(a),c!=b.getTimezoneOffset())return Math.max(c,b.getTimezoneOffset());return c};bw.ie&&(document._getElementById=document.getElementById,document.getElementById=function(a){var b=0,c=document._getElementById(a);if(c&&c.id!=a)for(;(c=document.all[b])&&c.id!=a;)b++;return c});
jQuery.fn.placeholder=function(a){return this.each(function(){var b=!1,c=$(this);this.title=a;if("placeholder"in this)c.attr("placeholder",a);else{this._placeholder=a;c.blur(function(b){""==$.trim(c.val())&&c.val(a);c.triggerHandler("change")}).focus(function(b){$.trim(c.val())==a&&c.val("");c.triggerHandler("change")}).change(function(b){b=c.val()==a;c[b?"addClass":"removeClass"]("placeholder").attr("spellcheck",b)});try{b=this==document.activeElement}catch(d){}b||c.blur()}})};
var Base64=function(){return{encode:function(a){if("function"===typeof window.btoa)return btoa(a);var b,c,d,e,f,h,k=0,g="",l=a.length;do b=a.charCodeAt(k++),c=a.charCodeAt(k++),d=a.charCodeAt(k++),e=b>>2,b=(b&3)<<4|c>>4,f=(c&15)<<2|d>>6,h=d&63,isNaN(c)?f=h=64:isNaN(d)&&(h=64),g=g+"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(e)+"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(b)+"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(f)+
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".charAt(h);while(k<l);return g},decode:function(a){if("function"===typeof window.atob)return atob(a);var b,c,d,e,f,h,k=0,g="";a=a.replace(/[^A-Za-z0-9\+\/\=]/g,"");h=a.length;do b="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".indexOf(a.charAt(k++)),c="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".indexOf(a.charAt(k++)),e="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".indexOf(a.charAt(k++)),
f="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=".indexOf(a.charAt(k++)),b=b<<2|c>>4,c=(c&15)<<4|e>>2,d=(e&3)<<6|f,g+=String.fromCharCode(b),64!=e&&(g+=String.fromCharCode(c)),64!=f&&(g+=String.fromCharCode(d));while(k<h);return g}}}();
