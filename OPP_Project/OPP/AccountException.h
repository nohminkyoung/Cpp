// 예외 처리 클래스 

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include "BankingCommonDecl.h"

class MinusException
{
    private : 
        int exval; // 예외의 원인이 되는 금액

    public :    
        MinusException(int ex):exval(ex){}
        void ShowException(void){
            cout<<"입(출)금액"<<exval<<"은 불가능"<<endl;
        }
};


class InsuffException{
    private : 
        int balance;
        int reqval;

    public :    
        InsuffException(int b, int r) :balance(b), reqval(r){};
        void ShowException(void){
            cout<<"잔액에서"<<reqval-balance<<"만큼 부족"<<endl;
        }
};


#endif