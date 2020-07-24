#include <stdio.h>

//定义常量一 
#define WIDTH 10
#define LENGTH 5
#define NEWLINE '\n'

/*
 * day06 : 
 *      1. 基本数据类型 及 打印
 *      2. 指针变量 和 获取地址的值
 *      3. 通过指针修改值
 *      4. 练习 ： 1>通过方法修改值 2> 不使用中间变量互换ab的值
 */
void main(){


    // part 1 : Hello
    // printf("hello world\n");


    // PART 2 : 基本数据类型
    /*
    int i = 10;
    short s = 100;
    long l = 1000;
    float f = 0.1;
    double d = 0.02;
    char c = 'x';
    printf("int 的值 %d \n",i);
    printf("int 的值 8进制 %o \n",i);
    printf("int 的值 16进制 %x \n",i);
    printf("int 的值 16进制 %X \n",i);
    printf("short 的值 %d \n",s);
    printf("long 的值 %ld \n", l);
    printf("float 的值 %f \n",f);
    printf("double 的值 %lf \n",d);
    printf("char 的值 %c \n",c);
    printf("int 值占的大小 %d \n",sizeof(i));
    printf("double 值占的大小 %d \n",sizeof(d));
    printf("char 值占的大小 %d \n",sizeof(c));

    //输出结果
    // int 的值 10
    // int 的值 8进制 12
    // int 的值 16进制 a
    // int 的值 16进制 A
    // short 的值 100
    // long 的值 1000
    // float 的值 0.100000
    // double 的值 0.020000
    // char 的值 x
    // int 值占的大小 4
    // double 值占的大小 8
    // char 值占的大小 1
    */


    

    //PART 3 : 指针变量和获取地址的值

    /*
    int a = 10;
    printf("a 的值 %d \n",a);
    // 通过 & 来取地址
    printf("a 的地址是 %p \n",&a);
    //通过 * 来取地址里面的值
    printf("a 的地址里面的值 %d \n",*(&a));
    //指针变量 : 指针变量存放的就是变量存放的地址

    double d = 0.1;
    printf("double类型变量 d的值 %lf \n",d);
    double* p = &d;
    printf("p 的值为 %p \n",p);
    printf("p 地址对应的值为 %lf \n",*p);


    //输出结果
    // a 的值 10
    // a 的地址是 000000000061FE14
    // a 的地址里面的值 10
    // double类型变量 d的值 0.100000
    // p 的值为 000000000061FE08
    // p 地址对应的值为 0.100000
    */


   //PART 4 : 通过指针修改值

    /*
   int b = 100;
   printf("b 的原始值 %d \n",b);
   b = 200;
   printf("b 变量重新赋值后的值 %d \n",b);
   int* p = &b;
   *p = 300;
   printf("b 通过指针修改后的值 %d \n",b);

   //输出结果
    //b 的原始值 100
    //b 变量重新赋值后的值 200
    //b 通过指针修改后的值 300
    */

   //PART 5 : 常量
   /*
   //方式一 在顶部 #define 常量名 常量值
   printf("width * length = %d %c",WIDTH * LENGTH,NEWLINE);

   //方式二 const 类型 常量名 = 常量值 
   const int X = 7;
   const int Y = 8;
   const char NEW_LINE = '\n';
   printf("x * y = %d %c",X * Y,NEW_LINE);
   */

   //练习 1 : 通过方法修改值
   /*
    int a = 1;
    change(&a);
    printf("修改后的值 %d \n",a);
    */

   //练习 2 : 不声明新的变量（不开辟内存） 交换a和b的值
   /*
    int a = 100;
    int b = 200;
    exchange(&a,&b);
    printf("交换后a : %d b : %d \n",a,b);
    */

    getchar();
}



void exchange(int* a,int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void change(int* p){
    *p = 100;
}