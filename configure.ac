#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([liblongnum_engine], [0.01], [peathot@hotmail.com])
#AC_CONFIG_SRCDIR([config.h.in])
#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

#Automake init and configure flags.
AM_INIT_AUTOMAKE
#LT_PREREQ([2.4.2])
LT_INIT

AC_ARG_ENABLE([debug],
AS_HELP_STRING([--enable-debug],[Turn on debugging]),
[case "${enableval}" in
  yes) debug=true ;;
  no)  debug=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],[debug=false])
AM_CONDITIONAL([DEBUG], [test x$debug = xtrue])

AC_ARG_ENABLE([demo],AS_HELP_STRING([--enable-demo],[Also compile demo program]))

AC_ARG_ENABLE([install-demo],AS_HELP_STRING([--enable-install-demo],[Compile and install demo program]))
AM_CONDITIONAL([INSTALL_DEMO], [test x$enable_install_demo = xyes])
AM_CONDITIONAL([COMPILE_DEMO], [test x$enable_demo = xyes -o x$enable_install_demo = xyes])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB


# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
