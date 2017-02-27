//
// Created by danielc on 21/02/17.
//

#include <iostream>

using namespace std;

void arr_Print(int arr [], int largo){
    int i;
    for(i=0 ; i < largo ; i++){
        cout << arr [i] << " in position: " << i <<  endl;
    }
    cout << "END" << endl << endl;
}
