//C++의 string과 같은 기능을 하는 클래스 만들어보기 
// 생성자, 소멸자, 복사연산자, 대입연산자, +, +=, ==, <<,>>

#include<iostream>
#include<cstring>
using namespace std;

class String{
    private :
        int len;
        char * str;

    public : 
        String(); //생성만 하고 초기화를 안햇을경우
        String(const char * s); // 생성자
        String(const String& s); // 복사연산자
        ~String();

        String& operator=(const String& s); //대입연산자
        bool operator==(const String& s);  // True, False 를 반환 
        String& operator+=(const String& s);
        String operator+(const String& s);

        // <<, >>의 전역함수의 접근을 허용
        friend ostream& operator<<(ostream& os, const String& s);
        friend istream& operator<<(istream& is, String& s);
        
};

// 생성자
String::String(){
    len = 0;
    str = NULL;
}

String::String(const char * s){
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
}

// 복사연산자
String::String(const String& s){
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);
}

//소멸자
String::~String(){
    if(str != NULL){
        delete []str;
    }
}

//대입연산자
String& String::operator=(const String& s){
    if(str!=NULL){
        delete []str; // 값이 있으면 지우고 다시 만들어야함
    }
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);

    return *this;

}

bool String::operator==(const String& s){
    return strcmp(str,s.str) ?  true : false;
}

String& String::operator+=(const String& s){
    len+=s.len;

    char * tmp = new char[len]; // s.len에 문자열 종료담겨있음
    strcpy(tmp, str);
    strcat(tmp, s.str);

    if(str!=NULL){
        delete []str; //원래 내용 삭제
    }
    str = tmp;
    return *this;
}

//+는 원래의 객체를 변경하는게 아니고, 새로운 객체를 생성할 때 사용(a= b+c), 그래서 객체를 만들어서 반환
String String::operator+(const String& s){
    char * tmp = new char[len+s.len]; // s.len에 문자열 종료담겨있음
    strcpy(tmp, str);
    strcat(tmp, s.str); // 뒤에 추가

    String tmpstring(tmp);
    return tmpstring;
}


ostream& operator<<(ostream& os, const String& s){
    os<<s.str;
    return os;
}

istream& operator>>(istream& is, String& s){
    char str[100];
    is>>str;
    s = String(str);
    return is;
}

int main(void){
    String str1 = "I like ";
    String str2 = "String class";
    String str3 = str1 + str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;

    str1+=str2;
    if(str1==str2){
        cout<<"동일"<<endl;
    }else{
        cout<<"동일xx"<<endl;
    }

    String str4;
    cout<<"문자열 입력"<<endl;
    cin>>str4;
    cout<<"입력한 문자열"<<str4<<endl;
    return 0;

}