//Chapter7의 HASComposite.cpp를 통해서 선언된 클래스들에 대해 Police를 대상으로 깊은 복사가 이뤄지도록 대입연산자와 복사생성자를 동시에 정의하고 적절한 main함수를 정의하자 

#include<iostream>
#include<cstring>

using namespace std;

class Gun{
    private :  
        int bullet;
    public :
        Gun(int bnum):bullet(bnum){};
        void shot(){
            cout<<"bbang"<<endl;
            bullet--;
        }
};

class Police{
    private :
        int handcuffs;
        Gun * pistol; //보유한 gun class를 포인터변수로 받아옴

    public :
        //생성자
        Police(int bnum, int bcuff):handcuffs(bcuff){
            if(bnum>0){
                pistol = new Gun(bnum);
            }else{
                pistol = NULL;
            }
        }
        //복사생성자
        Police(const Police & ref):handcuffs(ref.handcuffs){
            if(ref.pistol==NULL){
                pistol = NULL;
            }else{
                pistol = new Gun(*(ref.pistol)); //복사생성자 호출
            }
        }

        Police& operator=(const Police & ref){
            if(pistol!=NULL){
                delete pistol; // 데이터 삭제
            }

            if(ref.pistol==NULL){
                pistol = NULL;
            }else{
                pistol = new Gun(*(ref.pistol)); 
            }
            handcuffs = ref.handcuffs;
            return *this;
        }

        void PutHandcuff(){
            cout<<"SANP"<<endl;
            handcuffs--;
        }

        void shot(){
            if (pistol==NULL){
                cout<<"Hut bbang"<<endl;
            }else{
                pistol->shot();
            }
            
        }

        ~Police(){
            if (pistol!=NULL){
                delete pistol;
            }
        }
};

int main (void){
    Police pman1(5,3);
    Police pman2 = pman1;
    pman2.PutHandcuff();
    pman2.shot();

    Police pman3(2,4);
    pman3=pman1;
    pman3.PutHandcuff();
    pman3.shot();

    return 0;
}