//
// Created by w65510 on 24.05.2022.
//

#include "linear.h"

int linear_search(int arr[], int size, int target_value) {
    if (target_value == arr[size - 1]) {
        return size - 1;
    }

    int temp = arr[size - 1];
    arr[size - 1] = target_value;

    int i = 0;
    while (arr[size - 1] != arr[i]) {
        i++;
    }

    arr[size - 1] = temp;

    return i != size - 1 ? i : -1;
}