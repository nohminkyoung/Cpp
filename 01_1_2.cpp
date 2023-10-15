//프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력받은 데이터를 그대로 출력하는 프로그램을 작성해보자

 #include<iostream>

 int main(void){

    char str[100];
    std::cout<<"문자를 입력하세요";
    std::cin>>str;

    std::cout<<"사용자가 입력한 문장 : "<<str;

    return 0;
 }