//두 클래스에 적절한 생성자와 소멸자를 정의해보자 

#include <iostream>
#include<cstring>

using namespace std;

class MyFriendInfo{
    private :
        char * name;
        int age;
    public : 

        // 생성자 
        MyFriendInfo(char * n, int a) : age(a)
        {
            name = new char[strlen(n)+1];
            strcpy(name, n);
        }

        void ShowMyFriendInfo(){
            cout<<"이름 : "<<name<<endl;
            cout<<"나이 : "<<age<<endl;
        }

        //소멸자 
        ~MyFriendInfo(){
            delete []name;
        }
};

class MyFriendDetailInfo : public MyFriendInfo{
    private : 
        char * addr;
        char * phone;
    
    public : 
        //생성자
        MyFriendDetailInfo(char * n, int a, char * ad, char * ph) : MyFriendInfo(n, a){
            addr = new char[strlen(ad)+1];
            strcpy(addr, ad);

            phone = new char[strlen(ph)+1];
            strcpy(phone, ph);
        }

        void ShowMyFriendDetailInfo(){
            ShowMyFriendInfo();
            cout<<"주소 : "<<addr<<endl;
            cout<<"전화 : "<<phone<<endl;
        }

        //소멸자
        ~MyFriendDetailInfo(){
            delete []addr;
            delete []phone;
        }
};

int main(void){
    MyFriendDetailInfo Friend("노민경", 27, "경기", "010-1234-5678");
    Friend.ShowMyFriendDetailInfo();

    return 0;
}