# debian/source_package_build.bash
# Part of the Debian package ‘roundcube’.
#
# Copyright © 2013–2014 Ben Finney <ben+debian@benfinney.id.au>
# This is free software; you may copy, modify and/or distribute this work
# under the terms of the GNU General Public License, version 3 or later.
# No warranty expressed or implied. See the file ‘LICENSE’ for details.

# Common code for building Debian upstream source package.

working_dir="$(mktemp -d -t)"

exit_sigspecs="ERR EXIT SIGTERM SIGHUP SIGINT SIGQUIT"

function cleanup_exit() {
    exit_status=$?
    trap - $exit_sigspecs

    rm -rf "${working_dir}"
    printf "Cleaned up working directory ‘${working_dir}’\n"

    exit $exit_status
}
trap cleanup_exit $exit_sigspecs

package_name=$(dpkg-parsechangelog | sed -n -e 's/^Source: //p')
release_version=$(dpkg-parsechangelog | sed -n -e 's/^Version: //p')
upstream_version=$(printf "${release_version}" \
	| sed -e 's/^[[:digit:]]\+://' -e 's/[-][^-]\+$//')
upstream_dirname="${package_name}-${upstream_version}.orig"
upstream_tarball_basename="${package_name}_${upstream_version}.orig"

function extract_tarball_to_working_dir() {
    # Extract the specified tarball to the program's working directory.
    local tarball="$1"
    tar -xzf "${tarball}" --directory "${working_dir}"
}

function archive_working_dirname_to_tarball() {
    # Archive the specified directory, relative to the working directory,
    # to a new tarball of the specified name.
    local source_dirname="$1"
    local tarball="$2"
    GZIP="--best" tar --directory "${working_dir}" -czf "${tarball}" "${source_dirname}"
}


# Local variables:
# coding: utf-8
# mode: sh
# End:
# vim: fileencoding=utf-8 filetype=bash :
