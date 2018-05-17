#include "matrix.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix* makeMatrix(int width, int height) {
    Matrix* out;

    
    assert(width > 0 && height > 0, "New matrix must be at least a 1 by 1");

    out = (Matrix*) malloc(sizeof(Matrix));
    assert(out != NULL, "Out of memory.");

    out->width = width;
    out->height = height;
    out->data = (double*) malloc(sizeof(double) * width * height);

    assert(out->data != NULL, "Out of memory.");

    // Initialize the whole data at 0.0
    memset(out->data, 0.0, width * height * sizeof(double));

    return out;
}

/**
 * Frees the resources of a matrix
 * to avoid memory leacks!
 */
void freeMatrix(Matrix* m) {
    if (m != NULL) {
        if (m->data != NULL) {
            free(m->data);
            m->data = NULL;
        }

        free(m);
        m = NULL;
    }

    return;
}

/**
 * Great for debugging!
 */
void printMatrix(Matrix* m) {
    int i, j;
    double* ptr = m->data;

    printf("%d %d\n", m->width, m->height);

    for (i = 0; i < m->height; i++) {
        for (j = 0; j < m->width; j++) {
            printf(" %9.6f", *(ptr++));
        }

        printf("\n");
    }

    return;
}

Matrix* makeIdentityMatrix(int n) {
    int i;
    Matrix *out;
    double* data;

    assert(n > 0, "Identity matrix must have value greater than zero.");

    out = makeMatrix(n, n);
    data = out->data;
    for (i = 0; i < n; i++) {
        *data = 1.0;
        data += n + 1;
    }

    return out;
}

Matrix* multiplyMatrix(Matrix* a, Matrix* b) {
    int i, j, k;
    Matrix* out;
    double* ptrOut;
    double* ptrA;
    double* ptrB;

    assert(a->width == b->height, "Matrices have incorrect dimensions. a->width != b->height");

    out = makeMatrix(b->width, a->height);
    ptrOut = out->data;

    for (i = 0; i < a->height; i++) {

        for (j = 0; j < b->width; j++) {
            ptrA = &a->data[i * a->width];
            ptrB = &b->data[ j ];

            *ptrOut = 0;
            for (k = 0; k < a->width; k++) {
                *ptrOut += *ptrA * *ptrB;
                ptrA++;
                ptrB += b->width;
            }

            ptrOut++;
        }
    }

    return out;
}
