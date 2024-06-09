#include <iostream>
using namespace std;
//静态变量
class CPoint{
    public:
    /**在静态变量创建时不能在类中对其赋值,应该使用作用域符::进行赋值*/
    static int  xposition;
    /**可在类中赋值的类型,static const int*/
    static const int constNum=1;
    void setPoint(int this_constNum){
        //无法在方法中修改static区域的值,因为静态成员的一切初始化均在类的外面
        // constNum=this_constNum;
        //xposition=this_position;
    }
    void printPoint(){
        cout<<"x轴距离为:"<<xposition<<endl;
        cout<<"static const的初始化必须初始化且必须在类中进行"<<constNum<<endl;
        cout<<"枚举变量可在类中初始化,且必须为常数,例:"<<CLASSINCLUDED<<endl;
        cout<<&xposition<<endl;
    }
    /**可在类中赋值的类型,enum枚举成员*/
    enum initialize{CLASSINCLUDED=1};
};
int CPoint::xposition=1;
/**int CPoint::constNum=1; */
// error:conflicting declaration 'int CPoint::constNum'
//    24 | int CPoint::constNum=1;
// note: previous declaration as 'const int CPoint::constNum'
//     9 |     static const int constNum=1;
// error: duplicate initialization of 'CPoint::constNum'
//    24 | int CPoint::constNum=1;

int main(){
    CPoint a_point;
    a_point.setPoint(2);
    a_point.printPoint();
    cout<<"static值修改的依然是原来的值,不是副本,其地址只会是"<<&CPoint::xposition<<"值为"<<CPoint::xposition<<endl;
}