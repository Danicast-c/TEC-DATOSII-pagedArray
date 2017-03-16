//
//

#include "slotManagr.h"
// Created by danielc on 05/03/17.
#include <iostream>
#define CANT 256

using namespace std;
/// @brief constructor
slotManagr::slotManagr() {
    ID_modify(-1);
    set_veces_usado(0);
}
/// @brief get de veces usado
/// @return numero de veces usado
int slotManagr::get_veces_usado() {
    return veces_usado;
}
/// @brief suma 1 a las veces usado
void slotManagr::suma_veces_usado() {
    veces_usado++;
}
/// @brief setea el num de veces usado
/// @param num numero por asinar
void slotManagr::set_veces_usado(int num){
    veces_usado=num;

}
/// @brief modifica el id de la pagina
/// @param new_id el nuevo id
void slotManagr::ID_modify(int new_id){
    //cout << "id pasa de: "<< get_ID()<<" a "<<new_id<<endl;
    ID = new_id;
}
/// @brief retorna el id de la pagina
/// @return el id
int slotManagr::get_ID (){
    return ID;
}
int slotManagr::getPosition(int position){
    return Array[position];
}

/// @brief carga la pagina a memoria
/// @param page la pagina que se desea cargar
void slotManagr::pagetoMemory (int page){

    FILE *archivo;
    int i;
    archivo = fopen("Archivo.dat", "rb");
    int buffer [CANT];
    fseek(archivo, sizeof(int)*page*CANT, SEEK_SET);
    fread(buffer, sizeof(int),CANT,archivo);
    for (i=0; i<CANT ; i++){
        Array[i] = buffer[i];
    }
    ID_modify(page);
    fclose(archivo);

}
/// @brief salva la pagina cargada al archivo
/// @param id de la pag
void slotManagr::savetoMemory(int id){
    if (id != -1) {
        FILE *archivo;
        archivo = fopen("Archivo.dat", "r+");
        fseek(archivo, sizeof(int)*(id * CANT), SEEK_SET);
        fwrite(Array, sizeof(int), CANT, archivo);
        fclose(archivo);
    }

}

