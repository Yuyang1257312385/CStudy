#include <stdio.h>

/**
 * day07: 指针运算和函数指针
 */


//1. 二级指针和多级指针
/*
void main(){

    int a = 12;
    int* p = &a;
    //二级指针
    int** s_p = &p;
    //三级指针
    int*** s_s_p = &s_p;
    printf("一级指针 p 的值 %p , 二级指针 s_p 的值为 %p , 三级指针 s_s_p 的值为%p \n",p,s_p,s_s_p);

    printf("原始值 : %d \n",***s_s_p);

    // 注意点 : p[0] 表示指针p的值，等同于 *p ,即为 a ,
    printf("s_p的值 : %p , p的值 : %p , a的值 : %d \n", s_s_p[0], s_p[0], p[0]);

    //输出结果
    // 一级指针 p 的值 000000000061FE14 , 二级指针 s_p 的值为 000000000061FE08 , 三级指针 s_s_p 的值为000000000061FE00
    // 原始值 : 12
    //s_p的值 : 000000000061FE08 , p的值 : 000000000061FE14 , a的值 : 12

    int f = a++ + a++;
    printf("b %d \n",f);

    getchar();

}
*/


//2. 数组 和 数组指针 （重点）
/*
void main(){

    int arr[] = {1,2,3,4};

    //2.1 数组遍历
    //不推荐方式，Linux系统可能会有问题
    for (int i = 0; i < 4; i++)
    {   
        printf("arr[%d] is %d \n",i,arr[i]);
    }
    //推荐方式
    int i = 0;
    for(; i < 4; i++){
        printf("arr[%d] is %d \n",i,arr[i]);
    }

    //2.2 一种现象 arr == &arr == &arr[0] , 即 arr 的值等于 arr的地址 等于 arr[0] 的地址
    printf("arr = %p \n",arr);
    printf("&arr = %p \n",&arr);
    printf("&arr[0] = %p \n",&arr[0]);


    //2.3 获取 及 操作指针
    //获取指针 数组指针指向的就是数组的首地址
    int* arr_p = arr;
    //操作数组指针
    printf("*arr_p = %d \n",*arr_p);
    //向后挪一位
    arr_p++;
    printf("*arr_p = %d \n",*arr_p);
    //再向后挪两位
    arr_p += 2;
    printf("*arr_p = %d \n",*arr_p);

    getchar();
    

}
*/

//3. 使用指针遍历数组 循环赋值
/*
void main(){
    int arr[] = {1,2,3,4};

    //3.1 遍历
    int* arr_p = arr;
    int i = 0;
    for(; i < 4; i++ ){
        printf("arr[%d] is %d \n",i,*(arr_p + i));
    }

    //3.2 循环赋值
    i = 0;
    for(; i < 4; i++ ){
        //方式一
        // arr[i] = i*2;
        //方式二 arr[i] 等同于 *(arr_p + i)
        *(arr_p + i) = i*2;
    }

    i = 0;
    for ( ; i < 4; i++)
    {
        printf("arr[%d] is %d \n",i,*(arr_p + i));
    }
    
    getchar();
}
*/

//4. 函数指针
/*
void add(int a ,int b){
    printf("a + b = %d \n",a+b);
}

void minus(int a,int b){
    printf("a - b = %d \n",a-b);
}

//函数指针的定义   返回值类型(方法名称)(参数类型)
void operate(void(method)(int,int),int num1,int num2){
    method(num1,num2);
}

void main(){

    operate(add,1,2);
    operate(minus,1,2);
    getchar();

}
*/

//5. 方法回调

void callback(int current,int total){
    printf("current is %d , total is %d ",current,total);
}

void compress(char* filename,void(callbackmethod)(int,int)){
    callback(12,24);
}

void main(){
    //传入方法名，会回调该方法
    compress("haha.png",callback);
    getchar();

}



