//C의 string.h에 선언된 함수들을 C++의 표준함수로 구현하기

#include<iostream>
#include<cstring>

using namespace std;


int main(void){
    char str1[] = "ABC 123";
    char str2[] = "DEF 456";
    char str3[50];

    cout<<strlen(str1)<<endl; // 길이
    cout<<strlen(str2)<<endl;

    strcpy(str3, str1);     // 복사
    strcpy(str3, str2);
    cout<<str3<<endl;

    if(strcmp(str1,str2)==0){
        cout<<"문자열이 같다."<<endl;
    }else{
        cout<<"문자열이 다르다."<<endl;
    }

    return 0;
}