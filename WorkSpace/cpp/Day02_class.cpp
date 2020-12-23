#include <iostream>
// 1. 引用头文件
#include "MyTeacher.h"

using namespace std;

int a =1;

//vs code这种配置只能编译单文件，多文件就要靠Makefile文件来告诉编译器怎么编译了

int main(){

    MyTeacher teacher;
    teacher.setAge(10);

    cout << "teacher.getAge " << teacher.getAge() << endl;

    // //2. :: 的作用 相当于对作用域的限定

    float a = 3.14;
    cout << "local a : " << a << endl;
    cout << "global a : " << ::a << endl;


    int exit;
    cout << "input anything exit" ;
    cin >> exit;
    return 0;
}