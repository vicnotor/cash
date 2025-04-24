INSTALL_ROOT=/usr/local

OBJECTS = basic.o arithmetic.o logical.o filter.o shift.o noise.o \
random.o neighbors.o margolus.o io.o x11.o ps.o color.o movie.o png.o

.c.o:
	cc -O -c $*.c

$(OBJECTS):cash.h

libcash.a:$(OBJECTS)
	rm -f libcash.a
	ar rv libcash.a $(OBJECTS)

all:libcash.a

install:libcash.a
	-@if [ ! -d $(INSTALL_ROOT)/include  ]; then mkdir -p $(INSTALL_ROOT)/include; fi
	-@if [ ! -d $(INSTALL_ROOT)/lib ]; then mkdir -p $(INSTALL_ROOT)/lib; fi
	cp lib/cash.h $(INSTALL_ROOT)/include
	cp libcash.a $(INSTALL_ROOT)/lib
	ranlib $(INSTALL_ROOT)/lib/libcash.a

clean:
	rm -f *.o libcash.a
