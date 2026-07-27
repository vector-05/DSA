#include <iostream>
#include <vector>

/*
2.3-6: Binary Search
*/

/*
PSEUDO CODE
BINARY_SEARCH(A)
    while low <= high
        mid = floor((low + high) / 2)
        if A[mid] == x
            return mid
        else if A[mid] > x
            high = mid - 1
        else
            low = mid + 1
    return NIL
*/

/*
Worst Case Run time
    Worst Case
        Value Not Present
    Run Time
        In every iteration, the size of the array is halved. In worst case the size falls down to 1.
        i.e.    n/(2^k) = 1
        =>      n = 2^k
        =>      k = lgn
        Hence the time complexity comes to be lgn
*/

int main() {
    return 0;
}