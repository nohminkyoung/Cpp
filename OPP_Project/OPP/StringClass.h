#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String{
	private :
			int len;
			char * str;

		public : 
			String(); //생성자
			String(const char * s); // 생성자
			String(const String& s); // 복사생성자
			~String(); //소멸자

			String& operator=(const String& s); //대입연산
			String& operator+(const String& s); 
			String& operator+=(const String& s);
			bool operator==(const String& s); // 내용 비교

			friend ostream& operator<<(ostream& os, const String& s);
			friend istream& operator>>(istream& is, String& s);

};

#endif