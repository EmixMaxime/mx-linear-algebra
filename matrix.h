#ifndef __MX_MATRIX
#define __MX_MATRIX


typedef struct Matrix Matrix;

struct Matrix {
    int height;
    int width;
    // Will be a reference to an Array [width*height]
    double* data;
};

/**
 * Functions to deal with Matrix
 */

// Matrix* readMatrix(char* filename);
Matrix* makeMatrix(int width, int height);
void freeMatrix(Matrix* m);
Matrix* makeIdentityMatrix(int n);
// Matrix* copyMatrix(Matrix* m);
// void writeMatrix(Matrix* m, char* filename);
void printMatrix(Matrix* m);

/**
 * Basic operations
 */

Matrix* multiplyMatrix(Matrix* a, Matrix* b);


#endif