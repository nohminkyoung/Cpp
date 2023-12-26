#include "AccountArray.h"
#include "BankingCommonDecl.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len=100):arrlen(len){
    arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int index){
    if(index<0 || index>=arrlen){
        cout<<"올바르지않은 인덱스"<<endl;
        exit(1);
    }

    return arr[index];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int index) const{
    if(index<0 || index>=arrlen){
        cout<<"올바르지않은 인덱스"<<endl;
        exit(1);
    }

    return arr[index];
}

int BoundCheckAccountPtrArray::GetArrLen() const{
    return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray(){
    delete []arr;
}