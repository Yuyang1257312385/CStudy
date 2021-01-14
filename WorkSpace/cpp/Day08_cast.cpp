#include <iostream>

using namespace std;

//类型转化
class Person{
public:
    string name;
    int age;
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }

};


class Student : public Person{
    public:
        Student(string name,int age): Person(name,age){}
};

class Worker : public Person{

};


int main(){

    //1. 直接转换: 大多数的 C++ 编译器都支持大部分通用的强制转换运算符
    double num1 = 20.2;
    int num2 = num1;
    cout << "cast direct " << num2 << endl;

    //2. static_cast : 执行非动态转换，没有运行时类检查来保证转换的安全性。例如，它可以用来把一个基类指针转换为派生类指针。
    //2.1 用于基本数据类型的转换
    char a = 'a';
    int num3 = static_cast<int>(a);
    cout << "static_cast base datatype " << num3 << endl;
    //2.2 用于把一种类型转为另一种类型 (基类和派生类之间指针或引用的转换)
    Student* stu = new Student("Darren",12);
    Person* p1 = stu;
    Person* p2 = static_cast<Person*>(stu);
    cout << "static_cast class p1 : " << p1->name.c_str() << " , " << p1->age << endl;
    cout << "static_cast class p2 : " << p2->name.c_str() << " , " << p2->age << endl;

    cout << "stu address : " << static_cast<const void *>(stu) << " p1 address : " << static_cast<const void *>(p1) << " p2 address : " << static_cast<const void *>(p2)  << endl;  

    delete stu;

    // 子类 通过 static_cast 不能转为父类
    // Person p3 = Person("bobo",1);
    // Student* stu1 = static_cast<Student*>(p3);

    cout << endl;
    cout << endl;

    //3. const_cast : 用于修改类型的 const / volatile 属性。
    //除了 const 或 volatile 属性之外，目标类型必须与源类型相同。
    //这种类型的转换主要是用来操作所传对象的 const 属性，可以加上 const 属性，也可以去掉 const 属性
    const Person* p4 = new Person("bobo",2);
    //报错  常量不能在修改值
    //p4->name = 1;
    Person* p5 = const_cast<Person*>(p4);
    p5->name = "dodo";
    p5->age = 3;
    cout << " const_cast " << endl;
    cout << "p4 : " << p4 << " " << p4->name << " , " << p4->age << endl;
    cout << "p5 : " << p5 << " " << p5->name << " , " << p5->age << endl;


    cout << endl;
    cout << endl;

    //4. reinterpret_cast : 把某种指针改为其他类型的指针。它可以把一个指针转换为一个整数，也可以把一个整数转换为一个指针。
    cout << "reinterpret_cast " << endl;
    Person* p6 = new Person("coco",3);
    Student* stu3 = reinterpret_cast<Student*>(p6);

    cout << "stu3 " << stu3->name.c_str() << "," << stu3->age << endl;

    delete p6;

    cout << endl;
    cout << endl;
    

    //5. dynamic_cast<type> (expr): dynamic_cast 在运行时执行转换，验证转换的有效性。
    // 如果转换未执行，则转换失败，表达式 expr 被判定为 null。
    // dynamic_cast 执行动态转换时，type 必须是类的指针、类的引用或者 void*，
    // 如果 type 是类指针类型，那么 expr 也必须是一个指针，如果 type 是一个引用，那个 expr 也必须是一个引用。
    Person* p7 = new Person("dodo",4);
    //编译器报错 : 运行时 dynamic_cast 的操作数必须包含多态类类型
    //Student* stu4 = dynamic_cast<Student*>(p7);
    
    Student* stu5 = new Student("eoeo",5);
    Person* p8 = dynamic_cast<Person*>(stu5);
    cout << "dynamic_cast " << endl;
    cout << p8->name.c_str() << "," << p8->age << endl;

    delete stu5;
    delete p7;
    
    cout << endl;
    cout << endl;

   


    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;

     //输出结果 
    // cast direct 20
    // static_cast base datatype 97
    // static_cast class p1 : Darren , 12
    // static_cast class p2 : Darren , 12
    // stu address : 0x151a70 p1 address : 0x151a70 p2 address : 0x151a70


    // const_cast
    // p4 : 0x151a70 dodo , 3
    // p5 : 0x151a70 dodo , 3


    // reinterpret_cast
    // stu3 coco,3


    // dynamic_cast
    // eoeo,5


    // input anything exit
}