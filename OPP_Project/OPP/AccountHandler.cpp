//AccountHandler 정의 

#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "CreditAccount.h"
#include "StringClass.h"

AccountHandler::AccountHandler():accID(0){}; //AccountHandler가 생성될 때 고객 인덱스를 0으로 초기화

void AccountHandler::ShowMenu(void) const{
    cout<<"----Menu----"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입금 하기"<<endl;
    cout<<"3. 출금 하기"<<endl;
    cout<<"4. 전체고객 잔액조회"<<endl;
    cout<<"5. 종료하기"<<endl;
}


void AccountHandler::MakeAccount(void){ // 어떤 조건의 계좌를 개설할 것인지 보여주는 함수
    int select;
    cout<<"----계좌의 종류 선택----"<<endl;
    cout<<"1. 보통예금계좌"<<endl;
    cout<<"2. 신용신뢰계좌"<<endl;
    cout<<"선택 : "<<endl;
    cin>>select;

    if(select==NORMAL){
        MakeNormal();
    }else if (select==CREDIT)
    {
        MakeCradit();
    }else{
        cout<<"올바른 값을 입력"<<endl;
    }

}

void AccountHandler::MakeNormal(void){ // 보통예금계좌 개설
    String name;
    int acc;
    int bal;
    int rate;

    cout<<"[계좌개설]"<<endl;
    cout<<"이름 :"<<endl;
    cin>>name;
    cout<<"계좌 :"<<endl;
    cin>>acc;
    cout<<"잔액 :"<<endl;
    cin>>bal;
    cout<<"이자율 :"<<endl;
    cin>>rate; 

    AccArr[accID] = new NormalAccount(name, acc, bal, rate); // 포인터 배열이라 동적 할당으로 주소값을 저장
    accID++;
}

void AccountHandler::MakeCradit(void){ // 계좌 개설 함수
    String name;
    int acc;
    int bal;
    int rate;
    int level;

    cout<<"[계좌개설]"<<endl;
    cout<<"이름 :"<<endl;
    cin>>name;
    cout<<"계좌 :"<<endl;
    cin>>acc;
    cout<<"잔액 :"<<endl;
    cin>>bal;
    cout<<"이자율 :"<<endl;
    cin>>rate; 
    cout<<"신용등급(1toA, 2toB, 3toC) :"<<endl;
    cin>>level; 

    if(level==1){
        AccArr[accID] = new HighCreditAccount(name, acc, bal, rate, Level_A); // 포인터 배열이라 동적 할당으로 주소값을 저장
        accID++;
    }else if(level==2){
        AccArr[accID] = new HighCreditAccount(name, acc, bal, rate, Level_B); // 포인터 배열이라 동적 할당으로 주소값을 저장
        accID++;
    }else if(level==3){
        AccArr[accID] = new HighCreditAccount(name, acc, bal, rate, Level_C); // 포인터 배열이라 동적 할당으로 주소값을 저장
        accID++;
    }else{
        cout<<"올바른 값을 입력"<<endl;
    }

    
}


void AccountHandler::DepositMoney(void){ // 입금함수
    int money; //입금할 돈
    int acc; //입글할 계좌

    cout<<"[입금]"<<endl;
    cout<<"입금할 계좌 : "<<endl;
    cin>>acc;
    cout<<"입금할 돈 : "<<endl;
    cin>>money;

    try{
        for(int i=0; i<accID; i++){//전체 계좌를 하나씩 비교하며 같은 계좌 찾기

            if(AccArr[i]->GetAcc() == acc){  /////////ArrAcc가 동적할당 된 Acc의 주소값을 담고있는 배열이기 때문(포인터배열)
                AccArr[i]->Deposit(money);
                cout<<"입금 완료"<<endl;

                return; // 같은 계좌 만나서 입금 완료하면 여기서 끝내기
            }
        }

        cout<<"동일한 계좌가 없습니다."<<endl; //for문에서 같은 계좌를 못만낫기 때문에 입금 실패 
    }
    catch (MinusException expn){
        expn.ShowException();
        cout<<"입금액 재입력"<<endl;
    }
}

void AccountHandler::withdrowMoney(void){ //출금함수
    int acc; //출금할 계좌
    int money; //출금할 돈

    cout<<"[출금]"<<endl;
    cout<<"출금할 계좌 : "<<endl;
    cin>>acc;
    cout<<"출금할 돈 : "<<endl;
    cin>>money;


    try{
        for(int i=0; i<accID; i++){
            if(AccArr[i]->GetAcc() == acc){
                if(AccArr[i]->Withdraw(money)==0){ //잔액보다 출금액이 많으면 class의 함수가 0을 전달해줌
                    cout<<"잔액이 부족합니다."<<endl;
                    return; //잔액 부족하면 여기서 종료
                }
                cout<<"출금 완료"<<endl;
                return; //출금 완료하면 여기서 종료
            }
        }

        cout<<"동일한 계좌가 없습니다."<<endl; //for문에서 같은 계좌를 못만낫기 때문에 출금 실패 
    }
    catch (MinusException expn){
        expn.ShowException();
        cout<<"출금액 재입력"<<endl;
    }catch (InsuffException expn){
        expn.ShowException();
        cout<<"출금액 재입력"<<endl;
    }
}

void AccountHandler::ShowAllAccount(void){ // 전체 계좌 조회

    cout<<"[계좌 조회]"<<endl;
    for(int i=0; i<accID; i++){
        AccArr[i]->ShowAcc();
        cout<<"======================"<<endl;
    }
}

AccountHandler::~AccountHandler(){
    for(int i=0; i<accID; i++){
        delete AccArr[i];
    }
}