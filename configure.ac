AC_INIT([kinect-relay], [1.0], [captain@othsrobotics.ca], [kinect-relay], [https://github.com/frc1334/kinect-relay])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall -Werror no-define])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
AC_PROG_CC
AC_ARG_VAR([HEADER], [Specifies the header that should be used for implementation, not including the .h])
if test "$HEADER" = ""; then
HEADER="Default"
fi
link_header="src/Implementations/$HEADER.h"
AC_SUBST(link_header)
PKG_CHECK_MODULES([libfreenect], [libfreenect >= 0.1])
PKG_CHECK_MODULES([opencv], [opencv >= 0.1])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
