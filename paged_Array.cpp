//
// Created by danielc on 26/02/17.
//
#include <iostream>
#include "paged_Array.h"
#include "slotManagr.h"

using namespace std;

paged_Array::paged_Array(){
    //constructor

};

void paged_Array::test(){

    cout << endl << "working " << endl;
}

int paged_Array::check_freeSlot (){
    int i;
    int result = -1;
    int ID;
    for (i=0 ; i<6 ; i++){
        ID= slotArray[i].get_ID();
        if (ID == -1){
            result =i ;
            break;
        }

    }

    return result;

}

int paged_Array::page_loader (int page_num){
    int freeslot;
    freeslot = check_freeSlot();
    int new_slot;
    if (freeslot != -1){
        slotArray[freeslot].pagetoMemory(page_num);
        new_slot = freeslot;
    }
    else{
        //algoritmo de remplazo
        slotArray[0].pagetoMemory(page_num);
        new_slot = 0;
    }
    return new_slot;
}