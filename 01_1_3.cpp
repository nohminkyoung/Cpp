//숫자 하나를 입력받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램

#include<iostream>

int main(void){
    int num;
    std::cout<<"몇 단?";
    std::cin>>num;

    for(int i=1; i<=9;i++){
        std::cout<<num<<"x"<<i<<"="<<num*i<<std::endl;
    }

    return 0;
}