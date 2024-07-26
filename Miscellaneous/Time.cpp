#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include<windows.h>

int main() {
    // 1. Get current time point
    auto now = std::chrono::system_clock::now();
    
    // 2. Convert to C style     time_t
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    
    // 3. Format and print current time
    std::cout << "Current time: " << std::put_time(std::localtime(&now_c), "%F %T") << std::endl;

    // 4. Measure elapsed time
    auto start = std::chrono::high_resolution_clock::now();
    // Simulate some work
    Sleep(5000);
    std::chrono::_V2::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    //or std::chrono::duration<double> duration = end - start;
    std::cout << "Elapsed time: " << duration.count() << " ms" << std::endl;
    
    // 5. Using C-style time functions
    std::time_t t = std::time(nullptr);
    std::cout << "Current time (C-style): " << std::ctime(&t);

    // 6. Get time components using struct tm (a struct with useful clock attributes.)
    //can't create with c++ time point, convert it to time_t first, then pass that as reference to localtime()
    std::tm* now_tm = std::localtime(&t);
    std::cout << "Current year: " << now_tm->tm_year + 1900 << std::endl;
    std::cout << "Current month: " << now_tm->tm_mon + 1 << std::endl;
    std::cout << "Current day: " << now_tm->tm_mday << std::endl;

    // 7. Add duration to time point
    auto future = now + std::chrono::hours(24);
    std::time_t future_c = std::chrono::system_clock::to_time_t(future);
    std::cout << "24 hours from now: " << std::put_time(std::localtime(&future_c), "%F %T") << std::endl;

    return 0;
}