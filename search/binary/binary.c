//
// Created by w65510 on 24.05.2022.
//

#include <time.h>
#include <stdio.h>
#include "binary.h"

int binary_search(const int *arr, int left_index, int right_index, int target_value) {
    clock_t begin = clock();
    unsigned long long OPERATIONS = 0;

    int mid = left_index + (right_index - left_index) / 2; OPERATIONS += 4;

    while (arr[mid] != target_value) { OPERATIONS += 3;
        if (right_index <= left_index || right_index < 0) {
            clock_t end = clock();
            double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
            printf("\nNumber of operations: %d\n", OPERATIONS);
            printf("\nFunction took (%f) cycles.\n", time_spent);
            return -1;
        }

        OPERATIONS += 1;
        if (arr[mid] > target_value) {
            right_index = mid - 1;
            OPERATIONS += 2;
        } else {
            left_index = mid + 1;
            OPERATIONS += 2;
        }

        mid = left_index + (right_index - left_index) / 2;
        OPERATIONS += 4;
    }

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nNumber of operations: %d\n", OPERATIONS);
    printf("\nFunction took (%f) cycles.\n", time_spent);
    return mid;
}