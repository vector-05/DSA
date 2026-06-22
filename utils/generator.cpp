// utils/generator.cpp
#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>

namespace fs = std::filesystem;

void generate_test_case(size_t size, const std::string& filename) {
    fs::create_directories("data");
    std::ofstream file("data/" + filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to create " << filename << "\n";
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 50000); // Random range

    for (size_t i = 0; i < size; ++i) {
        file << dis(gen) << (i == size - 1 ? "" : " ");
    }
    
    file.close();
    std::cout << "Generated " << size << " numbers in data/" << filename << "\n";
}

int main() {
    // Run this from your project root directory to create standard baseline inputs
    generate_test_case(100, "sample_100.txt");
    generate_test_case(1000, "sample_1000.txt");
    generate_test_case(10000, "sample_10000.txt");
    generate_test_case(50000, "sample_50000.txt");
    return 0;
}