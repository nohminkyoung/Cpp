//위의 구조체를 기반으로 두 점의 합을 계산하는 함수를 다음의 형태로 정의하고 임의의 두 점을 선언해 이용한 덧셈연산을 진행하자 단 Poin 관련 변수의 선언은 무조건 new연산자를 이용해서 진행해야하며 할당된 메모리 공간의 소멸도 철저해야한다
//PntAdder(const Point &p1, const Point &p2)

#include<iostream>

typedef struct Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){ // Point의 참조자를 반환, 매개변수는 구조체의 참조자를 받음
    Point * ptr = new Point;  // 동적할당을 위해 
    ptr->xpos = p1.xpos+p2.xpos;
    ptr->ypos = p1.ypos+p2.ypos;
    
    return *ptr;
}

int main(void){
    Point * ptr1 = new Point;
    ptr1->xpos = 10;
    ptr1->ypos = 20;

    Point * ptr2 = new Point;
    ptr2 -> xpos = 1;
    ptr2 -> ypos = 2;

    Point &addptr = PntAdder(*ptr1, *ptr2); //반환값이 참조자
    std::cout<<"["<<addptr.xpos<<","<<addptr.ypos<<"]";

    delete ptr1;
    delete ptr2;
    delete &addptr;

    return 0;

}

