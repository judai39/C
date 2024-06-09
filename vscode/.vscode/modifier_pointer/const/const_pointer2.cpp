#include<iostream>
using namespace std;

/*修饰符不算做内存,其存在是为了使对象处于一种状态*/

class const_pointer_parameter{
    public:
    string str="我是类中字符串";
    void parameter_test(const string *pointer){
        string *p=&str;
        cout<<str<<" "<<*p<<" "<<p;
        p=(string*)pointer;//注意指针转换时的类型转换
        // *p=pointer;  //no match for 'operator ='(std:string and std::string*)
        cout<<str<<" "<<*p<<" "<<p;
    }
};
class const_position_return{
    public:
    string str="我是类中字符串";
    //string& str    引用类型(数据类型为string),也可以理解为指针头指向对象
    //string* str    引用变量指针尾,也可以理解为指针地址
    const string& return_test_fun1(string& position){
        string *p=&str;
        p=&position; //取地址对象的地址值
        return *p;
    }
    //参数也可以下形式
    const string& return_test_fun2(string* position){
        string *p=&str;
        p=position;
        return *p;
    }
    
};

int main(){
//4.上文3例说明了const修饰指针对象*p(ointer)的情况,本例作为对照说明const修饰指针指向的地址位置p(osition)
    int num1=1;
    int num2=2;

    int * const p=&num1;
    //被const修饰的地址位置p(osition)无法被更改,但指针对象可以被更改
    // p=&num2;    assignment of read-only variable p(只读)
    *p=num2;//通过编译,可以改变指针对象*p

//5.从四例得知,const修饰一个常量p的情况,接下来分析const_pointer在方法中的各种情况
    // 5.1.const *pointer      作为参数
    const_pointer_parameter obj1=const_pointer_parameter();
    string str="我是一个普通的string,我要被指针指向了";
    const string *p_str1=&str;
    obj1.parameter_test(p_str1);
    //这里会发现str的值没有实现交换,对指针的中介属性有了新的理解,
    //*p_str代表"指针头"(用于指向别的成员),str变量代表"指针尾"(用于初始化指针),p_str代表指向的对象成员
    //

    //5.2.const &positon        作为返回值
    string str2="我是一个普通的string,我要被指针指向了";
    string *p_str2=&str2;
    const_position_return obj2=const_position_return();
    cout<<obj2.return_test_fun1(*p_str2)<<endl;
    cout<<obj2.return_test_fun2(p_str2)<<endl;
    cout<<p_str2<<endl;
    cout<<*p_str2<<endl;
    string point=&p_str2;
    cout<<point<<endl;
}