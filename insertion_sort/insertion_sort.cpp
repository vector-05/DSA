// chapter_02/insertion_sort.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "../utils/logger.hpp"

// Standard CLRS Insertion Sort logic adapted to 0-indexed vectors
void insertion_sort(std::vector<int>& A) {
    int n = A.size();
    for (int j = 1; j < n; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

int main() {
// Look at the current path, or fall back to absolute tracking
    fs::path current_dir = fs::current_path();
    fs::path input_path = "../data/sample_10000.txt";

    // Fallback check: If run from root, look directly into data/
    if (current_dir.filename() == "clrs-workspace") {
        input_path = "data/sample_10000.txt";
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

    benchmark("Insertion Sort", insertion_sort, arr);
    return 0;
}