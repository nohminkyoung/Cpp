//좌표를 표현할 수 있는 구조체를 기반으로 다음의 함수를 정의해보자(좌표이동, 좌표증가, 현재의 좌표 출력)

#include<iostream>

struct Point
{
    int xpos;
    int ypos;

    void MovePos(int x, int y){
        xpos += x;
        ypos += y;
    }

    void AddPos (const Point &pos){
        xpos += pos.xpos;
        ypos += pos.ypos;
    }

    void ShowPos(){
        std::cout<<"["<<xpos<<","<<ypos<<"]"<<std::endl;
    }
};

int main(void){
    Point pos1 = {12,4};
    Point pos2 = {20,30};

    pos1.MovePos(-7, 10);
    pos1.ShowPos();

    pos1.AddPos(pos2);
    pos1.ShowPos();

    return 0;
}
