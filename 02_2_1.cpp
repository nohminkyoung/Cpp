// const int num = 12를 선언한 후 포인터 변수를 하나 선언해 이 변수를 가리키게 해보자. 그리고 이 포인터 변수를 참조하는 참조자를 하나 ㅅ선언하자
// 마지막으로ㅓ 이렇게 선언 된 포인터 변수와 참조자를 이용해서 num에 저장된 값을 출력하는 예제를 완성해보자

#include<iostream>

using namespace std;

int main(void){
    const int num = 12;

    const int * ptr = &num;
    const int * (&refptr) = ptr;
    
    cout<<*ptr<<endl;
    cout<<*refptr<<endl; // 얘도 주소값을 참조하니까 *필요

    return 0;   
}