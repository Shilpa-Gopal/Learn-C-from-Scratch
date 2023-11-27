#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();
    double elapsed_time();
    void reset();

private:
    std::chrono::steady_clock::time_point start_time;
};

#endif // TIMER_H
