AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = 
AM_CPPFLAGS = 
LDADD = 

lib_LTLIBRARIES = library/liblongnum_engine.la
library_liblongnum_engine_la_SOURCES = library/longnum_engine.cpp library/longnum_engine.h
library_liblongnum_engine_la_LIBADD = 

include_HEADERS = library/longnum_engine.h

#DemoProgs = 	demo-program/fac-longnum demo-program/fib demo-program/longnum_engine-diff demo-program/longnum_engine-divide demo-program/longnum_engine-multiply demo-program/longnum_engine-sum demo-program/longnum_engine-multinum-sum
EXTRA_PROGRAM = demo-program/fac-longnum demo-program/fib demo-program/longnum_engine-diff demo-program/longnum_engine-divide demo-program/longnum_engine-multiply demo-program/longnum_engine-sum demo-program/longnum_engine-multinum-sum

if COMPILE_DEMO

if INSTALL_DEMO
bin_PROGRAMS = demo-program/fac-longnum demo-program/fib demo-program/longnum_engine-diff demo-program/longnum_engine-divide demo-program/longnum_engine-multiply demo-program/longnum_engine-sum demo-program/longnum_engine-multinum-sum
else !INSTALL_DEMO
noinst_PROGRAMS = demo-program/fac-longnum demo-program/fib demo-program/longnum_engine-diff demo-program/longnum_engine-divide demo-program/longnum_engine-multiply demo-program/longnum_engine-sum demo-program/longnum_engine-multinum-sum
endif !INSTALL_DEMO

demo_program_longnum_engine_multinum_sum_SOURCES = demo-program/longnum_engine-multinum-sum.cpp
LDADD += library/liblongnum_engine.la
AM_CFLAGS += -Ilibrary/
AM_CPPFLAGS += -Ilibrary/

endif COMPILE_DEMO

if DEBUG
AM_CFLAGS += -g
endif
