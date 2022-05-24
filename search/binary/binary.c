//
// Created by w65510 on 24.05.2022.
//

#include "binary.h"

int binary_search(const int *arr, int left_index, int right_index, int target_value) {
    int mid = left_index + (right_index - left_index) / 2;

    while (arr[mid] != target_value)
    {
        if (right_index <= left_index || right_index < 0)
            return -1;

        if (arr[mid] > target_value)
            // If element is smaller than middle
            right_index = mid - 1;
        else
            // Else element is in right subarray
            left_index = mid + 1;

        mid = left_index + (right_index - left_index) / 2;
    }

    // When element is not present in array
    return mid;
}