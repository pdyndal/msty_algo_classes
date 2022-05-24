#include <stdio.h>
#include <stdlib.h>

#include "helpers/helpers.h"

#include "sorting/bubble/bubble.h"
#include "sorting/selection/selection.h"
#include "sorting/merge/merge.h"

#include "search/binary/binary.h"
#include "search/linear/linear.h"

int main() {
    const int ARRAY_SIZE = 10;

    srand(NULL);

    int *arr_random = generate_data_randomized(ARRAY_SIZE);

    display(arr_random, ARRAY_SIZE);

//    bubble_sort(arr_random, ARRAY_SIZE);
//    selection_sort(arr_random, ARRAY_SIZE);
//    merge_sort(arr_random, 0, ARRAY_SIZE - 1, ARRAY_SIZE);

    display(arr_random, ARRAY_SIZE);

//    int found = binary_search(arr_random, 0, ARRAY_SIZE - 1, 40);
    int found = linear_search(arr_random, ARRAY_SIZE, 40);

    printf("got(%d) expected_number(40)", found);
//    free(arr_random);

    return 0;
}
