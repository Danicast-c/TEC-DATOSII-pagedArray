//
//

#include "slotManagr.h"
// Created by danielc on 05/03/17.
#include <iostream>
#define CANT 256

using namespace std;

void slotManagr::test() {
    cout << "funciona"<< endl;
}

void slotManagr::ID_modify(int new_id){
    ID = new_id;
}

int slotManagr::get_ID (){
    return ID;
}

int slotManagr::getPosition(int position){
    return Array[position];
}

void slotManagr::pagetoMemory (int page){

    FILE *archivo;
    int i;
    archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "r+");
    int buffer [CANT];
    fseek(archivo, (page*CANT), SEEK_SET);
    fread(buffer, sizeof(int),CANT,archivo);
    for (i=0; i<CANT ; i++){
        Array[i] = buffer[i];
    }
    ID_modify(page);
    fclose(archivo);

}

void slotManagr::savetoMemory(int id){
    FILE *archivo;
    archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "r+");
    fseek(archivo, (id*CANT), SEEK_SET);
    fwrite(Array, sizeof(int), CANT  , archivo);
    fclose(archivo);
}
