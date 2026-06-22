// utils/logger.hpp
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

template<typename Func, typename T>
void benchmark(const std::string& algo_name, Func func, std::vector<T>& arr) {
    size_t input_size = arr.size();
    
    // Start high-precision steady clock
    auto start_time = std::chrono::steady_clock::now();
    
    // Execute the algorithm
    func(arr);
    
    // Stop clock
    auto end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    // Resolve directory paths safely relative to working directory
    fs::path log_dir = "../logs";
    fs::create_directories(log_dir);
    fs::path log_file = log_dir / "benchmark_log.csv";
    bool file_exists = fs::exists(log_file);

    // Write execution data to CSV
    std::ofstream file(log_file, std::ios::app);
    if (file.is_open()) {
        if (!file_exists) {
            file << "Timestamp,Algorithm,Input Size,Time Elapsed (sec)\n";
        }
        
        // Format timestamp
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");

        file << ss.str() << ","
             << algo_name << ","
             << input_size << ","
             << std::fixed << std::setprecision(6) << elapsed.count() << "\n";
        file.close();
    }

    std::cout << "[" << algo_name << "] Sorted " << input_size 
              << " elements in " << std::fixed << std::setprecision(6) 
              << elapsed.count() << " seconds. (Logged to CSV)\n";
}

#endif
// Note: Ensure your compiler flags support C++17 or above (-std=c++17) for <filesystem>