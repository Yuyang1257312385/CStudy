#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. 文件读 fopen fgets fclose
/*
void main(){

    // 打开文件 （文件名，模式）mode r(读) w(写) rb(作为二进制读) wb(作为二进制写)
	// FILE *fopen( const char *filename, const char *mode );

    //此处用的是相对路径
    char* fileName = "TestFile.txt";
    //1.1 打开文件 fopen
    FILE *file = fopen(fileName,"r");
    if(!file){
        printf("open file fail");
        exit(0);
    }
    //1.2 读取文件
    char buffer[10];
    while(fgets(buffer,10,file)){
        printf("%s",buffer);
    }

    //1.3 关闭文件
    fclose(file);

    getchar();

}
*/








//2. 文件写 fopen fputs fclose
/*
void main(){
    char* fileName = "TestFile_New.txt";
    //2.1 打开文件
    FILE *file = fopen(fileName,"w");
    if(!file){
        printf("open file fail");
        exit(0);
    }
    //2.2 写入内容
    char* input = "this is line one\n";
    char* input2 = "this is line two";
    fputs(input,file);
    fputs(input2,file);
    //2.3 关闭文件
    fclose(file);
}
*/








//3. 文件复制 当作二进制文件来操作 fread fwrite 注意 rb wb
/*
void main(){
    
    char* name_src = "timg.jpg";
    char* name_des = "timg_copy.jpg";

    //3.1 打开文件
    FILE *file_src = fopen(name_src,"rb");
    FILE *file_des = fopen(name_des,"wb");

    if(!file_src || !file_des){
        printf("open file fail");
        exit(0);
    }

    //3.2 从源文件中读取buffer
    int buffer[512];
    int len;
    while((len = fread(buffer,sizeof(int),512,file_src)) != 0)
    {
        //3.3 将buffer写入到目标文件中
        fwrite(buffer,sizeof(int),len,file_des);
    }

    //3.4 关闭文件
    fclose(file_src);
    fclose(file_des);

}
*/


//4. 获取文件的大小 
/*
void main(){
    char* fileName = "timg.jpg";
    //4.1 打开文件
    FILE *file = fopen(fileName,"rb");
    if(!file){
        printf("open file fail");
        exit(0);
    }
    //4.2 将文件指针移动到最后 fseek
    fseek(file,0,SEEK_END);
    //4.3 计算偏移量 ftell
    long size = ftell(file);
    printf("file size is %ld",size);
    //4.4 关闭文件
    fclose(file);
    getchar();
}
*/








//5. 文件加密 解密 

//5.1 每个字节都加密
/*
//加密

void main(){
    char* fileName = "timg.jpg";
    char* encryptFileName = "timg_encrypt.jpg";

    //5.1 打开文件
    FILE *file_src = fopen(fileName,"rb");
    FILE *file_encrypt = fopen(encryptFileName,"wb");

    if(!file_src || !file_encrypt){
        printf("file open fail");
        exit(0);
    }

    //5.2 加密
    // 思路：把每一个字节都拿出来，对每一个字节都处理，把某部分字节拿出来，进行处理
	// 10^5 异或  加密过程
	//  1010  
	// ^0101
	//  1111  加密

	// 解密 同样的去异或 5 
	//  1111
	// ^0101
	//  1010    解密后 10
    int c;
    //EOF :  end of file
    while((c = fgetc(file_src)) != EOF){

        fputc(c^5,file_encrypt);
    }

    fclose(file_encrypt);
    fclose(file_src);


}


//解密
void main(){
    char* file_name_src = "timg_encrypt.jpg";
    char* file_name_des = "timg_decrpyt.jpg";

    FILE *file_src = fopen(file_name_src,"rb");
    FILE *file_des = fopen(file_name_des,"wb");

    if(!file_src || !file_des){
        printf("file open fail");
        exit(0);
    }

    int c;
    while((c = fgetc(file_src)) != EOF){
        fputc(c^5,file_des);
    }

    fclose(file_src);
    fclose(file_des);

}

*/


//5.2 只加密第一个字节

//加密
/*
void main(){
    char* fileName = "timg.jpg";
    char* encryptFileName = "timg_encrypt.jpg";

    //5.1 打开文件
    FILE *file_src = fopen(fileName,"rb");
    FILE *file_encrypt = fopen(encryptFileName,"wb");

    if(!file_src || !file_encrypt){
        printf("file open fail");
        exit(0);
    }

    //5.2 加密
    int c;
    int index = 0;
    //EOF :  end of file
    while((c = fgetc(file_src)) != EOF){
        if(index == 0){
            fputc(c^5,file_encrypt);
            index = 1;
        }else {
            fputc(c,file_encrypt);
        }
    }

    fclose(file_encrypt);
    fclose(file_src);


}


//解密

void main(){
    char* file_name_src = "timg_encrypt.jpg";
    char* file_name_des = "timg_decrpyt.jpg";

    FILE *file_src = fopen(file_name_src,"rb");
    FILE *file_des = fopen(file_name_des,"wb");

    if(!file_src || !file_des){
        printf("file open fail");
        exit(0);
    }

    int c;
    int index = 0;
    while((c = fgetc(file_src)) != EOF){
        if(index == 0){
            fputc(c^5,file_des);
            index = 1;
        } else {
            fputc(c,file_des);
        }
    }

    fclose(file_src);
    fclose(file_des);

}
*/


//文件切割  思路类似于断点下载
//char** 二维数组？
 

 