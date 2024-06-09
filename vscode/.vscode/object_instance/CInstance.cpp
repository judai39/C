#include <iostream>
using namespace std;

extern string extern_member;//extern声明必须在全局,一般在调用处声明


class CInstance{
    private:
    int id;

    public:
    CInstance(int id){
        this->id=id;
        output();
        cout<<"这是CInstance的有参构造,id值为"<<this->id<<endl;
    }
    CInstance(){
        this->id=365;
        output();
        cout<<"这是CInstance的无参参构造,默认id值为"<<this->id<<endl;

    }
    ~CInstance(){
        output();
        cout<<"这是CInstance的析构函数"<<endl;
    }
    void output(){
        cout<<"*****"<<endl;
    }
};
/**c++的类实例化的几种方式*/
int main(){
    //1.隐式实例化
    // 这种创建方式在进程虚拟地址空间中的栈中分配内存，它的分配和释放由系统决定，
    // 函数内局部变量的存储单元可以在栈上创建，函数执行完毕，系统会自动释放这些存储单元。
    CInstance instance1;
    CInstance instance2(1);
    //疑惑:这不是声明吗,或者说,编译类型?
    //---与java一次预先编译后,可以在各种系统中处处运行,c++没有预先编译的过程,所以系统也不能做到即时提示错误(因为底层就做不到)
    //如果想要向java那样声明一个变量,可以使用extern关键字(extern会提供一个数据的引用)
    // cout<<extern_member<<endl;

    //2.显式实例化
    //和1一样
    CInstance instance3=CInstance();
    instance3.output();
    CInstance instance4=CInstance(1);

    //3.显示new实例化
    // 这种方式使用了new关键字，在堆中分配了内存，堆上的内存分配，亦称动态内存分配。
    // 程序在运行的期间用malloc申请的内存，这部分内存由程序员自己负责管理，其生存期由开发者决定:在何时分配，分配多少，并在何时用free来释放该内存.
    CInstance *instance5=new CInstance();
    CInstance *instance6=new CInstance(1);
    
    
}