//
// Created by danielc on 26/02/17.
//
#include <iostream>
#include "paged_Array.h"
#include "slotManagr.h"

using namespace std;


paged_Array::paged_Array(){
    //constructor

}



int& paged_Array::operator[](const int index) {

    int result;
    cout << " se ingreso como index: " << index << endl;
    int pageID = index / 256;
    int position_in_page = index%256;
    cout << " se ingreso como page id: " << pageID << endl;
    int page_loaded = check_Page(pageID);
    if (page_loaded != -1) {
        result= slotArray[page_loaded].getPosition(position_in_page); // por que la pagina si esta cargada
    }
    else {
        int nueva_pagina = page_loader(pageID);
        cout << " paso por el else" << endl;
        result= slotArray[nueva_pagina].getPosition(position_in_page); // por que ya la pagina ya ha sido cargada
        return result;
    }
}


int paged_Array::check_Page(int pageID){
    int i;
    int result = -1;
    for (i=0;i<6;i++){
        if (slotArray[i].get_ID() == pageID){
            result = i;
            break;
        }
    }
    return result;
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
        slotArray[freeslot].savetoMemory(slotArray[freeslot].get_ID());
        slotArray[freeslot].pagetoMemory(page_num);
        new_slot = freeslot;
    }
    else{
        //algoritmo de remplazo
        slotArray[0].savetoMemory(slotArray[freeslot].get_ID());
        slotArray[0].pagetoMemory(page_num);
        new_slot = 0;
    }
    return new_slot;
}