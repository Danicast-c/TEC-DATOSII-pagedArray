//
// Created by danielc on 04/03/17.
//
#include <iostream>
#include "fileGnerator.h"
#include "Quicksort.h"

using namespace std;

/// @brief genera el archivo binario
/// @param arr[] recive el array, size el largo
void fileGnerator (int arr[], int size)
{
    int i;

    int valor=size;

    FILE *archivo;
    archivo = fopen("Archivo.dat", "w+b");
    if (archivo) {
        fseek(archivo,0,SEEK_SET);
        fwrite(arr, sizeof(int), size  , archivo);
    }
    else {
        cout << "El archivo NO se creo" << endl;
    }
    fclose(archivo);



    FILE *archivo1;
    archivo1 = fopen("Archivo.dat", "rb");

    fseek(archivo1, 0, SEEK_END);
    long lsize = ftell(archivo1);
    rewind(archivo1);

    int buffer [lsize/sizeof(int)];
    fread(buffer, sizeof(int),size,archivo1);
    fclose(archivo1);


};

