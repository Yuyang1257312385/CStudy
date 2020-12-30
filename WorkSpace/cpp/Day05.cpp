#include <iostream>

using namespace std;

class Test{

    public:

        Test(){}

        Test(int a,int b){
            this->a = a;
            this->b = b;
        }

         //2. 友元类
        // 在FriendTest 中可以访问 Test类中的私有成员变量，私有函数
        
        //2.1 声明
        friend class FriendTest;

        //3. 友元函数
        //  定义在类的外部，有权访问类的所有private成员
        //  不能有 函数体，不然没有意义
        //  友元函数没有this指针
        //  你要访问的是类的非静态成员，需要对象做参数
        //  你要访问的是类的静态成员，则不需要对象做参数
        //  如果做参数的是全局对象，则不需要对象做参数
        //  
        //3.1 声明
        friend void friendPrint(Test t);
        friend void friendPrint2();
        void print(){
            cout << "print a : " << a << " b : " << b << endl;
        }

       


        static void change(){
            c = 10;
            // 报错 static 方法只能操作静态的属性或方法
            //a = 1;
        }

    private:
        int a;
        int b;
        static int c;

        void privatePrint(){
            cout << "privatePrint a : " << a << " b : " << b << endl;
        }
};

//1.static
//  可以直接用类名去操作  ::
//  静态的属性必须要初始化
//  静态的方法只能去操作静态的属性或方法 

//静态的属性在 c++ 中必须要初始化，初始化必须要这么写
int Test::c = 3;

Test gTest;

//3.2 实现
void friendPrint(Test t){
    cout << "t.a " << t.a << " t.b " << t.b << endl;
};

void friendPrint2(){
    cout << "gTest.a : " << gTest.a << "  static c : " << Test::c << endl;
}


//2.2 友元类实现
class FriendTest{

    public:
        void changeA(int a){
            gTest.a = a;
            cout << " a : " << gTest.a << endl;
        }
};

class Complex{
    public:
        Complex(){}

        Complex(int a,int i){
            this->a = a;
            this->i = i;
        }

        void print(){
            cout << "Complex : (" << a << "," << i << ")" << endl;
        }

    private:
        int a;
        int i;
        friend Complex mAdd(Complex c1,Complex c2);
        friend Complex operator+(Complex c1,Complex c2);
};

Complex mAdd(Complex c1,Complex c2){
    return Complex(c1.a + c2.a , c1.i + c2.i);
}

//4. 操作符重载
// 不可以重载的运算符
//   . 成员访问控制符
//   .*, ->* 成员指针访问运算符
//   :: 域运算符
//   sizeof 长度运算符
//   ?:  三目运算符
//  # 预处理符  
Complex operator+(Complex c1,Complex c2){
    return Complex(c1.a + c2.a , c1.i + c2.i);
}


int main(){

    //2.3 友元类使用
    cout << " ----Friend Class---- " << endl;
    FriendTest friendTest;
    friendTest.changeA(10);

    // 3.3 友元函数的使用
    cout << " ----Friend Function---- " << endl;
    friendPrint(Test(1,2));
    friendPrint2();

    // 1.1 静态函数调用
    cout << " ----static Function---- " << endl;
    Test::change();
    friendPrint2();

    // 4. 操作符重载
    //4.1 不使用操作符重载
    Complex sum;
    sum = mAdd(Complex(1,2),Complex(3,4));
    sum.print();

    //4.2 使用操作符重载
    Complex sum1;
    sum1 = Complex(1,1) + Complex(2,2);
    sum1.print();

    // 打印
    //  ----Friend Class----
    // a : 10
    // ----Friend Function----
    // t.a 1 t.b 2
    // gTest.a : 10  static c : 3
    // ----static Function----
    // gTest.a : 10  static c : 10
    // Complex : (4,6)
    // Complex : (3,3)
    // input anything exit


    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;
    return 0;
}

