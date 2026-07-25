#include <iostream>
#include <vector>

/*
2.2-2: Selection Sort
*/

/*
PSEUDO CODE
selection_sort (A, n)
    for i: 1 to n - 1
        min = i
        while j: i to n
            if A[j] < A[min]
                min = j
        swap A[i] and A[min]
*/

/*
INVARIANT
For every iteration i, subarray A[1:i-1] is always in sorted order with the smallest i-1 elements of A[1:n] 
*/

/*
PROOF
    INITIATION
        For i = 1, A[1:i-1] = A[1:0] which is an empty array, which is always sorted. Hence invariance holds.
    MAINTENANCE
        For every iteration i, we swap the smallest element of subarray A[i:n] with A[i], hence the invariance holds.
    TERMINATION
        Once i = n, the subarray A[1:n-1] is in sorted order. As the only remaining element, A[n] is the greatest number
        in the array A[1:n], the array A[1:n] is hence in sorted order and the loop terminates.
*/

/*
The algorithm only runs for n-1 times, and at the n-1 iteration, the n-1 smallest elements of the array A[1:n] are
in sorted order in the A[1:n-1] subarray, leaving only the greatest element, as the last element in A[n] position.
Hence the array is sorted in only n-1 iteraations.
*/

/*
Best Case - O(n^2)
Worst Case - O(n^2) [as the loop still needs to run n times to check for smallest elements]
*/

std::vector<int> selection_sort(std::vector<int> A, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j <n; j++) {
            if (A[j] < A[min]) {
            min = j;
            }
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    return A;
}

int main() {
    int n = 5;
    std::vector<int> arr = {4, 6, 3, 5, 2};
    std::vector<int> sorted_arr = selection_sort(arr, n);
    std::cout << "Sorted array: ";
    for (int val : sorted_arr) {
        std::cout << val << " ";
    }
    return 0;
}