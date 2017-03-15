//
//

#include "slotManagr.h"
// Created by danielc on 05/03/17.
#include <iostream>
#define CANT 256

using namespace std;

slotManagr::slotManagr() {
    ID_modify(-1);
    set_veces_usado(0);
}

int slotManagr::get_veces_usado() {
    return veces_usado;
}
void slotManagr::suma_veces_usado() {
    veces_usado++;
}
void slotManagr::set_veces_usado(int num){
    veces_usado=num;

}
void slotManagr::test() {
    cout << "funciona"<< endl;
}

void slotManagr::ID_modify(int new_id){
    //cout << "id pasa de: "<< get_ID()<<" a "<<new_id<<endl;
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
    archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "rb");
    int buffer [CANT];
    fseek(archivo, sizeof(int)*page*CANT, SEEK_SET);
    fread(buffer, sizeof(int),CANT,archivo);
    for (i=0; i<CANT ; i++){
        Array[i] = buffer[i];
    }
    //cout <<endl<< "pagina cargada: "<< page << endl;
    ID_modify(page);
    fclose(archivo);

}

void slotManagr::savetoMemory(int id){
   // cout << "pagina guardadita: "<< id << endl;
    if (id != -1) {
        FILE *archivo;
        archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "r+");
        fseek(archivo, sizeof(int)*(id * CANT), SEEK_SET);
        fwrite(Array, sizeof(int), CANT, archivo);
        fclose(archivo);
    }

}

