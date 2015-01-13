check_PROGRAMS = check_acp
check_acp_SOURCES = main.cc \
                    contents_of.hh contents_of.cc \
                    cp.cc \
                    cp_file.cc \
                    directory.hh directory.cc \
                    file.hh file.tcc file.cc \
                    paths.hh paths.cc \
                    variable.hh variable.tcc variable.cc \
                    variables_map.hh variables_map.cc \
                    verify.cc
check_acp_CPPFLAGS = -I../include
check_acp_LDADD = ../src/libacp.a \
                  -lboost_filesystem \
                  -lboost_system
AM_CXXFLAGS = -std=c++14

check: check-am
	./$(check_PROGRAMS)
