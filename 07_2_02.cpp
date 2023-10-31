//책을 의미하는 Book 클래스와 전자책을 의미하는 EBook 클래스를 정의, EBook클래스에는 Book클래스의 정보보다 Key을 하나 더 가지고있다. 

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

        void ShowEBookinfo(){
            Showinfo();
            cout<<"키 : "<<DRM<<endl;
        }
};

int main(void){
    Book A ("좋은책", "555-5655", 20000);
    A.Showinfo();

    EBook B("좋은책Ebook", "666-5465", 10000, "A12345sSS");
    B.ShowEBookinfo();

    return 0;
}