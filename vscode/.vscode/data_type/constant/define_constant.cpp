#include<iostream>
#include<cmath>

using namespace std;

int main(){
    //对于基本的常量格式:
        //整数常量
        //前缀0:8进制数; 前缀0x:16进制数
        //后缀:U(无符号整数),L(长整数)

        //浮点常量
        //后缀: 314159E~5L
        
        //例:
        short s=10;
        int i=-1000;
        long l=100000;
        float f=230.47;
        double d=200.347;
        //以下为数学运算
        cout<<"sin(d):"<<sin(d)<<endl;
        cout<<"abs(i):"<<abs(i)<<endl;
        cout<<"floor(d):"<<floor(d)<<endl;
        cout<<"sqrt(f):"<<sqrt(f)<<endl;    //开方
        cout<<"pow(d,2):"<<pow(d,2)<<endl;  //返回d的2次幂
        //

        //bool常量
        // cout<<"true输出"<<true<<"false输出"<<false<<endl;
        //但不能直接认为true就是1,false就是0

        //字符常量(转义字符 \+...)
//存疑  cout<<"Hello\r world"; Hello消失
        cout<<"Hello\nwo\trld"<<endl;

    //常量的定义
        #define DEFINE_VALUE "我是被define的常量,名字最好为大写,我后面不能加符号";
        const string CONST_VALUE="我是被constant规定的不可改变的量";
        // CONST_VALUE="我不能被修改";
        // DEFINE_VALUE="我后面不能加符号,包括等号,因此也无法修改";
        cout<<DEFINE_VALUE;//定义的常量后不能接符号
        cout<<endl;
        cout<<CONST_VALUE<<endl;


        

}