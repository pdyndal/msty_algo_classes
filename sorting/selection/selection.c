//
// Created by w65510 on 24.05.2022.
//

#include "selection.h"
#include "../../helpers/helpers.h"

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr + i, arr + min_index);
        }
    }
}