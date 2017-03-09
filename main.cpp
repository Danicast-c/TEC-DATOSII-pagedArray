#include <iostream>
#include <fstream>
#include "Quicksort.h"
#include "Insertionsort.h"
#include "ArrayConsolePrinter.h"
#include "fileGnerator.h"
#include "paged_Array.h"
#include "slotManagr.h"

using namespace std;
void buffer_printer ( int bffer[], int lsize);

int main() {
    int * buffer;
    FILE *archivo;
    int num [] = {1,2,3,4,5,6,7,8,9};
    /**archivo = fopen("/home/danielc/Git\ TEC\ /binary.dat", "w+b");
    if (archivo) {
        cout << "El archivo se creo correctamente" << endl;
        fwrite(num, sizeof(int), 9 , archivo);
        cout << "Se inserto num en el archivo" << endl;
    }
    else {
        cout << "El archivo NO se creo" << endl;
    }

    fseek(archivo, 0, SEEK_END);
    long lsize = ftell(archivo);
    rewind(archivo);
    cout << "tamaño: " << lsize << endl;


    buffer = (int*) malloc(sizeof(int)*lsize);
    fread(buffer, sizeof(int),lsize,archivo);
    cout << "lsize: " << lsize << endl;
    cout << "contenido: ";
    buffer_printer(buffer,lsize);
    free (buffer); **/

    fileGnerator(12);

    paged_Array p_ar;
    p_ar.test();

    remove("Archivo.dat");

    return 0;
}


void buffer_printer ( int bffer[], int lsize){
    int i =0;
    for (i = 1; i<lsize/4; i++){
        cout << bffer[i-1] << ", ";
    }
}
void try_page (){
    FILE *archivo;
    archivo = fopen("/home/danielc/Git\ TEC\ /binary.dat", "w+b");
    fseek(archivo, 0, SEEK_END);
    long lsize = ftell(archivo);
    rewind(archivo);
}
