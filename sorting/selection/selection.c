//
// Created by w65510 on 24.05.2022.
//

#include <time.h>
#include <stdio.h>
#include "selection.h"
#include "../../helpers/helpers.h"

void selection_sort(int *arr, int size) {
    clock_t begin = clock();
    unsigned long long OPERATIONS = 3; // Read arr, size, initialize i

    for (int i = 0; i < size - 1; i++) { OPERATIONS += 3; // Compare i with size, reduce size by 1, increment i
        int min_index = i; OPERATIONS += 2; // Initialize min_index and j
        for (int j = i + 1; j < size; j++) { OPERATIONS += 2; // Compare j with size, increment j
            OPERATIONS += 1; // Compare index with j
            if (arr[min_index] > arr[j]) {
                OPERATIONS += 1; // Assign min index to j
                min_index = j;
            }
        }

        OPERATIONS += 1; // Compare index with i
        if (min_index != i) {
            swap(arr + i, arr + min_index); OPERATIONS += 3;// Initialize temp with arr + i, assign arr + min_index to first passed index, assign temp to arr + min_index
        }
    }

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nNumber of operations: %d\n", OPERATIONS);
    printf("\nFunction took (%f) cycles.\n", time_spent);
}