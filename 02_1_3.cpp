// ptr1과 ptr2가 각각 num1,num2를 가리키는데 swap(ptr1,ptr2)로 ptr1과 2가 가리키는 대상을 바꾸도록 함수를 정의해보자

#include<iostream>

void swap(int * (&rptr1), int * (&rptr2)){ // ptr1,ptr2의 참조자 생성 -> 각 ptr에 담겨있는 값을 서로 바꿔줘서 참조하는 변수를 바꿔주기
    int * x = rptr1;
    rptr1 = rptr2;
    rptr2 = x;

}


int main(void){
    int num1 = 5;
    int * ptr1 = &num1;
    int num2 = 10;
    int * ptr2 = &num2;

    swap(ptr1, ptr2);
    std::cout<<*ptr1<<" "<<*ptr2<<std::endl;

    return 0;
}