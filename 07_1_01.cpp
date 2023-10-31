// 문제에 나타나있는 클래스들을 각각의 상속관계에 맞게 생성자를 정의해보자 
#include <iostream>
using namespace  std;


class Car {
    private : 
        int gasolineGauge;
    public : 
        // 생성자
        Car(int gas){
            gasolineGauge = gas;
        }
        int GetGasGauge(){
            return gasolineGauge;
        }
};

class hybridCar : public Car {
    private :
        int electricGauge;
    public : 
        // 생성자
        hybridCar(int gas, int elec) : Car(gas), electricGauge(elec){

        }

        int GetElecGauge(){
            return electricGauge;
        }
};

class HybridWaterCar : public hybridCar{
    private :  
        int WaterGauge;
    public : 

        // 생성자
        HybridWaterCar(int gas, int elec, int water) : hybridCar(gas, elec){
            WaterGauge = water;
        }

        void ShowcurrentGauge(){
            cout<<"잔여 가솔린 : "<<GetGasGauge()<<endl;
            cout<<"잔여 전기량 : "<<GetElecGauge()<<endl;
            cout<<"잔여 물의양 : "<<WaterGauge<<endl;
        }
};


//main 생성
int main (void){
    HybridWaterCar WCar(10,20,30);
    WCar.ShowcurrentGauge();

    return 0;
}