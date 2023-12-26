// Account 클래스의 선언
//Stringclass로 인해서 생성자 내 동적할당이 불필요, 소멸자, 복사생성자, 대입연산자가 모두 불필요해짐(String이 깊은 복사하도록 정의)

#include "StringClass.h"

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
    private : 
        String Name; //String 클래스로 변경
        int Acc;
        int Bal;

    public :
        Account(String name, int acc, int bal);           
        // Account(const Account &copy);
        int GetAcc() const;
        virtual void Deposit (int money);
        int Withdraw(int money);
        void ShowAcc()const;
        // Account& operator=(const Account& ref); // 복사 생성자 선언
        // ~Account();
};

#endif