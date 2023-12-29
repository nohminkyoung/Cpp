//Account클래스의 정의

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(String name, int acc, int bal) : Acc(acc), Bal(bal){
    // Name = new char[strlen(name)+1];
    // strcpy(Name, name);

    Name = name;
}

// Account::Account(const Account &copy) : Acc(copy.Acc), Bal(copy.Bal){
//     Name = new char[strlen(copy.Name)+1];
//     strcpy(Name, copy.Name);
// }

int Account::GetAcc() const{  // 계좌 호출 + const
    return Acc;
}

void Account::Deposit (int money){ // 입금

    if(money<0){
        throw MinusException(money); // 예외 던지기 추가
    }
    Bal += money;
}

int Account::Withdraw(int money){ // 출금
    
    if(Bal<money){
        throw MinusException(money); // 예외 던지기 추가
    }

    if(Bal<money){
        throw InsuffException(Bal, money); // 예외 던지기 추가
    }

    Bal -= money;
    return money;
}

void Account::ShowAcc()const{ // const추가 
    cout<<"이름: "<<Name<<endl;
    cout<<"계좌: "<<Acc<<endl;
    cout<<"잔액: "<<Bal<<endl;
}

//복사생성자 
// Account& Account::operator=(const Account& ref){
//     Acc = ref.Acc;
//     Bal = ref.Bal;
//     delete[]Name;

//     Name = new char[strlen(ref.Name)+1];
//     strcpy(Name, ref.Name);
//     return *this;
// }

// Account::~Account(){
//     delete []Name;
// }