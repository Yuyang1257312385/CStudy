#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. 枚举

/*
//1.1 定义 
//语法 : enum　枚举名　{枚举元素1,枚举元素2,……} 变量名;

//1.1.1 定义枚举类型的同时定义枚举变量
enum DAY_1
{
    //注意: 第一个枚举成员默认值为0 后续在前面的基础上加一
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} day1;

//1.1.2 定义枚举类型，之后再定义枚举变量
// 注意 同一个文件不能定义相同的枚举元素，会报 redeclaration of enumerator 'MON'
// enum DAY_2
// {
//     MON = 2,
//     TUE,
//     WED,
//     THU,
//     FRI,
//     SAT,
//     SUN

// };

//1.1.3 省略枚举类型，直接定义枚举变量
// enum
// {
//     MON = 1,
//     TUE,
//     WEN,
//     THR,
//     FRI,
//     SAT,
//     SUN
// } day3;

enum SEASON
{
    spring,
    summer = 3,
    autumn,
    winter
} season;

void main()
{
    day1 = TUE;
    printf("day1 is %d \n", day1);

    // enum DAY_2 day2;
    // day2 = WEN;
    // printf("day2 is %d \n", day2);

    // day3 = THR;
    // printf("day3 is %d \n", day3);

    season = spring;
    printf("season is %d \n", season);
    season = summer;
    printf("season is %d \n", season);
    season = autumn;
    printf("season is %d \n", season);
    season = winter;
    printf("season is %d \n", season);

    //1.2 在switch中使用
    printf("input your favorite season (0:spring 3:summer 4:autumn 5:winter):");
    enum SEASON favorite;
    scanf("%d", &favorite);
    switch (favorite)
    {
    case spring:
        printf("favorite spring \n");
        break;
    case summer:
        printf("favorite summer \n");
        break;
    case autumn:
        printf("favorite autumn \n");
        break;
    case winter:
        printf("favorite winter \n");
        break;
    default:
        break;
    }

    //1.3 将整数转化为枚举
    int sea = 4;
    enum SEASON season1;
    //将整数转化为枚举: 这样写也可以 ，并没有报错
    season1 = sea;
    printf("season1 is %d \n",season1);

    enum SEASON season2;
    season2 = (enum SEASON)sea;
    printf("season2 is %d \n",season2);

    int a;
    printf("input any char finish : ");
    scanf("%d",&a);
}
*/







//2. 结构体
// 数组允许存储相同类型数据项的变量
// 结构是另一种用户自定义的可用的数据类型，可以存储不同类型的数据项


//2.1 定义结构
//语法
//tag是结构体标签 ，member-list是标准的变量定义，如int i, variable-list是结构变量，可以指定一个或多个结构变量

//在一般情况下，tag、member-list、variable-list 这 3 部分至少要出现 2 个

// struct tag { 
//     member-list
//     member-list 
//     member-list  
// } variable-list ;

//定义结构体1 ： 有tag member-list variable-list
struct Book {
    char title[50];
    char author[50];
    int book_id;
} book1,book2;


//定义结构体2 : 没有tag
struct {
    int a;
    char b;
} s1;

//定义结构体3 : 没有声明变量
struct SIMPLE{
    int a;
    char b;
};
struct SIMPLE t1,t2[20],*t3;

//定义结构体4 : 使用typedef
typedef struct{
    int a ;
    char b;
} Simple;
//Simple是类型,可以声明新的结构变量
Simple u1,u2[20],*u3;

//定义结构体5 : 结构体包含其他结构体
struct COMPLEX{
    int a;
    struct SIMPLE s;
} complex = {
    10,{1,2}
};

//定义结构体6 : 包含指向自己类型的指针,这种是为了实现一些更高级的数据结构，如链表和树等
struct NODE{
    char string[100];
    struct NODE *next_node;
};

//定义结构体7 : 两个结构体互相包含  问题：有啥用呢？
//注意 需要对其中一个结构体进行不完整声明
struct B;
struct A{
    struct B *bPartener;
};
struct B{
    struct A *aPartener;
};

//2.2 结构初始化

/*
//2.2.1 直接在定义的时候初始化
struct Student{
    char name[50];
    int age;
} student = {"mr lu",28};

int main(){

    printf("student name is %s , age is %d \n",student.name,student.age);
    
    strcpy(book2.title,"c");
    strcpy(book2.author,"mr hu");
    book2.book_id = 2;
    printf("book2 title is %s, author is %s,book_id is %d \n",book2.title,book2.author,book2.book_id);

    struct Book book3;
     strcpy(book3.title,"java");
    strcpy(book3.author,"mr xu");
    book3.book_id = 3;
    printf("boo3 title is %s, author is %s,book_id is %d \n",book3.title,book3.author,book3.book_id);

    struct COMPLEX cp;
    cp.a = 1;
    cp.s.a = 2;
    cp.s.b = 3;
    printf("complex is %d ,{%d,%d} \n",complex.a,complex.s.a,complex.s.b);
    printf("cp is %d ,{%d,%d} \n",cp.a,cp.s.a,cp.s.b);

    //使用node实现类似链表的功能
    struct NODE node1;
    struct NODE node2;
    struct NODE node3;
    
    strcpy(node1.string,"node1Str");
    node1.next_node = NULL;
    strcpy(node2.string,"node2Str");
    node2.next_node = &node1;
    printf("node2.next_node->string is %s \n",node2.next_node->string);
    strcpy(node3.string,"node3Str");
    node3.next_node = &node2;
    printf("node3.next_node->next_node->string is %s \n",node3.next_node->next_node->string);

    

}
*/

//2.3 结构作为函数参数
/*
//2.3.1 函数声明
void printBook(struct Book book);

//2.3.2 函数定义
void printBook(struct Book book){
    printf("book title is %s,author is %s,book_id is %d",book.title,book.author,book.book_id);
}

void main(){
    struct Book book3;
    strcpy(book3.title,"python");
    strcpy(book3.author,"mr de");
    book3.book_id = 4;
    //2.3.3 函数使用
    printBook(book3);
    getchar();
}
*/

//2.4 指向结构的指针
/*
void printBook(struct Book *book);

void main(){

    //定义指向结构的指针
    struct Book *pbook;
    struct Book book5;
    strcpy(book5.title,"javascript");
    strcpy(book5.author,"mis ha");
    book5.book_id = 6;
    //在指针变量中存储变量的地址
    pbook = &book5;
    //通过 -> 使用指针访问结构的成员
    printf("book title is %s, author is %s ,book_id is %d \n",pbook->title,pbook->author,pbook->book_id);

    strcpy(pbook->title ,"js");
    strcpy(pbook->author,"mr ha");
    pbook->book_id = 7;

    printf("after change book title is %s, author is %s ,book_id is %d \n",pbook->title,pbook->author,pbook->book_id);
    printf("after change book title is %s, author is %s ,book_id is %d \n",book5.title,book5.author,book5.book_id);

    //下面两种方式一样
    printBook(pbook);
    printBook(&book5);
    getchar();

}

void printBook(struct Book *book){
    printf("printBook title is %s, author is %s ,book_id is %d \n",book->title,book->author,book->book_id);
}
*/






//3. 共用体

/*
//3.1 定义  
// union [union tag]
// {
//    member definition;
//    member definition;
//    ...
//    member definition;
// } [one or more union variables];

union Data{
    int a;
    float f;
    char str[20];
};

void main(){

    //3.2 共用体占用的大小是共用体中占用内存最大的成员
    union Data data;
    printf("data memory is %d \n",sizeof(data));

    data.a = 10;
    data.f = 20.01;
    strcpy(data.str,"haha");
    //3.3 最后只能正确输出 str ，因为后面的会覆盖前面的
    printf("data a : %d  f : %f  str : %s \n",data.a,data.f,data.str);

    data.a = 30;
    printf("data.a : %d \n",data.a);
    data.f = 40.01;
    printf("data.f : %f \n",data.f);
    strcpy(data.str,"hoho");
    printf("data.str : %s \n",data.str);

    getchar();

    //输出结果
    // data memory is 20
    // data a : 1634230632  f : 267916467819992060000.000000  str : haha
    // data.a : 30
    // data.f : 40.009998
    // data.str : hoho
}
*/






//4. typedef
// typedef 用来为类型取一个新的名字
typedef char CHAR;

//为结构体 Worker_Struct 起一个新名字 Worker
typedef struct Worker_Struct{
    char name[50];
    int age;
    float salary;
} Worker;

void main(){
    CHAR a = 'f';
    printf("a : %c \n",a);

    Worker worker;
    strcpy(worker.name,"ali");
    worker.age = 18;
    worker.salary = 100.1;

    printf("worker name is %s ,age is %d, salary is %f",worker.name,worker.age,worker.salary);

    getchar();
    
}