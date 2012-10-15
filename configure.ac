AC_INIT([kinect-relay], [1.0], [needanemail@derp.net], [kinect-relay], [https://github.com/frc1334/kinect-relay])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 -Wall no-define])
AC_DEFINE([SERVER], [], [42])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CXX
PKG_CHECK_MODULES([libfreenect], [libfreenect >= 0.1])
PKG_CHECK_MODULES([opencv], [opencv >= 0.1])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
