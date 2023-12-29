//AccountHandler 함수 선언

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler{
    private :
        BoundingCheckArray<Account*> AccArr; // 원래 전역 변수로 선언했던것을 class내부에
        int accID;

    public :
        AccountHandler(); //AccountHandler가 생성될 때 고객 인덱스를 0으로 초기화
        
        void ShowMenu(void) const;
        void MakeAccount(void);
        void MakeNormal(void);

        void MakeCradit(void);
        void DepositMoney(void);

        void withdrowMoney(void);
        void ShowAllAccount(void);

        ~AccountHandler();

};

#endif