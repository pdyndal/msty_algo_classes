//
// Created by w65510 on 24.05.2022.
//

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "bubble.h"
#include "../../helpers/helpers.h"

void bubble_sort(int *arr, int size) {
    clock_t begin = clock();
    unsigned long long OPERATIONS = 3; // Read arr, size, initialize i

    for (int i = 0; i < size - 1; i++) { OPERATIONS += 3; // Compare i with size, reduce size by 1, increment i
        bool swapped = false; OPERATIONS += 2; // Initialize swapped, Initialize j

        for (int j = 0; j < size - 1 - i; j++) { OPERATIONS += 3;// Compare j with size, reduce size by 1, increment j
            OPERATIONS += 2;// Compare 2 indexes of arr, increase j by 1;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); OPERATIONS += 3; // Initialize temp with arr[j], assign arr[j+1] to first passed index, assign temp to arr[j]
                swapped = true; OPERATIONS += 1;// Assign to true
            }
        }

        OPERATIONS += 1; // Check if swapped is false
        if (!swapped) {
            break;
        }
    }

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nNumber of operations: %d\n", OPERATIONS);
    printf("\nFunction took (%f) cycles.\n", time_spent);
}