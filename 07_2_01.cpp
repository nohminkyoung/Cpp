//정사각형을 의미하는 square클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다. 정사각형 클래스가 직사각형 클래스를 상속받도록 상속관계를 구성해보자

#include<iostream>
using namespace std;

class Rectangle{
    private : 
        int x;
        int y;
    public :
        Rectangle(int a, int b){
            x = a;
            y = b;
        }
        void ShowArea(){
            cout<<"면적 : "<<x*y<<endl;
        }
};

class Square : public Rectangle
{
    public : 
        Square(int a) : Rectangle(a,a){

        } 
        void ShowSqu(){
            ShowArea();
        }
};

int main (void){
    Rectangle A(3,4);
    A.ShowArea();

    Square B(3);
    B.ShowSqu();
}