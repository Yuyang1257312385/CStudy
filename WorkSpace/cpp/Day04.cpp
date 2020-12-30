#include <iostream>

using namespace std;

class A{

    private :
        int m_a;
    public :
        A(int a){
            m_a = a;
            cout << " constructor A ,m_a : " << m_a << endl;
        }    

        ~A(){
            cout << "destructor A " << endl;
        }

        int getMA(){
            return m_a;
        }
};


class B{

    private :
        int m_b;
        A a_1;
        A a_2;

    public :
        // 报错 :提示类A 不存在默认的构造函数
        // 初始化B的时候，若它内部的A 有默认构造函数,那么可以直接这样使用
        //B(){}

        // 2 . 构造函数的初始化列表
        // 2.1 语法 : ClassName() : m1(xx),m2(xx){}
        // 2.2 注意：
        // 2.2.1 若类B 中的成员变量 类A有有参构造函数，必须使用初始化列表
        // 2.2.2 初始化列表的顺序和成员变量的定义顺序有关系，和列表写的顺序没关系 
        B():m_b(1),a_1(1),a_2(2){
            cout << " constructor B no param" << endl;     
        }

        //2.2.3 优先使用构造函数参数中的值,初始化列表中提供的是默认值
        B(int b,A a1,A a2) : m_b(0),a_1(0),a_2(0){
            m_b = b;
            a_1 = a1;
            a_2 = a2;
        }

        B(int b,int a1,int a2):m_b(b),a_2(a2),a_1(a1){
            cout << " constructor B with param" << endl;     
        }

        ~B(){
            cout << " destructor B " << endl;
        }

        void print(){
            cout << "m_b : " << m_b << " a_1.getMA() : " << a_1.getMA() << " a_2.getMA() : " << a_2.getMA() << endl;    
        }    

};



//3. 构造函数中调用构造函数是一个危险的行为
class Test{

    private :
        int a;
        int b;
        int c;

    public :
        Test(int a,int b,int c){
            this->a = a;
            this->b = b;
            this->c = c;
            cout << "constructor Test three param" << endl;

        }    

        Test(int a,int b){
            // 构造函数里调用另一个构造函数，产生一个匿名对象，但是在函数结束后就释放掉了            
            Test(a,b,3);
            cout << "constructor Test two param" << endl;
        }

        ~Test(){
            cout << "destructor Test " << endl;
        }

        void print(){
            cout << "a : " << a << " b : " << b  << " c : " << c << endl;  
        }

        //调用：
        // Test test(1,2);
        // test.print();
        //输出:
        // constructor Test three param
        // destructor Test
        // constructor Test two param
        // a : 0 b : 55 c : 0
        // input anything exit


};

//4. 对象的动态创建和释放 new delete
// 4.1 在栈上对象创建与释放  和  在堆上对象创建与释放 的区别
// 栈：
// 1> 在栈上创建的对象，一经创建，对象的大小是无法改变的
// 2> 在栈上的对象，系统自动创建和销毁
// 堆 :
// 1> 堆上的内存空间，是可以动态调整的
// 2> 堆上的空间必须自己申请和释放

//4.2 分配基本类型
void dynamic1(){
    // c 的写法 malloc free
    int* p =  (int*)malloc(sizeof(int));
    *p = 10;
    cout << "p : " << *p << endl;
    free(p);
    p = nullptr;

    // c++ 写法 new delete
    // 堆上申请内存，分配基础类型
    int* p1 = new int;
    *p1 = 20;
    cout << "p1 : " << *p1 << endl;
    delete p1; 

}

//4.3 在堆上分配数组
void dynamic2(){

    // c 的写法
    int* array = (int*)malloc(sizeof(int)*10);
    array[0] = 10;
    free(array);

    // c++ 写法
    //  在堆上申请了一个 int[10] 的数组
    int* array1 = new int[10];
    array1[0] = 3;
    //这种写法是错误的
    // delete array1;
    delete[] array1;
} 


//4.4 在堆上分配复杂对象
void dynamic3(){
    //c
    //只是分配了一块内存空间 并没有初始化
    Test* t1 = (Test*) malloc(sizeof(Test));
    // *t1 = Test(1,2,3);
    t1->print();
    free(t1);

    cout << "-------" << endl; 

    //c++
    Test* t2 = new Test(1,2,3);
    t2->print();
    delete t2;

    //输出：

    // a : -1163005939 b : -1163005939 c : -1163005939
    
    // constructor Test three param
    // a : 1 b : 2 c : 3
    // destructor Test
    // input anything exit

}




// 默认构造函数
// 2. 若自己定义了构造函数，系统就不提供默认的无参构造函数
// 3. 提供默认拷贝构造函数
int main(){

    B b1;
    b1.print();  

    cout << "------init order -------" << endl; 

    B b2(1,2,3);
    b2.print(); 

    cout << "------init -------" << endl; 

    A a1(1);
    A a2(2);
    B b3(1,a1,a2);
    b3.print();

    // Test test(1,2);
    // test.print();

    // dynamic1();
    // dynamic3();

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
};