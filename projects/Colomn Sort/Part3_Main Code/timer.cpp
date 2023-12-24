#include "timer.h"

Timer::Timer() {
    start_time = clock();
}

double Timer::elapsed_time() {
    clock_t end_time = clock();
    return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}

void Timer::reset() {
    start_time = clock();
}
