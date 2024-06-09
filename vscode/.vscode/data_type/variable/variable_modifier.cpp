#include<iostream>
using namespace std;

int Test::index=0;
class Cconst_method{
    public:
    int get_value() const{  // const承诺的是一旦某个变量被其修饰，那么只要不使用强制转换(const_cast)，在任何情况下该变量的值都不会被改变，
                            //无论有意还是无意，而被const修饰的函数也一样，一旦某个函数被const修饰，那么它便不能直接或间接改变任何函数体以外的变
                            // 量的值，即使是调用一个可能造成这种改变的函数都不行。
                            //这种承诺在语法上也作出严格的保证，任何可能违反这种承诺的行为都会被编译器检查出来。
        return mutable_value;
    }
    void set_value(int fix_value)const{
        mutable_value=fix_value;
        cout<<"const修饰的方法中的成员可修改mutable修饰的变量"<<endl;
    }
    private:
    mutable int mutable_value;
};

int main(){
    //符号修饰符
    signed int num1=-10;//正常编译
    signed int num11=10;//正常编译,因为10也算作有符号数
    unsigned int num2=1;//正常编译
    unsigned int num22=-1;//通过编译,但运行结果 4294967295  将负号编译成无符号整数了
        /*补充一点,将符号数转换为无符号数,范围变为两倍*/

    //类型限制符
    const int num3 =10;//const修饰的变量的值无法被修改
    const int* p=&num1;//const修饰的指针变量无法被修改,即无法指向另一个量的地址值

    volatile int num4=1;//valatile意为易被改变,优化, 被其修饰的变量,!!!!!但是目的是为了告诉系统这个变量易变,要仔细审查地址变化,不要优化它
    num4=2;//在这里系统不会直接优化,会把num4=2的地址和num4=1的地址都存放起来

    Cconst_method cmethod=Cconst_method();
    cmethod.set_value(3);   
    //c++11后mutable取代了register的功能,本质上都是将变量存储到寄存器,可以直接让系统访问到
    //mutable 意为可变的,易变的,是系统为了突破const限制产生的限制词,被修饰的量永远处于可变化状态(可访问const成员)
    //mutable在类中只能够修饰非静态数据成员。mutable 数据成员的使用看上去像是骗术，因为它能够使const函数修改对象的数据成员。
    // 明智地使用 mutable 关键字可以提高代码质量，因为它能够让你向用户隐藏实现细节，而无须使用不确定的东西。我们知道，
    // 如果类的成员函数不会改变对象的状态，那么这个成员函数一般会声明成const的。
    // 但是，有些时候，我们需要在const的函数里面修改一些跟类状态无关的数据成员，那么这个数据成员就应该被mutalbe来修饰。
    cout<<cmethod.get_value()<<endl;

    cout<<"静态变量的声明周期与程序一致"<<Test::index<<endl;
};

