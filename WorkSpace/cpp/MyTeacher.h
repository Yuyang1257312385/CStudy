
// 只包含一次 和下面 ifndef 的作用相同
// 如果两个头文件互相include，若不定义只包含一次，那就是无限include,会出现问题
//#pragma once 

#ifndef ANDROIDDEMOSET_MYTEACHER_H
#define ANDROIDDEMOSET_MYTEACHER_H

//class 类的头文件  声明变量和方法
class MyTeacher {

    private:
        int m_age;
    public:
        void setAge(int age);
        int getAge();
};


#endif //ANDROIDDEMOSET_MYTEACHER_H