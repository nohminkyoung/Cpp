// 문제의 int형 배열의 값을 모두 저장하는 함수를 템플릿으로 정의하여 다양한 자료형의 배열을 대상으로 합을 계산하는 에제를 작성해보자

/*int SumArry(int arr[], int len){
    int sum = 0;
    for (int i=0; i<len; i++){
        sum += arr[i];
    }
    return sum;
}*/


#include<iostream>
using namespace std;

template <typename T>
T SumArry(T arr[], int len){
    T sum = 0;
    for (int i=0; i<len; i++){
        sum += arr[i];
    }
    return sum;
}

int main(void){
    int arr1[] ={4,6,9,10};
    cout<<SumArry(arr1, sizeof(arr1)/sizeof(int))<<endl;

    double arr2[] ={4.2,6.6,10.3};
    cout<<SumArry(arr2, sizeof(arr2)/sizeof(double))<<endl;

    return 0;
}