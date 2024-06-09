#include<iostream>
using namespace std;

class custom_class{
    public:
    string name="我是被引用对象中的对象成员";
};

class test{
    public:
    void parameter_kinds(string str,string* str_pointer,custom_class class_name){
    cout<<"第一种参数传值调用"<<str<<endl;
    cout<<"第二种指针调用"<<str_pointer<<endl;
    cout<<"第二种引用调用"<<class_name.name<<endl;
}
};

int main()
{
    string str="我是一个字符串";
    string* str_pointer=&str;
    custom_class custom=custom_class();
    test test1=test();
    test1.parameter_kinds(str,str_pointer,custom);
}
