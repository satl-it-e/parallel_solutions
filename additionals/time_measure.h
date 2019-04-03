//
// Created by Sofiia Tesliuk on 2019-04-03.
//

#ifndef PARALLEL_SOLUTIONS_TIME_MEASURE_H
#define PARALLEL_SOLUTIONS_TIME_MEASURE_H

#include <chrono>
#include <atomic>


inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

#endif //PARALLEL_SOLUTIONS_TIME_MEASURE_H
