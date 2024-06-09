#include<iostream>
using namespace std;

/*关于c++作用域问题
    问题引入,为何在class{}中不会默认初始化,而在在类外部初始化,这与java的初始化大不同
*/
class Test{
    public:
    int n=1;
    void print(){
        int n;
        cout<<n<<endl;//输出0,c++的除静态变量外的
    }
};
static int i;
int main(){
    cout<<i<<endl;
    Test test=Test();
    cout<<"输出局部变量n"<<test.n;//未将流刷新,默认初始化为随机数
    test.print();
    {
        int a;
        cout<<"输出块区域变量a"<<a<<endl;//未将流刷新,默认初始化为随机数
    }
}