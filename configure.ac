AC_INIT([acp], m4_esyscmd_s([git describe --dirty 2>/dev/null || echo v0.1]), [matan.nassau@gmail.com])
AM_INIT_AUTOMAKE([1.14.1 foreign -Wall -Werror])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CXX
AC_PROG_RANLIB
AM_PROG_AR
AX_BOOST_BASE([1.55], , [AC_MSG_ERROR(Boost libraries required but not found.)])
AX_BOOST_FILESYSTEM
AX_BOOST_SYSTEM
AX_BOOST_PROGRAM_OPTIONS
AX_BOOST_REGEX
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([Makefile src/Makefile test/Makefile])
AC_OUTPUT
