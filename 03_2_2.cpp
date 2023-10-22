//문자열 정보를 내부에 저장하는 Printer 클래스 정의(문자열 저장, 출력), 맴버변수는 private, 맴버함수는 public

#include <iostream>
#include<cstring>

class Printer
{
private:
    char str[50];

public:
    void Set(char * s);
    void Print();
};

void Printer::Set(char * s){
    strcpy(str, s); // str에 s복사
}
void Printer::Print(){
    std::cout<<str<<std::endl;
}

int main(void){
    Printer pnt;
    pnt.Set("Hello");
    pnt.Print();

    pnt.Set("bye");
    pnt.Print();

    return 0;
}
