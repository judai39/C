#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char string_arr1[]="four";
    string str="five";
    char string_arr2[]="five";
    //c语言下的char数组方法(strcat(),strlen(),strcpy()),使用前要进行cstring宏定义

    // strcat(string_arr,str); cannot convert str to char*
    strcat(string_arr1,string_arr2);
    strlen(string_arr1);
    strcpy(string_arr1,string_arr2);
}