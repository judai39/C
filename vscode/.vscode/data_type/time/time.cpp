#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

//struct tm {
//   int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
//   int tm_min;   // 分，范围从 0 到 59
//   int tm_hour;  // 小时，范围从 0 到 23
//   int tm_mday;  // 一月中的第几天，范围从 1 到 31
//   int tm_mon;   // 月，范围从 0 到 11
//   int tm_year;  // 自 1900 年起的年数
//   int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
//   int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
//   int tm_isdst; // 夏令时
// };

int main(){
//   1.输出当前时间(输出地址)
    time_t now=time(0);
    string str="ddddd";
    char str_char[13]="ddafdf";
    int int_arr[1]={1};
    cout<<now<<typeid(now).name()<<endl;//直接输出now会返回一个静态地址,想要打印该变量的数据类型可以经由typeid(parameter).name()
    //这样输出的变量类型是单个char, i代表int f代表float 一串字符(例如NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE)代表引用类型字符串
    /**（；´д｀）ゞ:指正,不是引用类型就会出现,就像数组依然会照常输出,只有向string,这种从外界引入(也可以叫自定义数据类型)才会出现*/
    //_c代表字符数组(c语言下的数组!) x本例输出的是长整型longlongint(c语言下的time_t在命名空间内就是以长整型类型进行封装的)

//   2.将now转化为字符串类型
    // char* str_time=&now; 错,cannot convert longlongint to char*
    //那么类型转换可以吗? char* str_time=(char*)&now;   错,如果按照char的寻址逻辑,会把地址数字当成字母对应的hash值,最终输出"BF"
    //该怎样合理的转换? 遇到了什么问题?--将longlongint*地址初始化char*指针的问题(不可以强行转换)
    //既然无法直接转换数字地址,那就先将数字地址转化成longlongint*类型地址,在将其地址用于指针的初始化
    //于是有
    // char* str_time=(time_t)&now;     invalid conversion from "time_t(longlongint)" to "char*"
    //发生了些小插曲,time_t的数据类型是longlongint,而不是longlongint*指针类型,ctime才是time_t的指针类型
    char* str_time=ctime(&now);
    cout<<str_time<<endl;

//   3.将now转化为tm结构
    //结构与2类似,都是用now地址初始化指针
    tm* tm_time=gmtime(&now);
    cout<<gmtime(&now)<<endl;
    cout<<tm_time<<endl;    //输出tm_time结构体的地址(0x1d215304bd0)
    cout<<tm_time->tm_hour<<endl;//访问tm_time结构体成员
    cout<<asctime(tm_time)<<endl;//asctime()输出时间

    //补充:time_t的具体用法
    time_t* time_t_instance=new time_t();
    time_t time_now=time_t(&time_t_instance);//time_t(&parameter) 会将系统距现在的时间传递给parameter的指针尾
    cout<<time_t_instance<<endl;
    cout<<time_now<<endl;
    cout<<time_t(0)<<endl;
    cout<<ctime<<endl;
    
}