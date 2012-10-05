include $(ROOTDIR)/test/common.mk

export PRODUCT = test_acp
OBJ := $(CURDIR)/main.o \
       $(CURDIR)/file.o \
       $(ROOTDIR)/src/cmdline.o \
       $(ROOTDIR)/src/cp.o \
       $(ROOTDIR)/src/cp_file.o
DEPS := $(OBJ:.o=.dep)

.PHONY: clean distclean

LDFLAGS+=-lboost_filesystem \
         -lboost_system
# see the comment of the $(PRODUCT) rule of the root makefile
$(PRODUCT): $(OBJ)
	$(LINK.cc) $(OUTPUT_OPTION) $^

check: $(PRODUCT)
	./$(PRODUCT) && touch check

all: check

clean:
	rm -f $(OBJ) $(DEPS) check

distclean: clean
	rm -f $(PRODUCT)

%.dep: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MG -MM -MP -MT"$@" -MT"$(<:.cc=.o)" "$<" >"$@"

ifneq "$(MAKECMDGOALS)" "clean"
ifneq "$(MAKECMDGOALS)" "distclean"
  -include $(DEPS)
endif
endif
