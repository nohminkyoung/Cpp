// Account 클래스의 선언

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
    private : 
        char * Name;
        int Acc;
        int Bal;

    public :
        Account(char * name, int acc, int bal);           
        Account(const Account &copy);
        int GetAcc() const;
        virtual void Deposit (int money);
        int Withdraw(int money);
        void ShowAcc()const;
        Account& operator=(const Account& ref); // 복사 생성자 선언
        ~Account();
};

#endif