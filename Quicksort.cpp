//
// Created by danielc on 21/02/17.
//

#include <iostream>
#include "paged_Array.h"


using namespace std;

void quickSort(paged_Array *arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr->operator[]((left + right) / 2);
    /* partition */
    while (i <= j) {
        while (arr->operator[](i) < pivot)
            i++;
        while (arr->operator[](j) > pivot)
            j--;
        if (i <= j) {
            tmp = arr->operator[](i);
            arr->operator[](i) = arr->operator[](j);
            arr->operator[](j) = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}