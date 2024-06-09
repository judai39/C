#include<iostream>
using namespace std;

/*本例主要用于讲解各个输出流(缓存与非缓存)的区别*/

// int main(int argc, char const *argv[]){
//     //标准输出流,缓存的
//     cout << "ERROR!!";
//     while (true);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     cerr << "ERROR!!";
//     while (true);
//     return 0;
// }

//应该输出456123789,但是不是这样输出,为什么?
int main(int argc, char const *argv[])
{
    setbuf(stderr,0);
    cout << "123";
    clog << "456";
    cerr << "789";

    return 0;
}