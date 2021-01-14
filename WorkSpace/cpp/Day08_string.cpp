#include <iostream>
#include <algorithm>// STL 算法包
#include <cctype> // 用到一个函数指针，回调函数



using namespace std;

string replaceStr(string initStr,string oldValue,string newValue){
    int pos = initStr.find(oldValue,0);
    while(pos != -1 ){
        initStr.replace(pos,oldValue.length(),newValue);
        pos = initStr.find(oldValue,0);
    }
    return initStr;
}

int main(){

    //字符串的常用操作

    //1. 对象的构建
    string str1 = "123";
    string str2("456");
    string *str3 = new string("789");

    char* c_str4 = "abc";
    string str4(c_str4);
    //这种方式报错
    // string str5(5,"a");
    cout << " str1 : " << str1.c_str() << " str2 : " << str2.c_str() << " str3 : " << str3->c_str() << " str4 " << str4.c_str() << endl;


    cout << endl;
    cout << endl;

    //2. 字符串的遍历
    cout << "traversing string " << endl; 
    //2.1 普通遍历
    string str6 = "123";
    for (int i = 0; i < str6.length(); i++)
    {
        cout << "str6[" << i << "] is " << str6[i] << endl; 
    }

    cout << endl;

    cout << "traversing by iterator " << endl;
    //2.2 迭代器遍历
    for (string::iterator it = str6.begin(); it < str6.end(); it++)
    {
       cout << *it << endl;
    }
    
    cout<< endl;

    cout << "str.at(i) and str[i]" << endl;
    //2.3 str.at(i) 和 str[i] 的区别
    cout << "str.at(i) " << endl;
    try
    {
         for (int i = 0; i < str6.length()+3; i++)
        {
            cout << str6.at(i) << endl;
        }
    }
    catch(const std::exception& e)
    {
        cout << "exception : " << e.what() << endl;
    }
    
   
    cout << "str[i] " << endl;

    try{
        //这里竟然没有异常 但是会输入乱七八糟的东西
        for (int i = 0; i < str6.length() + 3; i++)
        {
            cout << str6[i] << endl;
        }    
    }catch(...){
        cout << "exception " << endl;
    }

    //3. 添加
    string str7 = "123";
    string str8 = "456";
    string str9 = str7 + str8;
    string str10 = str7.append(str8);
    cout << "str9 : " << str9.c_str() << endl;
    cout << "str10 : " << str10.c_str() << endl;


    cout << endl;
    cout << endl;

    //4. 删除
    string str11 = "123abc456def";
    //参数一: 起始位置 参数二:删除几个
    str11.erase(1,2);
    cout << "str11 " << str11 << endl;

    string str12 = "123abc456def";
    for(string::iterator it = str12.begin() ;it<str12.begin()+3;it++){
        str12.erase(it);
    }
    cout << "str12 " << str12.c_str() << endl;


    //5. 替换
    string str13 = "1234abcd1234abcd";
    //参数一: 起始位置 参数二: 替换几个 参数三: 替换成谁
    str13.replace(0,2,"xxx");
    cout << "str13 : " << str13.c_str() << endl;

    cout << endl;
    cout << endl;

    //6. 查找
    string str14 = "123abc456abc";
    //参数一: 查找谁 参数二:从哪里开始 若找不到，返回 -1
    int position = str14.find("ab",4);
    int rPosition = str14.rfind("ab");
    cout << "position : " << position << " rPosition" << rPosition << endl;

    cout << endl;
    cout << endl;

    //7. 大小写转化
    string str15 = "AAA abc BBB abc 123";
    //导包 #include <algorithm>// STL 算法包
    //导包 #include <cctype> //toupper
    transform(str15.begin(),str15.end(),str15.begin(),::toupper);
    cout << "transform upper " << str15.c_str() << endl;
    transform(str15.begin(),str15.end(),str15.begin(),::tolower);
    cout << "transform lower " << str15.c_str() << endl;

    cout << endl;
    cout << endl;

    //8. string str1 = "AAA abc BBB abc 123";  abc 全部替换成 def 
    string str16 = "AAA abc BBB abc 123";
    string oldValue = "abc";
    string newValue = "def";
    string result = replaceStr(str16,oldValue,newValue);

    cout << result.c_str() << endl;

    

    cout << endl;
    cout << endl;


    int exit;
    cout << "input anything exit" << endl;
    cin >> exit;

    return 0;

    //输出结果
    // str1 : 123 str2 : 456 str3 : 789 str4 abc


    // traversing string
    // str6[0] is 1
    // str6[1] is 2
    // str6[2] is 3

    // traversing by iterator
    // 1
    // 2
    // 3

    // str.at(i) and str[i]
    // str.at(i)
    // 1
    // 2
    // 3
    // exception : basic_string::at: __n (which is 3) >= this->size() (which is 3)
    // str[i]
    // 1
    // 2
    // 3



    // str9 : 123456
    // str10 : 123456


    // str11 1abc456def
    // str12 2ac456def
    // str13 : xxx34abcd1234abcd


    // position : 9 rPosition9


    // transform upper AAA ABC BBB ABC 123
    // transform lower aaa abc bbb abc 123


    // AAA def BBB def 123


    // input anything exit
}

