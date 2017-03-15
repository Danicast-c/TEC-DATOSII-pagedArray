//
// Created by danielc on 15/03/17.
//

#include "Selectionsort.h"
#include <iostream>
#include "paged_Array.h"


using namespace std;

void selectionSort(paged_Array *arr, int n) {
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr->operator[](j) < arr->operator[](minIndex))
                minIndex = j;
        if (minIndex != i) {
            tmp = arr->operator[](i);
            arr->operator[](i) = arr->operator[](minIndex);
            arr->operator[](minIndex) = tmp;
        }
    }
}