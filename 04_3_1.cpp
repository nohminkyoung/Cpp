//04_2_1에서 정의한 클래스의 객체를 초기화함수를 생성해 초기화 해보자


#include<iostream>
using namespace std;

class Point {
    private :
        int xpos;
        int ypos;

    public:
        Point(int x, int y){
            xpos = x;
            ypos = y;
        }
    void showpoin() const{
        cout<<"["<<xpos<<","<<ypos<<"]"<<endl;

    }
};

class Circle{
    private:
        int rad;
        Point center;

    public:
        Circle(int x, int y, int r) :center(x,y){
            rad = r;
        }
        void showcircle() const{
            cout<<"radius : "<<rad<<endl;
            center.showpoin();
        }
};

class Ring {
    private:
        Circle incircle;
        Circle outcircle;

    public :
        Ring(int inx,int iny,int inr,int outx,int outy,int outr) :incircle(inx, iny, inr), outcircle(outx, outy, outr){}

        void showring(){
            cout<<"in"<<endl;
            incircle.showcircle();
            cout<<"out"<<endl;
            outcircle.showcircle();
        }      
};

int main(void){
    Ring ring(1,1,4,2,2,9);
    ring.showring();

    return 0;

}