#include <stdio.h>

//���峣��һ 
#define WIDTH 10
#define LENGTH 5
#define NEWLINE '\n'

/*
 * day06 : 
 *      1. ������������ �� ��ӡ
 *      2. ָ����� �� ��ȡ��ַ��ֵ
 *      3. ͨ��ָ���޸�ֵ
 *      4. ��ϰ �� 1>ͨ�������޸�ֵ 2> ��ʹ���м��������ab��ֵ
 */
void main(){


    // part 1 : Hello
    // printf("hello world\n");


    // PART 2 : ������������
    /*
    int i = 10;
    short s = 100;
    long l = 1000;
    float f = 0.1;
    double d = 0.02;
    char c = 'x';
    printf("int ��ֵ %d \n",i);
    printf("int ��ֵ 8���� %o \n",i);
    printf("int ��ֵ 16���� %x \n",i);
    printf("int ��ֵ 16���� %X \n",i);
    printf("short ��ֵ %d \n",s);
    printf("long ��ֵ %ld \n", l);
    printf("float ��ֵ %f \n",f);
    printf("double ��ֵ %lf \n",d);
    printf("char ��ֵ %c \n",c);
    printf("int ֵռ�Ĵ�С %d \n",sizeof(i));
    printf("double ֵռ�Ĵ�С %d \n",sizeof(d));
    printf("char ֵռ�Ĵ�С %d \n",sizeof(c));

    //������
    // int ��ֵ 10
    // int ��ֵ 8���� 12
    // int ��ֵ 16���� a
    // int ��ֵ 16���� A
    // short ��ֵ 100
    // long ��ֵ 1000
    // float ��ֵ 0.100000
    // double ��ֵ 0.020000
    // char ��ֵ x
    // int ֵռ�Ĵ�С 4
    // double ֵռ�Ĵ�С 8
    // char ֵռ�Ĵ�С 1
    */


    

    //PART 3 : ָ������ͻ�ȡ��ַ��ֵ

    /*
    int a = 10;
    printf("a ��ֵ %d \n",a);
    // ͨ�� & ��ȡ��ַ
    printf("a �ĵ�ַ�� %p \n",&a);
    //ͨ�� * ��ȡ��ַ�����ֵ
    printf("a �ĵ�ַ�����ֵ %d \n",*(&a));
    //ָ����� : ָ�������ŵľ��Ǳ�����ŵĵ�ַ

    double d = 0.1;
    printf("double���ͱ��� d��ֵ %lf \n",d);
    double* p = &d;
    printf("p ��ֵΪ %p \n",p);
    printf("p ��ַ��Ӧ��ֵΪ %lf \n",*p);


    //������
    // a ��ֵ 10
    // a �ĵ�ַ�� 000000000061FE14
    // a �ĵ�ַ�����ֵ 10
    // double���ͱ��� d��ֵ 0.100000
    // p ��ֵΪ 000000000061FE08
    // p ��ַ��Ӧ��ֵΪ 0.100000
    */


   //PART 4 : ͨ��ָ���޸�ֵ

    /*
   int b = 100;
   printf("b ��ԭʼֵ %d \n",b);
   b = 200;
   printf("b �������¸�ֵ���ֵ %d \n",b);
   int* p = &b;
   *p = 300;
   printf("b ͨ��ָ���޸ĺ��ֵ %d \n",b);

   //������
    //b ��ԭʼֵ 100
    //b �������¸�ֵ���ֵ 200
    //b ͨ��ָ���޸ĺ��ֵ 300
    */

   //PART 5 : ����
   /*
   //��ʽһ �ڶ��� #define ������ ����ֵ
   printf("width * length = %d %c",WIDTH * LENGTH,NEWLINE);

   //��ʽ�� const ���� ������ = ����ֵ 
   const int X = 7;
   const int Y = 8;
   const char NEW_LINE = '\n';
   printf("x * y = %d %c",X * Y,NEW_LINE);
   */

   //��ϰ 1 : ͨ�������޸�ֵ
   /*
    int a = 1;
    change(&a);
    printf("�޸ĺ��ֵ %d \n",a);
    */

   //��ϰ 2 : �������µı������������ڴ棩 ����a��b��ֵ
   /*
    int a = 100;
    int b = 200;
    exchange(&a,&b);
    printf("������a : %d b : %d \n",a,b);
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