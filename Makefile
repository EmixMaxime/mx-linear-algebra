.PHONY: compile tests run cleantmp

# The compilator
CC      = gcc
# flags for the compilator
CFLAGS  = -g

RM_FOLDER  = rm -fR

# Folders config
DIST    = ./dist
SRC     = ./
HEADERS = ./
TESTS   = ./
TESTS_DIST = ./tests/dist

$(SRC)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

cleantmp:
	@echo "Cleaning .o files"
	rm -rf $(SRC)/*.o

compile: $(SRC)/helpers.o $(SRC)/matrix.o
	gcc -o $(DIST)/Binary $?
	# $(MAKE) cleantmp

$(TESTS)/%.o: $(TESTS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

tests: $(SRC)/matrix.o $(SRC)/helpers.o $(TESTS)/matrix_test.o
	gcc -o $(TESTS_DIST)/Binary $?

# run: tests
# 	./tests/dist/Binary