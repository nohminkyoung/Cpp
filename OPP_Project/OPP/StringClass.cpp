#include"StringClass.h"
// 선언 후 초기화 없을 때 
String::String(){
	len = 0;
	str = NULL;
}

// 생성자 
String::String(const char * s){
	len = strlen(s) +1;
	str = new char[len];
	strcpy(str, s);
}

//소멸자
String::~String() {
	if(str!=NULL){
		delete []str;}
}


// 복사생성자 
String& String::operator=(const String& s){
	if(str!=NULL){
		delete []str;}
    
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);

    return *this;
}

String& String::operator+=(const String& s){
    len += s.len -1; 
    char * tmpstr = new char[len];
    
    strcpy(tmpstr, str);
    strcat(tmpstr, s.str);

    if(str!=NULL){
        delete []str;
    }
    str=tmpstr;
    return *this;
}

String& String::operator+(const String& s){
    char * tmpstr = new char[len+s.len-1];
    strcpy(tmpstr, str);
    strcat(tmpstr, s.str);

    String tmp(tmpstr);
    delete []tmpstr;
    return tmp;
}

bool String::operator==(const String& s){
    return strcmp(str, s.str) == 0  ? true : false;
}


// 전역함수 <<와 >> 생성
ostream& operator<<(ostream& os, const String& s){
    os<<s.str;
    return os;
}

istream& operator>>(istream& is,String& s){
    
    char str[100];
    is >> str;
    s = String(str);
    return is;
}