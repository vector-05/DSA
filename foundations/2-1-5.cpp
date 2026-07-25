#include <iostream>
#include <vector>

/*
2.1-5: Binary Integer Addition
*/

/*
ALGORITHM
ADD-BINARY-INTEGERS (A, B, n)
    let c[0:n] be a new array
    carry = 0
    for i: 0 to (n-1)
        sum = A[i] + B[i] + carry
        C[i] = sum % 2
        carry = sum / 2
    C[n] = carry
    return C
*/

/*
INVARIANT
For every iteration i, the aubarray C[0:i-1] along with the carry bit 
contains the binary sum of A[0:i-1] and B[0:i-1].
*/

/*
PROOF
    INITIATION
        For i = 0, the subarray C[0:i-1] = C[0:-1], A[0:-1] and B[0:-1] are empty array's. Since carry = 0
        the invariant holds.
    MAINTENANCE
        For every iteration i, C[i] = A[i] + B[i] + carry, where carry is generated from i-1 iteration. Here carry is
        further updated for the i+1 iteration. Hence the invariant holds.
    TERMINATION
        For i = n, C[0:n-1] = A[0:n-1] + B[0:n-1] along with C[n] = carry, holds the sum of binary integers a + b
        and the loop terminates.
*/

std::vector<int> add_binary_int(std::vector<int> A, std::vector<int> B, int n) {
    int carry = 0;
    int sum = 0;
    std::vector<int> C(n+1);
    for (int i = 0; i < n; i++) {
        sum = A[i] + B[i] + carry;
        C[i] = sum % 2;
        carry = sum / 2;
    }
    C[n] = carry;
    return C;
}

int main() {
    int n = 3;
    std::vector<int> A(n);
    std::vector<int> B(n);
    A[0] = 0; A[1] = 1; A[2] = 1;
    B[0] = 1; B[1] = 0; B[2] = 0;
    std::vector<int> C = add_binary_int(A, B, n);
    return 0;
}