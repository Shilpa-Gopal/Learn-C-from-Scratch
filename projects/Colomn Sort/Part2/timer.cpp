#include "timer.h"

Timer::Timer() {
    start_time = std::chrono::steady_clock::now();
}

double Timer::elapsed_time() {
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();
}

void Timer::reset() {
    start_time = std::chrono::steady_clock::now();
}
