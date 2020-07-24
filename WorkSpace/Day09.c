

#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //atoi
#include <ctype.h> // tolower


/*
//1. 字符串的定义 
void main(){

    //1.1 通过数组定义
    char arr[] = "darren";
    //注意 ：这种方式要写结束符 '\0'
    char arr1[] = {'d','a','r','r','e','n','\0'};
    printf("arr is %s \n",arr);
    printf("arr1 is %s \n",arr1);

    //1.2 通过 char* 定义
    char* str = "Darren";
    printf("arr1 is %s \n",str);

    // 1.3 两种方式区别  char*不能重新赋值 会报异常

    arr[1] = 'b';
    arr1[1] = 'b';
    // 报异常
    // str[1] = 'b';
    printf("arr is %s \n",arr);
    printf("arr1 is %s \n",arr1);

    getchar();

}

// 输出结果
// arr is darren
// arr1 is darren
// arr1 is Darren
// arr is dbrren
// arr1 is dbrren
*/

/*
//2. 字符串长度获取
  sizeof(str)/sizeof(char) 为什么不行，后面会介绍  结束标记 '\0'

//str是个指针
void strlength(char* str,int* result){
    int len = 0;
    //*str是指针存放的值
    while(*str != '\0'){
        //指针偏移
        str++;
        len++;
    }
    *result = len;
}

void main(){
    char* str = "darren";
    printf("%s length is %d \n" ,str,strlen(str));

    int len;
    strlength(str,&len);
    printf("%s length is %d \n",str,len);
    getchar();
}
*/

//3. 字符串的转换
/*
void main(){

    char* intStr = "12";
    printf("intStr is %d \n",atoi(intStr));

    char* intStr1 = "12xxx";
    printf("intStr1 is %d \n",atoi(intStr1));

    char* floatStr = "12.5";
    printf("floatStr is %f \n",atof(floatStr));

    char* floatStr1 = "12.5xx";
    printf("floatStr1 is %f \n",atof(floatStr1));

    char* str = "x12";
    printf("str is %d \n",atoi(str));

    char* str1 = "x12.5";
    printf("str1 is %f \n",atof(str1));

    getchar();

}

//返回值
// intStr is 12
// intStr1 is 12
// floatStr is 12.500000
// floatStr1 is 12.500000
// str is 0
// str1 is 0.000000
*/

//4. 字符串比较 strcmp
/*
void isEqual(char* left,char* right,char* result){

    int cp = strcmp(left,right);
    if(cp == 0){
        *result = "equal";
    }else{
        *result = "not equal";
    }

}

void isEqualIgnoreCase(char* left,char* right,char* result){

    int cp = strcmpi(left,right);
    if(cp == 0){
        *result = "equal";
    }else{
        *result = "not equal";
    }

}

void main(){

    char* str_1 = "darren";
    char* str_2 = "Darren";

    char* equalResult = "";
    isEqual(str_1,str_2,&equalResult);
    printf("%s and %s : %s \n",str_1,str_2,equalResult);

    char* result = "";
    isEqualIgnoreCase(str_1,str_2,&result);
    printf("%s and %s ignore case: %s \n",str_1,str_2,result);
    
    getchar();

}
*/


//5. 字符串的查找 包含 拼接 截取 大小写转换

//包含
int contain(char *str, char *subStr)
{

    if (strstr(str, subStr))
    { //等同于 strstr(str,subStr) != NULL
        printf("%s contain %s : \n", str, subStr);
        return 1;
    }
    else
    {
        printf("%s dont contain %s : \n", str, subStr);
        return 0;
    }
}

//截取
void subString(char* str, int start, int subLenght,char* result)
{
    // char result[subLenght+1];
    str += start;
    int i = 0;
    for (; i < subLenght; i++)
    {
        result[i] = *str;
        str++;
    }
    result[subLenght] = '\0';
    printf("subString %s \n",result);

    // return result;
}

//错误写法
//这种获取到的返回值还是null
//因为result是在栈中的，出了方法内存就会被回收掉
//或者就是在方法内通过malloc来动态分配内存，然后在外面free，不过不推荐这种，内存最好是自己处理好
char* substr(char* str, int start, int subLenght)
{
    char result[subLenght+1];
    str += start;
    int i = 0;
    for (; i < subLenght; i++)
    {
        result[i] = *str;
        str++;
    }
    result[subLenght] = '\0';
    // printf("subString %s \n",result);

    return result;
}

//转为小写
void toLowerCase(char* str,char* result){

    int i = 0;
    while(str[i]){
        result[i] = tolower(str[i]);
        i++;
    }
    result[i] = '\0';

}

//替换
void replace(char* str,char* res,char* des,char* result){



}

void main()
{

    // //5.1  查找 strstr
    // char *str = "tomorrow is another day";
    // char *subStr = "no";
    // //返回的是字符串第一次出现的位置
    // char *pos = strstr(str, subStr);
    // //若直接打印 后面会乱起八糟的其他东西  nother day绗竴娆″嚭鐜扮殑浣嶇疆鏄
    // printf("pos is : %s \n", pos);

    // int position = pos - str;
    // printf("the first postion of no is : %d \n", position);

    // //5.2 包含
    // contain(str, subStr);
    // char *subStr2 = "hello";
    // contain(str, subStr2);

    // //5.3 拷贝 strcpy
    // int length = strlen(str);
    // char cpy[length];
    // strcpy(cpy, str);
    // printf("cpy is : %s \n", cpy);

    // //5.4 拼接 strcat
    // char *a = "hello ";
    // char *b = "world";
    // char concatStr[strlen(a) + strlen(b)];
    // strcpy(concatStr, a);
    // strcat(concatStr, b);
    // printf("concatStr is :  %s \n", concatStr);

    // // //5.5 截取
    // char* hello = "helloworld";
    // char result[3];
    // subString(hello,1,2,result);
    
    // printf("substring(%s,%d,%d) is %s \n",hello,1,2,result);

    // //5.6 大小写转化

    // char* upper = "THISHAHAha";
    // char lower[strlen(upper)+1];
    // toLowerCase(upper,lower);
    // printf("%s toLowerCase : %s \n",upper,lower);

    //5.7 替换


    getchar();
}
