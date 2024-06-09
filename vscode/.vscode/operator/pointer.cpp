#include<iostream>
using namespace std;

/*&和*都是获取地址的一元运算符,区别在于,*是&的补充,*获取的是地址的值,算是个基本数据类型值,&获取的是地址对象,是个引用类型数据值*/
class staticElement{
    static string addressStr1;
};
string staticElement::addressStr1="0x2a9c9ffca9";
int main(){
    int address=1;
    int *address1;
    //错误示范
    // int address3=&address;
    //invalid conversion from 'int*' to 'int'
    // int address4=*address;
    //invalid type argument of unary '*'(have 'int') 
    //报错信息给出,
    //信息1:    &address是一个值(报错信息显示coversion error转换异常),
    //信息2:    *address是一个引用数据类型,指向地址,那问题又来了,*地址2=*地址1是正确的,这是修改了地址指针还是单纯的赋值其地址?

    // string addressStr="地址";
    // string addressNew=*addressStr;   nomatch for 'operator*'(operand type is 'std::string')
    //报错了,operand type is 'std::string, 取址数由std文件读取静态string对象数据,说明在编译时,系统预先将所有的变量,指针分配在static区
    //中,*的指针调整实际上就是将指针赋值给另一个在static区中存在的地址,因此像上面的随便赋值一个string给指针地址是行不通的

    //好,既然随便传值一个string不行,那在编译时我们定义一个static string addresStr1;这样addressStr1就会被放入命名空间的静态池
    //,从而被读取了吧?
    // string test=*staticElement::addressStr1; 报错
    //错误1:no match for 'operator*'(operand type is 'std::string'{operand type is 'std::string'})
    //错误2:'std::string staticElement::addressStr1' is private within this context
    //捏麻麻滴,开发者早就考虑到命名空间的安全性问题,不允许我们在代码层对命名空间的内容进行修改

    //结论:*变量a 和 变量a是两种数据类型,前者是引用数据类型,后者是基本数据类型(&也是取出数据的地址,地址会被当作字符串类型,也是基本类型)
    //想要取出引用地址需要用到&,引用地址的传递则需要"*引用地址1=*引用地址2"(这些引用地址是在编译时预先放在static的,由命名空间文件std读取);

    address1=&address;
    int address2=*address1;

    cout<<"&会输出地址值吗?"<<address1<<endl;//输出0x2a9c9ffca0
    cout<<"*会输出地址值吗?"<<address2<<endl;//输出1,int address2会根据指针传来的地址自行去变量池中寻找对象
    
    //还有一件事,允许修改变量值,不允许修改变量地址,这与java中的引用类型的特点一致(以String为例)
    //引用类型的原理差不多呢
}