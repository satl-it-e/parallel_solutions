//
// Created by Sofiia Tesliuk on 2019-04-03.
//

#ifndef PARALLEL_SOLUTIONS_SOLUTIONS_H
#define PARALLEL_SOLUTIONS_SOLUTIONS_H

int min_value = 1;
int max_value = 200;

#include <mutex>

std::mutex mutex;


int count_number_of_solutions(int min_w, int max_w) {
    int number_of_solutions = 0;
    int w, x, y, z;

    for (w = min_w; w <= max_w; w++) {
        for (x = w; x <= max_value; x++) {
            for (y = w + 1; y <= max_value; y++) {
                for (z = y; z <= max_value; z++) {
                    if (((w * w * w) + (x * x * x)) == ((y * y * y) + (z * z * z))) {
                        number_of_solutions++;
//                        std::cout << w << "^3 + " << x << "^3 = " << y << "^3 + " << z << "^3" << std::endl;
                    }
                }
            }
        }
    }

    return number_of_solutions;
}


int count_number_of_solutions_result_by_reference(int* result, int min_w, int max_w){
    mutex.lock();
    *result += count_number_of_solutions(min_w, max_w);
    mutex.unlock();

    return 0;
}

#endif //PARALLEL_SOLUTIONS_SOLUTIONS_H
