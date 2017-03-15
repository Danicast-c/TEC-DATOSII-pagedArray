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
    int arr[size];
    int valor=size;

    for (i=0; i<size; i++) {
        //valor= rand()%100;
        arr[i]=valor;
        valor--;
    }

    FILE *archivo;
    archivo = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "w+b");
    if (archivo) {
        cout << "El archivo se creo correctamente" << endl;
        fseek(archivo,0,SEEK_SET);
        fwrite(arr, sizeof(int), size  , archivo);
        cout << "Se inserto num en el archivo" << endl;
    }
    else {
        cout << "El archivo NO se creo" << endl;
    }
    fclose(archivo);



    FILE *archivo1;
    archivo1 = fopen("/home/danielc/Git\ TEC\ /Archivo.dat", "rb");

    fseek(archivo1, 0, SEEK_END);
    long lsize = ftell(archivo1);
    rewind(archivo1);
    cout << "tamaño: " << lsize << endl;

    int buffer [lsize/sizeof(int)];
    fread(buffer, sizeof(int),size,archivo1);
    cout << "contenido: ";

    for (i = 0; i<lsize/sizeof(int); i++){
        cout << buffer[i] << ", ";
    }
    fclose(archivo1);






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

