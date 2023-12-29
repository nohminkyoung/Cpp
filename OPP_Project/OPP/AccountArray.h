// Accout 정보를 저장할 배열정의

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

template<typename T>
class BoundingCheckArray{
    private :
        T * arr;
        int arrlen;

    public :
        BoundingCheckArray(int len=100);
        T& operator[](int index);
        T operator[](int index) const;
        int GetArrLen() const;
        ~BoundingCheckArray();

        BoundingCheckArray(const BoundingCheckArray& arr){}; 
        BoundingCheckArray& operator=(const BoundingCheckArray& arr){};

};

template<typename T>
BoundingCheckArray<T>::BoundingCheckArray(int len=100):arrlen(len){
    arr = new T[len];
}

template<typename T>
T& BoundingCheckArray<T>::operator[](int index){
    if(index<0 || index>=arrlen){
        cout<<"올바르지않은 인덱스"<<endl;
        exit(1);
    }

    return arr[index];
}

template<typename T>
T BoundingCheckArray<T>::operator[](int index) const{
    if(index<0 || index>=arrlen){
        cout<<"올바르지않은 인덱스"<<endl;
        exit(1);
    }

    return arr[index];
}

template<typename T>
int BoundingCheckArray<T>::GetArrLen() const{
    return arrlen;
}

template<typename T>
BoundingCheckArray<T>::~BoundingCheckArray(){
    delete []arr;
}


#endif