#include <iostream>
#include <string>

using namespace std;

//1. 属性初始化
/*
class Person{

    protected:
        char* name;
        int age;
    public: 
        Person(char* name,int age){
            this->name = name;
            this->age = age;
        };    

};

class Course{
    protected:
        string courseName = "";
    public:
        Course(string courseName){
           this->courseName = courseName;  
        }

        string _courseName(){
            return this->courseName;
        }

            
};




class Student : public Person{
    private:
        Course course;
        char* grade;
    public:
        //1.1 初始化父类，如 Person
        //1.2 初始化类成员变量
        //1.3 初始化基本类型成员变量
        Student(char* name,int age,string courseName,char* grade) : Person(name,age),course(courseName){
            this->grade = grade;
        }

        void print(){
            cout << "("<< name << "," << age << "," << course._courseName().c_str() << "," << grade << ")" << endl; 
        }   
};

int main(){

    Student* stu = new Student("Yu",25,"English","101");
    stu->print();
    delete stu;

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}
*/



//2. 多继承
/*
class Person{
    protected:
        string name;
    public:
        Person(string name){
            this->name = name; 
        }
};

class Child{
    protected:
        int age;
    public:
        Child(int age){
            this->age =age;
        }    
};

//2.1 多继承 c++ 是可以多继承的，但是要防止二义性的问题
class Student : public Person,public Child{
    private:
        string courseName;
    public:
        Student(string name,int age,string courseName):Person(name),Child(age){
            this->courseName = courseName;
        }
        void print(){
            cout << "(" << name.c_str() << "," << age << "," << courseName.c_str() << ")" << endl;
        }

};



//2.2 虚继承 
class A{
    public:
        string name;
};

// virtual 确保继承过来的相同属性或函数，只存在一份拷贝
class B : virtual public A{};

class C : virtual public A{};

class D : public B,public C{
    public:
        void print(){
            //若 B C 继承时不加 virtual, 会报D::name 不明确
            cout << name.c_str() << endl;
        }
};

int main(){
    //多继承
    Student* stu = new Student("Yu",1,"English");
    stu->print();
    delete stu;

    //虚继承
    D* d = new D();
    d->print();
    delete d;

    int exit;
    cout << "input anything exit " << endl;
    cin >> exit;
    return 0;
}
*/

/*
//3. 多态
// c++ 中的多态是怎样的，默认情况下不存在,必须定义虚函数
// 什么是多态 ：
    //父类指向子类的引用，重写 ，里氏替换原则 
    // 程序在编译期间并不知晓运行的状态(调用哪个函数)，只要在真正运行的过程中才会去找需要运行的方法
class Activity{
    public:
        // 若要实现多态，必须定义为虚函数
        virtual void onCreate(){
            cout << "Activity onCreate()" << endl;
        }
};

class MainActivity : public Activity{
    public:
        void onCreate(){
            cout << "MainActivity onCreate()" << endl;
        }
};

class WelcomeActivity : public Activity{
    public:
        void onCreate(){
            cout << "WelcomeActivity onCreate()" << endl;
        }
};

void startActivity(Activity* activity){
    activity->onCreate();
}

int main(){

    Activity* actMain = new MainActivity();
    Activity* actWelcome = new WelcomeActivity();
    //若 Activity 中的 onCreate() 不定义为虚函数，那么无论 new 的是哪个类，
    //调用的始终是activity中的 onCreate()
    startActivity(actMain);
    startActivity(actWelcome);
    delete actMain;
    delete actWelcome;

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}
*/


/*
//4. 纯虚函数

// 用于实现类似java 中的抽象类 接口
//4.1 类似抽象类
class BaseActivity{
    
    public:
        void onCreate(){
            initView();
            initData();
        }

        //4.1.1 定义虚函数 类似java中的抽象方法,子类必须实现
        // 注意 必须写 =0 不然会报错
        virtual void initView() = 0;
        virtual void initData() = 0;
};

class MainActivity : public BaseActivity{
    public:
        //4.1.2 实现方法
        void initView(){
            cout << "initView " << endl;
        }

        void initData(){
            cout << "initData " << endl;
        }

};

//4.2 类似接口
class ClickListener{
    public:
        virtual void onClick() = 0;
};

class ImageClickListener : public ClickListener{
    public:
        void onClick(){
            cout << "on Image click " << endl;
        }
};

int main(){
    BaseActivity* act = new MainActivity();
    act->onCreate();
    delete act;

    ClickListener* clickListener = new ImageClickListener();
    clickListener->onClick();
    delete clickListener;

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}
*/


/*
//5. 继承中的构造函数和析构函数
	// 构造函数：先父类 -> 再子类
	// 析构函数：先子类 -> 再父类
class Person{
    private:
        string name;
    public:
        Person(string name){
            this->name = name;
            cout << "Person constructor" << endl;
        }
        ~Person(){
            cout << "Person destructor" << endl;
        }    
};

class Student : public Person{
    public:
        Student(string name):Person(name){
            cout << "Student constructor" << endl;
        }
        ~Student(){
            cout << "Student destructor" << endl;
        }
};

int main(){

    Student* stu = new Student("Yu");
    delete stu;

    //输出
    // Person constructor
    // Student constructor
    // Student destructor
    // Person destructor
    // input anything exit

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}
*/



//6. 模板函数
// 类似java 中的泛型
//模板函数的定义
template <typename T>
T add(T num1,T num2){
    return num1 + num2;
}

//7. 模板类
template <class T>
class Callback{
    public:
    void onSuccess(T t){
        cout << t << endl;
    }
};

// 模板类的继承  注意HttpCallback是不跟 <> 的
template <class H>
class HttpCallback : public Callback<H>{
};


int main(){
    int sum = add(1,2);
    cout << sum << endl;

    int sum2 = add(1.0, 2.0);
	cout << sum2 << endl;

	int sum3 = add(1.0f, 2.0f);
	cout << sum3 << endl;

    string a = "hello";
    string b = "world";
    string sum4 = add(a, b);
	cout << sum4 << endl;

    HttpCallback<string>* callback = new HttpCallback<string>();
    callback->onSuccess("success");
    delete callback;

    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}