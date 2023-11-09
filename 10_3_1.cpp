// 예제 PointConsloeOutput.cpp 에서 정의한 Point 클래스를 대상으로 >>연산자를 오버로딩 해보자

#include<iostream>
using namespace std;

class Point{
    private : 
        int xpos, ypos;

    public : 
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        
        void ShowPosition() const{
            cout<<'['<<xpos<<','<<ypos<<']'<<endl;
        }

        friend ostream& operator<<(ostream&, const Point& pos);
        friend istream& operator>>(istream& , Point& pos);
};


ostream& operator<<(ostream& o, const Point& pos){
    o<<"["<<pos.xpos<<","<<pos.ypos<<"]"<<endl;
    return o;
}

istream& operator>>(istream& i, Point& pos){
    i>>pos.xpos>>pos.ypos;
    return i;
}

int main(void){
    Point pos1;
    cout<<"x,y좌표를 순서대로 입력"<<endl;
    cin>>pos1;
    cout<<pos1;

    Point pos2;
    cout<<"x,y좌표를 순서대로 입력"<<endl;
    cin>>pos2;
    cout<<pos2;

    return 0;

}