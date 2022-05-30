//
// Created by w65510 on 24.05.2022.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void display(const int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int get_data() {
    int input;
    scanf("%d", &input);

    return input;
}

int *generate_data_sorted_ascending(unsigned int size) {
    int *arr = malloc(size * sizeof(int));

    if(size == 0) return arr;

    arr[0] = rand() % 11;

    for (int i = 1; i < size; ++i) {
        arr[i] =  arr[i-1] + (rand() % 11);
    }

    return arr;
}

int *generate_data_sorted_descending(unsigned int size) {
    int *arr = malloc(size * sizeof(int));

    if(size == 0) return arr;

    arr[0] = rand() % 199;

    for (int i = 1; i < size; ++i) {
        arr[i] =  arr[i-1] - (rand() % 11);
    }

    return arr;
}

int *generate_data_randomized(unsigned int size){
    int *arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 51;
    }

    return arr;
}