#include <stdio.h>

/**
 * day07: ָ������ͺ���ָ��
 */


//1. ����ָ��Ͷ༶ָ��
/*
void main(){

    int a = 12;
    int* p = &a;
    //����ָ��
    int** s_p = &p;
    //����ָ��
    int*** s_s_p = &s_p;
    printf("һ��ָ�� p ��ֵ %p , ����ָ�� s_p ��ֵΪ %p , ����ָ�� s_s_p ��ֵΪ%p \n",p,s_p,s_s_p);

    printf("ԭʼֵ : %d \n",***s_s_p);

    // ע��� : p[0] ��ʾָ��p��ֵ����ͬ�� *p ,��Ϊ a ,
    printf("s_p��ֵ : %p , p��ֵ : %p , a��ֵ : %d \n", s_s_p[0], s_p[0], p[0]);

    //������
    // һ��ָ�� p ��ֵ 000000000061FE14 , ����ָ�� s_p ��ֵΪ 000000000061FE08 , ����ָ�� s_s_p ��ֵΪ000000000061FE00
    // ԭʼֵ : 12
    //s_p��ֵ : 000000000061FE08 , p��ֵ : 000000000061FE14 , a��ֵ : 12

    int f = a++ + a++;
    printf("b %d \n",f);

    getchar();

}
*/


//2. ���� �� ����ָ�� ���ص㣩
/*
void main(){

    int arr[] = {1,2,3,4};

    //2.1 �������
    //���Ƽ���ʽ��Linuxϵͳ���ܻ�������
    for (int i = 0; i < 4; i++)
    {   
        printf("arr[%d] is %d \n",i,arr[i]);
    }
    //�Ƽ���ʽ
    int i = 0;
    for(; i < 4; i++){
        printf("arr[%d] is %d \n",i,arr[i]);
    }

    //2.2 һ������ arr == &arr == &arr[0] , �� arr ��ֵ���� arr�ĵ�ַ ���� arr[0] �ĵ�ַ
    printf("arr = %p \n",arr);
    printf("&arr = %p \n",&arr);
    printf("&arr[0] = %p \n",&arr[0]);


    //2.3 ��ȡ �� ����ָ��
    //��ȡָ�� ����ָ��ָ��ľ���������׵�ַ
    int* arr_p = arr;
    //��������ָ��
    printf("*arr_p = %d \n",*arr_p);
    //���Ųһλ
    arr_p++;
    printf("*arr_p = %d \n",*arr_p);
    //�����Ų��λ
    arr_p += 2;
    printf("*arr_p = %d \n",*arr_p);

    getchar();
    

}
*/

//3. ʹ��ָ��������� ѭ����ֵ
/*
void main(){
    int arr[] = {1,2,3,4};

    //3.1 ����
    int* arr_p = arr;
    int i = 0;
    for(; i < 4; i++ ){
        printf("arr[%d] is %d \n",i,*(arr_p + i));
    }

    //3.2 ѭ����ֵ
    i = 0;
    for(; i < 4; i++ ){
        //��ʽһ
        // arr[i] = i*2;
        //��ʽ�� arr[i] ��ͬ�� *(arr_p + i)
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

//4. ����ָ��
/*
void add(int a ,int b){
    printf("a + b = %d \n",a+b);
}

void minus(int a,int b){
    printf("a - b = %d \n",a-b);
}

//����ָ��Ķ���   ����ֵ����(��������)(��������)
void operate(void(method)(int,int),int num1,int num2){
    method(num1,num2);
}

void main(){

    operate(add,1,2);
    operate(minus,1,2);
    getchar();

}
*/

//5. �����ص�

void callback(int current,int total){
    printf("current is %d , total is %d ",current,total);
}

void compress(char* filename,void(callbackmethod)(int,int)){
    callback(12,24);
}

void main(){
    //���뷽��������ص��÷���
    compress("haha.png",callback);
    getchar();

}



