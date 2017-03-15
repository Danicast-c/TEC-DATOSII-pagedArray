#include <iostream>
#include <fstream>
#include "Quicksort.h"
#include "Insertionsort.h"
#include "ArrayConsolePrinter.h"
#include "fileGnerator.h"
#include "paged_Array.h"
#include "slotManagr.h"
#include "Selectionsort.h"

using namespace std;
void p_ar_print ( paged_Array bffer, int lsize);

int main() {
    int num [] = {1,39,77,4,23,12,7,72,9};

    int largo = 2304;
    fileGnerator(largo);

    paged_Array p_ar;
    cout << endl <<"contenido leido: "<<endl;
    p_ar_print(p_ar,largo);


     selectionSort(&p_ar,largo);
     p_ar.saveAll();

   cout << endl << "Contenido ordenado: "<<endl;
    p_ar_print(p_ar,largo);


    return 0;
}


void p_ar_print ( paged_Array bffer, int lsize){
    int i =0;
    for (i = 0; i<lsize; i++){
        cout << bffer[i] << ", ";
    }
}
void try_page (){
    FILE *archivo;
    archivo = fopen("/home/danielc/Git\ TEC\ /binary.dat", "w+b");
    fseek(archivo, 0, SEEK_END);
    long lsize = ftell(archivo);
    rewind(archivo);
}
