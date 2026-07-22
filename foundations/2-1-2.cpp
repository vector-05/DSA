#include <iostream>
#include <vector>

/*
ALGORITHM
sum_array(A, n):
    sum = 0
    for i: 1 to n
        sum = sum + A[n]
    return sum
*/

/*
INVARIANT
    In every iteration, the sum variable stores the value of sum of all elements in A[1:i-1]
*/

/*
PROOF
    INITIALIZATION:
        For first (leftmost) element, we look at the elements in A[1:i-1] = A[1:1-1] = A[1:0]
        which is empty array, hence has form sum = 0. We set this condition initially, hence it is true.
    MAINTENANCE:
        For every iteration i, we add the element A[i] back to the sum variable, which preserves the
        invariant for next index.
    TERMINATION:
        Once i = n+1, we get sum of elements A[1:n] and the loop terminates
*/

int sum_array(std::vector<int>& A, int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {

    int n = 5;
    std::vector<int> arr(n);
    arr[0] = 4;
    arr[1] = 6;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    int sum = sum_array(arr, n);
    std::cout << "Sum: " << sum;

    return 0;
}