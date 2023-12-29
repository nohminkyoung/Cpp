//보통예금계좌 선언 및 정의 

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "StringClass.h"
#include "AccountException.h"

class NormalAccount : public Account{
    private :
        int interRate; //이자
    
    public :
        NormalAccount(String name, int acc, int bal, int rate):Account(name, acc, bal), interRate(rate){}

        virtual void Deposit(int money){ //virtual로 선언 -> 얘로 생성된 클래스는 어떤 포인터에 담겨도 이 함수가 호출
            if(money<0){
                throw MinusException(money);
            }

            Account::Deposit(money); // 입금
            Account::Deposit(money*(interRate/100.0)); // 입금시 이자 
        }

};

#endif
