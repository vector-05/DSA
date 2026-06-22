// chapter_02/insertion_sort.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "../utils/logger.hpp"

// Reverse Insertion Sort by right-to-left algorithm

void insertion_sort_rev(std::vector<int>& A) { 

}

/*
PSEUDO CODE

*/

/*
INVARIANT

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