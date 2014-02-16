IDIR=include
SDIR=src
ODIR=obj
TODIR=obj
BDIR=bin
TDIR=test

CC=gcc
MKDIR_P=mkdir -p
CFLAGS=-I$(IDIR) -I$(TDIR)
LFLAGS=-lm

DEPS=$(wildcard $(IDIR)/*.h)
TDEPS=$(wildcard $(TDIR)/*.h)
SRC=$(wildcard $(SDIR)/*.c)
TSRC=$(wildcard $(TDIR)/*.c)
OBJ=$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))
TOBJ=$(patsubst $(TDIR)/%.c, $(TODIR)/%.o, $(TSRC))

all: directories test

$(BDIR)/structures: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)

$(ODIR):
	@$(MKDIR_P) $@

$(BDIR):
	@$(MKDIR_P) $@

$(TODIR)/%.o: $(TDIR)/%.c $(DEPS) $(TDEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	@rm -rf $(ODIR) $(BDIR)

.PHONY: directories

directories: $(ODIR) $(BDIR)

test: directories $(BDIR)/run_tests
	@$(BDIR)/run_tests

$(BDIR)/run_tests: $(OBJ) $(TOBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
