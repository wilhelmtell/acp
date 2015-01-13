bin_PROGRAMS = acp
acp_SOURCES = main.cc
acp_CPPFLAGS = -I../include
acp_LDADD = libacp.a \
            -lboost_filesystem \
            -lboost_system \
            -lboost_program_options
AM_CXXFLAGS = -std=c++14

noinst_LIBRARIES = libacp.a
libacp_a_SOURCES = commandline.hh commandline.cc \
                   cp.hh cp.tcc cp.cc \
                   cp_file.hh cp_file.cc \
                   verify.hh verify.tcc \
                   verify_error.hh verify_error.tcc verify_error.cc
