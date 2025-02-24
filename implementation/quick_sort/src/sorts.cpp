// Author: Hoai Dinh

#include <vector>

#include "sorts.hpp"

// Allows the use of random numbers
std::random_device rd;
std::mt19937 gen(rd());

int qsort_partition(int array[], int left, int right, bool random) {
    std::uniform_int_distribution<> distrib(left, right);
    if(random) {
        int switch_index = distrib(gen);
        SWAP(array[switch_index], array[right]);
    }
    int pivot_value = array[right];
    int i = left - 1;
    int j;

    for(j = left; j < right; j++) {
        if(array[j] <= pivot_value) {
            i++;
            SWAP(array[i], array[j]);
        }
    }
    SWAP(array[i+1], array[right]);

    return i+1;
}

void quick_sort(int array[], int left, int right, bool random) {
    if(left < right) {
        int mid = qsort_partition(array, left, right, random);
        quick_sort(array, left, mid-1, random);
        quick_sort(array, mid+1, right, random);
    }
}

void merge(int array[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    std::vector<int> left_array = {};
    std::vector<int> right_array = {};

    int i, j;
    for(i = 0; i < left_size; i++)
        left_array.push_back(array[i + left]);

    for(j = 0; j < right_size; j++)
        right_array.push_back(array[j + mid + 1]);

    i = 0;
    j = 0;
    int k = left;
    while(i < left_size && j < right_size) {
        if(left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while(i < left_size) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while(j < right_size) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void insertion_sort(int array[], int size) {
    int i = 0;
    for(i = 1; i < size; i++) {
        int key = array[i];
        int j = i-1;

        while(j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void selection_sort(int array[], int size) {
    int i = 0;
    int j = 0;
    for(i = 0; i < size-1; i++) {
        int min_idx = i;
        for(j = i+1; j < size; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            SWAP(array[i], array[min_idx]);
        }
    }
}

void bubble_sort(int array[], int size) {
    bool did_swap = false;

    int i = 0;
    int r = size; // remaining elements to be sorted
    do {
        did_swap = false;
        for(i = 1; i < r; i++) {
            if(array[i-1] > array[i]) {
                SWAP(array[i-1], array[i]);
                did_swap = true;
            }
        }
        r--; // At least 1 element is palced in the correct spot after swaping
    } while(did_swap);
}
