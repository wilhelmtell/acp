include $(ROOTDIR)/test/common.mk

export PRODUCT = test_acp
OBJ := $(CURDIR)/main.o \
       $(CURDIR)/paths.o \
       $(CURDIR)/cp_file.o \
       $(CURDIR)/cp.o \
       $(CURDIR)/file.o \
       $(CURDIR)/directory.o \
       $(CURDIR)/contents_of.o \
       $(ROOTDIR)/src/cp.o \
       $(ROOTDIR)/src/cp_file.o
DEPS := $(OBJ:.o=.dep)

.PHONY: check clean distclean

LDFLAGS+=-lboost_filesystem \
         -lboost_system
# see the comment of the $(PRODUCT) rule of the root makefile
$(PRODUCT): $(OBJ)
	$(LINK.cc) $(OUTPUT_OPTION) $^

check: $(PRODUCT)
	./$(PRODUCT)

all: check

clean:
	rm -f $(OBJ) $(DEPS)

distclean: clean
	rm -f $(PRODUCT)

%.dep: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MG -MM -MP -MT"$@" -MT"$(<:.cc=.o)" "$<" >"$@"

ifneq "$(MAKECMDGOALS)" "clean"
ifneq "$(MAKECMDGOALS)" "distclean"
  -include $(DEPS)
endif
endif
