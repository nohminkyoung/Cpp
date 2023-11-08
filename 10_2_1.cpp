//OneOpndOverloading.cpp에서 보ㄴ Point를 대상으로 연산자를 오버로딩
// 부호연산자 -를 이용해서 피연산자의 부호를 반전시키기(멤버함수)
// ~연산자를 만들어서 xpos와 ypos의 값을 바꾸기(전역함수)

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

        //추가
        Point operator- (){
            Point pos(-xpos, -ypos);
            return pos;
        }

        friend Point operator~(const Point &);
};

Point operator~ (const Point &pos){
    Point pos1(pos.ypos, pos.xpos);
    return pos1;
}

int main(void){
    Point pos(9, -7);
    pos.ShowPosition();

    Point pos1 = -pos;
    pos1.ShowPosition();

    Point pos2 = ~pos;
    pos2.ShowPosition();

    return 0;
}