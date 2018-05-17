#include <stdio.h>
#include <stdlib.h>

/**
 * If the assertion is non-zero (i.e. true), then it returns.
 * If the assertion is zero (i.e. false), then it display the string and
 * aborts the program.
 * This is ment to act like Python's, NodeJS... assert utility.
 */
void assert(int assertion, char* message) {
    if (assertion == 0) {
        fprintf(stderr, "%s\n", message);
        exit(1);
    }
}