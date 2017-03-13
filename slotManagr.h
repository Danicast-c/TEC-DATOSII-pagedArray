//
// Created by danielc on 05/03/17.
//

#ifndef PAGEDARRAY_SLOTMANAGR_H
#define PAGEDARRAY_SLOTMANAGR_H


class slotManagr {

public:
    int ID = -1;
    void test ();
    int Array[256];
    void pagetoMemory (int page);
    int getPosition(int position);
    void savetoMemory(int id);
    void ID_modify(int new_id);
    int get_ID ();
};


#endif //PAGEDARRAY_SLOTMANAGR_H
