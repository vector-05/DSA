#include <iostream>
#include <vector>

/*
2.1-3: Reverse Insertion Sort
*/

/*
PSEUDO CODE
for i = 2 to n                          // Running through all elements
    key = A[i]                          // Selecting i element
    j = i - 1                           // inner loop variable
    while j > o and A[j] < key          // running inner loop for all elements left of i and the sorting condition
        A[j+1] = A[j]                   // swapping indexes
        j = j - 1                       // loop variable decrement
    A[j + 1] = key                      // inner loop stops when either sorting condition is false or we reach end of the left
                                            elements, the value of which is placed in j, which is where we then swap the element i
*/

/*
INVARIANT
For every iteration, A[1: i-1] is always in sorted (reverse) order
*/

/*
PROOF
    INITIATION
        First element is always in sorted order.
    MAINTENANCE
        For every iteration, we sort the array A[1:i-1] in reverse order hence preserving invariant
        for the next iteration.
    TERMINATION
        When i = n+1, the array A[1:n] is sorted in reverse order and loop terminates.
*/

void insertion_sort_rev(std::vector<int>& A) { 
    int n = A.size();
    for (int i = 1; i < n; i++) {               // i != 0: as first element is always sorted (initialization condition)
        int key = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] < key)) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main() {

    std::vector<int> arr;
    arr[0] = 4;
    arr[1] = 6;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    insertion_sort_rev(arr);
    
    return 0;
}