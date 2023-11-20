//인자로 전달되는 두 변수에 저장된 값을 서로 교환하는 swapData 라는 이름의 함수를 템플릿으로 정의해보자 그리고 다음 두 Point 클래스를 대상으로 값의 교환이 이뤄짐을 확인할 수 있도록 main함수를 구성해보자

#include<iostream>
using namespace std;

class Point {
    private :
        int xpos, ypos;
    public :
        Point(int x=0, int y=0):xpos(x), ypos(y){};
        void ShowPosition() const{
            cout<<"["<<xpos<<","<<ypos<<"]"<<endl;
        }
};

template <typename T>
void SwapData(T& A, T& B){ //참조값으로
    T tmp = A;
    A = B;
    B = tmp;
}

int main(void){
    Point pos1(1,2);
    Point pos2(5,6);

    cout<<"전"<<endl;
    pos1.ShowPosition();
    pos2.ShowPosition();

    SwapData(pos1, pos2);

    cout<<"후"<<endl;
    pos1.ShowPosition();
    pos2.ShowPosition();

    return 0;
}
