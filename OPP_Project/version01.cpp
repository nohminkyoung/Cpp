//c스타일로 구현하기 
// 기능 1. 계좌 개설, 2. 입금 3. 출금 4. 전체고객 잔액조회
// 프로그래밍을 간결히 하기 위한 가정 : 계좌번호는 중복x(중복검사안함), 입출금 금액은 0보다 크게, 고객정보는 계좌, 이름, 잔액 세가지만 관리, 줄이상의 고객정보 저장을 위해 배열 사용, 계좌번호는 정수 

#include<iostream>
#include<cstring>

using namespace std;


typedef struct {
    char Name[20]; //이름
    int Acc; //계좌 
    int Bal; //잔액
} Account;

Account AccArr[100]; //고객정보를 담을 구조채배열
int accID = 0; // 고객 아이디 번호 -> 배열의 인덱스 번호로 사용됨

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

    strcpy(AccArr[accID].Name, name);
    AccArr[accID].Acc = acc;
    AccArr[accID].Bal = bal;

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

        if(AccArr[i].Acc == acc){
            AccArr[i].Bal += money;
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
        if(AccArr[i].Acc == acc){
            if(AccArr[i].Bal < money){
                cout<<"잔액이 부족합니다."<<endl;
                return; //잔액 부족하면 여기서 종료
            }
            AccArr[i].Bal -= money;
            cout<<"출금 완료"<<endl;
            return; //출금 완료하면 여기서 종료
        }
    }

    cout<<"동일한 계좌가 없습니다."<<endl; //for문에서 같은 계좌를 못만낫기 때문에 출금 실패 
}

void ShowAllAccount(void){ // 전체 계좌 조회

    cout<<"[계좌 조회]"<<endl;
    for(int i=0; i<accID; i++){
        cout<<"이름 :"<<AccArr[i].Name<<endl;
        cout<<"계좌 :"<<AccArr[i].Acc<<endl;
        cout<<"잔액 :"<<AccArr[i].Bal<<endl;
        cout<<"======================"<<endl;
    }
}

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
            return 0;
        }else{
            cout<<"보기에 있는 번호를 선택하세요"<<endl;
        }
    }
    
    
    
    
    
    
}