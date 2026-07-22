#include <iostream>
#include <vector>

/*
2.1-4: Searching Problem - Linear Search
*/

/*
PSEUDO CODE
linear_search(A, n, x)
    for i = 1 to n
        if A[i] == x
            return i
    return Nil
*/

/*
INVARIANT
For every iteration i, key x is not in subarray A[1:i-1]
*/

/*
PROOF
    INITIATION
        For i = 1, we get A[1:i-1] = A[1:1-1] = A[1:0] which is an empty array. As key x dosent not exist
        in empty array, the invariance holds.
    MAINTENANCE
        Assume the invariant holds at the start of iteration i (x is not in A[1 : i - 1]).
        If A[i] != x, the loop increments i to i + 1. Since x was not in A[1 : i - 1] 
        and A[i] != x, x is not in A[1 : i]. Thus, the invariant is preserved for i + 1.    
    TERMINATION
        The loop terminates in one of two ways:
            Found: A[i] == x. 
                The loop terminates early and returns i. Since x was not in A[1:i-1], i is the first occurrence 
                of x.
            Not Found: 
                The loop finishes all iterations, so i = n + 1. By the loop invariant, x does not appear in 
                A[1 : (n+1)-1] = A[1:n]. The procedure executes line 5 and returns NIL.
    */

int linear_search(std::vector<int>& A, int x) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i;
        }
    }
    return NULL;
}

int main() {

    std::vector<int> arr;
    arr[0] = 4;
    arr[1] = 6;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    int key = 5;
    int key_position = linear_search(arr, key);
    std::cout << "Key Position" << key_position;
    return 0;
}