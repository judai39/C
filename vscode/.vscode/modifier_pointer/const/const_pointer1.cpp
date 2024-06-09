#include <iostream>
using namespace std;

/*修饰符不算做内存,其存在是为了使对象处于一种"状态"*/

/*对一个指针变量赋值,等价于让这个指针变量指向赋值变量*/

//指向const修饰对象的指针将会重新指向另一个const底层的指针,又由const指针指向该对象
//const修饰的成员将处于只读状态(不可重写),优先级小于mutable



//1.const变量,该类型下的变量的值不可被覆盖(必须初始化,且初始化必须在类中,不初始化又不让别人赋值是要怎样)
class const_constant{
    const static int num=1;
};
    // int const_constant::num=1;    previous declaration as 'const int const_constant::num'


//2.const引用对象,该类型下的引用对象中的成员的值不可更改,不能调用非const成员函数(如果真的可以访问非const成员,它们将会被覆盖,这与const的定义相悖)
class const_quote_object{
    public:
    const int num1=0;
    int num2=1;
    void cannot_access(){
        cout<<"我是非const成员函数,不可以被访问"<<endl;
    }
    void access()const{
        cout<<"我是const成员函数,可以被访问"<<endl;
    }
        /*以下为什么不能被访问
        const void access(){
            cout<<"我是const成员函数,可以被访问"<<endl;
        }*/
};

//3.const指针(const *p),此类型下的指针指向p(osition)(指向本质就是指针p存放的指向地址)可以改变,
// 指向的位置*p(ointer)(指向的位置指的是*p根据指向p所指向的对象)不可以改变


int main(){
//1.
    const_constant const1=const_constant();

//2.
    const const_quote_object const2=const_quote_object();
    // const2.cannot_access();
    const2.access();
    cout<<"成员变量可以被访问,不可被修改"<<const2.num1<<const2.num2<<endl;
//3.
    const int const_num=10;
    int num=1;
    cout<<&const_num<<endl;
    cout<<&num<<endl;
    const int *const_p=&const_num;
/**/    cout<<*const_p<<"  "<<const_p<<endl;
    // *const_p=num; assignment of read-only location *const_p [const修饰了指针*p,那就不能更改*p(指向的位置)]
    
    const_p=&num;//被const修饰的指针*const_p,它的地址区域p(osition)可以被非const指针的地址区域覆盖
    // *const_p=5;  更改对象num的地址后,对象依旧无法访问
/**/    cout<<*const_p<<"  "<<const_p<<endl;
    int *p=&num;
/**/    cout<<*p<<"  "<<p<<endl;
    // *p=(int*)&const_num; *p代表指向的对象,这里就是2,所以这句变成了赋值语句 int=(int*),编译肯定不通过
    p=(int*)&const_num;
/**/    cout<<*p<<"  "<<p<<endl;
/**/    cout<<*const_p<<"  "<<const_p<<endl;
    *p=5;//给正常指针的地址区域p更改为const指针的地址区域后,正常指针的指向对象依旧可以更改
    /*结论:（；´д｀）ゞ::编译器是通过 “指针的类型”而不是"指向数据的类型", 来判断是否只读的。const限制状态的是指针指向的对象(对象指向数据),指针间接指向数据对象
    和对象间直接传值覆盖本质上差不多,只不过指针传值中间插入了中介指针对象,如果指针对象被const修饰,那么指针对象是无法更改的,因为编译器要通过
    指针的类型来判断是否是只读*/
    
    /*（；´д｀）ゞ:也就是说,指针从功能上说更像是一个"中介类",而这个中介类就是指针初始化时指向的对象(这个具体查看5.1)*/

}