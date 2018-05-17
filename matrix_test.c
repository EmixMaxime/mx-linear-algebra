#include "matrix.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix* test_makeMatrix(int width, int height) {
    Matrix* matrix = makeMatrix(width,height);

    assert(matrix->width == width, "Problem with width initialization");
    assert(matrix->height == height, "Problem with height initialization");

    printf("%f", *matrix->data); 
}

int main() {
    test_makeMatrix(2,5);
    test_makeMatrix(1,2);
    test_makeMatrix(2,5);
    return 0;
}