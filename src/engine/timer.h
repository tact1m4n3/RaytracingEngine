#pragma once

#include <chrono>

class Timer
{
    using clock = std::chrono::high_resolution_clock;
    using duration = std::chrono::duration<double>;
    using time_point = std::chrono::time_point<clock>;
private:
    time_point start_time;
    time_point end_time;
public:
    Timer() = default;
    ~Timer() = default;

    void start();
    double stop();
};
