#include <iostream>
#include <vector>

/*
4.2-2: Strassen's Algorithm for Matrix Multiplication
*/

/*
PSEUDO CODE
STRASSEN(A, B, C, n)
    if n == 1
        C[0][0] = A[0][0] * B[0][0]
        reutrn C

    let A11, A12, A21, A22 be four n/2*n/2 partitions of A
    let B11, B12, B21, B22 be four n/2*n/2 partitions of B
    let C11, C12, C21, C22 be four n/2*n/2 partitions of C

    // S matrices
    S1 = B12 - B22
    S2  = A11 + A12
    S3  = A21 + A22
    S4  = B21 - B11
    S5  = A11 + A22
    S6  = B11 + B22
    S7  = A12 - A22
    S8  = B21 + B22
    S9  = A11 - A21
    S10 = B11 + B12

    // P matrices
    P1 = STRASSEN(A11, S1,  n/2)
    P2 = STRASSEN(S2,  B22, n/2)
    P3 = STRASSEN(S3,  B11, n/2)
    P4 = STRASSEN(A22, S4,  n/2)
    P5 = STRASSEN(S5,  S6,  n/2)
    P6 = STRASSEN(S7,  S8,  n/2)
    P7 = STRASSEN(S9,  S10, n/2)

    // C matrix
    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7

    return C
*/

int main() {
    return 0;
}