#!/bin/sh
#
# The program/js/jquery-ui-1.9.1.custom.js can't be shipped
# because we don't have the source for it.  So construct that
# works the way roundcude wants it from the original sources.
#
# We actually just mung the minified source because it's closest
# to what we want.
#
# This transformation was figured out by diffing the
# jquery-ui-1.9.1.custom.js to the one shipped in the original
# (ie unrepacked, ie not the Debian .orig.tar.gz) tarball.
#
# In brief, the transformation is to replace every global
# function definition, which all have the form:
#   function (arg ...) { ... } (jQuery),
# with:
#   (function (arg ...) { ... }) (jQuery);

unzip -p "${1}" "*/jquery-ui.min.js" |
  sed '
      s/}\((jQuery)\),\(jQuery.effects||\)\?\(function([a-z$]\)/})\1;\2(\3/g
      s/})(jQuery),function(/})(jQuery);(function(/
      s/}(jQuery);$/})(jQuery);/'
