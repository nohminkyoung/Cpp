// p.41의 Namesp2.cpp을 헤더파일(main함수응 제외한 나머지 두 함수의 선언을 삽입), 소스파알1(main함수를 제외한 나머지 두 함수의 정의를 삽입), 소스파일2(main함수만 삽입)으로 나눠서 컴파일


// Namesp2.cpp
#include<iostream>

namespace BestComImpl{
    void SimpleFunc(void);
}

namespace ProgComImpl{
    void SimpleFunc(void);
}

int main (void){
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}

void BestComImpl::SimpleFunc(void){
    std::cout<<"BestCom이 정의한 함수"<<std::endl;
}

void ProgComImpl::SimpleFunc(void){
    std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}