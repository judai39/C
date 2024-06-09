#include <iostream>
using namespace std;

// 类的命名规范:C+类名
class CPoint{
    public:
    //方法规范:动作+行为
    void setPoint(int x,int y){
        xposition=x;
        yposition=y;
    }
    void printPoint(){
        cout<<"x轴距离为:"<<xposition<<endl;

        cout<<"y轴距离为:"<<yposition<<endl;
    }

    private:
    int xposition;
    int yposition;
};
int main(){
    CPoint a_point;
    a_point.setPoint(10,2);
    a_point.printPoint();
}