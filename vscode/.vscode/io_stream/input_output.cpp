#include<iostream>
//I/O库头文件 
// <iostream>	该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。
// <iomanip>	该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。
// <fstream>	该文件为用户控制的文件处理声明服务。我们将在文件和流的相关章节讨论它的细节。
using namespace std;

int main(){
    //1.标准输入流与标准输出流
    cout<<"我是标准输出流"<<endl;

    cout<<"请输入您的姓名"<<endl;
    char name[50];
    cin>>name;//输入流
    cout<<"您的姓名为:"<<name<<endl;

    //2.标准错误流[非缓冲的,流加载到立即执行]
    char error[]="this a fatal error";
    cerr<<"Throw A Exception:"<<error<<endl;

    //3.标准日志流[缓冲的,流不会立即加载执行,直至缓冲区填充满才会输出]
    char log[]="Unable to read...";
    clog<<"Overflow Message:"<<log<<endl;

    /*我们无法区分 cout、cerr 和 clog 的差异，但在编写和执行大型程序时，它们之间的差异就变得非常明显。
    所以良好的编程实践告诉我们，使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出。*/
}