AC_INIT([autotools-cpp-template], [1.0])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AX_CXX_COMPILE_STDCXX_17
AC_PROG_CXXCPP
CXXFLAGS=-Wliteral-suffix

PKG_CHECK_MODULES([GTEST], [gtest >= 1.10.0])

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 test/Makefile
])
AC_OUTPUT
