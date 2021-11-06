#include "timer.h"

void Timer::start()
{
    start_time = clock::now();
}

double Timer::stop()
{
    using std::chrono::duration_cast;
    using std::chrono::seconds;

    end_time = clock::now();

    duration sec = duration_cast<seconds>(end_time - start_time);

    return sec.count();
}
