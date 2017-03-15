//
// Created by danielc on 26/02/17.
//

#ifndef PAGEDARRAY_PAGED_ARRAY_H
#define PAGEDARRAY_PAGED_ARRAY_H


#include "slotManagr.h"

class paged_Array {

    public:

    paged_Array();
    int mas_usada();
    int &operator[] (int index);
    int check_Page (int PageID);
    int page_loader (int page_num);
    int check_freeSlot ();
    slotManagr slot0 , slot1, slot2, slot3, slot4, slot5;
    slotManagr slotArray [6] = {slot0 , slot1, slot2, slot3, slot4, slot5};
    void saveAll ();


};


#endif //PAGEDARRAY_PAGED_ARRAY_H
