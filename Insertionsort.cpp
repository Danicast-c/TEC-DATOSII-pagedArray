//
// Created by danielc on 21/02/17.
//

#include "Insertionsort.h"
#include "paged_Array.h"


void insertion_Sort (paged_Array *arr, int length){
    int j, temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr->operator[](j) < arr->operator[](j-1)){
            temp = arr->operator[](j);
            arr->operator[](j) = arr->operator[](j-1);
            arr->operator[](j-1) = temp;
            j--;
        }
    }
}