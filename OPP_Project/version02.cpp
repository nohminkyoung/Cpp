#include<iostream>
#include<cstring>

using namespace std;

enum{Level_A=7,Level_B=4,Level_C=2};
enum{NOMAL=1, CREDIT=2};


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

        int GetAcc() const{  // 계좌 호출 + const
            return Acc;
        }

        virtual void Deposit (int money){ // 입금 //여기에도 virtual을 빼먹지않아야 유도클래스들의 Deposit함수를 불러올수있음 (AccountHandler에서 Account의 포인터함수배열로 받기때문)
            Bal += money;
        }

        int Withdraw(int money){ // 출금
            
            if(Bal<money){
                return 0;
            }

            Bal -= money;
            return money;
        }

        void ShowAcc()const{ // const추가 
            cout<<"이름: "<<Name<<endl;
            cout<<"계좌: "<<Acc<<endl;
            cout<<"잔액: "<<Bal<<endl;
        }

        ~Account(){
            delete []Name;
        }
};


//보통예금계좌 
class NomalAccount : public Account{
    private :
        int interRate; //이자
    
    public :
        NomalAccount(char * name, int acc, int bal, int rate):Account(name, acc, bal), interRate(rate){}

        virtual void Deposit(int money){ //virtual로 선언 -> 얘로 생성된 클래스는 어떤 포인터에 담겨도 이 함수가 호출
            Account::Deposit(money); // 입금
            Account::Deposit(money*(interRate/100.0)); // 입금시 이자 
        }

};

class HighCreditAccount : public NomalAccount{
    private :   
        int special;
    public:
        HighCreditAccount(char * name, int acc, int bal, int rate, int spe) : NomalAccount(name, acc, bal, rate), special(spe){}

        virtual void Deposit(int money){ //virtual로 선언 -> 얘로 생성된 클래스는 어떤 포인터에 담겨도 이 함수가 호출
            NomalAccount::Deposit(money); // 입금 및 입금한 돈의 이자를 추가함
            Account::Deposit(money*(special/100.0)); // 등급에 따른 특별이자 추가
        }
};


// 기존의 전역함수들을 모두 맴버함수로 갖는 class선언
class AccountHandler{
    private :
        Account * AccArr[100]; // 원래 전역 변수로 선언했던것을 class내부에
        int accID;

    public :
        AccountHandler():accID(0){}; //AccountHandler가 생성될 때 고객 인덱스를 0으로 초기화
        
        void ShowMenu(void) const{
            cout<<"----Menu----"<<endl;
            cout<<"1. 계좌 개설"<<endl;
            cout<<"2. 입금 하기"<<endl;
            cout<<"3. 출금 하기"<<endl;
            cout<<"4. 전체고객 잔액조회"<<endl;
            cout<<"5. 종료하기"<<endl;
        }


        void MakeAccount(void){ // 어떤 조건의 계좌를 개설할 것인지 보여주는 함수
            int select;
            cout<<"----계좌의 종류 선택----"<<endl;
            cout<<"1. 보통예금계좌"<<endl;
            cout<<"2. 신용신뢰계좌"<<endl;
            cout<<"선택 : "<<endl;
            cin>>select;

            if(select==NOMAL){
                MakeNomal();
            }else if (select==CREDIT)
            {
                MakeCradit();
            }else{
                cout<<"올바른 값을 입력"<<endl;
            }

        }

        void MakeNomal(void){ // 보통예금계좌 개설
            char name[20];
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

            AccArr[accID] = new NomalAccount(name, acc, bal, rate); // 포인터 배열이라 동적 할당으로 주소값을 저장
            accID++;
        }

        void MakeCradit(void){ // 계좌 개설 함수
            char name[20];
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

        ~AccountHandler(){
            for(int i=0; i<accID; i++){
                delete AccArr[i];
            }
        }


};

int main(void){
    AccountHandler manager;
    int select;

    while (1)
    {
        manager.ShowMenu();
        cout<<"메뉴를 선택하세요"<<endl;
        cin>>select;

        if(select==1){
            manager.MakeAccount();
        }else if (select==2)
        {
            manager.DepositMoney();
        }else if (select==3)
        {
            manager.withdrowMoney();
        }else if (select==4)
        {
            manager.ShowAllAccount();
        }else if (select==5)
        {   
            /*for(int i=0; i<accID; i++){
                delete AccArr[i];
            }*/  // AccountHandler의 소멸자에서 모두 소멸시키기 때문에 필요x
            return 0;
        }else{
            cout<<"보기에 있는 번호를 선택하세요"<<endl;
        }
    }
}



//####  version2  ####
//version 01의 struct를 class로 정의하기 
// name을 동적할당의 형태로 받아 char변수에 저장하기 
// 객체 포인터 배열을 선언

//####  version3  ####
// Account 클래스의 복생성자 추가

//####  version4  ####
// const로 선언 가능한 멤버 함수를 모두 const로 선언

//####  version5  ####
// AccountHandler라는 이름의 컨트롤 클래스 정의 + Account 객체의 저장을 위해 선언한 배열과 변수도 포함
// AccountHandler를 기반으로 프로그램이 실행되도록 main수정


//####  version6  ####
// 게좌를 보통예금계좌와 신용신뢰계좌로 나누기
// 보통예금계좌 : 이율정보 등록 -> 입금 할 때 입금하는 돈의 이자가 추가로 입금
// 신용신뢰계좌 : 보통예금계좌의 기본이율 + 신용정보 ABC에 따른 추가이율 7, 4, 2
// 이자는 초기 금액에는 발생 

//####  version7  ####
// 클래스의 선언과 정의를 구분