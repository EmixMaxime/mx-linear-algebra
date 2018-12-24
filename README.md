# Mx linear algebra

This will be my set of C libraries for doing simple matrix operations and
linear algebra.

## Why in C?
Because I want to learn! Using Python and Numpy is just simple. And, I love this language.

## Operations

### Simple Matrix Operations
- [x] Identity Matrices
- [ ] Matrix Transpose (To flip a matrix along the diagonal)
- [x] Matrix Multiplication
- [ ] Matrix Scaling
- [ ] Matrix Covariance
- [ ] Matrix Dot Product
- [ ] Matrix Dot Diagonal (computes the dot product of the diagonals of two matrices)
- [ ] Matrix Trace (Sum of elements along the diagonal)
- [ ] Matrix Mean (returns the average of each column in a matrix)
- [ ] Matrix Multiplication

### Advanced Matrix Operations
- [x] Matrix Inverts

## Explain me

### Advanced Matrix Operations
#### LU Decomposition

##### What
In numerical analysis and linear algebra, LU decomposition factors a matrix as the product of a lower triangular matrix and an upper triangular matrix. "LU" stands for "lower upper", and also called LU factorization.
The LU decomposition was introduced by mathematician Tadeusz Banachiewicz in 1938.


An LU factorization refers to the factorization of A, with proper row and/or column orderings or permutations, into two factors, a **lower triangular matrix** `L` and an **upper triangular matrix** `U`, `A=LU`.

##### Why?
Computers usually solve square systems of linear equations using the LU decomposition, and it is also a key step when inverting a matrix, or computing the determinant of a matrix.

- Solve square systems of linear equations based on the LU decomposition.
- Inverting a matrix.
- Computing the determinant of a matrix.

So, yes it's very important!

##### Requirements
`LU` is a decomposition for a `A` matrix. **`A` have to be a square matrix.**

#####
Sources:
- https://en.wikipedia.org/wiki/LU_decomposition