// 04-3-2를 통해 만든 NameCard 클래스는 메모리 공간을 동적할당 하기 때문에 복사생성자가 필요하다. 이에 복사생성자를 적절히 정의해보자

#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void showPosition(int pos){
        switch (pos)
        {
        case CLERK:
            cout<<"사원"<<endl;
            break;
        case SENIOR :
            cout<<"주임"<<endl;
            break;
        case ASSIST :
            cout<<"대리"<<endl;
            break;
        case MANAGER :
            cout<<"과장"<<endl;
            break;
        }
    }
}

class NameCard{
    private:
        char * name;
        char * company;
        char * phone;
        int position;

    public:
        NameCard(char * name1, char * company1, char * phone1, int position1): position(position1){
            name = new char[strlen(name1+1)];
            company = new char[strlen(company1+1)];
            phone = new char[strlen(phone1+1)];
            
            strcpy(name, name1);
            strcpy(company, company1);
            strcpy(phone, phone1);
        }

        //추가 시작
        NameCard(const NameCard & namecard) :position(namecard.position){
            name = new char[strlen(namecard.name)+1];
            company = new char[strlen(namecard.company)+1];
            phone = new char[strlen(namecard.phone)+1];

            strcpy(name, namecard.name);
            strcpy(company, namecard.company);
            strcpy(phone, namecard.phone);
        }
        //추가 끝
        
        void showNameCard(){
            cout<<"이름 : "<<name<<endl;
            cout<<"회사 : "<<company<<endl;
            cout<<"전화번호 : "<<phone<<endl;
            cout<<"직책 : "<<position<<endl;
        }
        ~NameCard(){
            delete []name;
            delete []company;
            delete []phone;
        }
};

int main(void){
    NameCard man1("Lee", "ABC", "010-111-1111", COMP_POS::CLERK);
    NameCard copy1 = man1;

    NameCard man2("Lee1", "ABC1", "010-222-2222", COMP_POS::SENIOR);
    NameCard copy2 = man2;
    
    copy1.showNameCard();
    copy2.showNameCard();

    return 0;
}