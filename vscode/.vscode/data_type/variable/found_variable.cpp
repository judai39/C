#include<iostream>   
using namespace std;  

class test{
    public:
        typedef int customInt;
        customInt customNum=1;
};
    int main(){
            //错!!!!!!c++中的字符串字符串类型就是基本数据类型,不是引用数据类型
            //是引用类型,只不过是放在std命名空间作静态成员调用
    string s1="ddd";
    cout<<&s1<<s1<<endl;
    s1=s1+"dd";
    cout<<&s1<<s1<<endl;

    int num1=1;
    cout<<&num1<<endl;

    double num2=2.12;
    cout<<num2<<endl;

//存疑
    float num3=1.17549;
    //有效数字
    cout<<num3<<endl;

    double num4=1.222222222;
    cout<<num4<<endl;

    // char charest1='za';  overflow in conversion from 'int' to 'char' changes value from '31329' to '97' 输出的值为最后一个字符a
    char charest1='d';
    cout<<charest1<<endl;
//存疑 wchar_t是一个数?    
    wchar_t charest2='您';
    cout<<charest2<<endl;
    
    }