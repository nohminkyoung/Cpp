//rand, srand, time을 활용해서 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들되 C++의 헤더를 선언해서 작성해보자
// time : time.h, rand+srand : stdlib.h

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void){
    srand(time(NULL)); // 얘를 선언해줘야 난수가 돼
    for(int i =0; i<5;i++){
        cout<<rand()%100<<endl;
    }

    return 0;
}