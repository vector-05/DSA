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

using Matrix = std::vector<std::vector<int>>;

// Helper function to add two matrices
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Helper function to subtract two matrices
Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Strassen's Algorithm Implementation
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // Base Case: 1x1 Matrix
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    // Create submatrices of size (n/2) x (n/2)
    Matrix A11(k, std::vector<int>(k)), A12(k, std::vector<int>(k)),
           A21(k, std::vector<int>(k)), A22(k, std::vector<int>(k));
    
    Matrix B11(k, std::vector<int>(k)), B12(k, std::vector<int>(k)),
           B21(k, std::vector<int>(k)), B22(k, std::vector<int>(k));

    // Splitting matrices A and B into 4 submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Step 1: Calculate S1 through S10
    Matrix S1  = subtract(B12, B22);
    Matrix S2  = add(A11, A12);
    Matrix S3  = add(A21, A22);
    Matrix S4  = subtract(B21, B11);
    Matrix S5  = add(A11, A22);
    Matrix S6  = add(B11, B22);
    Matrix S7  = subtract(A12, A22);
    Matrix S8  = add(B21, B22);
    Matrix S9  = subtract(A11, A21);
    Matrix S10 = add(B11, B12);

    // Step 2: Recursive calls to compute P1 through P7
    Matrix P1 = strassen(A11, S1);
    Matrix P2 = strassen(S2, B22);
    Matrix P3 = strassen(S3, B11);
    Matrix P4 = strassen(A22, S4);
    Matrix P5 = strassen(S5, S6);
    Matrix P6 = strassen(S7, S8);
    Matrix P7 = strassen(S9, S10);

    // Step 3: Combine P matrices to get C submatrices
    Matrix C11 = add(subtract(add(P5, P4), P2), P6);
    Matrix C12 = add(P1, P2);
    Matrix C21 = add(P3, P4);
    Matrix C22 = subtract(subtract(add(P5, P1), P3), P7);

    // Step 4: Merge C11, C12, C21, C22 into final result Matrix C
    Matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j]         = C11[i][j];
            C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    // Example with 4x4 matrices (n must be a power of 2)
    Matrix A = {
        {1, 3},
        {7, 5}
    };

    Matrix B = {
        {6, 8},
        {4, 2}
    };

    std::cout << "Matrix A * B (Identity Matrix):\n";
    Matrix C = strassen(A, B);
    printMatrix(C);

    return 0;
}