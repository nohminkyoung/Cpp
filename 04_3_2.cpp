//명함을 의미하는 NameCard클래스를 정의(성명, 회사명, 전화번호, 직급)
// 단 직급정보를 제외한 나머지는 문자열의 형태로 저장하되, 길이에 딱 맞는 메모리 공간을 할당받는 형태로 정의하자
// 직급정보는 int형 멤버변수를 선언해 저장하되, enum선언을 활용한다 

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
    NameCard man2("Lee1", "ABC1", "010-222-2222", COMP_POS::SENIOR);
    NameCard man3("Lee3", "ABC2", "010-3333-3333", COMP_POS::ASSIST);
    
    man1.showNameCard();
    man2.showNameCard();
    man3.showNameCard();

}