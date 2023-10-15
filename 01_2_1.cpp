//main함수에서 필요로 하는 swap함수를 오버로딩해서 구현해보자 

#include<iostream>

void swap(int * a, int * b){
    
    int x = *a;
    *a = *b;
    *b = x;
}

void swap(char * a, char * b){
    
    char x = *a;
    *a = *b;
    *b = x;
}

void swap(double * a, double * b){
    
    double x = *a;
    *a = *b;
    *b = x;
}

int main(void){
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout<<num1<<" "<<num2<<std::endl;

    char ch1='a', ch2='z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<" "<<ch2<<std::endl;

    double db1 = 0.12, db2 = 1.34;
    swap(&db1, &db2);
    std::cout<<db1<<" "<<db2<<std::endl;


}
