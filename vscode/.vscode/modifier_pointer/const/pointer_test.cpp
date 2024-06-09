#include<iostream>
using namespace std;

int main(){
    int num1=1;
    int num2=2;
    int num3=3;
    int num4=4;
    int num5=5;

    int *pointer1=&num1;//实例化一个指针对象pointer(此时还没有设置指针指向谁)  图解: num1(指针尾,用来代表pointer1的地址)--*pointer1(指针头)>>    
    /*规定::输出一个指针的对象,本质上就是输出对应指针对象的指向值(并且这个指向值会因为指针的地址或指针头指向的变化而变化)*/

    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl;   //地址1

//1.    以下是修改指针的两种方式
    pointer1/*修改pointer1(地址)*/=&num2;   //此时的指针的地址发生改变     图解: num2(指针尾)--*pointer1(指针头)>>
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl;   //地址2(地址改变)

    *pointer1/*修改*pointer1(指针指向)*/=num3;   //此时的指针指向一个新的对象  图解: num2(尾)--*pointer1(头)>> num3
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl;   //地址2(地址未改变,但是值改变了)

    pointer1=&num4;/**指针头指向变量的场合,修改*pointer1地址,会发现地址,值均会被改变*/
                    //图解:     num4--*pointer1>>num4
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl;
    //无论是改变地址还是指针头指向,指针变量本身的值都会发生改变


//2.    引入二尾指针    
    //二尾指针的创建
    int *pointer2=&num5;
    cout<<"输出指针的地址和指向值"<<pointer2<<" "<<*pointer2<<endl;    //地址3
    *pointer2=*pointer1;    
    cout<<"输出指针的地址和指向值"<<pointer2<<" "<<*pointer2<<endl;    //地址3(未改变,但值改变)
    // 此时会生成一个二尾指针
    // num4(尾)--*pointer1(头):父指针>> num3
    //               ^
    //               ^
    //          *pointer2(头):子指针
    //               |
    //             num4(尾)     ????????????????????????????这里,有问题,尾部都是num4的话,为什么尾巴分开?
    

//3.修改二尾指针
    /*我们对二尾指针"父指针"指针进行修改,预期:父指针改变*/
    pointer1=&num5;
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl; //地址3,值也未改变
    *pointer1=num5;
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl; //地址3,值也未改变
    /*我们再对二尾指针"子指针"指针头的指针变量,更改其地址值*/
    pointer2=&num5;
    cout<<"输出指针的地址和指向值"<<pointer2<<" "<<*pointer2<<endl;//会发现pointer2未发生改变
    /*我们把二尾指指针"子指针"更改指针头指向以形成一个新的二尾指针*/
    int* pointer3=&num1;
    *pointer2=*pointer3;
    cout<<"输出指针的地址和指向值"<<pointer2<<" "<<*pointer2<<endl;//会发现pointer2成功修改指向
    /*pointer2指针指向更改结构是...
        0x666--pointer1*>
                  
        ox777--pointer3*>
                  ^
                  |
             ?--pointer2*   ???????????????????这里指针尾的地址怎么填呢,之前就有这样的问题
             看下面的代码
    */
    *pointer1=num5;
    cout<<"输出指针的地址和指向值"<<pointer1<<" "<<*pointer1<<endl;//会发现pointer1的指针指向值跟随着pointer2的改变而改变了!!!!!!!
    //所以*pointer1=*pointer2一开始的图解就有问题,应该是
    /*
        (0x666(num4)--pointer1*>)--pointer2*>
        加入pointer3后的图解应该是:
       (   ( ((num4)0x666)--pointer1*> ) --pointer2*> )  pointer3*> num1  [指针变量的指向值根据最后一次修改指针的那次指向值决定]
    */

   //对于这种多重指针,只有修改最前面指针的指针头才能更改指向变量指向值,并且,多重指针的整个指针的指针尾(0x666)是不变的


    /*!!!!!!!!!(这个结论是错的),注意!!!!（；´д｀）ゞ结论:指针通过指针头指向的对象传值,如果没有指向对象,默认会传值为指针尾的值
                      指针通过指针尾输出地址*/

}