//신용신뢰계좌 선언 및 정의

#ifndef __CREDIT_ACCOUNT_H__
#define __CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount{
    private :   
        int special;
    public:
        HighCreditAccount(char * name, int acc, int bal, int rate, int spe) : NormalAccount(name, acc, bal, rate), special(spe){}

        virtual void Deposit(int money){ //virtual로 선언 -> 얘로 생성된 클래스는 어떤 포인터에 담겨도 이 함수가 호출
            NormalAccount::Deposit(money); // 입금 및 입금한 돈의 이자를 추가함
            Account::Deposit(money*(special/100.0)); // 등급에 따른 특별이자 추가
        }
};

#endif