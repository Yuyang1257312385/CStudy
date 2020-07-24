
#include <stdio.h>
#include <stdlib.h>

//c 有分区，四区模型，栈，堆
// 栈 : 占用内存空间最大值为2M ，开辟内存的方式为静态内存开辟 int arr[10*1024*1024] ,方法结束会自动回收
// 堆 : 占用内存空间最大值 80% ， 开辟内存的方式时动态开辟内存 ，不会自动回收，必须手动回收 （内存不再使用的时候一定要手动回收）

//1. 静态内存开辟
/*
void staticlloc()
{

    int arr[5];

    int i = 0;
    for (; i < 5; i++)
    {
        arr[i] = i*2;
        printf("arr[%d]  is %d, &arr[%d] is %p \n",i,arr[i],i,arr+i);
    }
}

void main(){

    while (1)
    {
        Sleep(5000);
        staticlloc();
    }

}
*/

//2. 动态开辟  （注意：一定要手动回收）
/*
void dynamiclloc(){
    // malloc 动态开辟一段连续的内存空间
    int* arr = malloc(1024*1024*sizeof(int));
    printf("arr is %p \n",arr);
    // 手动释放 arr 这一块的内存
    free(arr);

}


void main(){

    while(1){
        _sleep(3000);
        dynamiclloc();
    }

}
*/

//3. 动态开辟内存 使用场景
/*
void main(){

    int count;
    printf("please input num count : ");
    scanf("%d",&count);

    int* arr = malloc(count*sizeof(int));

    int i = 0;
    int input;
    for (; i < count; i++)
    {
        printf("input index %d num : ",i);
        scanf("%d",&input);
        arr[i] = input;
    }


    i = 0;
    for (; i < count; i++)
    {
        printf("arr[%d] is %d,&arr[%d] is %p \n",i,arr[i],i,&arr[i]);
    }

    free(arr);

    scanf("%d",i);

}
*/

//4. 增加一段内存
void main()
{

    printf("input count : ");
    int count;
    scanf("%d", &count);

    int *arr = malloc(count * sizeof(int));

    int i = 0;
    int input;
    for (; i < count; i++)
    {
        printf("input %d : ", i);
        scanf("%d", &input);
        arr[i] = input;
    }

    i = 0;
    for (; i < count; i++)
    {
        printf("arr[%d] is %d, &arr[%d] is %p \n", i, arr[i], i, &arr[i]);
    }

    //在原来的基础上新增一块内存
    printf("input add count : ");
    int addCount;
    scanf("%d", &addCount);
    int *new_arr = realloc(arr, (count + addCount) * sizeof(int));
    ////等同于 new_arr != NULL
    if (new_arr)
    { 
        i = count;
        int addInput;
        for (; i < count + addCount; i++)
        {
            printf("input %d : ", i);
            scanf("%d", &addInput);
            new_arr[i] = addInput;
        }

        i = 0;
        for (; i < count + addCount; i++)
        {
            printf("new_arr[%d] is %d, &new_arr[%d] is %p \n", i, new_arr[i], i, &new_arr[i]);
        }

        free(new_arr);
    }else {
        printf("add memory fail");
        free(arr);
    }
    printf("input any char finish");
    int any;
    scanf("%d",&any);

}

// malloc 动态开辟  连续的一段空间
// free  释放内存

// 使用场景
//根据输入的动态存储

//realloc 改变内存大小空间  realloc(原来内存的指针，总的大小)
//free new_arr 还是 arr

//1. 可以不重新赋值
//2. 若后面的不够，会重新找一块内存，把原来的数据拷贝过来，释放原来的内存，新的头指针就不是原来的头指针了，
//3. 新增内存有可能会失败，失败的时候返回的是NULL   if(new_arr != NULL)    if(new_arr) 一样
//4. 释放的时候也要进行判断，释放完最好把指针置为NULL
//5. 不要反复去释放
