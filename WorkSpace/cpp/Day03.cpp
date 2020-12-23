#include <iostream>
#include <string.h>

using namespace std;

//一 构造函数和析构函数
//构造函数 ClassName(){}
// 1.没有返回值
// 2. 函数名称和类名相同
//析构函数  ~ClassName(){}
// 1.没有返回值
// 2. 函数名称和类名相同
class Person{
    private :
        int m_age;
        int m_grade;

    public :
        //构造函数 初始化工作
        Person(){
            m_age = 0;
            m_grade = 0;

            cout << "person constructor no param" << endl;    
        }

        Person(int age){
            m_age = age;
            cout << "person constructor with param one" << m_age << "," << m_grade << endl;    
        }

         Person(int age,int grade){
            m_age = age;
            m_grade = grade;
        
            cout << "person constructor with param two" << m_age << "," << m_grade << endl;    
        }

        // 拷贝构造函数
        Person(const Person& person){
            cout << "copy constructor" << endl;     
        }

        //析构函数 释放资源的工作
        ~Person(){
            //析构函数是当我们的对象被销毁之前，由编译器去主动调用的
            cout << "person destructor" << endl;    
        }

        //成员函数
        void print(){
            cout << "age : " << m_age << " grade : " << m_grade <<  endl;
        }

};


//二 调用无参的构造函数
void objTest1(){
    //创建了一个对象
    Person person;
    person.print();

    //输出
    // person constructor
    // age : 8
    // person destructor

}

//三 调用有参构造函数方法 三种
void objTest2(){
    //1. 括号法
    // c++编译器自动的调用相应的构造函数
    Person p1(1);
    Person p2(2);

    //2. = 法
    // c++ 对 = 功能增强，调用了构造函数,
    //注意，这里调用的是一个参数的构造函数，只有最后一个值有效
    Person p3 = (3,4);
    Person p4 = (5,6,7,8);
    // 这里不是把 9 赋值给 p5,而是调用了Person的构造函数
    Person p5 = 9;

    //3. 直接调用构造函数
    Person p7 = Person(7,8);

    //输出结果
    // person constructor with param one1,0
    // person constructor with param one2,0
    // person constructor with param one4,0
    // person constructor with param one8,0
    // person constructor with param one9,0
    // person constructor with param two7,8
    // person destructor
    // person destructor
    // person destructor
    // person destructor
    // person destructor
    // person destructor
}


// 四 拷贝构造函数的调用时机

//拷贝函数调用三
void copyTest(Person p){
    p.print();
}

void objTest3(){

    Person p1(1,2);
    Person p2 = Person(3,4);

    //赋值操作 : 把 p2 copy 给p1;
    // p1 = p2;
    // p1.print();

    // 调用拷贝构造函数
    //注意: 这里只是调用拷贝构造函数,里面的值并不会拷贝
    //      注意区分赋值和调用拷贝，未初始化过的，才会调用拷贝

    //拷贝函数调用一 
    Person p3 = p2;
    p3.print();
    // 拷贝函数调用二
    Person p4(p2);
    p4.print();

    cout << "==========="<<endl;

    // 拷贝函数调用三
    copyTest(p2);

    //输出:
    // person constructor with param two1,2
    // person constructor with param two3,4
    // copy constructor
    // age : 2043400 grade : 0
    // copy constructor
    // age : 0 grade : 0
    // ===========
    // copy constructor
    // age : 0 grade : 0
    // person destructor
    // person destructor
    // person destructor
    // person destructor
    // person destructor

}

Person getPerson(){
    Person p(1,2);
    return p;
}

void objTest5_1(){
    getPerson();
    //输出：
    // person constructor with param two1,2
    // person destructor
    // input anything exit
}

void objTest5_2(){
    //初始化p1
    //创建了一个匿名对象，从匿名转成了有名字的 p1; 
    Person p1 = getPerson();
    p1.print();

    //输出:
    // person constructor with param two1,2
    // age : 1 grade : 2
    // person destructor
    // input anything exit
}

//五 深拷贝和浅拷贝
class Test{
    private :
        int a;
        char* name;
    public :

        Test(){
            a = 1;
             //给name变量在堆区分配了一块内存
            name = (char*)malloc(100);    
            strcpy(name,"init");
            cout << "Test constructor no param" << endl;
        }

        Test(const char* arg){
            a = 2;
            //给name变量在堆区分配了一块内存
            name = (char*)malloc(100);    
            strcpy(name,arg);
            cout << "Test constructor with param" << endl;
        }

        //深拷贝 
        // 若不使用深拷贝，测试中是会报错的
        // 因为新的对象 和 老的对象中的name会指向同一片内存区域，在析构的时候会报错
        Test(const Test& t){
            a = t.a;
            name = (char*) malloc(100);
            strcpy(name,t.name);
            cout << "copy constructor" << endl;
        }

        ~Test(){
            if(name != NULL){
                free(name);
            }
            cout << "Test destructor" << endl;
        }

        void print(){
            cout << "name : " << name << endl;
        }
};

//浅拷贝和深拷贝测试
void objTest7(){
    Test t1("init value");
    t1.print();
    

    Test t2 = t1;
    t2.print();

    // cout << "---------" << endl;

    //报错: 重新赋值会导致析构失败
    // Test t3("t3 name");
    // t3 = t1;
    // t3.print();
    

    //输出
    // Test constructor with param
    // name : init value
    // copy constructor
    // name : init value
    // Test destructor
    // Test destructor
    // input anything exit

}


int main(){

    // objTest1();
    // objTest2();
    // objTest3();

    //objTest5_1();
    //objTest5_2();

    objTest7();

    int exit;
    cout << "input anything exit " << endl;
    cin >> exit;
    return 0;
}