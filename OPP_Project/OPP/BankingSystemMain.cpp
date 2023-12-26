#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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


//#### version8  ####
//Account 클래스에 대입연산자 정의
//AccountHandler 클래스의 멤버변수인 배열이 객체를 저장했는데, 이를 BoundCheckPointPtrArray로 대체 

//####  version9  ####
//직접 구현한  String 클래스를 사용
