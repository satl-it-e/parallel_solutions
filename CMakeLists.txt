cmake_minimum_required(VERSION 3.5.2)
project(parallel_solutions)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
#set(additional_files additionals/solutions.h)
add_executable(consistent_program consistent.cpp)
add_executable(parallel_program parallel.cpp)
