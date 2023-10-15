//급여계산프로그램, 모든 판매원에게 매달 50만원의 기본급여와 물품판매가격의 12%에 해당하는 돈을 지급, -1을 입력하면 종료

#include<iostream>

int main(void){
    int s;

    while (1)
    {
        std::cout<<"판매 금액을 만원단위로 입력";
        std::cin>>s;

        if(s==-1){
            std::cout<<"프로그램 종료";
            break;
        }
        else{
            std::cout<<"이번 달 급여"<<50+s*0.12<<std::endl;
        }
    }

    return 0;
    
    
}