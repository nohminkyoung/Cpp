//p.31에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌 '한수 오버로딩의 형태로 재구현 해보자. 

#include<iostream>

int BoxVolume(int length, int width, int heigth){
    return length*width*heigth;
}

int BoxVolume(int length, int width){
    return length*width*1;
}

int BoxVolume(int length){
    return length*1*1;
}

int BoxVolume(){
    return 1*1*1;
}

int main(void){
    std::cout<<"[3,3,3] : " << BoxVolume(3,3,3)<<std::endl;
    std::cout<<"[5,5,D] : " << BoxVolume(5,5)<<std::endl;
    std::cout<<"[7,D,D] : " << BoxVolume(7)<<std::endl;
    std::cout<<"[D,D,D] : " << BoxVolume()<<std::endl;
}