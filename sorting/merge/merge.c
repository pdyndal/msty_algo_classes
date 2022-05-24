//
// Created by w65510 on 24.05.2022.
//

#include <malloc.h>
#include "../../helpers/helpers.h"

void merge(int *arr, int left_index, int right_index, int size) {
    int *b = (int *)malloc(size * sizeof(int)); /* dynamic memory must be freed */
    int c = left_index;
    int p1, p2;
    p1 = left_index;
    p2 = ((left_index + right_index) / 2) + 1;
    while ((p1 < ((left_index + right_index) / 2) + 1) && (p2 < right_index + 1))
    {
        if (arr[p1] <= arr[p2])
        {
            b[c++] = arr[p1];
            p1++;
        }
        else
        {
            b[c++] = arr[p2];
            p2++;
        }
    }

    if (p2 == right_index + 1)
    {
        while ((p1 < ((left_index + right_index) / 2) + 1))
        {
            b[c++] = arr[p1];
            p1++;
        }
    }
    else
    {
        while ((p2 < right_index + 1))
        {
            b[c++] = arr[p2];
            p2++;
        }
    }

    for (c = left_index; c < right_index + 1; c++) arr[c] = b[c];

    free(b);
}

void merge_sort(int *arr, int left_index, int right_index, int size) {
    if (right_index - left_index == 1)
    {
        if (arr[left_index] > arr[right_index])
            swap(&arr[left_index], &arr[right_index]);
    }
    else if (left_index != right_index)
    {
        merge_sort(arr, left_index, (left_index + right_index) / 2, size);
        merge_sort(arr, ((left_index + right_index) / 2) + 1, right_index, size);
        merge(arr, left_index, right_index, size);
    }
}