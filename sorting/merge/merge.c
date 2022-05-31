//
// Created by w65510 on 24.05.2022.
//

#include <malloc.h>
#include <time.h>
#include <stdio.h>
#include "../../helpers/helpers.h"

unsigned long long OPERATIONS = 0;

void merge(int *arr, int left_index, int right_index, int size) {
    OPERATIONS += 4; // Read params?

    OPERATIONS += 4; // Initialize b, c, p1, p2
    int *b = (int *) malloc(size * sizeof(int)); /* dynamic memory must be freed */
    int c = left_index;
    int p1, p2;
    p1 = left_index;
    p2 = ((left_index + right_index) / 2) + 1;
    OPERATIONS += 3; // Division, two additions

    while ((p1 < ((left_index + right_index) / 2) + 1) && (p2 < right_index + 1)) { OPERATIONS += 7;
        OPERATIONS += 1; // Check if arr[p1] <= arr[p2]
        if (arr[p1] <= arr[p2]) {
            OPERATIONS += 3; // Incrementing c and p1, assigning arr[p1] to b[c++]
            b[c++] = arr[p1];
            p1++;
        } else {
            OPERATIONS += 3; // Incrementing c and p2, assigning arr[p2] to b[c++]
            b[c++] = arr[p2];
            p2++;
        }
    }

    OPERATIONS += 2; // Add 1 to right_index and check if equal with p2
    if (p2 == right_index + 1) {
        while ((p1 < ((left_index + right_index) / 2) + 1)) { OPERATIONS += 4;
            OPERATIONS += 3; // Incrementing c and p1, assigning arr[p1] to b[c++]
            b[c++] = arr[p1];
            p1++;
        }
    } else {
        while ((p2 < right_index + 1)) { OPERATIONS += 2;
            OPERATIONS += 3; // Incrementing c and p2, assigning arr[p2] to b[c++]
            b[c++] = arr[p2];
            p2++;
        }
    }


    OPERATIONS += 1; // Assign left_index to c
    for (c = left_index; c < right_index + 1; c++) { OPERATIONS += 3; // Compare c with right_index, add to right index, increment c
        arr[c] = b[c]; OPERATIONS += 1; // Assign this
    }

    free(b);
}

void merge_sort(int *arr, int left_index, int right_index, int size) {
    OPERATIONS += 4; // Read params?

    OPERATIONS += 1; // Compare if difference between indexes is 1
    if (right_index - left_index == 1) {
        OPERATIONS += 1; // Compare if value in arr[left_index] is greater than arr[right_index]
        if (arr[left_index] > arr[right_index])
            swap(&arr[left_index], &arr[right_index]);
    } else if (left_index != right_index) {
        OPERATIONS += 1; // Compare if indexes are equal
        merge_sort(arr, left_index, (left_index + right_index) / 2, size);
        merge_sort(arr, ((left_index + right_index) / 2) + 1, right_index, size);
        merge(arr, left_index, right_index, size);
    }
}

void init_merge_sort(int *arr, int size) {
    clock_t begin = clock();

    OPERATIONS += 2; // Read arr and size
    merge_sort(arr, 0, size - 1, size);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nNumber of operations: %d\n", OPERATIONS);
    printf("\nFunction took (%f) cycles.\n", time_spent);
}