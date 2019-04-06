//
// Created by Sofiia Tesliuk on 2019-04-02.
//

#include <iostream>
#include <fstream>
#include "additionals/time_measure.h"
#include "additionals/solutions.h"


int main(){
    auto search_start = get_current_time_fenced();
    // The whole range of w
    int number_of_solutions = count_number_of_solutions(min_value, max_value);
    auto search_finish = get_current_time_fenced();

    std::ofstream out_file("results/consistent_results.txt", std::ios_base::app);

    if (out_file.good()) {
        out_file << "Number of solutions: " << number_of_solutions
                 << "\nTotal time: " << to_us(search_finish - search_start) << " microseconds" << std::endl;
        out_file.close();
    } else{
        std::cout << "Something gone wrong with file." << std::endl;
        return -1;
    }
    return 0;
}
