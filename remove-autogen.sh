#!/bin/sh
[ -f Makefile ] && make distclean
rm -rf  Makefile.in \
	aclocal.m4 \
	autom4te.cache/ \
	config.guess \
	config.sub \
	configure \
	depcomp \
	install-sh \
	ltmain.sh \
	m4/ \
	missing \
	compile
