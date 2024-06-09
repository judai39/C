#include<iostream>
using namespace std;

//这是一开始的单例,14行报错,因为static Singleton singleton对类隐藏,无法赋值
// class Singleton{
//     private:
//     int id;
//     static Singleton singleton;
//     Singleton(int id){
//         this->id=id;
//     }
//     public:
//     static Singleton getInstance(int id){
//         singleton=Singleton(id);
//         return singleton;
//     }
// };
//     // Singleton Singleton::singleton=Singleton::getInstance(1);
//     // Singleton Singleton::singleton=Singleton(1);
// int main(){
//     Singleton::getInstance(1);

// }
class Singleton{
    private:
    int id;
    // static Singleton singleton;  既然静态变量无法在类中初始化,那索性不要了,直接
    Singleton(int id){
        this->id=id;
    }
    public:
    static Singleton getInstance(int id){
        Singleton singleton=Singleton(id);
        return singleton;
    }
};
    // Singleton Singleton::singleton=Singleton::getInstance(1);
    // Singleton Singleton::singleton=Singleton(1);
int main(){
    Singleton::getInstance(1);

}