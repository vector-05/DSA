// chapter_02/insertion_sort.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "../utils/logger.hpp"

// Reverse Insertion Sort by changing condition in Insertion Sort Algo

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

int main() {
// Look at the current path, or fall back to absolute tracking
    fs::path current_dir = fs::current_path();
    fs::path input_path = "../data/sample_10000.txt"; // modify sample file path to necessity

    // Fallback check: If run from root, look directly into data/
    if (current_dir.filename() == "DSA") {
        input_path = "data/sample_10000.txt"; // modify sample file path to necessity
    }

    std::ifstream input_file(input_path);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not find data file at: " << fs::absolute(input_path) << "\n";
        std::cerr << "Current working directory is: " << current_dir << "\n";
        return 1;
    }

    std::vector<int> arr;
    int num;
    while (input_file >> num) {
        arr.push_back(num);
    }
    input_file.close();

    benchmark("Insertion Sort Rev", insertion_sort_rev, arr); 
    return 0;
}