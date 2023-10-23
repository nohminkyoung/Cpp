//Point클래스를 기반으로 원을 나타내는 Cricle클래스를 정의 -> 이를 가반으로 두개의 원을 정의하는 Ring 클래스도 구현

#include<iostream>
using namespace std;

class Point {
    private :
        int xpos;
        int ypos;

    public:
    void initpos(int x, int y) {
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
        void initcircle(int x, int y, int r){
            rad = r;
            center.initpos(x,y);
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
        void initring(int inx,int iny,int inr,int outx,int outy,int outr){
            incircle.initcircle(inx, iny, inr);
            outcircle.initcircle(outx, outy, outr);
        }
        void showring(){
            cout<<"in"<<endl;
            incircle.showcircle();
            cout<<"out"<<endl;
            outcircle.showcircle();
        }      
};

int main(void){
    Ring ring;
    ring.initring(1,1,4,2,2,9);
    ring.showring();

    return 0;

}