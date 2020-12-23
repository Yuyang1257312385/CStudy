#include <iostream>

using namespace std;


int getA1(){
    int a;
    a = 1;
    return a;
}

int& getA2(){
    int a;
    a = 2;
    return a;
}

int* getA3(){
    int a;
    a = 3;
    return &a;
}

int getG1(){
    static int g1 = 1;
    return g1;
}


int& getG2(){
    static int g2 = 2;
    g2 = 10;
    cout << "g2 : " << g2 << endl;
    g2 = 20;
    return g2;
}

void staticTest(int a){
    static int s = a;
    cout << "s : " << s << endl;
}

int main(){

    //1.内存四区模型
    
    //1.1 栈中的内存不能返回地址或引用，因为在方法结束后，栈的内存就被回收掉了
    int a1 = getA1();
    cout << "a1 : " << a1 << endl;

    // 会报异常 : reference to local variable 'a' returned 
    // 因为不能返回一个栈中的变量的引用
    // int a2 = getA2();
    // cout << "a2 : " << a2 << endl;

    // 报错 :  address of local variable 'a' returned
    // 不能返回一个栈中变量的指针(地址)
    // int* a3 = getA3();
    // cout << "a3 : " << *a3 << endl;

    //1.2 static 全局的
    int g1 = getG1();
    cout << "g1 : " << g1 << endl;
    // 返回的只是一个数值，不可以做左值
    //getG1() = 10;


    //g2 : 2
    // g2 : 20
    // g2 : 200
    // 20
    int g = getG2();
    getG2() = 200;
    //todo : 输出不太理解
    int g_ = getG2();
    cout << g_ << endl;


    staticTest(1);
    staticTest(2);
    staticTest(3);



    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}