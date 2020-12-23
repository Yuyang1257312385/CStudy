#include <iostream>

using namespace std;

namespace spaceA{
    int a = 10;
    namespace spaceB{
        int b = 20;
    }
}

class Teacher{
    public:
        char name[20];
        int age = 1;
};

class Circle
{
    private:
        double m_r;
        double m_s;
    public:
        void setR(double r){
            m_r = r;
        }

        double getS(){
            m_s = 3.14*m_r*m_r;
            return m_s;
        }
};


//常量指针 表示一种输入参数
void operatT1(const Teacher* pT){
    //报错
    //pT->age = 20;
    cout << "operatT1 : " << pT->age << endl;
    pT = NULL;
}

//指针常量 表示一种输出参数
void operatT2(Teacher* const pT){
    pT->age = 20;
    cout<< "operatT2 : " << pT->age << endl;
    // 报错
    //pT = NULL;
}

#define def1 10;
// define 和 const 的区别
void fun1(){

    #define def1 10
    #define def2 11
    const int cst1 = 20;
    //卸载
    #undef def2
}

void fun2(){

    printf("def1 = %d \n",def1);
    // 未定义标识符 def2
    //printf("def1 = %d \n",def2);

    // printf("cst1 = %d \n",cst1);
}

//无法实现互换
void exchange(int a, int b){
    //值传递
    int temp = a;
    a = b;
    b = temp;
}

//可以实现互换
void exchange2(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void printT1(const Teacher* pT ){
    cout<< "printT1 age : " << pT->age << endl;
}

void printT2(Teacher &r_t){
    cout<< "printT2 age : " << r_t.age << endl;
    r_t.age = 2;
    cout << "after change age : " << r_t.age << endl;
}

void printT3(Teacher t){
    cout<< "printT3 age : " << t.age << endl;
    t.age = 3;
    cout << "after change age : " << t.age << endl;
}

void modifyA1(int &a){
    //引用
    a = 1;
}
//引用实质
void modifyA2(int *const a){
    *a = 2;
}

int main(){

    //1. c++ 
    // cout << "input r" << endl;
    // Circle c1;
    // double r;
    // cin >> r;
    // c1.setR(r);
    // cout << "area is " << c1.getS() <<endl;

    //2. 命名空间 
    // 2.1 定义
    // 2.2 使用  嵌套
    // using namespace spaceA;
    // cout << "spaceA : "<< a << endl;
    // cout << "spaceB : " << spaceB::b << endl;

    //3. Bool 注意输出值 所有非0 的值都是输出 1 
    //  C++ 中的bool 理论上只占一个字节，也就是 8bit
    // 如果多个bool 变量定义在一起的时候，可能各自占一个bit，取决于编译器的实现
    cout << "-------- Bool --------" << endl;
    bool b1 = 10;
    bool b2 = -10;
    bool b3 = 0;
    printf("b1:%d,b2:%d,b3:%d \n",b1,b2,b3);

    //4. const 
    cout << "-------- const --------" << endl;


    //4.1 基本使用  这两种用法是一样的
    const int A = 10;
    int const B = 20;

    //4.2 常量指针 (个人理解: 是一个指向常量的指针)
    // const 修饰的是指针所指向的变量，代表指针所指向的内存空间不能被修改
    const int * c;
    c = &A;
    c = &B;
    int d = 10;
    c = &d;
    d = 20;
    printf("%d,%d,%d,%d \n",A,B,d,*c);

    //这行代码是报错的，常量指针指向的内存空间是不能被修改的 
    //*c = 30;

    //4.3 指针常量 （个人理解: 是一个常量，这个常量是一个指针）
    int a1 = 1;
    int a2 = 2;
    // 指针常量，const修饰的是指针本身，指向不可变
    int *const p_c = &a1;
    // 会提示 表达式必须是可修改的左值  也就是说，这个指针的指向是可以修改的
    //p_c = &a2;


    //4.4 常量指针常量
    int a3 = 3;
    int a4 = 4;
    // 指针的指向不能变，所指向的内存也不能变
    const int *const c_p_c = &a3; 
    //报错: 表达式必须是可修改的左值
    //c_p_c = &a4;
    //报错: 表达式必须是可修改的左值
    //*c_p_c = 20;

    //4.5 使用 
    // 好处
    // 1> 指针函数参数，可以有效的提高代码的可读性，减少bug
    // 2> 清楚的区分参数是输入还是输出特性，C/C++中有些参数是作为返回值用的
    Teacher t1;
    operatT1(&t1);
    operatT2(&t1);


    //4.6 const 和 #define 的区别 
    // 1> 作用范围不同,在 fun1 中的define 在fun2中是可以使用的，而const 在 fun2中是不能使用的
    // 2> #define是在编译预处理阶段，只是简单的文本替换 const是由编译器处理的，提供类型检查和作用域检查 

    int a5 = 10;
    int a6 = 20;
    // linux内核可以 gcc 编译器支持
    //int array[a5+a6];
    const int a7 = 10;
    const int a8 = 20;
    int array2[a7+a8];
    int array3[a7+def1];
    fun2();

    //5. 引用
    cout << "---------REFERENCE USE--------" << endl;

    //5.1 用法
    int a9 = 9;
    //语法  ： 类型 &引用名 = 变量
    // 报错: 引用必须依附某个变量，必须初始化
    //int &r_a9;
    // r_a9就是一个引用 ，不要使用C 的语法思考，就是给 a9 变量起了一个别名
    int &r_a9 = a9;
    cout << "a9 value : "<< a9 << "  ,a9 address &a9 : " << &a9 << endl;
    cout << "r_a9 value : " << r_a9 << " ,r_a9 address &r_a9 : " << &r_a9 << endl;

    r_a9 = 100;
    cout << "after change " << endl;
    cout << "a9 value : "<< a9 << "  ,a9 address &a9 : " << &a9 << endl;
    cout << "r_a9 value : " << r_a9 << " ,r_a9 address &r_a9 : " << &r_a9 << endl;

    int a10 = 10;
    int a11 = 11;
    exchange(a10,a11);
    cout << " exchange " << endl;
    cout << "a10 value : "<< a10 << "  ,a11 value : " << a11 << endl;

    exchange2(a10,a11);
    cout << " exchange2 " << endl;
    cout << "a10 value : "<< a10 << "  ,a11 value : " << a11 << endl;

    Teacher t2;
    printT1(&t2);
    printT2(t2);
    printT3(t2);

    //5.2 理解引用实质
    // 引用在C++ 内部的实现，就是一个指针常量
    int a12 = 12;
    modifyA1(a12);

    modifyA2(&a12);

    int a13 = 13;
    int a14 = 14;
    int &r_num = a13;
    r_num = a14;
    //a13 (14,0x61fc98), a14 (14,0x61fc94) , r_num (14,0x61fc98)
    cout << "a13 (" << a13 << "," << &a13 << "), a14 (" <<a14 << "," << &a14 << ") , r_num ("<< r_num << ","<< &r_num << ")" <<endl;


    int a;
    cout << "input anything exit" << endl;
    cin >> a;
    return 0;
}



