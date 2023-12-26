// Accout 정보를 저장할 배열정의

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account * ACCOUNT_PTR;

class BoundCheckAccountPtrArray{
    private :
        ACCOUNT_PTR * arr;
        int arrlen;

    public :
        BoundCheckAccountPtrArray(int len=100);
        ACCOUNT_PTR& operator[](int index);
        ACCOUNT_PTR operator[](int index) const;
        int GetArrLen() const;
        ~BoundCheckAccountPtrArray();

        BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}; 
        BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr){};

};

#endif