#include <iostream>
#include <vector>

/*
2.3-5: Recursive Insertion Sort
*/

/*
PSEUDO CODE
RECURSIVE-INSERTION-SORT(A, n)
if n > 1
    RECURSIVE-INSERTION-SORT(A, n - 1)
    key = A[n]
    j = n - 1
    while j > 0 and A[j] > key
        A[j + 1] = A[j]
        j = j - 1
    A[j + 1] = key
*/

/*
Worst Case Running Time
T(n) = T(n-1) + O(n^2)
*/

int main() {
    return 0;
}