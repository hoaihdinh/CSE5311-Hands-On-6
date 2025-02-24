// Author: Hoai Dinh

#include <chrono>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>

#include "sorts.hpp"

std::string print_array(int array[], int size) {
    std::stringstream ss;

    ss << "{";
    for(int i = 0; i < size; i++) {
        ss << " " << array[i] << ((i != size-1) ? ", " : "");
    }
    ss << "}";

    return ss.str();
}

void copy_array(int dest[], const int src[], int size) {
    for(int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void benchmark_qsorts(int array[], int size, int cur_num, std::string array_type) {
    int dupe_array[size];
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double, std::milli> time_difference;

    std::string sort_names[] = {"Quick Sort (no random pivot)", "Quick Sort (random pivot)"};
    std::cout << "===== " << array_type << " BENCHMARK " << cur_num << " =====\n"
              << ((size <= 10) ? "Array: " + print_array(array, size) + "\n" : "")
              << "Size: " << size << "\n"
              << std::endl;
    
    for(int i = 0; i < 2; i++) {
        copy_array(dupe_array, array, size);
        std::cout << "--- " << sort_names[i] << " ---" << std::endl;
        start = std::chrono::high_resolution_clock::now();
        quick_sort(dupe_array, 0, size-1, ((i+1) % 2) == 0);
        end = std::chrono::high_resolution_clock::now();
        time_difference = end - start;
        std::cout << ((size <= 10) ? "Output: " + print_array(dupe_array, size) + "\n" : "")
                  << "Time to execute: " << time_difference.count() << "ms"
                  << std::endl;
    }
    std::cout << "\n\n";
}

int main() {
    int array_sizes[] = {
        #include "../array_data/array_sizes.txt"
    };
    int all_arrays[][11][1000] = {
        {
            #include "../array_data/optimal_qsort_arrays.txt"
        },
        {
            #include "../array_data/worst_qsort_arrays.txt"
        },
        {
            #include "../array_data/uniform_rand_dist_array.txt"
        },
    };

    std::string array_tags[] = {"OPTIMAL ARRAY", "WORST-CASE ARRAY", "UNIFORM RAND ARRAY"};
    for(int i = 0; i < 2; i++) {
        int j = 0;
        while(array_sizes[j] != -1) {
            benchmark_qsorts(all_arrays[i][j], array_sizes[j], j+1, array_tags[i]);
            j++;
        }
    }

    return 0;
}
