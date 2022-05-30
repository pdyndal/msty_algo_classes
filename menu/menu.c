//
// Created by w65510 on 30.05.2022.
//

#include <stdlib.h>
#include <stdio.h>

#include "../helpers/helpers.h"

#include "../sorting/bubble/bubble.h"
#include "../sorting/selection/selection.h"
#include "../sorting/merge/merge.h"

#include "../search/binary/binary.h"
#include "../search/linear/linear.h"

int get_data_length() {
    printf("Input length of data array.\n\n");

    int array_size = get_data();

    return array_size;
}

int *get_data_type(unsigned int data_size) {
    printf("Select type of generated data: \n"
           "1. Randomly generated not sorted\n"
           "2. Randomly generated sorted ascending\n"
           "3. Randomly generated sorted descending\n\n");

    int chosen_data_type = get_data();
    int *arr_to_return = NULL;

    if (chosen_data_type > 3 || chosen_data_type < 1) {
        perror("Invalid value passed! ");
    } else if (!chosen_data_type) {
        perror("Invalid value passed!");
    }

    switch (chosen_data_type) {
        case 1:
            arr_to_return = generate_data_randomized(data_size);
            break;
        case 2:
            arr_to_return =  generate_data_sorted_ascending(data_size);
            break;
        case 3:
            arr_to_return =  generate_data_sorted_descending(data_size);
            break;
        default:
            perror("Invalid value passed!");
    }

    return arr_to_return;
}

void get_algorithm(int *arr, int size) {
    printf("Select algorithm: \n"
           "--- SORTING ---\n"
           "1. Bubble sort\n"
           "2. Selection sort\n"
           "3. Merge sort\n"
           "--- SEARCH ---\n"
           "4. Binary search\n"
           "5. Linear search\n\n");

    int selected_algorithm = get_data();

    int searched_value;
    int position_in_array;

    switch (selected_algorithm) {
        case 1:
            bubble_sort(arr, size);
            break;
        case 2:
            selection_sort(arr, size);
            break;
        case 3:
            merge_sort(arr, 0, size - 1, size);
            break;
        case 4:
            printf("Input selected value in array. \n");
            searched_value = get_data();
            position_in_array = binary_search(arr, 0, size - 1, searched_value);
            printf("Found number (%d) in position (%d). \n\n", searched_value, position_in_array);
            break;
        case 5:
            printf("Input selected value in array.\n");
            searched_value = get_data();
            position_in_array = linear_search(arr, size, searched_value);
            printf("Found number (%d) in position (%d). \n\n", searched_value, position_in_array);
            break;
        default:
            perror("Invalid value");
            break;
    }
}

int show_menu() {
    int data_length = get_data_length();
    int *data = get_data_type(data_length);

    printf("Generated array: \n");
    display(data, data_length);
    printf("\n");

    get_algorithm(data, data_length);

    printf("Array after algorithm array: \n");
    display(data, data_length);
    printf("\n");

    free(data);
}