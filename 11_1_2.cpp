//07_2문제에서 정의한 클래스에서 두 클래스 모두 깊은 복사가 되도록 복사생성자와 대입연산자 정의

#include<iostream>
#include<cstring>
using namespace std;

class Book{
    private : 
        char * name;
        char * isbn;
        int price;
    public :
        Book(char * n, char * is, int p) : price(p){
            name = new char[strlen(n)+1];
            strcpy(name, n);
            isbn = new char[strlen(is)+1];
            strcpy(isbn, is);
        }

        //복사생성자 
        Book(const Book& ref):price(ref.price){
            name = new char[strlen(ref.name)+1];
            isbn = new char[strlen(ref.isbn)+1];

            strcpy(name, ref.name);
            strcpy(isbn, ref.isbn);
        }
        //대입연산자
        Book& operator=(const Book& ref){
            delete []name;
            delete []isbn;

            name = new char[strlen(ref.name)+1];
            isbn = new char[strlen(ref.isbn)+1];

            strcpy(name, ref.name);
            strcpy(isbn, ref.isbn);
            price = ref.price;

            return *this;
        }

        void Showinfo(){
            cout<<"제목 : "<<name<<endl;
            cout<<"ISBN : "<<isbn<<endl;
            cout<<"가격 : "<<price<<endl;
        }

};

class EBook : public Book{
    private :
        char * DRM;
    
    public : 
        EBook(char * n, char * is, int p, char * D) : Book(n, is, p){
            DRM = new char[strlen(D)+1];
            strcpy(DRM, D);
        }

        EBook(const EBook& ref):Book(ref){
            DRM = new char[strlen(ref.DRM)+1];
            strcpy(DRM, ref.DRM);
        }

        EBook& operator= (const EBook& ref){
            Book::operator=(ref);
            delete[]DRM;
            DRM = new char[strlen(ref.DRM)+1];
            strcpy(DRM, ref.DRM);
            return *this;
        }


        void ShowEBookinfo(){
            Showinfo();
            cout<<"키 : "<<DRM<<endl;
        }
};

int main(void){
    EBook A("좋은책Ebook", "666-5465", 10000, "A12345sSS");
    EBook B = A;
    B.ShowEBookinfo();

    EBook C("ss","ss",0,"sss");
    C = B;
    C.ShowEBookinfo();

    return 0;
}