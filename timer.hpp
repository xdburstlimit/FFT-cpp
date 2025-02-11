#ifndef _TIMER_
#define _TIMER_

#include <memory>
#include <chrono>
#include <iostream>

class Timer
{
    public:
        Timer();
        ~Timer();
        void Stop();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

#endif