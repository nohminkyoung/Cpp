//계산기 기능의 Calculator클래스를 정의해보자(덧셈 뺄셈 곱셈 나눗셈, 각 계산의 횟수) 맴버 변수는 private, 맴버 함수는 public으로 선언 

#include <iostream>
using namespace std;

class Calculator{
    private :
        int numadd;
        int nummin;
        int nummul;
        int numdiv;
    

    public :
        void Init(); //각 횟수 초기화
        double Add(double num1, double num2);
        double Min(double num1, double num2);
        double Mul(double num1, double num2);
        double Div(double num1, double num2);
        void Show();
};

void Calculator::Init(){
    numadd = 0;
    nummin = 0;
    nummul = 0;
    numdiv = 0;
}
double Calculator::Add(double num1, double num2){
    numadd++;
    return num1 + num2;
}
double Calculator::Min(double num1, double num2){
    nummin++;
    return num1 - num2;
}
double Calculator::Mul(double num1, double num2){
    nummul++;
    return num1 * num2;
}
double Calculator::Div(double num1, double num2){
    numdiv++;
    return num1 / num2;
}
void Calculator::Show(){
    cout<<numadd<<nummin<<nummul<<numdiv<<endl;
}

int main (void){
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2,2.4)<<endl;
    cout<<"3.2 - 2.4 = "<<cal.Min(3.2,2.4)<<endl;
    cout<<"3.2 * 2.4 = "<<cal.Mul(3.2,2.4)<<endl;
    cout<<"3.2 / 2.4 = "<<cal.Div(3.2,2.4)<<endl;
    cal.Show();

    return 0;
}
