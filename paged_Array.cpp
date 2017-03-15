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



int &paged_Array::operator[](int index) {

    int result;
    int pageID = index / 256;
    int position_in_page = index%256;
    int page_loaded = check_Page(pageID);
    if (page_loaded != -1) {

        result=page_loaded;
    }
    else {
        int nueva_pagina = page_loader(pageID);
        result = nueva_pagina;
        slotArray[result].set_veces_usado(0);
    }
    slotArray[result].suma_veces_usado();
    return slotArray[result].Array[position_in_page];
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
    //cout << endl<< "freeslot es: "<< freeslot << endl;
    int new_slot;
    if (freeslot != -1){
       slotArray[freeslot].savetoMemory(slotArray[freeslot].get_ID());
       // slotArray[freeslot].savetoMemory(page_num);
        //cout << "llama savetomemory: "<< slotArray[freeslot].get_ID()<<endl;
        slotArray[freeslot].pagetoMemory(page_num);
        new_slot = freeslot;
    }
    else{
       int mas_usada1= mas_usada();//algoritmo de remplazo
       // cout << "mas usada= "<< mas_usada1 << endl;
       slotArray[mas_usada1].savetoMemory(slotArray[mas_usada1].get_ID());
        //slotArray[freeslot].savetoMemory(page_num);
      // cout << "llama savetomemory: "<< slotArray[freeslot].get_ID()<<endl;
        slotArray[mas_usada1].pagetoMemory(page_num);
        new_slot = mas_usada1;
    }
    return new_slot;
}

int paged_Array::mas_usada() {
    int veces=0;
    int result = 0;
    int i;
    for (i=0;i<6;i++){
        if (slotArray[i].get_veces_usado() > veces){
            veces=slotArray[i].get_veces_usado();
            result=i;
        }
    }
    return result;

}

void paged_Array::saveAll (){
    int i;
    for (i=0; i<6;i++){
        slotArray[i].savetoMemory(slotArray[i].get_ID());
    }

}