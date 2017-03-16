#include <iostream>
#include <fstream>
#include "Quicksort.h"
#include "Insertionsort.h"
#include "fileGnerator.h"
#include "paged_Array.h"
#include "slotManagr.h"
#include "Selectionsort.h"
#include "fstream"

using namespace std;
void bin_to_text (paged_Array *p_ar,int size , string newfilename);
void p_ar_print ( paged_Array bffer, int lsize);
int main(int narg, char *args[]) {

    if (narg != 7 ){
        cout << "ERROR:"<<endl;
        cout << "The format must be: pagedArray -i <file-name>.txt -a {QS|IS|SS} -o <result-file-name>.txt"<<endl;
        return 1;
    }
    string fileforRead = args[2];
    string sortoUse = args[4];
    string sortedFile = args[6];
    if (sortoUse != "QS" and sortoUse!="IS" and sortoUse != "SS"){
        cout << "ERROR:"<<endl;
        cout << "The sort indicator must be: QS, IS or SS"<<endl;
        return 1;
    }



    paged_Array p_ar;
    ifstream inFile;
    inFile.open(fileforRead);
    if (!inFile) {
        cerr << "Unable to open file: "<< fileforRead << endl;
        cerr << "The file must exist and the correct format is: <file-name>.txt"<<endl;
        exit(1);   // call system to stop
    }
    string cont;
    int size=0;
    while (getline(inFile,cont,',')){
        size++;
    }
    inFile.close();
    int array[size];
    int i=0;
    ifstream inFile2;
    inFile2.open(fileforRead);
    while (getline(inFile2,cont,',')){
       array[i]=stoi(cont);
       i++;
    }
    inFile2.close();

   fileGnerator(array,size);

    if (sortoUse == "QS"){
        quickSort(&p_ar,0,size);
    } else if (sortoUse == "SS"){
        selectionSort(&p_ar,size);
    } else if (sortoUse == "IS"){
        insertion_Sort(&p_ar,size);
    }

    p_ar.saveAll();

    bin_to_text(&p_ar,size,sortedFile);

    remove("Archivo.dat");
    return 0;
}

/// @brief carga el binario a un nuevo texto
/// @param p_ar puntero de pagedarray, size el tamano, newfilename nuevo nombre

void bin_to_text (paged_Array *p_ar,int size , string newfilename){
    string filedirection= newfilename;
    ofstream newFile;
    newFile.open(filedirection);
    int i;
    int num;
    string allarray = "";
    string numastring;
    for (i=0;i<size;i++){
        num = p_ar->operator[](i);
        numastring = to_string(num);
        allarray = allarray+numastring+",";
    }
    newFile << allarray;
}
