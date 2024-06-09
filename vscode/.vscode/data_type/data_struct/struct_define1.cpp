#include<iostream>
#include<cstring>
using namespace std;


// C/C++ 数组允许定义可存储相同类型数据项的变量，但是结构是 C++ 中另一种用户自定义的可用的数据类型，它允许你存储不同类型的数据项。

//总感觉和类很相似
//虽然看起来很相似,但是有着根本上的不同,类大部分包裹的是"逻辑",即使有少部分的变量,常量,那些也是为了逻辑而设置的;;;;但结构是数据的存储,专用于数据的存储规范
//可以类比于xml(数据集),html(数据显示(也是一种规范))

//1.定义结构
struct CBooks{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

//3.结构作参数
void print(struct CBooks book){
    cout<<book.title<<endl;
    cout<<book.author<<endl;
    cout<<book.subject<<endl;
    cout<<book.book_id<<endl;
}


//2.使用
int main(){
    CBooks Book1;
    CBooks Book2;

    //数据详述
    strcpy(Book1.title,"C++,从入门到入坑");
    strcpy(Book1.author,"无名氏");
    strcpy(Book1.subject,"教程类");
    // Book1.subject="教程类"; 不可直接添加,因为c++中的有关string的功能是引入自c的,若想使用功能则需要使用对应组件中的方法(并且要声明宏定义cstring)
    Book1.book_id=1;

    //输出信息
    cout<<Book1.title<<endl;
    cout<<Book1.author<<endl;
    cout<<Book1.subject<<endl;
    cout<<Book1.book_id<<endl;
    print(Book1);
}
