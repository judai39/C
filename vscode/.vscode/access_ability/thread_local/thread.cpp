#include <iostream>
#include <thread>
// using namespace std;

class ThreadTest{
    public:
    void test(const std::string name){
        thread_local int count=0;
        count++;
        std::cout<<name<<":"<<count<<std::endl;
    }
};

//方法不在类中定义,属于哪一层级?
void function(const std::string name){//加上&,意味着参数只能传入值,不能传入值的地址(即不能传入引用变量) 见24行
    ThreadTest thread1;
    thread1.test(name);
    thread1.test(name);
    ThreadTest thread2;
    thread2.test(name);
    thread2.test(name);

}//方法不用;?

int main(int argc,char*argv[]){
    // string str="t1";
    // std::thread t1(function, str); str was not declared in this scope;
    std::string str="t1";
    std::thread t1(function,str);
    t1.join();
    std::thread t2(function,"t2");
    t2.join();

    //输出结果1,2,3,4,1,2,3,4
    // thread_local修饰的变量(仅能修饰变量!!!!)在同一线程内共享值域
    //作用:实现线程与线程间的数据隔离(在java中的sycronize关键字是实现线程间的数据通信,是通过锁完成的,两者相反),在无锁多线程中很好用
    //thread_local 最简单的理解，可以举例error 这个int变量。error存放当前发生的错误ID，但在多线程环境下，
    //      需要每个线程保存一个error（空间）。这样每个线程的错误都可以记录了。




}