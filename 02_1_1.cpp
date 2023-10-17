//참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하라
// 인자로 전달된 int형 변수의 값을 1씩 증가시키는 함수
// 인자로 전달된 int형 변수의 부호를 바꾸는 함수

#include<iostream>

void plus_one(int &num){
    num++;
}

void change(int &num){
    num *= -1;
}

int main(void){
    int val = 1;
    plus_one(val);
    std::cout<<val<<std::endl;

    change(val);
    std::cout<<val<<std::endl;

    return 0;
}