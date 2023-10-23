//chapter3 의 예제 FruitSaleSim1.cpp에서 정의한 맴버변수들에 사과의 구매를 목적으로 0보다 작은수를 전달할 수 없다는 제약사항을 만족시키도록 예제를 변경하자

#include <iostream>
using namespace std;

class FruitSeller{
    private:
    int APPLE_PRICE;
    int numofApples;
    int myMoney;

    public:
    void InitMembers(int price, int num, int money){
        APPLE_PRICE = price;
        numofApples = num;
        myMoney = money;
    }
    int SaleApples(int money){
        if(money < 0){ // 추가되는 부분 
            cout<<"잘못된 값 입력"<<endl;
            return 0;
        }
        int num = money/APPLE_PRICE;
        numofApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult() const{
        cout<<"남은사과"<<numofApples<<endl;
        cout<<"수익"<<myMoney<<endl;
    }
};

class FruitBuyer{
    private:
        int myMoney;
        int numofApple;
    public:
        void InitMembers(int money){
            myMoney = money;
            numofApple = 0;
        }
        void BuyApples(FruitSeller &seller, int money){
            if (money<0){
                cout<<"잘못된 값 입력"<<endl;
                return;
            }
            numofApple += seller.SaleApples(money);
            myMoney -= money;
        }
        void ShowSalesResult() const{
        cout<<"남은사과"<<numofApple<<endl;
        cout<<"수익"<<myMoney<<endl;
    }
};

int main (void){
    FruitSeller seller;
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);

    buyer.BuyApples(seller,2000);

    cout<<"판매자 현황"<<endl;
    seller.ShowSalesResult();

    cout<<"구매자 현황"<<endl;
    buyer.ShowSalesResult();

    return 0;
}

