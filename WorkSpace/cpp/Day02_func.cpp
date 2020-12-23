#include <iostream>

using namespace std;


//1. 函数声明
void printA();

//2. 内联函数
// 1> 声明的时候必须实现，没有办法分开，如果分开了 c++ 编译器会取消内联
// 2> 内联函数必须放在调用它的方法前面
// 3> 内联函数实际是将代码嵌入到调用点
// 4> C++ 编译器不一定会允许函数内联
//      不能存在任何形式的循环语句
//      不能存在过多的条件判断语句
//      函数体不能过于庞大
//      不能对函数进行取地址操作
inline void printB(){
    cout << " printB " << endl;
}

//3. 宏定义 C语言中没有内联函数，使用宏定义
#define MIN(a,b) ((a)<(b)) ? (a) : (b)

//4. 函数占位参数 只有参数类型，没有参数名
// 意义: 1> 兼容C语言可能出现的不规范写法
//       2> 为以后的程序留下线索
void printC(int a,int b,int){
    cout<< "a : " << a << "b : " << b << endl;
}

//5. 函数默认参数和展位参数结合
void printD(int a,int b,int = 0){
    cout << "a : " << a << " b : " << b << endl;
}


//6. 函数重载
//  函数名一致，参数不同（个数或类型）
void test(int a){
    cout << "test a : " << a << endl;
}

void test(char* a){
    cout << "test a : " << a << endl;
} 

void test(int a ,int b){
    cout << "test a : " << a << " b : " << b << endl;
}

// 若这么定义 ，会导致 test(1,2)调用失败，因为test函数会不知道调哪一个，是两参数的，还是三参数的
// void test(int a,int b,int c = 3){
//     cout << "test a : " << a << " b : " << b << " c: " << c << endl;
// }

void helloFunc(int a ,int b){
    // cout << "helloFunc a : " << a << " b : " << b << endl;
    cout << "helloFunc : a: " << a << " b: " << endl;
}



//7. 函数指针与函数重载

// 声明一个函数类型
//函数指针的定义 : 返回值类型(方法名称)(参数类型)
typedef void(typeFunc)(int a,int b);

// 声明一个函数指针类型
typedef void(*pFunc)(char* a);


int main(){

    cout << "----- Function -----" << endl;
    printA();
    printB();
    int min = MIN(10,15);
    cout << "min : " << min << endl;


    printC(1,2,3);
    printD(1,2);

    test(1);
    test("hello");
    test(2,3);

    typeFunc* pTypeFunc = NULL;
    pTypeFunc = helloFunc;
    pTypeFunc(1,2);
    pTypeFunc = test;
    pTypeFunc(3,4);

    pFunc pFunc = NULL;
    pFunc = test;
    pFunc("pFunc hello");


    int exit;
    cout << "input anything exit " << endl;
    cin >> exit;
    return 0;
}

void printA(){
    cout << "printA " << endl;
}