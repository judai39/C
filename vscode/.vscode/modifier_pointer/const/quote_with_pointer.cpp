#include<iostream>
using namespace std;

int main(){
    //引用声明与指针声明的区别:
    //不存在空引用。引用必须连接到一块合法的内存。  但指针可以随便声明(指针头)
    //一旦引用被初始化为一个对象，就不能被指向到另一个对象。    指针可以在任何时候指向到另一个对象。
    //引用必须在创建时被初始化。    指针可以在任何时间被初始化。    

    //引用声明
    int num=17;
    int& i=num;
    
    int * p=&num;
    //int *p=i; invalid conversion from 'int' to 'int*' 说明虽然看上去 int&返回的是一个*int,但实际上是一个int
    //(同时这也体现了,如果过想让指针初始化,就只能指向*type类型)
}