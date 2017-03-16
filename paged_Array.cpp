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

/// @brief sobrecarga del operador
/// @param el index
/// @return el numero que se desea acceder
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

/// @brief chequea la pag
/// @param el id de la pag
/// @return si la pagina esta cargada
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
/// @brief busca slots libres
/// @return el numero de slot libre
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
/// @brief carga la pagina
/// @param numero de pagina
/// @return el slot donde se cargo la pag
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
       int mas_usada1= mas_usada();//algoritmo de remplazo
       slotArray[mas_usada1].savetoMemory(slotArray[mas_usada1].get_ID());
        slotArray[mas_usada1].pagetoMemory(page_num);
        new_slot = mas_usada1;
    }
    return new_slot;
}

/// @brief busca la pag mas usada
/// @return el numero de slot con la pag mas usada
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

/// @brief salva todas las paginas cargadas en slots
void paged_Array::saveAll (){
    int i;
    for (i=0; i<6;i++){
        slotArray[i].savetoMemory(slotArray[i].get_ID());
    }

}