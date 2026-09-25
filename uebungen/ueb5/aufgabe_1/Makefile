CXXFLAGS=-Wall -Werror -g
MAIN=drawing
LIB=geo
LDFLAGS=-L"$(shell pwd)"
LDLIBS=-l$(LIB)
LINK.o=$(LINK.cc)

$(MAIN):: lib$(LIB).a

all: lib$(LIB).a $(MAIN)

geo.o:: geo.hh

lib$(LIB).a: geo.o
	$(AR) rcs $@ $^

.PHONY: clean distclean
clean:
	-rm -f *.o *~ lib$(LIB).a $(MAIN)

distclean: clean
