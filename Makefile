RM  = /bin/rm

# The compilator
CC      = gcc
# flags for the compilator
# -Wall
CFLAGS  = -lm

RM_FOLDER  = rm -fR

# Folders config
DIST    = ./dist
SRC     = ./
HEADERS = ./
TESTS   = ./
TESTS_DIST = ./tests/dist

LIBRARY = matrix.o
TEST_APS = matrix_test

# all: $(TEST_APS)

# %.o: $*.c $*.h
# 	@echo "Compiling"
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning .o files"
	-$(RM) $(SRC)/*.o

# $(TESTS)/%.o: $(TESTS)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

DEPS = helpers.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

matrix: matrix.o helpers.o
	gcc $(CFLAGS) -o $@ $^
