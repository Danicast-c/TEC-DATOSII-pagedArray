//
// Created by danielc on 04/03/17.
//
#include <iostream>
#include "fileGnerator.h"
#include "Quicksort.h"

using namespace std;

void fileGnerator (int size)
{
    int i;
    int arr [size];
    int valor;
    int * buffer;

    for (i=0; i<size; i++)
    {
        valor= rand()%100;
        arr[i]=valor;
    }

    FILE *archivo;
    archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "w+b");
    if (archivo) {
        cout << "El archivo se creo correctamente" << endl;
        rewind(archivo);
        fwrite(arr, sizeof(int), size  , archivo);
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
    fread(buffer, sizeof(int),size,archivo);
    cout << "contenido: ";

    for (i = 0; i<lsize/4; i++){
        cout << buffer[i] << ", ";
    }

    fclose(archivo);






    /*//lee solo DOS datos
    int * page;
    //cambia el tercer atributo de fseek para correr el puntero en el archivo :D
    fseek(archivo, sizeof(int),SEEK_SET);
    page = (int*) malloc(sizeof(int)*8);
    fread(page, sizeof(int),8,archivo);

    cout<< endl << "pagina: " << endl;

    for (i = 0; i<8/4; i++){
        cout << page[i] << ", ";
    }
    free (page);*/





};

