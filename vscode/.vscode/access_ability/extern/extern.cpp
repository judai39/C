#include <iostream>
using namespace std;

int count;
//extern存储类提供一个全局变量的引用,对所有程序文件可见,被extern修饰的成员会在赋初始值之前去寻找其他文件的其他地址
extern void write_extern();
// extern string str="extern声明的成员不能主动初始化,需要在其他类中初始化";

int main(){
    count=5;
    write_extern();
}