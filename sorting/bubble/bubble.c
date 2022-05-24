//
// Created by w65510 on 24.05.2022.
//

#include <stdbool.h>
#include "bubble.h"
#include "../../helpers/helpers.h"

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) { /* for each array index */
        bool swapped = false; /* flag to check if any changes had to be made */
        /* perform iterations until no more changes were made or outer loop
           executed for all array indices */
        for (int j = 0; j < size - 1 - i; j++) { /* for each element in the array */
            if (arr[j] > arr[j + 1]) { /* if the order of successive elements needs update */
                swap(&arr[j], &arr[j + 1]);
                swapped = true; /* set flag */
            }
        }
        if (!swapped) {
            /* since no more updates we made, the array is already sorted
                this is an optimization for early termination */
            break;
        }
    }
}
