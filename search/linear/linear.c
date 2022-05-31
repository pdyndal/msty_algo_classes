//
// Created by w65510 on 24.05.2022.
//

#include <time.h>
#include <stdio.h>
#include "linear.h"

int linear_search(int arr[], int size, int target_value) {
    clock_t begin = clock();
    unsigned long long OPERATIONS = 0;

    OPERATIONS += 2;
    if (target_value == arr[size - 1]) {
        OPERATIONS += 1;
        clock_t end = clock();
        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
        printf("\nNumber of operations: %d\n", OPERATIONS);
        printf("\nFunction took (%f) cycles.\n", time_spent);
        return size - 1;
    }

    int temp = arr[size - 1]; OPERATIONS += 2;
    arr[size - 1] = target_value; OPERATIONS += 2;

    int i = 0; OPERATIONS += 1;
    while (arr[size - 1] != arr[i]) { OPERATIONS += 2;
        i++; OPERATIONS += 1;
    }

    arr[size - 1] = temp; OPERATIONS += 2;

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nNumber of operations: %d\n", OPERATIONS);
    printf("\nFunction took (%f) cycles.\n", time_spent);

    return i != size - 1 ? i : -1;
}