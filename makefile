INSTALL_ROOT = /usr/local

SRCDIR = lib
OBJECTS = $(SRCDIR)/basic.o $(SRCDIR)/arithmetic.o $(SRCDIR)/logical.o $(SRCDIR)/filter.o \
          $(SRCDIR)/shift.o $(SRCDIR)/noise.o $(SRCDIR)/random.o $(SRCDIR)/neighbors.o \
          $(SRCDIR)/margolus.o $(SRCDIR)/io.o $(SRCDIR)/x11.o $(SRCDIR)/ps.o $(SRCDIR)/color.o \
          $(SRCDIR)/movie.o $(SRCDIR)/png.o

libcash.a: $(OBJECTS)
	rm -f libcash.a
	ar rv libcash.a $(OBJECTS)
	ranlib libcash.a

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/cash.h
	cc -O -c $< -o $@

all: libcash.a

install: libcash.a
	@mkdir -p $(INSTALL_ROOT)/include
	@mkdir -p $(INSTALL_ROOT)/lib
	cp lib/cash.h $(INSTALL_ROOT)/include
	cp libcash.a $(INSTALL_ROOT)/lib

clean:
	rm -f $(OBJECTS) libcash.a
