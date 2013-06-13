ACLOCAL_AMFLAGS = -I m4

# includes append to these:
SUFFIXES =
PHONY =
TESTS =
CLEANFILES =
bin_PROGRAMS =
noinst_HEADERS =
lib_LTLIBRARIES =
noinst_LTLIBRARIES =
noinst_PROGRAMS =
include_HEADERS =
nobase_include_HEADERS =
check_PROGRAMS =
EXTRA_HEADERS =
BUILT_SOURCES=
EXTRA_DIST= \
	    ${srcdir}/m4/pandora_*.m4 \
	    .quickly \
	    README.FIRST \
	    README.win32 \
	    config/autorun.sh \
	    config/pandora-plugin \
	    config/uncrustify.cfg \
	    m4/ac_cxx_header_stdcxx_98.m4 \
	    m4/acx_pthread.m4  \
	    m4/gettext.m4 \
	    m4/iconv.m4 \
	    m4/pkg.m4 \
	    m4/po.m4 \
	    m4/progtest.m4


include libmemcached/include.am
include libhashkit/include.am
include poll/include.am
include win32/include.am


CLEANFILES+= config/top.h
