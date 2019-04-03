cmake_minimum_required(VERSION 3.5.1)
project(parallel_solutions)

set(CMAKE_CXX_STANDARD 14)

set(additional_files additionals/solutions.h additionals/time_measure.h)
add_executable(consistent_program consistent.cpp ${additional_files})
add_executable(parallel_program parallel.cpp ${additional_files})