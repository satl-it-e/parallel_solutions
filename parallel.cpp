//
// Created by Sofiia Tesliuk on 2019-04-02.
//

#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <sstream>
#include "additionals/time_measure.h"
#include "additionals/solutions.h"

int main(int argc, char *argv[]){
    int number_of_threads = 0;
    std::vector<std::thread> threads;
    int whole_number_of_solutions = 0;


    if (argc < 2) {
        number_of_threads = 4;
    } else{
        std::istringstream iss( argv[1] );
        int val;

        if (iss >> val)
        {
            number_of_threads = val;
        } else{
            std::cout << "Invalid argument. Should be one integer -- number of used threads." << std::endl;
        }
    }

    int from;
    int till;

    for (int i = 0; i < number_of_threads; i++){
        from = ((int) ((((float) i) / number_of_threads) * max_value)) + 1;
        till = (int) ((((float) (i + 1)) / number_of_threads) * max_value);
        std::thread new_thread(count_number_of_solutions_result_by_reference,
                &whole_number_of_solutions, from, till);
        threads.push_back(std::move(new_thread));
    }

    auto start = get_current_time_fenced();
    for (auto &current_thread: threads){
        current_thread.join();
    }
    auto finish = get_current_time_fenced();

    std::ofstream out_file("../results/parallel_results.txt", std::ios_base::app);
    out_file << "Number of threads: " << number_of_threads << "\nNumber of solutions: " << whole_number_of_solutions
             << "\nTotal time: " << to_us(finish - start) << " microseconds" <<  std::endl;
    out_file.close();

    return 0;
}