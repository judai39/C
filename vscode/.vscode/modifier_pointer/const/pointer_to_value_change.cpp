#include<iostream>
using namespace std;

int main(){
    int num1=1;
    int num2=2;
    cout<<&num1<<endl;
    cout<<&num2<<endl;

    int* pointer1=&num1;
    cout<<*pointer1<<"--"<<pointer1<<endl;
    // pointer1=&num2;  //指针尾改变而导致的值改变仅仅是因为地址寻址的间接印象
    *pointer1=num2;     //指针头改变会改变引用变量的实值
    cout<<*pointer1<<"--"<<pointer1<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
}