#include<iostream>
#include<cstring>

using namespace std;


class Account{
    private : 
        char * Name;
        int Acc;
        int Bal;

    public :
        Account(char * name, int acc, int bal) : Acc(acc), Bal(bal){
            Name = new char[strlen(name)+1];
            strcpy(Name, name);
        }

        Account(const Account &copy) : Acc(copy.Acc), Bal(copy.Bal){
            Name = new char[strlen(copy.Name)+1];
            strcpy(Name, copy.Name);
        }

        int GetAcc(){  // 계좌 호출
            return Acc;
        }

        void Deposit (int money){ // 입금
            Bal += money;
        }

        int Withdraw(int money){ // 출금
            
            if(Bal<money){
                return 0;
            }

            Bal -= money;
            return money;
        }

        void ShowAcc(){
            cout<<"이름: "<<Name<<endl;
            cout<<"계좌: "<<Acc<<endl;
            cout<<"잔액: "<<Bal<<endl;
        }

        ~Account(){
            delete []Name;
        }
};


void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void withdrowMoney(void);
void ShowAllAccount(void);



Account * AccArr[100]; //고객정보를 담을 포이너 배열
int accID = 0; // 고객 아이디 번호 -> 배열의 인덱스 번호로 사용됨


int main(void){
    int select;

    while (1)
    {
        ShowMenu();
        cout<<"메뉴를 선택하세요"<<endl;
        cin>>select;

        if(select==1){
            MakeAccount();
        }else if (select==2)
        {
            DepositMoney();
        }else if (select==3)
        {
            withdrowMoney();
        }else if (select==4)
        {
            ShowAllAccount();
        }else if (select==5)
        {   
            for(int i=0; i<accID; i++){
                delete AccArr[i];
            }
            return 0;
        }else{
            cout<<"보기에 있는 번호를 선택하세요"<<endl;
        }
    }
}


//함수 : 메뉴 보여주는 함수, 계좌개설함수, 입금함수, 출금함수, 잔액조회 함수
void ShowMenu(void){
    cout<<"----Menu----"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입금 하기"<<endl;
    cout<<"3. 출금 하기"<<endl;
    cout<<"4. 전체고객 잔액조회"<<endl;
    cout<<"5. 종료하기"<<endl;
}

void MakeAccount(void){ // 계좌 개설 함수
    char name[20];
    int acc;
    int bal;

    cout<<"[계좌개설]"<<endl;
    cout<<"이름 :"<<endl;
    cin>>name;
    cout<<"계좌 :"<<endl;
    cin>>acc;
    cout<<"잔액 :"<<endl;
    cin>>bal;

    AccArr[accID] = new Account(name, acc, bal); // 포인터 배열이라 동적 할당으로 주소값을 저장
    accID++;
}


void DepositMoney(void){ // 입금함수
    int money; //입금할 돈
    int acc; //입글할 계좌

    cout<<"[입금]"<<endl;
    cout<<"입금할 계좌 : "<<endl;
    cin>>acc;
    cout<<"입금할 돈 : "<<endl;
    cin>>money;

    for(int i=0; i<accID; i++){//전체 계좌를 하나씩 비교하며 같은 계좌 찾기

        if(AccArr[i]->GetAcc() == acc){  /////////ArrAcc가 동적할당 된 Acc의 주소값을 담고있는 배열이기 때문(포인터배열)
            AccArr[i]->Deposit(money);
            cout<<"입금 완료"<<endl;

            return; // 같은 계좌 만나서 입금 완료하면 여기서 끝내기
        }
    }

    cout<<"동일한 계좌가 없습니다."<<endl; //for문에서 같은 계좌를 못만낫기 때문에 입금 실패 
}

void withdrowMoney(void){ //출금함수
    int acc; //출금할 계좌
    int money; //출금할 돈

    cout<<"[출금]"<<endl;
    cout<<"출금할 계좌 : "<<endl;
    cin>>acc;
    cout<<"출금할 돈 : "<<endl;
    cin>>money;

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

void ShowAllAccount(void){ // 전체 계좌 조회

    cout<<"[계좌 조회]"<<endl;
    for(int i=0; i<accID; i++){
        AccArr[i]->ShowAcc();
        cout<<"======================"<<endl;
    }
}




//####  version2  ####
//version 01의 struct를 class로 정의하기 
// name을 동적할당의 형태로 받아 char변수에 저장하기 
// 객체 포인터 배열을 선언

//####  version3  ####
// Account 클래스의 복생성자 추가