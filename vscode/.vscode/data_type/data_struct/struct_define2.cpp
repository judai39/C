#include<iostream>
#include<cstring>
using namespace std;

struct CBooks{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
//4.结构体指针
int main(){
    CBooks Book1;
    strcpy(Book1.title,"C++,从入门到入坑");
    strcpy(Book1.author,"无名氏");
    strcpy(Book1.subject,"教程类");
    Book1.book_id=1;
    cout<<&Book1<<endl;

    struct CBooks* struct_pointer=&Book1;
    cout<<struct_pointer<<endl;//输出结构体地址
    cout<<struct_pointer->title<<endl;//输出指针变量指向结构体成员
    cout<<struct_pointer->author<<endl;
    cout<<*struct_pointer<<endl;
    
}