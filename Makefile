IDIR=include
SDIR=src
ODIR=obj
BDIR=bin

CC=gcc
MKDIR_P=mkdir -p
CFLAGS=-I$(IDIR)

DEPS=$(wildcard $(IDIR)/*.h)
SRC=$(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

all: directories $(BDIR)/structures

$(BDIR)/structures: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(ODIR):
	@$(MKDIR_P) $@

$(BDIR):
	@$(MKDIR_P) $@

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

all: directories $(BDIR)/structures

.PHONY: clean

clean:
	@rm -rf $(ODIR) $(BDIR)

.PHONY: directories

directories: $(ODIR) $(BDIR)