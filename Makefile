IDIR = include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = lib

LIBS = -lm

_DEPS = ac.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


_OBJ = stack.o op.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ac.o: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
